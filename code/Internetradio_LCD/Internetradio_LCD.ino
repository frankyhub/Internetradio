/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: WEB-Radio mit LCD Display 4 Zeilen 

**************************************************************************************************
Version: 06.07.2024
**************************************************************************************************
Board: ESP32vn IoT UNO
**************************************************************************************************
Libraries:
https://github.com/espressif/arduino-esp32/tree/master/libraries
C:\Users\User\Documents\Arduino
A250
**************************************************************************************************
C++ Arduino IDE V1.8.19

**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
http://arduino.esp8266.com/stable/package_esp8266com_index.json

        
**************************************************************************************************/

#include <WiFi.h> 
#include <ArduinoOTA.h>

//esp32 library to save preferences in flash
#include <Preferences.h>

//instance of prefernces
Preferences pref;
Preferences sender;

//structure for station list
typedef struct {
  char url[150];  //stream url
  char name[32];  //stations name
  uint8_t enabled;//flag to activate the station
} Station;

#define STATIONS 30 //number of stations in the list

//gloabal variables
Station stationlist[STATIONS];
String ssid = "";
String pkey = "";
String ntp = "de.pool.ntp.org";
boolean connected;
uint8_t curStation = 0;   //index for current selected station in stationlist
uint8_t curGain = 200;    //current loudness
uint8_t actStation = 0;   //index for current station in station list used for streaming 
uint32_t lastchange = 0;  //time of last selection change
char title[64];           //character array to hold meta data message
bool newTitle = false;
uint32_t tick = 0;        //last tick-counter value to trigger timed event
uint32_t discon = 0;      //tick-counter value to calculate disconnected time

      
//setup
void setup() {
  Serial.begin(115200);
  Serial.println("Load preferences");
  //preferences will be saved in the EPROM of the ESP32 to keep the values even 
  //if power supply will be interrupted
  //Two topics "radio" and "senderliste" are defined. We will mount both
  pref.begin("radio", false);
  sender.begin("senderlist",false);
  //get ssid and pkey, ntp-server and last gain and last station from preferences
  if (pref.isKey("ssid")) ssid = pref.getString("ssid");
  if (pref.isKey("pkey")) pkey = pref.getString("pkey");
  if (pref.isKey("ntp")) ntp = pref.getString("ntp");
  curGain = 50; //default value
  if (pref.isKey("gain")) curGain = pref.getUShort("gain");
  curStation = 0; //default value
  //set current station to saved value if available
  if (pref.isKey("station")) curStation = pref.getUShort("station");
  if (curStation >= STATIONS) curStation = 0; //check to avoid invalid station number
  actStation = curStation;   //set active station to current station 
  Serial.printf("station %i, gain %i, ssid %s, ntp %s\n", curStation, curGain, ssid.c_str(), ntp.c_str());
  //run setup functions in the sub parts
  setup_audio(); //setup audio streams
  setup_display(); //setup display interface
  setup_senderList(); //load station list from preferences
  setup_rotary(); //init rotary encoder for station selection
  setup_gain(); //init rotary encoder for gain control
  setGain(); //set the current gain
  //Try to connect WLAN show process on display 
  displayClear();
  displayMessage(0, "Servus Franky");

  displayMessage(2, "Verbinde mit");
  displayMessage(3,ssid);

  
  Serial.println("Verbinde WiFi");
  connected = initWiFi(ssid, pkey);
  if (connected) { //successful connection
    displayClear();
    //setup real time clock
    configTzTime("CET-1CEST,M3.5.0/03,M10.5.0/03", ntp.c_str());
    //show date and time and the name of the station
    displayDateTime();
    showStation();
    delay(500);
    // start playing audio stream from web
    if (!startUrl(String(stationlist[actStation].url))) {
      //if no success switch to station 0
      actStation = 0;
      startUrl(String(stationlist[actStation].url));
    }
  } else { //connection not successful
    displayClear();
    displayMessage(0,"Not connected");
    displayMessage(1,"SSID: webradioconf");
    displayMessage(2,"Conf: 192.168.4.1");
    //remember current tick count to allow
    //a retry after five minutes disconnected
    discon = millis();
  }
  //setup the web server and the over the air update
  setup_webserver();
  setup_ota();
  //remember the tick count for the timed event
  tick = millis();
}


void loop() {
  //Check over the air update
  ArduinoOTA.handle();
  //Check for http requests
  webserver_loop();
  if (newTitle) {
    //show the message on the display
    displayMessage2(2,title);
    newTitle = false;
  }
  //detect a disconnect
  if (connected && (WiFi.status() != WL_CONNECTED)){
    connected = false;
    //remember tick count for automatic retry
    discon = millis();
    displayClear();
    displayMessage(1,"  Connection lost!");
  }
  if (connected) {
    audio_loop();
    rotary_loop();
    gain_loop();
  }
  //timed event updatetime display every minute  
  if ((millis() - tick) > 60000) {
    if (connected) displayDateTime();
    tick = millis();
  }
  //do a restart if device was disconnected for more then 5 minutes
  if (!connected && ((millis() - discon) > 300000)) ESP.restart();
}
