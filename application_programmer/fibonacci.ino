        // int x = 0;
        // int y = 0;
        // int z = 1;
        
        // while (x < 300) {
        //     System.out.println(x);
        //     x = z + y;
        //     z = y;
        //     y = x;
        // }

int x = dataOffset;
int y = dataOffset + 1;
int z = dataOffset + 2;

void fibonacci() {
  instructionCounter = 0;
  dataCounter = 0;

  // init;
  writeInstruction(LDI, 0);
  writeInstruction(OUT);
  writeInstruction(STA, x);
  writeInstruction(STA, y);
  writeInstruction(LDI, 1);
  writeInstruction(STA, z);

  Serial.print("Loop starts at ");
  Serial.println(instructionCounter);
  //loop
  writeInstruction(LDA, z);
  writeInstruction(ADD, y);
  writeInstruction(JC, 0);
  writeInstruction(OUT);
  writeInstruction(STA, x);
  writeInstruction(LDA, y);
  writeInstruction(STA, z);
  writeInstruction(LDA, x);
  writeInstruction(STA, y);
  writeInstruction(JMP, 11);

  Serial.print("Instruction counter at ");
  Serial.println(instructionCounter);
  Serial.print("Data counter at ");
  Serial.println(dataCounter);
  Serial.println("Done writing fibonacci");
}