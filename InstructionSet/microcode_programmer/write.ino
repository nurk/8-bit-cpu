void writeByte(uint32_t address, uint32_t data) {
  digitalWrite(OUTPUT_EN, HIGH);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    pinMode(pin, OUTPUT);
  }
  if (DEBUG) {
    Serial.print("Data: ");
    Serial.print(data, BIN);
    Serial.print(" ");
    Serial.println(data, HEX);
  }
  setAddress(address);

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  delay(1);
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(15);
  digitalWrite(WRITE_EN, HIGH);
  // delay of 5 did not give correct data.  Every other byte seemed to have been skipped
  delay(15);
}

void eraseEEPROM(int upTo) {
  for (int i = 0; i < upTo; i++) {
    if (i % 128 == 0) {
      Serial.print(".");
    }
    writeByte(i, 0);
  }
  Serial.println();
  Serial.println("Done erasing");
}