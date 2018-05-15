#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Fifo {

private:
    int size = 0;
    std::vector<int> refs;
    int fail = 0;

    int check(int*, int);
    void init(int*);
public:
    Fifo(int, std::vector<int>);
    void result();

};

Fifo::Fifo(int size, std::vector<int> refs){
    this->size = size;
    this->refs = refs;
    this->fail = 0;
}

int Fifo::check (int *arr, int value){
    int i;

    for(i = 0; i < size; i++)
        if(value == arr[i])
            return 1;

    return 0;

}

void Fifo::init(int *quadros){
    int i;

    for(i = 0; i < size; i++){
        quadros[i] = -1;
    }
}

void Fifo::result(){

    int index = 0, i;
    int *quadros = new int(size);

    init(quadros);

    for(i = 0; i < (int) refs.size(); i++){

        if(!check(quadros, refs[i])){
            quadros[index++ % size] = refs[i];
            this->fail++;
        }
    }
    std::cout << "FIFO " << this->fail << std::endl;
}


#endif // FIFO_H
