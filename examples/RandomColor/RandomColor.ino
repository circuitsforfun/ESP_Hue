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
  randomSeed(analogRead(A0));
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
      int rndNum = random(267, 65534);
      myHue.setGroup(0, myHue.ON, 255, 255, rndNum);   // Set group 0 to random color (group 0 is all lights by default)
      delay(100);
  }
}


