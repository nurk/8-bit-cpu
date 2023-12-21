#define DATA 2
#define CLOCK 3
#define LATCH 4
#define EEPROM_D0 5
#define EEPROM_D7 12
#define WRITE_EN 13
#define OUTPUT_EN A0

bool DEBUG = false;
bool available = true;

void setup() {
  Serial.begin(57600);
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(WRITE_EN, OUTPUT);
  pinMode(OUTPUT_EN, OUTPUT);

  digitalWrite(WRITE_EN, HIGH);
  digitalWrite(OUTPUT_EN, LOW);
}

void loop() {
  readSerial();
}

void setAddress(int address) {
  shiftOut(DATA, CLOCK, MSBFIRST, address);
  shiftOut(DATA, CLOCK, MSBFIRST, (address >> 8));

  digitalWrite(LATCH, LOW);
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
}
