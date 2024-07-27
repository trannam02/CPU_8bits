#ifndef PARSER_H
#define PARSER_H
#include "./../headers/utils.h"
#include <regex>
using namespace std;

void parserLine(string line, int& op, bool& isImmediate, int& con);
void parserLines(vector<string>& lines, string opFileName, vector<int> & data);
#endif
