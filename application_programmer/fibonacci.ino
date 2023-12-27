// int x = 0;
// int y = 0;
// int z = 1;

// while (x < 300) {
//     System.out.println(x);
//     x = z + y;
//     z = y;
//     y = x;
// }

void fibonacci() {
  resetCounters();

  int x = dataOffset;
  int y = dataOffset + 1;
  int z = dataOffset + 2;

  // init;
  writeInstruction(LDI, 0);
  writeInstruction(OUT);
  writeInstruction(STA, x);
  writeInstruction(STA, y);
  writeInstruction(LDI, 1);
  writeInstruction(STA, z);

  int loop = instructionCounter;
  //loop;
  writeInstruction(LDA, z);
  writeInstruction(ADD, y);
  writeInstruction(JC, 0);
  writeInstruction(OUT);
  writeInstruction(STA, x);
  writeInstruction(LDA, y);
  writeInstruction(STA, z);
  writeInstruction(LDA, x);
  writeInstruction(STA, y);
  writeInstruction(JMP, loop);

  Serial.print("Instruction counter at ");
  Serial.println(instructionCounter);
  Serial.print("Data counter at ");
  Serial.println(dataCounter);
  Serial.println("Done writing fibonacci");
}

// int x = 0;
// int y = 0;
// int z = 1;

// while (x < 300) {
//     System.out.println(x);
//     x = z + y;
//     z = y;
//     y = x;
// }

void fibonacciInstructionCounter() {
  resetCounters();

  int x = dataOffset;
  int y = dataOffset + 1;
  int z = dataOffset + 2;

  // init;
  writeInstruction(LDI, 1);
  writeInstruction(PSH);
  writeInstruction(LDI, 0);
  writeInstruction(PSH);
  writeInstruction(OUTX);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(NOP);
  writeInstruction(LDIX, 0);
  writeInstruction(POP);
  writeInstruction(INCX);
  writeInstruction(OUT);
  writeInstruction(INCX);
  writeInstruction(STA, x);
  writeInstruction(INCX);
  writeInstruction(STA, y);
  writeInstruction(INCX);
  writeInstruction(POP);
  writeInstruction(INCX);
  writeInstruction(STA, z);

  int loop = instructionCounter;
  //loop;
  writeInstruction(INCX);
  writeInstruction(LDA, z);
  writeInstruction(INCX);
  writeInstruction(ADD, y);
  writeInstruction(JC, 0);
  writeInstruction(INCX);
  writeInstruction(INCX);
  writeInstruction(OUT);
  writeInstruction(INCX);
  writeInstruction(STA, x);
  writeInstruction(INCX);
  writeInstruction(LDA, y);
  writeInstruction(INCX);
  writeInstruction(STA, z);
  writeInstruction(INCX);
  writeInstruction(LDA, x);
  writeInstruction(INCX);
  writeInstruction(STA, y);
  writeInstruction(INCX);
  writeInstruction(JMP, loop);

  Serial.print("Instruction counter at ");
  Serial.println(instructionCounter);
  Serial.print("Data counter at ");
  Serial.println(dataCounter);
  Serial.println("Done writing fibonacci");
}