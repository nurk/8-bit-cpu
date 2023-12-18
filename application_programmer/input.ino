String serialInput = "";

void readSerial() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();

    serialInput += incomingByte;
  }

  if (serialInput.length() > 0 && serialInput.indexOf("\n") == serialInput.length() - 1) {
    if (serialInput.indexOf("test") == 0) {
      Serial.println("Programming test");
      test();
    }
    if (serialInput.indexOf("fibonacci") == 0) {
      Serial.println("Programming fibonacci");
      fibonacci();
    }
    serialInput = "";
  }
}