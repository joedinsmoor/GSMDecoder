#include <iostream>
#include <string>
#include <fstream>
using namespace std;



const string messageHeader = "02 15 00 00 01 16 01 04 06";
const string numberHeader = "7F 80";
const string contactHeader = "30 01 06 00 05 08 08 00";
const string sizeHeader = "04 00 00 04 00";

int decode(string contents, ofstream outfile){
    size_t found = contents.find(messageHeader);
    cout << contents;
    int i = 0;
    if(found!=std::string::npos){
        cout << "Text Messages found, stored in messages.txt";
        outfile.open("messages.txt", std::ios_base::app);
        for(i = 0; i < found; i++){
            outfile << contents[i];
        }
    }
    int line = 0;
    return line;
}

