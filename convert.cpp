#include <iostream>
#include <fstream>
using namespace std;

void readData(string lines[], int & size);

int main(){
    string lines[64];
    int size = 0;
    readData(lines, size);
};

void readData(string lines[], int & size){
    char * fileName = "code.txt";
    fstream file;
    file.open(fileName, ios_base::in);
    string line = "";
    while(!file.eof()){
        getline(file, line);
        lines[size++] = line; 
    };
    file.close();
};
