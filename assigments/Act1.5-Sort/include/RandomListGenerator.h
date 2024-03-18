// RandomListGenerator.h
#ifndef RANDOMLISTGENERATOR_H
#define RANDOMLISTGENERATOR_H

#include <vector>
#include <cstdlib>
#include <ctime>


template <typename T>
std:: vector<T> generateRandomList(int n){
    std::vector<T> list(n);
    for(int i = 0; i < n; i++) {
        list[i] = static_cast<T>(rand() % 100); 
    }
    return list;
}

#endif 
