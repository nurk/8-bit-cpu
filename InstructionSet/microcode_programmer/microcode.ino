// left
uint32_t CE   = 0b100000000000000000000000;    // Program counter enable
uint32_t RI   = 0b010000000000000000000000;    // RAM data in
uint32_t RaI  = 0b001000000000000000000000;   // RAM address in
uint32_t RO   = 0b000100000000000000000000;    // RAM data out
uint32_t II   = 0b000010000000000000000000;    // Instruction register in
uint32_t J    = 0b000001000000000000000000;     // Jump (program counter in)
uint32_t CO   = 0b000000100000000000000000;    // Program counter out
uint32_t AI   = 0b000000010000000000000000;    // A register in

// middle
uint32_t S    = 0b000000001000000000000000;     // ALU subtract
uint32_t HALT = 0b000000000100000000000000;  // Halt
uint32_t AO   = 0b000000000010000000000000;    // A register out
uint32_t AlO  = 0b000000000001000000000000;   // ALU out
uint32_t BI   = 0b000000000000100000000000;    // B register in
uint32_t BO   = 0b000000000000010000000000;    // B register out
uint32_t OI   = 0b000000000000001000000000;    // Output
uint32_t FI   = 0b000000000000000100000000;    // Flags in

// right
uint32_t INC  = 0b000000000000000010000000;   // Increment X
uint32_t DCR  = 0b000000000000000001000000;   // Decrement X
uint32_t SUP  = 0b000000000000000000100000;   // Stack up
uint32_t SDN  = 0b000000000000000000010000;   // Stack down
uint32_t SA   = 0b000000000000000000001000;    // Stack address
uint32_t SO   = 0b000000000000000000000100;    // Stack output
uint32_t XI   = 0b000000000000000000000010;    // X register in
uint32_t XO   = 0b000000000000000000000001;    // X register out

