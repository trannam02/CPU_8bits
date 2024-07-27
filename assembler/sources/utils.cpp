#include "./../headers/utils.h"

void readFile(char * fileName, vector<string> & lines){
    string line;
    fstream file;
    file.open(fileName, ios_base::in);
    while(1){
        if(file.eof()) break;
        getline(file, line);
        // remove black line
        if(line.size() == 0) continue;
        lines.push_back(line);

    };
};

void clearSpace(string& s){
    int start = -1;
    int end = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || s[i] == '\t'){
            start = i;
        }else {
            break;
        };
    };
    for(int i = s.size() - 1; i > 0; i--){
        if(s[i] == ' ' || s[i] == '\t'){
            end = i;
        }else{
            break;
        };
    };
    if(end != -1) s.erase(end, s.size());
    if(start != -1) s.erase(0, start+1);
    return;
};

string ith(int x, int max){
    stringstream stream;
    stream << setfill('0') << setw(max) << std::hex << x;
    string result(stream.str());
    return result;
};

void printData(int startAddress,int endAddress,const vector<int> & data){
    cout << "Start address: " << startAddress << endl;
    cout << "End address: " << endAddress << endl;
    cout << "Number of bytes: " << (endAddress - startAddress) * 8 << endl;
    int maxInline = 10;
    int count = 0;
    int line = 0;
    cout << ith(line,4) << ": "; 
    for(auto it = data.begin(); it != data.end(); it++){
        cout << ith(*it, 2) << " ";
        count++;
        if(count == 10) {
            cout << "\n" << ith(++line, 4) << ": ";
            count = 0;
        };
    };
    cout << endl;
};

