#include <iostream>
#include <vector>
#include "include/List.h"

// Jesus Raul Jimenez Perez - A01666493

using namespace std;

int main(){
    List<int> list;

    // insert elements using a loop and random numbers
    for (int i = 0; i < 10; i++) {
        list.insert(rand() % 100);
    }


    // remove last element
    list.removeLast();

    // get data at index 1
    cout << list.getData(1) << endl;

    // get size of list
    cout << list.getSize() << endl;

    // get max value in list
    cout << list.getMax() << endl;

    // print list
    list.print();


    return 0;
}