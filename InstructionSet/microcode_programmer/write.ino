void writeByte(uint32_t address, uint32_t data) {
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
  delayMicroseconds(5);
  digitalWrite(WRITE_EN, HIGH);
  // delay of 5 did not give correct data.  Every other byte seemed to have been skipped
  delay(11);
}

void eraseEEPROM(int upTo) {
  for (int i = 0; i < upTo; i++) {
    if(i % 128 == 0) {
      Serial.print(".");
    }
    writeByte(i, 0x0);
  }
  Serial.println();
  Serial.println("Done erasing");
}