#include <SoftwareSerial.h>
SoftwareSerial SIM900(2,3); // gsm module connected here
String textForSMS;
//int smokeS = A1; // smoke / gas  sensor connected with analog pin A1 of the arduino / mega. 
//int data = 0; 
 

void setup() {


  //randomSeed(analogRead(0));
  
  Serial.begin(9600);
 SIM900.begin(9600); // for sim900D 19200. while enter 9600 for sim900A
 // pinMode(smokeS, INPUT); 
   
}

void loop() {

    int a=analogRead(A1);
    int b=map(a,0,1023,0,255);
    Serial.println(b);
    delay(100);

  //data = analogRead(smokeS); 
  
  //Serial.print("Smoke: "); 
  //Serial.println(data); 

  
     if ( b > 150) // 
  {
       textForSMS =  "\nGas Or Smoke Detected in rit boys hostel";  
  sendSMS(textForSMS);
  Serial.println(textForSMS);
  Serial.println("message sent."); 
delay(2000);
while(1)
{
  
}
  }
}


void sendSMS(String message)
{
  SIM900.print("AT+CMGF=1\r");                     // AT command to send SMS message
  delay(1000);
 SIM900.println("AT + CMGS = \"+917979040028\"");  // recipient's mobile number, in international format
 
  delay(1000);
  SIM900.println(message);                         // message to send
  delay(1000);
  SIM900.println((char)26);                        // End AT command with a ^Z, ASCII code 26
  delay(1000); 
  SIM900.println();
  delay(100);                                     // give module time to send SMS
 // SIM900power();                                   // turn off module
}
