#include <iostream>

#include "BST.h"

using namespace std;

//TODO testar inserções iguais!!!
//TODO Menor e maior 
//TODO Remoção

int main() {
  cout << "Binary Search Tree\n" << "Provide the keys you want to insert or -1 to leave insertion:\n";
  BST<int> bst;
  int key;
  cin >> key;
  while(key != -1) {
    bst.insert(key);
    cin >> key;
  }
  bst.print();
}