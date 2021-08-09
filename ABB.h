#ifndef ABB_H
#define ABB_H

#include <iostream>

#include "NoABB.h"

using namespace std;

template <class TIPO>
class ABB {

    //Funções
    public:
        ABB();
        ~ABB();

        TIPO getRaiz();
        bool vazia() { return (raiz == NULL); };
        bool busca(TIPO val);
        void insere(TIPO val);
        void imprime();
        //void remove(TIPO val);

    private:
        bool auxBusca(NoABB<TIPO> *n, TIPO val);
        NoABB<TIPO>* auxInsere(NoABB<TIPO> *n, TIPO val);
        void auxImprime(string prefixo, NoABB<TIPO>* n, bool esquerda);

    //Variáveis
    public:

    private:
        NoABB<TIPO> *raiz;

};

// *Construtor ABB

template <class TIPO>
ABB<TIPO>::ABB() {
    raiz = NULL;
}

template <class TIPO>
ABB<TIPO>::~ABB() {
    //dtor
}

template <class TIPO>
TIPO ABB<TIPO>::getRaiz() {
    if(raiz != NULL)
        return raiz->getChave();
    else {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

// *Busca ABB

template <class TIPO>
bool ABB<TIPO>::auxBusca(NoABB<TIPO>* n, TIPO val) {
    if(n == NULL)
        return false;
    else if(val == n->getChave())
        return true;
    else if(val < n->getChave())
        return auxBusca(n->getEsq(), val);
    else
        return auxBusca(n->getEsq(), val);
}

template <class TIPO>
bool ABB<TIPO>::busca(TIPO val) {
    return auxBusca(raiz, val);
}

// *Inserção ABB

template <class TIPO>
NoABB<TIPO>* ABB<TIPO>::auxInsere(NoABB<TIPO>* n, TIPO val) {
    if(n == NULL) {
        n = new NoABB<TIPO>(val);
    }
    else if(val < n->getChave())
        n->setEsq(auxInsere(n->getEsq(), val));
    else if(val > n->getChave())
        n->setDir(auxInsere(n->getDir(), val));
    else {
        cout << "Valor já está na árvore!" << endl;
        exit(1);
    }
    return n;
}

template <class TIPO>
void ABB<TIPO>::insere(TIPO val) {
    raiz = auxInsere(raiz, val);
}

// *Impressão ABB (para int ou float)

template <class TIPO>
void ABB<TIPO>::auxImprime(string prefixo, NoABB<TIPO>* n, bool esquerda) {
    if(n != NULL) {
        cout << prefixo;
        cout << (esquerda ? "├──" : "└──");
        cout << n->getChave() << endl;
        auxImprime(prefixo + (esquerda ? "│   " : "    "), n->getEsq(), true);
        auxImprime(prefixo + (esquerda ? "│   " : "    "), n->getDir(), false);
    }
}

template <class TIPO>
void ABB<TIPO>::imprime(){
    auxImprime("", raiz, false);
}

#endif // ABB_H