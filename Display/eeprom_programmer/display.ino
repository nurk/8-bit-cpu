void writeDisplay() {
  byte digits[] = { 0x7e, 0x30, 0x6d, 0x79, 0x33, 0x5b, 0x5f, 0x70, 0x7f, 0x7b };

  Serial.println("Programming ones place");
  for (int value = 0; value < 256; value++) {
    writeByte(value, digits[value % 10]);
  }

  Serial.println("Programming tens place");
  for (int value = 0; value < 256; value++) {
    writeByte(value + 256, digits[(value / 10) % 10]);
  }

  Serial.println("Programming hundreds place");
  for (int value = 0; value < 256; value++) {
    writeByte(value + 512, digits[(value / 100) % 10]);
  }

  Serial.println("Programming 00 to thousands place");
  for (int value = 0; value < 256; value++) {
    writeByte(value + 768, 0x00);
  }


  Serial.println("Programming ones place (twos complement)");
  for (int value = -128; value < 128; value++) {
    writeByte((byte)value + 1024, digits[abs(value) % 10]);
  }

  Serial.println("Programming tens place (twos complement)");
  for (int value = -128; value < 128; value++) {
    writeByte((byte)value + 1280, digits[abs(value / 10) % 10]);
  }
  Serial.println("Programming hundreds place (twos complement)");
  for (int value = -128; value < 128; value++) {
    writeByte((byte)value + 1536, digits[abs(value / 100) % 10]);
  }
  Serial.println("Programming sign (twos complement)");
  for (int value = -128; value < 128; value++) {
    if (value < 0) {
      writeByte((byte)value + 1792, 0x01);
    } else {
      writeByte((byte)value + 1792, 0);
    }
  }

  Serial.println("Writing display done");
}