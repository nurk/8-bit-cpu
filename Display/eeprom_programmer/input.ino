String serialInput = "";

void readSerial() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();

    serialInput += incomingByte;
  }

  if (serialInput.length() > 0 && serialInput.indexOf("\n") == serialInput.length() - 1) {
    if (serialInput.indexOf("readAll") == 0) {
      Serial.println("Reading all");
      readEEPROM(8192);
    }
    if (serialInput.indexOf("readDisplay") == 0) {
      Serial.println("Reading display");
      readEEPROM(2048);
    }
    if (serialInput.indexOf("writeDisplay") == 0) {
      Serial.println("Writing dispaly");
      writeDisplay();
    }
    if (serialInput.indexOf("eraseAll") == 0) {
      Serial.println("Erasing all");
      eraseEEPROM(8192);
    }
    if (serialInput.indexOf("eraseDisplay") == 0) {
      Serial.println("Erasing display");
      eraseEEPROM(2048);
    }
    serialInput = "";
  }
}