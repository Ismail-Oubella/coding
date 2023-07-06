#include <MFRC522.h>
#include <SPI.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

void setup() 
{
  Serial.begin(9600);
    SPI.begin();      // Initiate  SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  Serial.println("Approximate your Card to the Reader....");
}
void loop() 
{
  rfid1();
  
} 

void rfid1()
{
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
  String UID="";
  for (byte i=0;i<rfid.uid.size;i++) 
  {
     Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");// E8 07 C7 D2
     Serial.print(rfid.uid.uidByte[i], HEX);
     UID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ")); // 0E c2 12 
     UID.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  UID.toUpperCase();
  // E8 07 C7 D2
  if (UID.substring(1) == "69 A1 8E 9D") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Ismail");
    Serial.println("Authorized access");
  }
  else
  {
    Serial.println(" Access denied");
  }
  
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  
}
}
