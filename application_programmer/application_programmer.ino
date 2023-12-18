#define NOP 0b00000000
#define LDA 0b00000001
#define ADD 0b00000010
#define SUB 0b00000011
#define STA 0b00000100
#define LDI 0b00000101
#define JMP 0b00000110
#define JC 0b00000111
#define JZ 0b00001000
#define LDB 0b00001001
#define STB 0b00001010
#define LDIB 0b00001011
#define OUT 0b00001100
#define OUTB 0b00001101
#define OUTX 0b00001110
#define HLT 0b00001111
#define LDX 0b00010000
#define STX 0b00010001
#define LDIX 0b00010010
#define PSH 0b00010110
#define POP 0b00010100
#define PSHB 0b00010101
#define POPB 0b00010110
#define JSR 0b00010111
#define RTS 0b00011000
#define INCX 0b00011001
#define DECX 0b00011010

const int ADDRESS_PINS[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };  // D2, D3, D4, D5, D6, D7, D8, D9
#define WRITE_PIN 10                                     // D10

int instructionCounter = 0;
int dataCounter = 0;
const int dataOffset = 128;

void setup() {
  Serial.begin(115200);

  pinMode(WRITE_PIN, OUTPUT);
  digitalWrite(WRITE_PIN, LOW);
  for (int i = 0; i < 9; i++) {
    pinMode(ADDRESS_PINS[i], OUTPUT);
    digitalWrite(ADDRESS_PINS[i], LOW);
  }

  pinMode(A7, OUTPUT);
  digitalWrite(A7, LOW);
  pinMode(A6, OUTPUT);
  digitalWrite(A6, LOW);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, LOW);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
}

void loop() {
  readSerial();
}
