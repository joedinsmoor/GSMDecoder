#include "decoder.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;



bool RUNNING = true;

void my_handler(int s) {
    cout << "Detected CTRL-C signal no. " << s << '\n';
    RUNNING = false;
}


int main(){
    cout << "Testing to make sure joseph isn't stupid\n\n";
    ifstream file;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    string contents;

    //open file, pipe contents to string container

    file.open(filename);
    if (file.is_open()){
        file >> contents;
        cout << contents;
    }
    
   int i = decode(contents);

    
    return i;
}
