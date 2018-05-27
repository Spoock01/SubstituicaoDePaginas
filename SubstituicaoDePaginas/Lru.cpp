#include <iostream>
#include "Lru.h"
#include <vector>
#include <string>
#include "LruProcess.h"

int *counter;

Lru::Lru(int size, std::vector<int> refs){

    this->refs = refs;
    this->size = size;
    this->fail = 0;
    counter = new int(size);
}

int isFree(std::vector<LruProcess> quadros){
    int i;
    for(i = 0; i < (int) quadros.size(); i++){
        if(quadros[i].getTime() == -1){
            return i;
        }
    }
    return -1;

}

int checkTime(std::vector<LruProcess> quadros, int timeMax){

    int menor = timeMax + 1, i, index = 0; // Maior valor de tempo eh igual ao timeMax

    for (i = 0; i < (int)quadros.size(); i++){
        if(quadros[i].getTime() < menor){
            menor = quadros[i].getTime();
            index = i;
        }
    }
    return index;
}

bool check(std::vector<LruProcess> &quadros, std::vector<LruProcess> &refs, int size,int index){
    int i;
    bool ret = true;

    for(i = 0; i < size; i++)
        if(refs[index].getValue() == quadros[i].getValue()){
            ret = false;
            refs[index].setTime(index);
            quadros[i] = refs[index];
            break;
        }


    if(ret){ // Caso nao esteja nos quadros

        int insertIndex = isFree(quadros);

        if(insertIndex == -1){  // Nao tem quadros disponiveis
            insertIndex = checkTime(quadros, index); // Procura indice com menor tempo
            refs[index].setTime(index); // Modifica
            quadros[insertIndex] = refs[index];
        }
        else{
            refs[index].setTime(index);
            quadros[insertIndex] = refs[index];
        }
    }
    return ret;
}

void initCounter(std::vector<LruProcess> &refs, std::vector<int> &refs1,
                 std::vector<LruProcess> &quadros, int size){
    int i;

    for(i = 0; i < (int)refs1.size(); i++)
        refs.push_back(*new LruProcess(-1, refs1[i]));

    for(i = 0; i < size; i++)
        quadros.push_back(*new LruProcess(-1, -1));

}

void Lru::result(){

    std::vector<LruProcess> quadros;
    std::vector<LruProcess> refsLru;

    int i;
    initCounter(refsLru, refs, quadros, size);

    for(i = 0; i < (int)refsLru.size(); i++)
        if(check(quadros, refsLru, size, i))
            fail++;


    std::cout << "LRU " << fail << std::endl;
}
