#ifndef LRU_PROCESS_H
#define LRU_PROCESS_H

#include <iostream>

class LruProcess {

public:
    LruProcess(int, int);
    int getTime();
    int getValue();
    void setTime(int);
    void setValue(int);
private:
    int time;
    int value;
};

LruProcess::LruProcess (int time, int value){
    this->time = time;
    this->value = value;
}

int LruProcess::getTime(){
    return time;
}

int LruProcess::getValue(){
    return value;
}

void LruProcess::setTime(int time){
    this->time = time;
}

void LruProcess::setValue(int value){
    this->value = value;
}

#endif // LRU_PROCESS_H
