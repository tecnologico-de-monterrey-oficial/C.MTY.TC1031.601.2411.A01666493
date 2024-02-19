#ifndef List_H
#define List_H


using namespace std;

template <class T>
class List {
    private:
        vector<T> data;
        int size;
    public:
        List();
        void insert(T a);
        void removeLast();
        T getData(int index);
        int getSize();
        T getMax();
        void print();
};

template <class T>
List<T>::List() {
    size = 0;
}

template <class T>
void List<T>::insert(T a){
    data.push_back(a);
    size++;
}

template <class T>
void List<T>::removeLast(){
    data.pop_back();
    size--;
}

template <class T>
T List<T>::getData(int index){
    return data[index];
}


template <class T>
int List<T>::getSize(){
    return size;
}


// Returns the maximum value in the list
template <class T>
T List<T>::getMax() {
    T maxVal = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

template <class T>
void List<T>::print(){
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

#endif