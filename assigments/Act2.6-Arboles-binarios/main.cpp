#include <iostream>
#include "include/AVLNode.h"
#include "include/AVLTree.h"

using namespace std;

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Preorder traversal of the AVL tree is: ";
    tree.preOrder();
    cout << endl;

    tree.deleteNode(50);
    cout << "Preorder traversal after deletion of 50: ";
    tree.preOrder();
    cout << endl;

    tree.find(25);
    tree.find(100);

    return 0;
}
