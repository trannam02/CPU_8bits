#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "./../headers/opcodes.h"
using namespace std;


void readFile(char * fileName, vector<string> & lines);
void clearSpace(string& s);
string ith(unsigned int x, int max); // int to hex string
void printData(const string & title, int startAddress, int endAddress, const vector<unsigned int> & data);

string bin2ihx(const string & binFile,int maxByteCount);

#endif
