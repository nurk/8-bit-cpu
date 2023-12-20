void test() {
  instructionCounter = 0;
  dataCounter = 0;

  // writeInstruction(LDA, dataOffset);
  // writeData(0b10100101);
  // writeInstruction(OUT);

  //writeInstruction(LDIB, 5);
  writeInstruction(LDI, 5);
  writeInstruction(OUT);
  writeInstruction(LDIB, 7);
  writeInstruction(STA, dataOffset);
  writeInstruction(LDB, dataOffset);
  writeInstruction(HLT);

  Serial.print("Instruction counter at ");
  Serial.println(instructionCounter);
  Serial.print("Data counter at ");
  Serial.println(dataCounter);
  Serial.println("Done writing test");
}