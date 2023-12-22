void test() {
  resetCounters();

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

void countDownTest() {
  resetCounters();

  writeInstruction(LDI, 13);
  writeInstruction(OUT);
  writeInstruction(PSH);
  writeInstruction(LDI, 0);
  writeInstruction(OUT);
  writeInstruction(LDIX, 100);
  int decx = instructionCounter;
  writeInstruction(DECX);
  int jz = instructionCounter + 4;
  writeInstruction(JZ, jz);
  writeInstruction(JMP, decx);
  writeInstruction(POP);
  writeInstruction(OUT);
  writeInstruction(HLT);

  Serial.println("Done writing countdown");
}

void subtractTest() {
  resetCounters();

  writeInstruction(LDI, 13);
  writeInstruction(OUT);
  writeInstruction(SUB, dataOffset);
  writeInstruction(OUT);
  writeInstruction(HLT);

  writeData(3);

  Serial.println("Done writing subtract");
}

void subroutenTest() {
  resetCounters();

  ex(LDI, 13);
  ex(OUT);

  int jsr = instructionCounter + 6;
  ex(JSR, jsr);

  ex(LDI, 5);
  ex(OUT);
  ex(HLT);

  // subroutine
  ex(LDIX, 100);
  int decx = instructionCounter;
  ex(DECX);
  int jz = instructionCounter + 4;
  ex(JZ, jz);
  ex(JMP, decx);
  ex(RTS);
  // end subroutine

  Serial.println("Done writing subroutine");
}