#ifndef INSTRUCTION_H
#define INSTRUCTION_H

enum eOpcodes2
{
    Op_NOP = 0,
    Op_R = 1, // con lai
    Op_J = 2
};
enum eReg
{
    Reg_A = 1,
    Reg_B = 2,
    Reg_C = 3,
    Reg_D = 4,
    Reg_TL = 5,
    Reg_TH = 6,
};
enum eFunc // 7 bits
{
    Func_MOV = 1, // mov a,b
    Func_ADD = 2, // add a,b,c
    Func_MOVI = 64, // movi a,1
    /* Func_ADDI = 65 // addi a,b,5 */
};
#endif
