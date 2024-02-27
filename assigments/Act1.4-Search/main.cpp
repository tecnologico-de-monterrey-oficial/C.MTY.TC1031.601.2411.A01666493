#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
int sequentialSearch(T arr[], T value, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}

template <class T>
int binarySearch(T arr[], T value, int size){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(arr[middle] == value){
            return middle;
        }
        else if(arr[middle] < value){
            left = middle + 1;
        }else {
            right = middle - 1;
        }
    }
    return -1;
}

void  createList(vector<int> &list, int qty){
    for(int i = 0; i < qty; i++){
        int random = rand() % 1000000 + 1;
        list.push_back(random);
    }
}

void printList(vector<int> list){
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
}

int main(){
    // int arr[] = {1, 2, 3, 4, 5};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int value = 3;
    // cout << "dIndex of " << value << " is " << sequentialSearch(arr, value, size) << endl;

    // string arr2[] = {"a", "b", "c", "d", "e"};
    // size = sizeof(arr2) / sizeof(arr2[0]);
    // string value2 = "c";
    // cout << "Index of " << value2 << " is " << sequentialSearch(arr2, value2, size) << endl;


    // vector<int> list;
    // createList(list, 1000);
    // printList(list);


    // Binary Search
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 3;
    cout << "Index of " << value << " is " << binarySearch(arr, value, size) << endl;
}