#include "./../headers/utils.h"
#include "./../headers/parser.h"
#include "./../headers/control.h"
using namespace std;

int main(const int argc,char* argv[]){
    if(argc != 2){
        cout << "Please input only 1 source file";
        return 1;
    };
    cout << "ROM build..." << endl;

    vector<string> lines;
    vector<unsigned int> data; // data to write to main rom
    vector<unsigned int> opcodes;
    vector<unsigned int> controls;

    readFile(argv[1], lines);
    parserLines(lines, opcodes, data);
    generateControl(opcodes, controls);

    outputControl(controls);
    return 0;
}
