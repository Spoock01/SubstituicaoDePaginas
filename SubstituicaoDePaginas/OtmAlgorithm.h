#ifndef OTM_ALGORITHM_H
#define OTM_ALGORITHM_H
#include <vector>

class OtmAlgorithm{

public:
    OtmAlgorithm(int, std::vector<int>);
    void result();
private:
    int size;
    std::vector<int> refs;
    int fail;
    int getTradeIndex(int*, int);
};



#endif // OTM_ALGORITHM_H
