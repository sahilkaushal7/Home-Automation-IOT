//my web site, replace with yours
#define DST_IP "iotprojects.000webhostapp.com"//"myprojectshub.com"

//Define the pin for the on board LED
int led = 8;

#define R1 A0
#define R2 A1
#define R3 A2
#define R4 A3



String iot_data,str;
int counter = 0;
int lastIndex = 0;
const int numberOfPieces = 4;
String pieces[numberOfPieces];

int len=0;
int i=0;
char *buff, *token;


#include <LiquidCrystal.h>
#include <EEPROM.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A5, A4, 4, 5, 6, 7);

//Initialize Device
void relay_action()
{
//__________________Relay control_______________________________


   if(EEPROM.read(11)==1)
   {
    digitalWrite(R1,HIGH);
    lcd.setCursor(0, 2); 
    lcd.print("ON  ");
   }
  else if(EEPROM.read(11)==0)
   {
    digitalWrite(R1,LOW);
    lcd.setCursor(0, 2); 
    lcd.print("OFF ");
   }

   if(EEPROM.read(12)==1)
   {
    digitalWrite(R2,HIGH);
    lcd.setCursor(4, 2); 
    lcd.print("ON  ");
   }
  else if(EEPROM.read(12)==0)
   {
    digitalWrite(R2,LOW);
    lcd.setCursor(4, 2); 
    lcd.print("OFF ");
   }

   if(EEPROM.read(13)==1)
   {
    digitalWrite(R3,HIGH);
    lcd.setCursor(8, 2); 
    lcd.print("ON  ");
   }
  else if(EEPROM.read(13)==0)
   {
    digitalWrite(R3,LOW);
    lcd.setCursor(8, 2); 
    lcd.print("OFF ");
   }

   if(EEPROM.read(14)==1)
   {
    digitalWrite(R4,HIGH);
    lcd.setCursor(12, 2); 
    lcd.print("ON  ");
   }
  else if(EEPROM.read(14)==0)
   {
    digitalWrite(R4,LOW);
    lcd.setCursor(12, 2); 
    lcd.print("OFF ");
   }

   
   
   
}
void save_data()
{
//______________________save eeprom___________________________________________

   if(pieces[0]=="on" ||pieces[0]=="ON" )
   {
    EEPROM.write(11,1);
   }
  else if(pieces[0]=="off" ||pieces[0]=="OFF" )
   {
    EEPROM.write(11,0);
   }


   if(pieces[1]=="on" ||pieces[1]=="ON" )
   {
    EEPROM.write(12,1);
   }
  else if(pieces[1]=="off" ||pieces[1]=="OFF" )
   {
    EEPROM.write(12,0);
   }


   if(pieces[2]=="on" ||pieces[2]=="ON" )
   {
    EEPROM.write(13,1);
   }
  else if(pieces[2]=="off" ||pieces[2]=="OFF" )
   {
    EEPROM.write(13,0);
   }


   if(pieces[3]=="on" ||pieces[3]=="ON" )
   {
    EEPROM.write(14,1);
   }
  else if(pieces[3]=="off" ||pieces[3]=="OFF" )
   {
    EEPROM.write(14,0);
   }

   
}

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("welcome to online");
  lcd.setCursor(0, 1); 
  lcd.print("home automation     ");
//Enable the Onboard LED to act as a Status indicator light
pinMode(led,OUTPUT);
pinMode(R1,OUTPUT);
pinMode(R2,OUTPUT);
pinMode(R3,OUTPUT);
pinMode(R4,OUTPUT);
//Set the speed for communicating with the ESP8266 module
Serial.begin(115200);
//Send a series of flashes to show us we are in the bootup phase.
blinkcode ();
Serial.println("AT");
//Reset the ESP8266
//Serial.println("AT+RST");
//Wait for the WiFi module to bootup
//delay(800);
//Switch the chip to "client" mode
//Serial.println("AT+CWMODE=1");
//Connect to our Wireless network NOTE: change SSID to your wireless
//network and PASSWORD to the key used to join the network.
//Serial.println("AT+CWJAP=\"SSID\",\"PASSWORD\"");
//Once again blink some lights because it is fun!
blinkcode ();
  
}

