String serialInput = "";

void readSerial() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();

    serialInput += incomingByte;
  }

  if (serialInput.length() > 0 && serialInput.indexOf("\n") == serialInput.length() - 1) {
    if (serialInput.indexOf("read") == 0) {
      Serial.println("Reading");
      readEEPROM(8192);
    }
    if (serialInput.indexOf("write") == 0) {
      Serial.println("Writing");
      writeEeprom();
    }
    if (serialInput.indexOf("erase") == 0) {
      Serial.println("Erasing all");
      eraseEEPROM(8192);
    }
    serialInput = "";
  }
}