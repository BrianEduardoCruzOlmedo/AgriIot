#include <Adafruit_NeoPixel.h>

#include <WiFi.h>
const char* ssid[] = {
    "IZZI-8699",
    "TecNM/ITM_WIFI-cloud",
    "Esp8266"
    };
const char* password[] = {
  "109397F28699",
  NULL,
  "hello1818"
};
int Pos_Wifi = 0; 
int intentos = 0;
Adafruit_NeoPixel pixels;
void InitLed(){
  pixels.begin();
}
void ChangeColorLed(int I_Led, int R, int G, int B ){
  pixels.setPixelColor(I_Led, pixels.Color(R, G, B)); 
  pixels.show();
}

void ConnectedWifi(int time, int Maxintentos = 14){
  while(WiFi.status() != WL_CONNECTED){
    WiFi.disconnect(true);
    WiFi.begin(ssid[Pos_Wifi], password[Pos_Wifi]);
    delay(time);
    Serial.print("\nConectando con Wifi " + String(ssid[Pos_Wifi]));
    while (intentos < Maxintentos && WiFi.status() != WL_CONNECTED) {
        ChangeColorLed(0, 255, 0, 0); 
        delay(time);
        Serial.print(".");
        ChangeColorLed(0, 125, 125, 0); 
        delay(time);
        intentos++;
    }
    
    intentos = 0;
    Pos_Wifi = (Pos_Wifi + 1) % (sizeof(ssid)/sizeof(ssid[0]));

  }
  Serial.println("");
  Serial.println("WiFi conectado! " + String(ssid[Pos_Wifi]));
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}
