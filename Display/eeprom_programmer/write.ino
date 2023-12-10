void writeByte(int address, byte data) {
  digitalWrite(OUTPUT_EN, HIGH);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    pinMode(pin, OUTPUT);
  }

  setAddress(address);

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(WRITE_EN, HIGH);
  // delay of 5 did not give correct data.  Every other byte seemed to have been skipped
  delay(10);
}

void eraseEEPROM(int upTo) {
  for (int i = 0; i < upTo; i++) {
    writeByte(i, 0xff);
  }
  Serial.println("Done erasing");
}