#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Fifo.h"
#include "OtmAlgorithm.h"
#include "Lru.h"

using namespace std;

const string PATH = "arquivo.txt";

int main()
{
    openFile(PATH);

    int size = getQuadros();
    vector<int> arr = getArray();

    Fifo *fifo = new Fifo(size, arr);
    fifo->result();
    OtmAlgorithm *otm = new OtmAlgorithm(size, arr);
    otm->result();
    Lru *lru = new Lru(size, arr);
    lru->result();
    return 0;
}
