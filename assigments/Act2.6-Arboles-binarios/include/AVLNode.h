#ifndef AVLNODE_H
#define AVLNODE_H

class AVLNode {
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

#endif // AVLNODE_H