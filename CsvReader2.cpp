#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream inputFile("data.csv");
    ofstream outputFile("noCommaData.csv");
    if(!inputFile.is_open() || !outputFile.is_open()){
        cout << "Error: file is unable to open" << endl;
    }

    string line;
    while(getline(inputFile, line)){
        size_t pos;
        while((pos = line.find(',')) != string::npos){
            line.replace(pos, 1, " ");
        }
        outputFile << line << '\n' << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}