/**************************************************************************
				= Philips Hue Library for ESP8266 =

	This library is designed to access and control Philips Hue Lights Directly.

    Written by: Richard Wardlow @ Circuits for Fun, LLC
    GNU GPL, include above text in redistribution
***************************************************************************/
#include <ESP8266WiFi.h>

////////////////////////////////////////
// ESPHue Class
////////////////////////////////////////
class ESPHue
{
	public:
		ESPHue(WiFiClient& client, const char* APIKey, const char* host, uint8_t port);
		String getLightInfo(int lightNum);
		int getLightState(int lightNum);
		void setLight(int lightNum, int state, int sat, int bri, int hue);
		void setLightPower(int lightNum, int state);
		String getGroupInfo(int groupNum);
		int getGroupState(int groupNum);
		void setGroup(int groupNum, int state, int sat, int bri, int hue);
		void setGroupPower(int groupNum, int state);
		int ON = 1;
		int OFF = 0; 
		
	private:
		const char* _host;
		const char* _apiKey;
		uint8_t _port;
		WiFiClient* _client;
		
};


