#ifndef CONTROL_H
#define CONTROL_H
#include "./../headers/utils.h"
using namespace std;

enum eControls
// 1A: 0-7
// 1B: 8-15
// 2A: 16-23
// 2B: 24-32
{
    Control_NOP = 0x00,

    /////////////////// 1A
    Control_Load_Const_Mem = 0x01<<7, // one bit

    Control_Select_ALUInputLHS_RegA = 0x00<<2, // two bits
    Control_Select_ALUInputLHS_RegB = 0x01<<2, // two bits
    Control_Select_ALUInputLHS_RegC = 0x02<<2, // two bits
    Control_Select_ALUInputLHS_RegD = 0x03<<2, // two bits
    Control_Select_ALUInputRHS_RegA = 0x00<<0, // two bits
    Control_Select_ALUInputRHS_RegB = 0x01<<0, // two bits
    Control_Select_ALUInputRHS_RegC = 0x02<<0, // two bits
    Control_Select_ALUInputRHS_RegD = 0x03<<0, // two bits
    /////////////////// 1B
    /////////////////// 2A
    Control_Assert_Bus_RegA = 0x01<<16,
    Control_Assert_Bus_RegB = 0x02<<16,
    Control_Assert_Bus_RegC = 0x03<<16,
    Control_Assert_Bus_RegD = 0x04<<16,
    Control_Assert_Bus_Const = 0x05<<16,

    Control_Load_RegA_Bus = 0x01<<20,
    Control_Load_RegB_Bus = 0x02<<20,
    Control_Load_RegC_Bus = 0x03<<20,
    Control_Load_RegD_Bus = 0x04<<20,
    // ALU

    Control_Assert_Bus_ALU = 0x06<<16,
    /////////////////// 2B
};

void generateControl(const vector<unsigned int>& instructions, vector<unsigned int>& controls);
void generateMainRom(const vector<unsigned int> & instructions);

void outputControl(const vector<unsigned int> & controls);
#endif
