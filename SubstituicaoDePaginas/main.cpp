#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Fifo.h"

using namespace std;

const string PATH = "arquivo.txt";

int main()
{
    openFile(PATH);

    int size = getQuadros();
    vector<int> arr = getArray();

    Fifo *fifo = new Fifo(size, arr);
    fifo->result();

    return 0;
}
