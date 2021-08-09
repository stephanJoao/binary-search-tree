#ifndef NOABB_H
#define NOABB_H

#include <iostream>

using namespace std;

template <class TIPO>
class NoABB {

    //Funções
    public:
        NoABB(TIPO val);
        ~NoABB();

        void setEsq(NoABB *n) { esq = n; };
        void setDir(NoABB *n) { dir = n; };
        void setChave(TIPO c) { chave = c; };

        NoABB* getEsq() { return esq; };
        NoABB* getDir() { return dir; };
        TIPO getChave() { return chave; };

    private:

    //Variáveis
    public:

    private:
        NoABB *esq;
        NoABB *dir;
        TIPO chave;

};

template <class TIPO>
NoABB<TIPO>::NoABB(TIPO val) {
    chave = val;
    esq = NULL;
    dir = NULL;
}

#endif // NoABB_H