#ifndef LRU_H
#define LRU_H

#include <vector>

class Lru{

public:
    int size = 0;
    std::vector<int> refs;
    int fail = 0;

    Lru(int, std::vector<int>);
    void result();

};


#endif // LRU_H

