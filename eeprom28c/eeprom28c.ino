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
unsigned int data[100] = {0,1,2,4,8,16,32,64,128,255};
int size = 9;
unsigned int addr = 0;
void loop() {
  // byte data = 0b00001111;
  // int addr = 0b1111111101010101;
  if(addr == size) delay(1000000);
  writeData(data[addr], addr);
  addr = addr + 1;
  
  digitalWrite(13,1);
  delay(2000);
  digitalWrite(13,0);
  // unsigned int data = 2;
  // unsigned int addr = 2;
  // writeData(data, addr);
  
  // delay(100000);
}
