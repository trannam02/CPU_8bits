#include "./../headers/utils.h"
#include "./../headers/parser.h"
using namespace std;

int main(const int argc,char* argv[]){
    if(argc != 2){
        cout << "Please input only 1 file";
        return 1;
    };
    cout << "ROM build..." << endl;

    vector<string> lines;
    vector<int> data; // data to write to main rom
    readFile(argv[1], lines);
    parserLines(lines, "opdata.txt", data);

    return 0;
}
