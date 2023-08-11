#include "decoder.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <csignal>
using namespace std;



bool RUNNING = true;

void my_handler(int s) {
    cout << "Detected CTRL-C signal no. " << s << '\n';
    RUNNING = false;
}


int main(){
    signal(SIGINT, my_handler);
    const string messageHeader = "02 15 00 00 01 16 01 04 06";
    const string numberHeader = "7F 80";
    
    cout << messageHeader;
    cout << "\n";
    cout << numberHeader;
    cout <<"\n";

    cout << "Testing to make sure joseph isn't stupid\n\n";
    ifstream file;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    string contents;

    while(RUNNING){
        

        //open file, pipe contents to string container

        file.open(filename);
        if (file.is_open()){
            file >> contents;
            cout << contents;
        }
        
        int i = 0; 
        i = decode(contents);
        return i;
    }
    return 0;
}
