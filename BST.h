#ifndef BST_H
#define BST_H

#include <iostream>

#include "NodeBST.h"

using namespace std;

//Binary Search Tree
template <class TYPE>
class BST {

    //Functions
    public:
        BST();
        ~BST();

        TYPE getRoot();
        bool empty() { return (root == NULL); };
        
        bool search(TYPE val);
        void insert(TYPE val);
        //void remove(TYPE val);
        void print();

    private:
        bool auxSearch(NodeBST<TYPE> *n, TYPE val);
        NodeBST<TYPE>* auxInsert(NodeBST<TYPE> *n, TYPE val);
        void auxPrint(string prefix, NodeBST<TYPE>* n, bool left);

    //Variables
    public:

    private:
        NodeBST<TYPE> *root;

};

#endif // BST_H