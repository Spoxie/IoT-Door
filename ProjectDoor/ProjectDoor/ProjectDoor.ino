

  

const int sck = 9; 
const int mosi = 8; 
const int cs = A3; 
const int res = A2; 
const int dc = A1; 

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

Adafruit_SSD1331 afficheur = Adafruit_SSD1331(cs, dc, mosi, sck, res); //création of object 

  

void setup(void) 
{ 
afficheur.begin(); // initialization of display objcet 
  pinMode (1, INPUT); 
  Serial.begin(9600); 
} 

  

void loop() 
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

  

  

/* afficheur.fillScreen(BLACK); // background screen in black 

afficheur.setTextColor(SKY); // color of text in cyan 

afficheur.setCursor(0,20); // cursor is in x=0 and y=15 

afficheur.setTextSize(4); 

afficheur.print("YOU"); // display text 

delay(500); // wait 500 ms 

afficheur.fillScreen(BLACK); // background screen in black 

afficheur.setTextColor(SKY); // color of text in cyan 

afficheur.setCursor(0,20); // cursor is in x=0 and y=15 

afficheur.setTextSize(4); 

afficheur.print("GOT"); // display text 

delay(500); // wait 500 ms 

afficheur.fillScreen(BLACK); // background screen in black 

afficheur.setTextColor(SKY); // color of text in cyan 

afficheur.setCursor(0,20); // cursor is in x=0 and y=15 

afficheur.setTextSize(4); 

afficheur.print("MAIL"); // display text 

delay(500); // wait 500 ms 

/* 

//afficheur.setCursor(0,15); // cursor is in x=0 and y=15 

//afficheur.setTextSize(2); // size of text 

//afficheur.setTextColor(ROUGE); // text in red color 

//afficheur.println("DIGILENT"); // display text 

//afficheur.setCursor(20,40); // cursor is in x=20 and y=40 

//afficheur.setTextSize(1); // size of text 

//afficheur.setTextColor(VERT); // text in green color 

//afficheur.println("LEXTRONIC"); // display text 

//afficheur.drawFastHLine(1, 60, afficheur.width()-1, BLEU); // blue line x=1 to screen width-1 and y=60 

delay(2000); // wait 2 s 

afficheur.fillScreen(ORANGE); // background display in black (erase display) 

  

afficheur.fillRoundRect(0, 0, 96, 10.666, 0, RED); // (x, y, leveys, korkeus, pyöreys) 

afficheur.fillRoundRect(0, 10.666, 96, 10.666, 0, ORANGE); 

afficheur.fillRoundRect(0, 21.333, 96, 10.666, 0, YELLOW); 

afficheur.fillRoundRect(0, 32, 96, 10.666, 0, GREEN); 

afficheur.fillRoundRect(0, 42.666, 96, 10.666, 0, BLUE); 

afficheur.fillRoundRect(0, 53.333, 96, 10.666, 0, PURPLE); 

//afficheur.fillCircle(90, 55, 5, JAUNE); // yellow circle with radius=5 in=90 and y=55 

delay(1000); */ 

} 