uint32_t NOP[8] = { RaI | CO, RO | II | CE, 0, 0, 0, 0, 0, 0 };
uint32_t NOP_ADDRESS = 0b000000000;  // 000000
uint32_t LDA[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RO | AI, 0, 0, 0 };
uint32_t LDA_ADDRESS = 0b000001000;  // 000001
uint32_t ADD[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RO | BI, AI | AlO | FI, 0, 0 };
uint32_t ADD_ADDRESS = 0b000010000;  // 000010
uint32_t SUB[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RO | BI, AI | AlO | S | FI, 0, 0 };
uint32_t SUB_ADDRESS = 0b000011000;  // 000011
uint32_t STA[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RI | AO, 0, 0, 0 };
uint32_t STA_ADDRESS = 0b000100000;  // 000100
uint32_t LDI[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RO | AI, 0, 0, 0, 0 };
uint32_t LDI_ADDRESS = 0b000101000;  // 000101
uint32_t JMP[8] = { RaI | CO, RO | II | CE, CO | RaI, RO | J, 0, 0, 0, 0 };
uint32_t JMP_ADDRESS = 0b000110000;  // 000110
uint32_t JC[8] = { RaI | CO, RO | II | CE, CO | RaI, CE, 0, 0, 0, 0 };
uint32_t JC_ADDRESS = 0b000111000;  // 000111
uint32_t JZ[8] = { RaI | CO, RO | II | CE, CO | RaI, CE, 0, 0, 0, 0 };
uint32_t JZ_ADDRESS = 0b001000000;  // 001000
uint32_t LDB[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RO | BI, 0, 0, 0 };
uint32_t LDB_ADDRESS = 0b001001000;  // 001001
uint32_t STB[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RI | BO, 0, 0, 0 };
uint32_t STB_ADDRESS = 0b001010000;  // 001010
uint32_t LDIB[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RO | BI, 0, 0, 0, 0 };
uint32_t LDIB_ADDRESS = 0b001011000;  // 001011
uint32_t OUT[8] = { RaI | CO, RO | II | CE, AO | OI, 0, 0, 0, 0, 0 };
uint32_t OUT_ADDRESS = 0b001100000;  // 001100
uint32_t OUTB[8] = { RaI | CO, RO | II | CE, BO | OI, 0, 0, 0, 0, 0 };
uint32_t OUTB_ADDRESS = 0b001101000;  // 001101
uint32_t OUTX[8] = { RaI | CO, RO | II | CE, XO | OI, 0, 0, 0, 0, 0 };
uint32_t OUTX_ADDRESS = 0b001110000;  // 001110
uint32_t HLT[8] = { RaI | CO, RO | II | CE, HALT, 0, 0, 0, 0, 0 };
uint32_t HLT_ADDRESS = 0b001111000;  // 001111
uint32_t LDX[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RO | XI, 0, 0, 0 };
uint32_t LDX_ADDRESS = 0b010000000;  // 010000
uint32_t STX[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RaI | RO, RI | XO, 0, 0, 0 };
uint32_t STX_ADDRESS = 0b010001000;  // 010001
uint32_t LDIX[8] = { RaI | CO, RO | II | CE, CO | RaI, CE | RO | XI, 0, 0, 0, 0 };
uint32_t LDIX_ADDRESS = 0b010010000;  // 010010
uint32_t PSH[8] = { RaI | CO, RO | II | CE, RaI | SA | SO, RI | AO | SUP | SA, 0, 0, 0, 0 };
uint32_t PSH_ADDRESS = 0b010110000;  // 010011
uint32_t POP[8] = { RaI | CO, RO | II | CE, SDN, RaI | SA | SO, RO | AI | SA, 0, 0, 0 };
uint32_t POP_ADDRESS = 0b010100000;  // 010100
uint32_t PSHB[8] = { RaI | CO, RO | II | CE, RaI | SA | SO, RI | BO | SUP | SA, 0, 0, 0, 0 };
uint32_t PSHB_ADDRESS = 0b010101000;  // 010101
uint32_t POPB[8] = { RaI | CO, RO | II | CE, SDN, RaI | SA | SO, RO | BI | SA, 0, 0, 0 };
uint32_t POPB_ADDRESS = 0b010110000;  // 010110
uint32_t JSR[8] = { RaI | CO, RO | II | CE, RaI | SA | SO, RI | CO | SUP | SA, RaI | CO, RO | J, 0, 0 };
uint32_t JSR_ADDRESS = 0b010111000;  // 010111
uint32_t RTS[8] = { RaI | CO, RO | II | CE, SDN, RaI | SA | SO, RO | J, CE, 0, 0 };
uint32_t RTS_ADDRESS = 0b011000000;  // 011000
uint32_t INCX[8] = { RaI | CO, RO | II | CE, INC, FI, 0, 0, 0, 0 };
uint32_t INCX_ADDRESS = 0b011001000;  // 011001
uint32_t DECX[8] = { RaI | CO, RO | II | CE, DCR, FI, 0, 0, 0, 0 };
uint32_t DECX_ADDRESS = 0b011010000;  // 011010

uint32_t FLAGS_Z0C0 = 0b00000000000;
uint32_t FLAGS_Z0C1 = 0b01000000000;
uint32_t FLAGS_Z1C0 = 0b10000000000;
uint32_t FLAGS_Z1C1 = 0b11000000000;
uint32_t FLAGS[4] = { FLAGS_Z0C0, FLAGS_Z0C1, FLAGS_Z1C0, FLAGS_Z1C1 };

uint32_t LEFT = 0b0000000000000;
uint32_t MIDDLE = 0b1000000000000;
uint32_t RIGHT = 0b0100000000000;


