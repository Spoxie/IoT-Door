// Définition of colors 
#define BLACK 0x0000 //musta 
#define BLUE 0x001F //sininen 
#define RED 0xF800 //punainen 
#define GREEN 0x07E0 //vihreä 
#define SKY 0x07FF //vaaleansininen 
#define PURPLE 0xF81F //violetti 
#define ORANGE 0xFF00 //oranssi 
#define YELLOW 0xFFE0 //keltainen 
#define WHITE 0xFFFF //white 

// Call libraries 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1331.h> 
#include <SPI.h> 
#include <WiFi101.h>
#include <WiFiSSLClient.h>
#include <MQTTClient.h> 

const int sck = 9; 
const int mosi = 8; 
const int cs = A3; 
const int res = A2; 
const int dc = A1; 

Adafruit_SSD1331 afficheur = Adafruit_SSD1331(cs, dc, mosi, sck, res); //création of object 

// WLAN. PSA; When trying to get this to work on your network, change the SSID AND PASS!!!!
char ssid[] = "Machine's Android"; //  your network SSID (name)
char pass[] = "chogathop";    // your network password (use for WPA)

//IBM Watson definitions for the Arduino.
//char *client_id = "d:<your Organization ID>:<your Device Type>:<your Device ID>"; 
char *client_id = "d:pm8jn8:Arduino_MKR1000:AMKR1000";
char *user_id = "use-token-auth";   // telling that authentication will be done with token
char *authToken = "HomoSapiens3000"; // Your IBM Watson Authentication Token

//char *ibm_hostname = "<your-org-id.messaging.internetofthings.ibmcloud.com>";
char *ibm_hostname = "pm8jn8.messaging.internetofthings.ibmcloud.com";



WiFiClient net;
MQTTClient MQTTc;

unsigned long lastMillis = 0;


void setup() 
{ 
  afficheur.begin(); // initialization of display objcet 
  pinMode (1, INPUT); //EXCUSE ME, WHat is this???? 
  Serial.begin(9600); //Initilization of the serial monitor. Shows if you are connected to the IBM Cloud
  WiFi.begin(ssid, pass);
  Serial.println("Connected to WLAN");
  printWiFiStatus();
  
//Starts the MQTT broker and connects.
  
  MQTTc.begin(ibm_hostname, 1883, net);
  connect();
  
} 

  

void loop() 
{ 

MQTTc.loop(); 
if(millis() - lastMillis > 10000) 
     {
        Serial.println(digitalRead(1));
        if (digitalRead(1) == 0) 
          { 
          afficheur.fillScreen(BLACK); // background screen in black 
          afficheur.setTextColor(SKY); // color of text in cyan 
          afficheur.setCursor(0,20); // cursor is in x=0 and y=15 
          afficheur.setTextSize(4); 
          afficheur.print("MAIL"); // display text   
          } 
    
          else 
          { 
          afficheur.fillScreen(BLACK); // background screen in black 
          afficheur.setTextColor(SKY); // color of text in cyan 
          afficheur.setCursor(0,20); // cursor is in x=0 and y=15 
          afficheur.setTextSize(2); 
          afficheur.print("Waiting"); // display text   
          } 
       lastMillis = millis();
     }

}
//Connection establisment
void connect() 
{
  Serial.print("checking WLAN...");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.println("Connecting WLAN...  ");
    Serial.print(".");
    delay(500);
  }
   Serial.print("\nconnecting Watson with MQTT....");
  while (!MQTTc.connect(client_id,user_id,authToken)) 
  {
    Serial.println("Connecting mqtt broker...  ");
    Serial.print(".");
    delay(10000);
  }
  Serial.println("\nconnected!");
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  

  


} 
