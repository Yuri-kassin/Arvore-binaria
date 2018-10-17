//
// Created by yoru on 14/09/18.
//

#ifndef ARVORE_BINARIA_DE_BUSCAA_ARVOVE_HPP
#define ARVORE_BINARIA_DE_BUSCAA_ARVOVE_HPP

#include "No.hpp"

using namespace std;
template <typename T>
class Arvove {
private:

    int n;
    No<T>*raiz;
    void edr(No<T>* r){
//        puts("printanduuu");
        if(r){
            edr(r->Dirt);
            cout << **r << endl;
            edr(r->Esqr);
        }
    }

        void erd(No<T>* r){
//        puts("printanduuu");
        if(r){
            erd(r->Esqr);
            cout << **r << endl;
            erd(r->Dirt);
        }
    }

public:
    Arvove():n(0),raiz(nullptr){
    }

    void erd(){
        erd(raiz);
    }


    void edr(){
        edr(raiz);
    }

    No<T>* busca(T valor){
        No<T>* atual = raiz;
        while(atual){
            if(valor==atual->valor)
                return atual;

            if(valor <= atual->valor){
                atual = atual->Esqr;
            }else{
                atual = atual->Dirt;
            }
        }
        if(!atual || valor!=atual->valor) return nullptr;
    }

     int contaFilhos(No<T>* x){
        return (x->Esqr!=NULL)+(x->Dirt!=NULL);
    }

    No<T>** ponteiroDoPai(No<T>* p){
        if(p->anterior->Esqr == p){
            return &(p->anterior->Esqr);
        }else{
            return &(p->anterior->Dirt);
        }
    }

    void remove(T valor){
        No<T>* x = busca(valor);
        if(!x)
            return;

        int filhos = contaFilhos(x);
        if(filhos == 0){
            *ponteiroDoPai(x) = nullptr;
            delete x;
        }
        else if(filhos == 1){
            No<T> *f = x->Esqr;
            if(!f) f = x->Dirt;

            *ponteiroDoPai(x) = f;
            f->anterior = x->anterior;
            delete x;
        }
        else{
            No<T> *atual = x;
            No<T> *anterior;
            while(contaFilhos(atual)!=0){
                anterior = atual;
                atual = atual->Esqr;
                if(!atual) atual = atual->Dirt;
                anterior->valor = atual->valor;
            }
            *ponteiroDoPai(x) = nullptr;
            delete atual;
        }

    }

    bool insere(T valor){
        No<T>* novo = new No<T>(valor);
        if(novo == nullptr) return false;
        No<T>*atual = raiz;
        No<T>*ant = nullptr;
        while(atual){
            ant = atual;
            if(valor <= atual->valor) atual = atual->Esqr;

            else atual = atual->Dirt;
        }

        if(ant) {
            if(valor <= ant->valor){
                ant->Esqr = novo;
                (ant->Esqr)->anterior = ant;
            }
            else{
                ant->Dirt = novo;
                (ant->Dirt)->anterior = ant;
            }
        }

        else{
            raiz = novo;
        }
        n++;
        return true;
    }

};


#endif //ARVORE_BINARIA_DE_BUSCAA_ARVOVE_HPP
