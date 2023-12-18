void writeInstruction(byte instruction) {
  write(instructionCounter, instruction);
  instructionCounter++;
}

void writeInstruction(byte instruction, byte operand) {
  write(instructionCounter, instruction);
  instructionCounter++;
  write(instructionCounter, operand);
  instructionCounter++;
}

void writeData(byte data) {
  write(dataOffset + dataCounter, data);
  dataCounter++;
}

void write(byte address, byte data) {
  writeAddressLines(address);
  writeDataLines(data);

  digitalWrite(WRITE_PIN, HIGH);
  delay(10);
  digitalWrite(WRITE_PIN, LOW);

  for (int i = 0; i < 9; i++) {
    digitalWrite(ADDRESS_PINS[i], LOW);
  }

  digitalWrite(A7, LOW);
  digitalWrite(A6, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A0, LOW);
}

void writeAddressLines(byte address) {
  for (int i = 0; i <= 8; i++) {
    digitalWrite(ADDRESS_PINS[i], address & 1);
    address = address >> 1;
  }
}

void writeDataLines(byte data) {
  digitalWrite(A7, data & 1);
  data = data >> 1;
  digitalWrite(A6, data & 1);
  data = data >> 1;
  digitalWrite(A5, data & 1);
  data = data >> 1;
  digitalWrite(A4, data & 1);
  data = data >> 1;
  digitalWrite(A3, data & 1);
  data = data >> 1;
  digitalWrite(A2, data & 1);
  data = data >> 1;
  digitalWrite(A1, data & 1);
  data = data >> 1;
  digitalWrite(A0, data & 1);
}