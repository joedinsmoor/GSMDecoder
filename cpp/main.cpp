#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <csignal>
extern "C"{
    #include <regex.h>
}
using namespace std;

const string messageHeader = "02 15 00 00 01 16 01 04 06";
const string numberHeader = "7F 80";
const string contactHeader = "30 01 06 00 05 08 08 00";
const string sizeHeader = "00 00 04 00";

bool RUNNING = true;

void my_handler(int s) {
    cout << "Detected CTRL-C signal no. " << s << '\n';
    RUNNING = false;
}


void decode(string contents, string outfilename){
    size_t foundM = contents.find(messageHeader);
    size_t foundC = contents.find(contactHeader);
    size_t foundN = contents.find(numberHeader);
    size_t foundS = contents.find(sizeHeader); 
    regex_t pNumber;
    int pattern;
    pattern = regcomp(&pNumber, "\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d", REG_EXTENDED | REG_ICASE);
    if (pattern){
        cout << "Could not compile regex!\n";
    }


    int i = 0;
    ofstream outfile;
    if(foundM!=std::string::npos){
        cout << "Text Messages found, stored in messages.txt";
        outfile.open("messages.txt", std::ios_base::app);
        for(i = 0; i < foundM; i++){
            outfile << contents[i];
            cout << contents[i];
        }
    }
    regfree(&pNumber);
}

void threadShred(size_t header, string name, string filename, string contents){
    int i = 0;
    ofstream outfile;
    if(header!=std::string::npos){
        cout << name << "found, stored in" << filename;
        outfile.open(filename, std::ios_base::app);
        for(i = 0; i < header; i++){
            outfile << contents[i];
            cout << contents[i];
        }
    }
}

int main(){
    signal(SIGINT, my_handler);
    cout << "Testing to make sure joseph isn't stupid\n\n";
    fstream file;
    string outfilename;
    string infilename;
    cout << "Enter filename: ";
    cin >> infilename;
    string contents;

    while(RUNNING){
        

        //open file, pipe contents to string container

        file.open(infilename);
        if (file.is_open()){
            file >> contents;
            cout << contents;
        }
        
        int i = 0; 
        decode(contents, outfilename);
        return i;
    }
    return 0;
}


