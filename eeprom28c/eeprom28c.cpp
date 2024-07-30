#include "Arduino.h"
#include "eeprom28c.h"
void on(int pin){
  digitalWrite(pin, HIGH);
};
void off(int pin){
  digitalWrite(pin, LOW);
};

void writeData(unsigned int data,unsigned int addr){
  off(ADDR0EN);
  off(ADDR1EN);
  digitalWrite(EEPROM_WRITE, 1);
  delay(100);
  digitalWrite(DATA0, bitRead(addr, 0));
  digitalWrite(DATA1, bitRead(addr, 1));
  digitalWrite(DATA2, bitRead(addr, 2));
  digitalWrite(DATA3, bitRead(addr, 3));
  digitalWrite(DATA4, bitRead(addr, 4));
  digitalWrite(DATA5, bitRead(addr, 5));
  digitalWrite(DATA6, bitRead(addr, 6));
  digitalWrite(DATA7, bitRead(addr, 7));
  delay(100);
  on(ADDR0EN); // load
  delay(100);
  off(ADDR0EN);
  delay(100);
  digitalWrite(DATA0, bitRead(addr, 8));
  digitalWrite(DATA1, bitRead(addr, 9));
  digitalWrite(DATA2, bitRead(addr, 10));
  digitalWrite(DATA3, bitRead(addr, 11));
  digitalWrite(DATA4, bitRead(addr, 12));
  digitalWrite(DATA5, bitRead(addr, 13));
  digitalWrite(DATA6, bitRead(addr, 14));
  digitalWrite(DATA7, bitRead(addr, 15));
  delay(100);
  on(ADDR1EN); // load
  delay(100);
  off(ADDR1EN);
  delay(100);
  digitalWrite(DATA0, bitRead(data, 0));
  digitalWrite(DATA1, bitRead(data, 1));
  digitalWrite(DATA2, bitRead(data, 2));
  digitalWrite(DATA3, bitRead(data, 3));
  digitalWrite(DATA4, bitRead(data, 4));
  digitalWrite(DATA5, bitRead(data, 5));
  digitalWrite(DATA6, bitRead(data, 6));
  digitalWrite(DATA7, bitRead(data, 7));
  delay(100);
  digitalWrite(EEPROM_WRITE, 0);
  delay(100);
};

