#ifndef EEPROM28C_H
#define EEPROM28C_H
#include "Arduino.h"

const int DATA0 = 2;
const int DATA1 = 3;
const int DATA2 = 4;
const int DATA3 = 5;
const int DATA4 = 6;
const int DATA5 = 7;
const int DATA6 = 8;
const int DATA7 = 9;
const int ADDR0EN = 14; // enable address from 0->7
const int ADDR1EN = 15; // enable address from 8->15
const int EEPROM_WRITE = 16;
const unsigned int ROMSIZE = (8*1024); // bytes

void on(int pin);
void off(int pin);

void writeData(unsigned int data, unsigned int addr);

#endif
