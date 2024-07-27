#include "./../headers/parser.h"
using namespace std;


void parserLines(vector<string> & lines, vector<unsigned int>& opcodes, vector<unsigned int> & data){
    unsigned int op = -1; 
    bool isImmediate = false;
    int con = 0;
    int romAddr = 0;
    
    for(auto line = lines.begin(); line != lines.end(); line++){
        // reset variable
        op = -1;
        isImmediate = false;
        con = 0;
        clearSpace(*line);
        parserLine(*line,op,isImmediate,con);
        // write op to file to handle control signal
        opcodes.push_back(op);

        data.push_back(romAddr++);
        if(isImmediate) data.push_back(con);
    };
    printData(0, romAddr, data);
};


void parserLine(string line,unsigned int& op, bool& isImmediate, int& con){
    // get const
    if(isdigit(line[line.size()-1])){
        isImmediate = 1;
        int pos = line.rfind(',');
        if(pos >= 0 && pos < line.size()){
            char num[line.size()];
            line.copy(num,line.size() - pos - 1, pos + 1);
            con = stoi(num);
        }
    }
    // get operator
    regex reFunc("^[a-z]+");
    smatch matched;
    regex_search(line, matched, reFunc);
    if(matched[0] == "nop"){
        op = Op_NOP;
        return;
    };
    if(matched[0] == "mov"){
        regex reFisrtReg(" ([a-z])+,");
        regex_search(line, matched, reFisrtReg);
        string firstReg = matched[matched.size() - 1];
        if(isImmediate){
            if(firstReg == "a"){op = Op_MOV_RegA_Const; return;};
            if(firstReg == "b"){op = Op_MOV_RegB_Const; return;};
            if(firstReg == "c"){op = Op_MOV_RegC_Const; return;};
            if(firstReg == "d"){op = Op_MOV_RegD_Const; return;};
        }else{
            regex reSecondReg(",([a-z]+)$");
            regex_search(line, matched, reSecondReg);
            string secondReg = matched[matched.size() - 1];
            if(firstReg == "a" && secondReg == "b") {op = Op_MOV_RegA_RegB; return;};
            if(firstReg == "a" && secondReg == "c") {op = Op_MOV_RegA_RegC; return;};
            if(firstReg == "a" && secondReg == "d") {op = Op_MOV_RegA_RegD; return;};
            if(firstReg == "b" && secondReg == "a") {op = Op_MOV_RegB_RegA; return;};
            if(firstReg == "b" && secondReg == "c") {op = Op_MOV_RegB_RegC; return;};
            if(firstReg == "b" && secondReg == "d") {op = Op_MOV_RegB_RegD; return;};
            if(firstReg == "c" && secondReg == "a") {op = Op_MOV_RegC_RegA; return;};
            if(firstReg == "c" && secondReg == "b") {op = Op_MOV_RegC_RegB; return;};
            if(firstReg == "c" && secondReg == "d") {op = Op_MOV_RegC_RegD; return;};
            if(firstReg == "d" && secondReg == "a") {op = Op_MOV_RegD_RegA; return;};
            if(firstReg == "d" && secondReg == "b") {op = Op_MOV_RegD_RegB; return;};
            if(firstReg == "d" && secondReg == "c") {op = Op_MOV_RegD_RegC; return;};
        };
        return;
    }
};


