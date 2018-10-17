//
// Created by yoru on 14/09/18.
//

#ifndef ARVORE_BINARIA_DE_BUSCAA_NO_HPP
#define ARVORE_BINARIA_DE_BUSCAA_NO_HPP
using namespace std;
template <typename T>
class Arvove;

template <typename T>
class No {
private:
    T valor;
    No<T>* anterior;
    No<T>* Esqr;
    No<T>*Dirt;
    No(T Valor): valor(Valor), Esqr(nullptr),Dirt(nullptr),anterior(nullptr){
    }
public:
    T getValor(){
        return valor;
    }

    T operator*(){
        return getValor();
    }

    friend class Arvove<T>;
};


#endif //ARVORE_BINARIA_DE_BUSCAA_NO_HPP