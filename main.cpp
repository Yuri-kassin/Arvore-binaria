#include <iostream>
#include "Arvove.hpp"
#include "No.hpp"
using namespace std;

int main() {
    Arvove <int> x;
//    puts("0");
    x.insere(20);
//    puts("1");
    x.insere(30);
//    puts("2");
    x.insere(10);
//    puts("3");
    x.insere(25);
    x.insere(24);
    x.insere(26);
    x.insere(6);
    x.erd();


    x.remove(3); //caso o numero nao existe
    x.remove(6); // caso q o numero existe
    cout<<endl;
    x.edr();

    cout<<endl;
    cout<<x.busca(25)->getValor()<<endl;
    return 0;
}