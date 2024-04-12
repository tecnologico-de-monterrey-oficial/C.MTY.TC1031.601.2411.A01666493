#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
    T data;
    ListNode<T>* next;

    ListNode(const T& data) : data(data), next(nullptr) {}
};

#endif 