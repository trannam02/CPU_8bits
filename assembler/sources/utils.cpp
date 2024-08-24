#include "./../headers/utils.h"



void readFile(char * fileName, vector<string> & lines) {
    string line;
    fstream file;
    file.open(fileName, ios_base::in);
    while(1) {
        if(file.eof()) break;
        getline(file, line);
        // remove black line
        if(line.size() == 0) continue;
        lines.push_back(line);

    };
};

void clearSpace(string& s) {
    int start = -1;
    int end = -1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ' || s[i] == '\t') {
            start = i;
        } else {
            break;
        };
    };
    for(int i = s.size() - 1; i > 0; i--) {
        if(s[i] == ' ' || s[i] == '\t') {
            end = i;
        } else {
            break;
        };
    };
    if(end != -1) s.erase(end, s.size());
    if(start != -1) s.erase(0, start+1);
    return;
};

string ith(unsigned int _x, int max) { // fix max size
    unsigned int x = (_x << (32 - max * 4)) >> (32 - max * 4);
    stringstream stream;
    stream << setfill('0') << setw(max) << std::hex << x;
    string result = stream.str().c_str();
    int i = 0;
    while(result[i]){
        result[i] = toupper(result[i]);
        i++;
    };
    return result;
};

void printData(const string &title, int startAddress,int endAddress,const vector<unsigned int> & data) {
    cout << setfill('=') << setw((40-(title.length()))/2 + title.length()) << title << setfill('=') << setw((40-(title.length()))/2) << "" << endl;
    cout << "Start address: " << startAddress << endl;
    cout << "End address: " << endAddress << endl;
    cout << "Number of bytes: " << (endAddress - startAddress) << " bytes" << endl;
    int maxInline = 10;
    int count = 0;
    int line = 0;
    cout << ith(line,4) << ": ";
    for(auto it = data.begin(); it != data.end(); it++) {
        cout << ith(*it, 2) << " ";
        count++;
        line++;
        if(count == 10) {
            cout << "\n" << ith(line, 4) << ": ";
            count = 0;
        };
    };
    cout << "\nCOPY:";
    for(auto i : data) cout << i << ",";
    cout << endl;
};


string bin2ihx(const string & binFile,int maxByteCount) {
    ifstream file(binFile, ios::binary);
    file.seekg(0, ios::end);
    unsigned int length = file.tellg();
    file.seekg(0,ios::beg);
    char buffer[length];
    file.read(buffer, length);

    file.close();

    char startAddr = 0;
    string results = "";
    for(int i = 0; i < length; i += maxByteCount) {
        results = ":";
        if(i + maxByteCount > length) { // overflow
            int theRest = length - i;
            int checkSum = theRest + (startAddr & 3) + (startAddr >> 2 & 3) + 0;
            results += ith(theRest,2);
            results += ith(startAddr, 4);
            results += ith(0, 2);
            for(int j = i; j < i+theRest; j++) {
                results += ith(buffer[j], 2);
                checkSum += buffer[j];
            };
            results += ith( ( ~(checkSum & 255) + 1) & 255, 2);
            results += "\n";
            cout << results;
            break;
        } else {
            int checkSum = maxByteCount + (startAddr & 3) + (startAddr >> 2 & 3) + 0;
            results += ith(maxByteCount,2);
            results += ith(startAddr, 4);
            results += ith(0, 2);
            startAddr += maxByteCount;
            for(int j = i; j < i+maxByteCount; j++) {
                results += ith(buffer[j], 2);
                checkSum += buffer[j];
            };
            results += ith( ( ~(checkSum & 255) + 1) & 255, 2);
            results += "\n";
            cout << results;
        };
    };
    results = ":00000001FF";
    cout << results << endl;
    return "";
};
