#include <iostream>

#include "ABB.h"

using namespace std;

//TODO testar inserções iguais!!!
//TODO Menor e maior 
//TODO Remoção

int main() {
  cout << "Árvore Binária de Busca\n" << "Informe as chaves ou -1 para sair:\n";
  ABB<int> abb;
  int chave;
  cin >> chave;
  while(chave != -1) {
    abb.insere(chave);
    cin >> chave;
  }
  abb.imprime();
}