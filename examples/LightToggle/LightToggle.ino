#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESPHue.h>

const char* ssid     = "Your_SSID_Here";
const char* password = "Your_PASS_Here";

WiFiClient client;
int Button1 = 12;

ESPHue myHue = ESPHue(client, "Your_API_Key_Here", "Your_Hue_Bridge_IP_Here", 80);

void setup() {
  pinMode(Button1, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
}

void loop() {

  if(digitalRead(Button1) == 0) // If Button1 is pressed
  {
      Serial.println("Button1 Pressed");
      if (myHue.getLightState(3) == 1) // If Light 3 is on
      {
          Serial.println("Hue Light 3 is Currently On, Turning Light Off");
          myHue.setLightPower(3, myHue.OFF);
      }
      else // Light 3 is off
      {
          Serial.println("Hue Light 3 is Currently Off, Turning Light On");
          myHue.setLightPower(3, myHue.ON);
      }
  }
}


