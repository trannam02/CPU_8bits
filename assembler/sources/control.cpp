#include "./../headers/control.h"
#include "./../headers/instruction.h"
using namespace std;
void generateControl(const vector<unsigned int>& instructions, vector<unsigned int>& controls){
    fstream filePtr1A;
    fstream filePtr1B;
    fstream filePtr2A;
    fstream filePtr2B;
    unsigned char buffer1A[instructions.size()];
    unsigned char buffer1B[instructions.size()];
    unsigned char buffer2A[instructions.size()];
    unsigned char buffer2B[instructions.size()];

    unsigned int out = 0;
    int index = 0;
    for(auto it = instructions.begin(); it != instructions.end(); it++){
        out = 0;
        // op
        unsigned int op = (*it >> 30) & 3;
        unsigned int func = (*it >> 23) & 127;
        unsigned int des = (*it >> 18) & 31;
        unsigned int rs = (*it >> 13) & 31;
        unsigned int rt = (*it >> 8) & 31;
        unsigned int constant = (*it) & 255;
        if(op == Op_NOP) {}
        else if(op == Op_J){}
        else if(op == Op_R){ // Op_R
            /* cout << func << endl; */
            switch(func){
                case Func_MOV:{
                                  switch(des){
                                      case Reg_A: {out |= Control_Load_RegA_Bus; break;};
                                      case Reg_B: {out |= Control_Load_RegB_Bus; break;};
                                      case Reg_C: {out |= Control_Load_RegC_Bus; break;};
                                      case Reg_D: {out |= Control_Load_RegD_Bus; break;};
                                  };
                                  switch(rs){
                                      case Reg_A: {out |= Control_Assert_Bus_RegA; break;};
                                      case Reg_B: {out |= Control_Assert_Bus_RegB; break;};
                                      case Reg_C: {out |= Control_Assert_Bus_RegC; break;};
                                      case Reg_D: {out |= Control_Assert_Bus_RegD; break;};
                                  };
                                  break;
                               };
                case Func_MOVI:{
                                  switch(des){
                                      case Reg_A: {out |= Control_Load_RegA_Bus; break;};
                                      case Reg_B: {out |= Control_Load_RegB_Bus; break;};
                                      case Reg_C: {out |= Control_Load_RegC_Bus; break;};
                                      case Reg_D: {out |= Control_Load_RegD_Bus; break;};
                                  };
                                  out |= Control_Load_Const_Mem | Control_Assert_Bus_Const;
                                  break;
                               };
                case Func_ADD:{
                                  switch(des){
                                      case Reg_A: {out |= Control_Load_RegA_Bus; break;};
                                      case Reg_B: {out |= Control_Load_RegB_Bus; break;};
                                      case Reg_C: {out |= Control_Load_RegC_Bus; break;};
                                      case Reg_D: {out |= Control_Load_RegD_Bus; break;};
                                  };
                                  switch(rs){
                                      case Reg_A:{out |= Control_Select_ALUInputLHS_RegA;break;};
                                      case Reg_B:{out |= Control_Select_ALUInputLHS_RegB;break;};
                                      case Reg_C:{out |= Control_Select_ALUInputLHS_RegC;break;};
                                      case Reg_D:{out |= Control_Select_ALUInputLHS_RegD;break;};
                                  };
                                  switch(rt){
                                      case Reg_A:{out |= Control_Select_ALUInputRHS_RegA;break;};
                                      case Reg_B:{out |= Control_Select_ALUInputRHS_RegB;break;};
                                      case Reg_C:{out |= Control_Select_ALUInputRHS_RegC;break;};
                                      case Reg_D:{out |= Control_Select_ALUInputRHS_RegD;break;};
                                  };
                                  out |= Control_Assert_Bus_ALU;
                              };
            };
        };
        buffer1A[index] = out&255;
        buffer1B[index] = out>>8&255;
        buffer2A[index] = out>>16&255;
        buffer2B[index] = out>>24&255;
        index++;
        controls.push_back(out);
    };
    // write file
    filePtr1A.open("Control1A.bin", ios::binary | ios::out);
    filePtr1A.write((char*)buffer1A, sizeof buffer1A);
    filePtr1A.close();

    filePtr1B.open("Control1B.bin", ios::binary | ios::out);
    filePtr1B.write((char*)buffer1B, sizeof buffer1B);
    filePtr1B.close();

    filePtr2A.open("Control2A.bin", ios::binary | ios::out);
    filePtr2A.write((char*)buffer2A, sizeof buffer2A);
    filePtr2A.close();

    filePtr2B.open("Control2B.bin", ios::binary | ios::out);
    filePtr2B.write((char*)buffer2B, sizeof buffer2B);
    filePtr2B.close();
    return;
};
void generateMainRom(const vector<unsigned int> & instructions){
    const char * fileName = "MainRom.bin";
    FILE* filePtr;
    filePtr = fopen(fileName,"w"); 
    unsigned char buffer[instructions.size() * 2];
    int addr = 0;
    int index = 0;
    /* cout << "MAINDATA:"; */
    for(auto ins : instructions){
        if((ins>>23&127) <= 63){
            buffer[index] = addr;
            /* cout << ith(addr, 2) << " "; */
            index++; addr++;
        }else{
            buffer[index] = addr;
            /* cout << ith(addr, 2) << " "; */
            index++;
            buffer[index] = (ins&255);
            /* cout << ith(ins&255,2) << " "; */
            index++; addr++;
        };
    };
    fwrite(buffer,sizeof(unsigned char),index+ 1, filePtr);
    fclose(filePtr);
};
void outputControl(const vector<unsigned int> & controls){
    vector<unsigned int> control1A;
    vector<unsigned int> control1B;
    vector<unsigned int> control2A;
    vector<unsigned int> control2B;
    for(auto control = controls.begin(); control != controls.end(); control++){
        control1A.push_back( *control & 255 );
        control1B.push_back( *control>>8 & 255 );
        control2A.push_back( *control>>16 & 255 );
        control2B.push_back( *control>>24 & 255 );
    };
    /* cout << "=====Control 1A=====" << endl; */
    printData("Control 1A",0, control1A.size(), control1A);
    /* cout << "=====Control 2A=====" << endl; */
    printData("Control 2A", 0, control2A.size(), control2A);
};
