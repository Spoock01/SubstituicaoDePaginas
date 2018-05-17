#include <iostream>
#include "OtmAlgorithm.h"

OtmAlgorithm::OtmAlgorithm(int size, std::vector<int>refs){
    this->refs = refs;
    this->size = size;
    this->fail = 0;
}

void init (int *quadros, int size) {
    int i;

    for(i = 0; i < size; i++){
        quadros[i] = -1;
    }

}

/*
    'check' VERIFICA SE O VALOR JA SE ENCONTRA
    EM UM DOS QUADROS.
*/
bool check(int *quadros, int value, int size){
    int i;

    for(i = 0; i < size; i++){
        if(quadros[i] == value)
            return false;
    }
    return true;
}

int OtmAlgorithm::getTradeIndex(int *quadros, int actIndex){
    int i, index = 0, aux = actIndex, last = -1;
    bool test;

    /*
        VERIFICANDO SE ALGUMA POSICAO DOS QUADROS
        SE ENCONTRA DISPONIVEL
    */
    for( i = 0; i < size; i++)
        if(quadros[i] == -1)
            return i;

    /*
        DUAS VERIFICACOES SERAO FEITAS

        1-  CASO EXISTA UM QUADRO QUE NAO SERA UTILIZADO
            NOVAMENTE, 'test' CONTINUA COMO TRUE E O VALOR
            RETORNADO SERA A POSICAO DESSE QUADRO.

        2-  CASO TODOS OS QUADROS ATUAIS SEJAM UTILIZADOS
            NOVAMENTE NO FUTURO, O VALOR RETORNADO SERA A
            POSICAO DO QUADRO QUE IRA DEMORAR MAIS PARA
            SER USADO NOVAMENTE.
    */
    for(i = 0; i < size; i++){

        aux = actIndex + 1;

        test = true;
        for(; aux < (int) refs.size(); aux++)
            if(refs[aux] == quadros[i]){
                if(aux > last){
                    last = aux;
                    index = i;
                }
                test= false;
                break;
            }

        if(test)
            return i;
    }

    return index;
}

void OtmAlgorithm::result(){
    int *quadros = new int(size), i;
    init(quadros, size);

    for(i = 0; i < (int)refs.size(); i++){

        if(check(quadros, refs[i], size)){
            fail++;
            quadros[getTradeIndex(quadros, i)] = refs[i];
        }
    }

    std::cout << "OTM " << fail << std::endl;
}

