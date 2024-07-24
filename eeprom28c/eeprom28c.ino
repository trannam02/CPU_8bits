// TRAN XUAN NAM
#include "eeprom28c.h"

void setup() {            
  pinMode(DATA0, OUTPUT);
  pinMode(DATA1, OUTPUT);
  pinMode(DATA2, OUTPUT);
  pinMode(DATA3, OUTPUT);
  pinMode(DATA4, OUTPUT);
  pinMode(DATA5, OUTPUT);
  pinMode(DATA6, OUTPUT);
  pinMode(DATA7, OUTPUT);
  pinMode(ADDR0EN, OUTPUT);
  pinMode(ADDR1EN, OUTPUT);
  pinMode(EEPROM_WRITE, OUTPUT);
}
void loop() {
  byte data = 0b00001111;
  int addr = 0b1111111101010101;
  writeData(data, addr);
  delay(10000);
}
