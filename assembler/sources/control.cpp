#include "./../headers/control.h"
using namespace std;

void generateControl(const vector<unsigned int>& opcodes, vector<unsigned int>& controls){
    unsigned int out = 0;
    for(auto op = opcodes.begin(); op != opcodes.end(); op++){
        out = 0;
        switch(*op){
            case Op_NOP: break;

            case Op_MOV_RegA_Const: {out = out | Control_Load_Const_Mem | Control_Assert_Bus_Const | Control_Load_RegA_Bus; break;};
            case Op_MOV_RegB_Const: {out = out | Control_Load_Const_Mem | Control_Assert_Bus_Const | Control_Load_RegB_Bus; break;};
            case Op_MOV_RegC_Const: {out = out | Control_Load_Const_Mem | Control_Assert_Bus_Const | Control_Load_RegC_Bus; break;};
            case Op_MOV_RegD_Const: {out = out | Control_Load_Const_Mem | Control_Assert_Bus_Const | Control_Load_RegD_Bus; break;};

            case Op_MOV_RegA_RegB: {out = out | Control_Assert_Bus_RegB | Control_Load_RegA_Bus; break;};
            case Op_MOV_RegA_RegC: {out = out | Control_Assert_Bus_RegC | Control_Load_RegA_Bus; break;};
            case Op_MOV_RegA_RegD: {out = out | Control_Assert_Bus_RegD | Control_Load_RegA_Bus; break;};
            case Op_MOV_RegB_RegA: {out = out | Control_Assert_Bus_RegA | Control_Load_RegB_Bus; break;};
            case Op_MOV_RegB_RegC: {out = out | Control_Assert_Bus_RegC | Control_Load_RegB_Bus; break;};
            case Op_MOV_RegB_RegD: {out = out | Control_Assert_Bus_RegD | Control_Load_RegB_Bus; break;};
            case Op_MOV_RegC_RegA: {out = out | Control_Assert_Bus_RegA | Control_Load_RegC_Bus; break;};
            case Op_MOV_RegC_RegB: {out = out | Control_Assert_Bus_RegB | Control_Load_RegC_Bus; break;};
            case Op_MOV_RegC_RegD: {out = out | Control_Assert_Bus_RegD | Control_Load_RegC_Bus; break;};
            case Op_MOV_RegD_RegA: {out = out | Control_Assert_Bus_RegA | Control_Load_RegD_Bus; break;};
            case Op_MOV_RegD_RegB: {out = out | Control_Assert_Bus_RegB | Control_Load_RegD_Bus; break;};
            case Op_MOV_RegD_RegC: {out = out | Control_Assert_Bus_RegC | Control_Load_RegD_Bus; break;};
        };
        controls.push_back(out);
    };
    return;
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
        control2B.push_back( *control & 255 );
    };
    cout << "Control 1A" << endl;
    printData(0, control1A.size(), control1A);
    cout << "Control 2A" << endl;
    printData(0, control2A.size(), control2A);
};
