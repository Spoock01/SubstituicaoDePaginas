#ifndef LRU_H
#define LRU_H

#include <vector>

class Lru{

public:
    int size;
    std::vector<int> refs;
    int fail;

    Lru(int, std::vector<int>);
    void result();

};


#endif // LRU_H

