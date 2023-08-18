/*
The bulk of the decoding is done in the decode function, supplemented by threadShred to parallelize the workload. This is built for C++ and cmake on MacOS Monterey.
Testing is done using a system-agnostic approach, so functionality should be identical across operating systems.

Written by: Joe Dinsmoor
Github: https://github.com/joedinsmoor

*/




#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <csignal>
#include <unistd.h>
#include <regex>
extern "C"{
    #include <time.h>
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
    cout << "Entering Decode Stage \n\n";
    usleep(500);
    smatch match;
    size_t foundM = contents.find(messageHeader);
    size_t foundC = contents.find(contactHeader);
    size_t foundN = contents.find(numberHeader);
    size_t foundS = contents.find(sizeHeader); 
    regex pNumber;
    regex re("\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d");

    int i = 0;
    while (regex_search(contents, match, re)) {
        cout << "\n Matched string is " << match.str(0) << endl;
        cout << "It can be found at position " << match.position(0) << endl;
    }
    int pattern;
    /*pattern = regcomp(&pNumber, "\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d", REG_EXTENDED | REG_ICASE);
    if (pattern){
        cout << "Could not compile regex!\n";
    }*/



    ofstream outfile;
    if(foundM!=std::string::npos){
        cout << "Text Messages found, stored in messages.txt";
        outfile.open("messages.txt", std::ios_base::app);
        for(i = 0; i < foundM; i++){
            outfile << contents[i];
            cout << contents[i];
            RUNNING = false;
        }
    }

    if(foundC!=std::string::npos){
        cout << "Contacts found, stored in contacts.txt";
        outfile.open("contacts.txt", std::ios_base::app);
        for(i = 0; i < foundC; i++){
            outfile << contents[i];
            cout << contents[i];
            RUNNING = false;
        }
    }

    if(foundN!=std::string::npos){
        cout << "Phone Numbers found, stored in numbers.txt";
        outfile.open("numbers.txt", std::ios_base::app);
        for(i = 0; i < foundN; i++){
            outfile << contents[i];
            cout << contents[i];
            RUNNING = false;
        }
    }

    if(foundS!=std::string::npos){
        cout << "Size Indicators found, stored in sizes.txt";
        outfile.open("sizes.txt", std::ios_base::app);
        for(i = 0; i < foundM; i++){
            outfile << contents[i];
            cout << contents[i];
            RUNNING = false;
        }
    }
   //regfree(&pNumber);
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
            cout << "Contents written to temp string.\n";
            file.close();
        }
        
        int i = 0; 
        decode(contents, outfilename);
    }
    return 0;
}


