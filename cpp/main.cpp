#include "decoder.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


bool RUNNING = TRUE;

void my_handler(int s) {
    cout << "Detected CTRL-C signal no. " << s << '\n';
    RUNNING = FALSE;
}


int main(){
    cout << "Testing to make sure joseph isn't stupid";
    ifstream file;
    string filename;
    cin >> "Input filename" >> filename;
    string contents;

    //open file, pipe contents to string container

    file.open(filename);
    if (file.is_open()){
        file >> contents;
        cout << contents;
    }
    

    
    return 0;
}
