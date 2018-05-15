#include <iostream>
#include "Lru.h"
#include <vector>

int lastIndex;
bool quadrosLivres = true;

Lru::Lru(int size, std::vector<int> refs){

    this->refs = refs;
    this->size = size;
    this->fail = 0;

}

int isFree(std::vector<int> quadros, int value){
    int i = 0;

    for(i = 0; i < (int) quadros.size(); i++){
        if(quadros[i] == -1){
            lastIndex = i;// ultima posicao inserida
            return i;
        } else if (quadros[i] == value)
            return -1;
    }


    quadrosLivres = false;
    return -1;
}

bool check(std::vector<int>&quadros, int size, int value){

    int i, ret;

    // verifica se existem posicoes livres
    ret = isFree(quadros, value);
    if(quadrosLivres && ret >= 0){
        //std::cout << "inserindo na posicao " << ret <<std::endl;
        quadros[ret] = value;
        return true;
    }

    // se chegar aqui, n existem posicoes livres ou o elemento
    // ja se encontra em um dos quadros
    for(i = 0; i < size; i++){

        if(quadros[i] == value){
            if(!quadrosLivres){
                quadros.push_back(value);
                quadros.erase(quadros.begin() + i);
            }else{
                quadros.erase(quadros.begin() + 1);
                quadros.insert(quadros.begin() + lastIndex, value);
            }

            return false;
        }
    }



    return true;   // Retorna TRUE caso o valor não esteja nos quadros

}

void printQ(std::vector<int> &quadros){
    std::cout << "Quadros: " << quadros[0] << " "<< quadros[1] << " "
              << quadros[2] << " " << quadros[3] << std::endl;
}


void Lru::result(){

    std::vector<int> quadros(size, -1);
    int i;

    for(i = 0; i < (int)refs.size(); i++){
        //std::cout << "Posicao: " << i << " Valor: " << refs[i] << std::endl;
        //printQ(quadros);
        if(check(quadros, size, refs[i])){
            fail++;
        }
    }

    std::cout << "LRU " << fail << std::endl;
}
