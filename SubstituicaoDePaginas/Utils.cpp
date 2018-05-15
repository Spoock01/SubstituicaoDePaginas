#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> arr;
int size;
ifstream inFile;

void readFile(){

    inFile >> size;
    int aux;

    while(!inFile.eof()){
        inFile >> aux;
        arr.push_back(aux);
    }

}

void openFile(string path){

    inFile.open(path.c_str());

    if(inFile.fail()){
       cout << "Erro ao abrir arquivo!\n";
       exit(0);
    }
    readFile();
}

int getQuadros(){
    return size;
}

vector<int> getArray(){
    return arr;
}
