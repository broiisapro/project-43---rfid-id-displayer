#include <SPI.h>
#include <MFRC522.h>

// RFID reader pins
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);  
  // Initialize SPI
  SPI.begin();
  // Initialize MFRC522 RFID reader
  mfrc522.PCD_Init();
  Serial.println("Scan your RFID card.");
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {

    if (mfrc522.PICC_ReadCardSerial()) {
      
      String cardID = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        cardID += String(mfrc522.uid.uidByte[i], HEX);
      }

      // Output only the Card ID
      Serial.println(cardID);

      mfrc522.PICC_HaltA(); 
    }
  }
}
