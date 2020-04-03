/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA: Pin 10
* RST: Pin 9
*/
/*
 * for LCD interfacing use myLCD.h file
 */
#include "myLCD.h"
#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

void setup(){
    lcd.begin(16,2);
    SPI.begin();
//    rfid.init(); 
    lcd.print("Rfid Card Reader" );
    delay(2000);
    Serial.begin(9600);
}
RFIDTag tag;
void loop(){
   if (rfid.available()){
     tag = rfid.getTag(); 
     lcd.setCursor(0,1);
        Serial.print("FC      : ");  // and prints that info on the serial port
        Serial.println(tag.mfr, HEX);
        Serial.print("CC      : ");
        Serial.println(tag.id, HEX);
        lcd.print(tag.id, HEX);
        Serial.print("CHECKSUM: ");
        Serial.println(tag.chk, HEX);
        Serial.print("RAW DATA: ");
        Serial.println(tag.raw);
        Serial.print("The ID is ");
        if (tag.valid) lcd.println("valid");
        else lcd.println("invalid");
   }
   
//    if(rfid.isCard()){
//    
//        if(rfid.readCardSerial()){
//            lcd.clear();
//            lcd.setCursor(0,0);
//            lcd.print("Rfid Card No - " );
//            lcd.setCursor(0,1);
//            lcd.print(rfid.serNum[0]);
//            lcd.print(" ");
//            lcd.print(rfid.serNum[1]);
//            lcd.print(" ");
//            lcd.print(rfid.serNum[2]);
//            lcd.print(" ");
//            lcd.print(rfid.serNum[3]);
//            lcd.print(" ");
//            lcd.print(rfid.serNum[4]);
//            lcd.println("");
//         }
//        
//    }
//  rfid.halt();
  
     
}
