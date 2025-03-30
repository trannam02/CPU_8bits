# BREADBOARD CPU 8 BITS
CPU can run some basic function like load, add, and, or, shift
## Preview
![CPU Gif](./assets/cpu.gif)
## Some IC use in this project
| IC Name  | Function |
| ------------- | ------------- |
| EEPROM AT28C64B  | Static RAM |
| NE555P  | Pulse Generater  |
| 74LS04N | Hex Inverter |
| 74LS08 | Quad And Gate
| 74LS193 | Up/Down Counter |
| 74HC541 | Non-Invert Buffer |
| 74HC138 | Demutiflexer |
| 74HC151 | 8 bits Mutiflexer |
| 74HC574 | 8 bits D-FF |
| 74LS83 | 4 bits Adder |
## How to run assembler
Write assembly code in `code.asm` file. Run `main.cpp` to compile this code to binary code.
## How to flash code to EEPROM28C
Open binary file and flash to EEPROM28C use Arduino
