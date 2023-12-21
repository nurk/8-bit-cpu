void countDownTest() {
  instructionCounter = 0;
  dataCounter = 0;
  writeInstruction(LDI, 13);
  writeInstruction(OUT);
  writeInstruction(PSH);
  writeInstruction(LDI, 0);
  writeInstruction(OUT);
  writeInstruction(LDIX, 10);
  int decx = instructionCounter;
  writeInstruction(DECX);
  int jz = instructionCounter + 4;
  writeInstruction(JZ, jz);
  writeInstruction(JMP, decx);
  writeInstruction(POP);
  writeInstruction(OUT);
  writeInstruction(HLT);
}