void loop()
{
  lcd.setCursor(0, 0); 
  lcd.print("R1  R2  R3  R4  ");
 
  


  //____________________________________________________________________________________
  digitalWrite(led,LOW);
  Serial.println("AT");
  delay(300);
//  Serial.println("AT+RST");
//  delay(4000);
//  Serial.println("AT");
//  delay(1000);
  Serial.println("AT");
  delay(500);
  Serial.println("AT+CIPMUX=1");
  delay(1000);
  
//Open a connection to the web server
String cmd = "AT+CIPSTART=0,\"TCP\",\""; //make this command: AT+CPISTART="TCP","192.168.88.35",80
cmd += DST_IP;
cmd += "\",80\r\n";
Serial.println(cmd);

//wait a little while for 'Linked'
delay(2000);
Serial.println("AT+CIPSTART=?");
delay(800);



//This is our HTTP GET Request change to the page and server you want to load.
String cmd2  = "GET /message.html HTTP/1.0\r\n";
       cmd2 += "Host: iotprojects.000webhostapp.com\r\n\r\n";
//      cmd2 += "Connection: keep-alive\r\n";
//       cmd2 += "Accept: */*\r\n";
String url =" GET / HTTP/1.0Host: myprojectshub.comConnection: keep-aliveAccept: */*\r\n";
//The ESP8266 needs to know the size of the GET request
Serial.print("AT+CIPSEND=0,");
Serial.println((cmd2.length()));
//Serial.println("99");

//Look for the > prompt from the esp8266
if(Serial.find(">"))
{
//Send our http GET request
Serial.println(cmd2);
}
else
{
//Something didn't work...
Serial.println("AT+CIPCLOSE");
}

//Check the returned header & web page. Looking for a keyword. I used YES12321

if (Serial.find("IOT"))
{

//light to show the server is ONLINE
   lcd.setCursor(0, 0);
  //  lcd.print("done it        ");
     digitalWrite(led,HIGH);
      if(Serial.available() > 0)
      {
//         lcd.clear(); // C LEARC DISPLAY IN CASE OF MESSAGE DISPLAY
         str = Serial.readStringUntil('*');

         
         for(i=0;i<str.length();i++)
         { 
           if (str.substring(i, i+1) == ",")
           {
              pieces[counter] = str.substring(lastIndex, i);
              lastIndex = i + 1;
              counter++;
           }
         }

         if (i == str.length() - 1) 
         {          
            pieces[counter] = str.substring(lastIndex, i);
         }



         for(i=0;i<4;i++)
         {   
  //          lcd.setCursor(0, i);      
  //          lcd.print(pieces[i]);           
         }

          counter = 0;
          lastIndex = 0;
                
        // lcd.setCursor(0, 0);
        // lcd.print(str);
      }
        
  
     
}
else
{
//If the string was not found then we can assume the server is offline therefore
//we should turn of t he light.
digitalWrite(led,LOW);
 
  lcd.clear();
  lcd.print("could not get     ");
  lcd.setCursor(0,1);
  lcd.print(" server data   ");
}
save_data();
relay_action();
//Wait a second for everything to settle.
delay(5000);
delay(5000);
//Be great people and close our connection.
Serial.println("AT+CIPCLOSE");

//Introduce a delay timer before we finish and go back to the begining.
delay (500);
//delay (5000);
}
//**********************************************************************************
void blinkcode ()
{
//Simply loop a few times flashing the status light (this is used during boot up)
int i;
for (i = 1; i <= 10; i++){
delay (100);
digitalWrite(led,HIGH);
delay (100);
digitalWrite(led,LOW);
}
}





