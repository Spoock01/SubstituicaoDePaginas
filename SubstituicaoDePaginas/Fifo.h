#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Fifo {

private:
    int tamanho;
    std::vector<int> refs;
    int faults;

    int check(int*, int);
    void init(int*);
public:
    Fifo(int, std::vector<int>);
    void result();

};

Fifo::Fifo(int tamanho, std::vector<int> refs){
    this->tamanho = tamanho;
    this->refs = refs;
    this->faults = 0;
}

int Fifo::check (int *arr, int value){
    int i;

    for(i = 0; i < tamanho; i++)
        if(value == arr[i])
            return 1;

    return 0;

}

void Fifo::init(int *quadros){
    int i;

    for(i = 0; i < tamanho; i++){
        quadros[i] = -1;
    }
}

void Fifo::result(){

    int index = 0, i;
    int *quadros = (int *) malloc(sizeof(int) * tamanho);

    init(quadros);

    for(i = 0; i < (int) refs.size(); i++){

        if(!check(quadros, refs[i])){
            quadros[index++ % tamanho] = refs[i];
            this->faults++;
        }
    }
    std::cout << "FIFO " << this->faults << std::endl;
}


#endif // FIFO_H
