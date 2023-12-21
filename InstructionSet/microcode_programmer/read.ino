byte readByte(int address) {
  digitalWrite(WRITE_EN, HIGH);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin++) {
    pinMode(pin, INPUT_PULLUP);
  }
  setAddress(address);
  digitalWrite(OUTPUT_EN, LOW);
  delay(1);

  byte data = 0;
  for (int pin = EEPROM_D7; pin >= EEPROM_D0; pin--) {
    data = (data << 1) + digitalRead(pin);
  }
  digitalWrite(OUTPUT_EN, HIGH);
  return data;
}

void readEEPROM(int upTo) {
  for (int base = 0; base < upTo; base += 16) {
    byte data[16];
    for (int offset = 0; offset < 16; offset++) {
      data[offset] = readByte(base + offset);
    }

    char buf[80];
    sprintf(buf, "%04x:  %02x %02x %02x %02x %02x %02x %02x %02x   %02x %02x %02x %02x %02x %02x %02x %02x",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);

    Serial.println(buf);
  }
  available = true;
}