void test() {
  DEBUG = true;
  Serial.println(RI|AO, BIN);
  writeInstructions(STA_ADDRESS, STA);
  //Serial.println("Written OUT");
  //writeInstruction(OUT_ADDRESS, OUT[2], 2, FLAGS_Z0C0);
  DEBUG = false;
  available = true;
}
void writeEeprom() {
  writeInstructions(NOP_ADDRESS, NOP);
  Serial.println("Written NOP");
  writeInstructions(LDA_ADDRESS, LDA);
  Serial.println("Written LDA");
  writeInstructions(ADD_ADDRESS, ADD);
  Serial.println("Written ADD");
  writeInstructions(SUB_ADDRESS, SUB);
  Serial.println("Written SUB");
  writeInstructions(STA_ADDRESS, STA);
  Serial.println("Written STA");
  writeInstructions(LDI_ADDRESS, LDI);
  Serial.println("Written LDI");
  writeInstructions(JMP_ADDRESS, JMP);
  Serial.println("Written JMP");
  writeInstructions(JC_ADDRESS, JC);
  Serial.println("Written JC");
  writeInstructions(JZ_ADDRESS, JZ);
  Serial.println("Written JZ");
  writeInstructions(LDB_ADDRESS, LDB);
  Serial.println("Written LDB");
  writeInstructions(STB_ADDRESS, STB);
  Serial.println("Written STB");
  writeInstructions(LDIB_ADDRESS, LDIB);
  Serial.println("Written LDIB");
  writeInstructions(OUT_ADDRESS, OUT);
  Serial.println("Written OUT");
  writeInstructions(OUTB_ADDRESS, OUTB);
  Serial.println("Written OUTB");
  writeInstructions(OUTX_ADDRESS, OUTX);
  Serial.println("Written OUTX");
  writeInstructions(HLT_ADDRESS, HLT);
  Serial.println("Written HLT");
  writeInstructions(LDX_ADDRESS, LDX);
  Serial.println("Written LDX");
  writeInstructions(STX_ADDRESS, STX);
  Serial.println("Written STX");
  writeInstructions(LDIX_ADDRESS, LDIX);
  Serial.println("Written LDIX");
  writeInstructions(PSH_ADDRESS, PSH);
  Serial.println("Written PSH");
  writeInstructions(POP_ADDRESS, POP);
  Serial.println("Written POP");
  writeInstructions(PSHB_ADDRESS, PSHB);
  Serial.println("Written PSHB");
  writeInstructions(POPB_ADDRESS, POPB);
  Serial.println("Written POPB");
  writeInstructions(JSR_ADDRESS, JSR);
  Serial.println("Written JSR");
  writeInstructions(RTS_ADDRESS, RTS);
  Serial.println("Written RTS");
  writeInstructions(INCX_ADDRESS, INCX);
  Serial.println("Written INCX");
  writeInstructions(DECX_ADDRESS, DECX);
  Serial.println("Written DECX");

  writeInstruction(JC_ADDRESS, RO | J, 3, FLAGS_Z0C1);
  writeInstruction(JZ_ADDRESS, RO | J, 3, FLAGS_Z1C0);
  writeInstruction(JC_ADDRESS, RO | J, 3, FLAGS_Z1C1);
  writeInstruction(JZ_ADDRESS, RO | J, 3, FLAGS_Z1C1);
  Serial.println("Written Special flags");

  Serial.println("Writing done");
  available = true;
}
void writeInstructions(uint32_t address, uint32_t instructions[8]) {
  for (int step = 0; step < 8; step++) {
    for (int flag = 0; flag < 4; flag++) {
      writeToEeproms(FLAGS[flag] | address | step, instructions[step]);
    }
  }
}

void writeInstruction(uint32_t address, uint32_t instruction, int step, uint32_t flag) {
  writeToEeproms(flag | address | step, instruction);
}

void writeToEeproms(uint32_t address, uint32_t instruction) {
  byte right = instruction;
  byte middle = instruction >> 8;
  byte left = instruction >> 16;

  if (DEBUG) {
    Serial.println(instruction, BIN);
  }

  writeByte(LEFT | address, left);
  writeByte(MIDDLE | address, middle);
  writeByte(RIGHT | address, right);
}