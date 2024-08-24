#include "./../headers/parser.h"
#include "./../headers/instruction.h"
using namespace std;

void parserLines(vector<string> & lines, vector<unsigned int>& instructions) {
    int romAddr = 0;
    unsigned int instruction = 0;
    for(auto line = lines.begin(); line != lines.end(); line++) {
        // reset variable
        instruction = 0;
        clearSpace(*line);
        parserLine(*line,instruction);
        /* cout << ith(instruction, 8) << endl; */
        instructions.push_back(instruction);
    };
};


void parserLine(string line,unsigned int & instruction) {
    instruction = 0;
    // get opcode
    regex reFunc("^[a-z]+");
    smatch funcMatched;
    regex_search(line, funcMatched, reFunc);
    if(funcMatched[0] == "nop") {
        return;
    } else { // R type
        // opcode
        instruction = (instruction | 1);
        // first register
        instruction = (instruction << 12) | (findFirstReg(line)&31);
        if(funcMatched[0] == "mov") {
            instruction = instruction | ((Func_MOV & 127) << 5);
            instruction = (instruction << 5) | (findThirdReg(line)&31);
            instruction <<= 13;
            return;
        };
        if(funcMatched[0] == "movi") {
            instruction = instruction | ((Func_MOVI & 127) << 5);
            instruction = (instruction << 18) | (findConstant(line)&255);
            return;
        };
        if(funcMatched[0] == "add") {
            instruction = instruction | ((Func_ADD & 127) << 5);
            instruction = (instruction << 5) | (findSecondReg(line)&31);
            instruction = (instruction << 5) | (findThirdReg(line)&31);
            instruction <<= 8;
            return;
        };
        /* if(funcMatched[0] == "addi") { */
        /*     instruction = instruction | ((Func_ADDI & 127) << 5); */
        /*     instruction = (instruction << 5) | (findSecondReg(line)&31); */
        /*     instruction = (instruction << 13) | (findConstant(line) & 255); */
        /*     return; */
        /* }; */
    };
};
unsigned int findFirstReg(const string & line) {
    regex reFisrtReg(" ([a-z])+,");
    smatch matched;
    regex_search(line, matched, reFisrtReg);
    string firstReg = matched[matched.size() - 1];
    return strRegToInt(firstReg);
};
unsigned int findSecondReg(const string & line) {
    regex reSecondReg(",([a-z]+),");
    smatch matched;
    regex_search(line, matched, reSecondReg);
    string secondReg = matched[matched.size() - 1];
    return strRegToInt(secondReg);
};
unsigned int findThirdReg(const string & line) {
    regex reSecondReg(",([a-z]+)$");
    smatch matched;
    regex_search(line, matched, reSecondReg);
    string secondReg = matched[matched.size() - 1];
    return strRegToInt(secondReg);
};
unsigned int findConstant(const string & line) {
    regex reSecondReg(",([0-9]+)$");
    smatch matched;
    regex_search(line, matched, reSecondReg);
    string secondReg = matched[matched.size() - 1];
    return stoi(secondReg);
};
unsigned int strRegToInt(string & reg) {
    if(reg == "a") return Reg_A;
    if(reg == "b") return Reg_B;
    if(reg == "c") return Reg_C;
    if(reg == "d") return Reg_D;
    return 0;
};
