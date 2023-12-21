void writeByte(int address, byte data) {
  digitalWrite(OUTPUT_EN, HIGH);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    pinMode(pin, OUTPUT);
  }
  if (DEBUG) {
    Serial.print("Address ");
    Serial.print(address, BIN);
    Serial.print(" ");
    Serial.print(address, HEX);
    Serial.print(" | Data: ");
    Serial.print(data, BIN);
    Serial.print(" ");
    Serial.println(data, HEX);
  }
  delay(1);
  setAddress(address);
  delay(1);

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(10);
  digitalWrite(WRITE_EN, HIGH);
  // delay of 5 did not give correct data.  Every other byte seemed to have been skipped
  delay(10);
}

void eraseEEPROM(int upTo) {
  DEBUG = false;
  for (int i = 0; i < upTo; i++) {
    if (i % 128 == 0) {
      Serial.print(".");
    }
    writeByte(i, 0x00);
  }
  Serial.println();
  Serial.println("Done erasing");
  DEBUG = false;
  available = true;
}