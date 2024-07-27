#ifndef PARSER_H
#define PARSER_H
#include "./../headers/utils.h"
#include <regex>
using namespace std;

void parserLine(string line,unsigned int& op, bool& isImmediate, int& con);
void parserLines(vector<string> & lines, vector<unsigned int>& opcodes, vector<unsigned int> & data);
#endif
