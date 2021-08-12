#include "BST.h"

//BST constructor
template <class TYPE>
BST<TYPE>::BST() {
    root = NULL;
}

//BST destructor
template <class TYPE>
BST<TYPE>::~BST() {
    //dtor
}

template <class TYPE>
TYPE BST<TYPE>::getRoot() {
    if(root != NULL)
        return root->getKey();
    else {
        cout << "Empty tree!" << endl;
        //TODO resolve this!!!!
        return;
    }
}

//Auxiliary to BST search
template <class TYPE>
bool BST<TYPE>::auxSearch(NodeBST<TYPE>* n, TYPE val) {
    if(n == NULL)
        return false;
    else if(val == n->getKey())
        return true;
    else if(val < n->getKey())
        return auxSearch(n->getLeft(), val);
    else
        return auxSearch(n->getLeft(), val);
}

//BST search
template <class TYPE>
bool BST<TYPE>::search(TYPE val) {
    return auxSearch(root, val);
}

//Auxiliary to BST insertion
template <class TYPE>
NodeBST<TYPE>* BST<TYPE>::auxInsert(NodeBST<TYPE>* n, TYPE val) {
    if(n == NULL) {
        n = new NodeBST<TYPE>(val);
    }
    else if(val < n->getKey())
        n->setLeft(auxInsert(n->getLeft(), val));
    else if(val > n->getKey())
        n->setRight(auxInsert(n->getRight(), val));
    else {
        cout << "The value is already in the tree!" << endl;
    }
    return n;
}

//BST insertion
template <class TYPE>
void BST<TYPE>::insert(TYPE val) {
    root = auxInsert(root, val);
}

//Auxiliary to printing
template <class TYPE>
void BST<TYPE>::auxPrint(string prefix, NodeBST<TYPE>* n, bool left) {
    if(n != NULL) {
        cout << prefix;
        cout << (left ? "├──" : "└──");
        cout << n->getKey() << endl;
        auxPrint(prefix + (left ? "│   " : "    "), n->getLeft(), true);
        auxPrint(prefix + (left ? "│   " : "    "), n->getRight(), false);
    }
}

//Printing
template <class TYPE>
void BST<TYPE>::print(){
    auxPrint("", root, false);
}

template class BST<int>;