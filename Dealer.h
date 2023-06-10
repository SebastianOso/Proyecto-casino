#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Dealer{
    private:
        string nombre;
    public:
        Dealer();
        Dealer(string);
        string getNombre();
};

Dealer:: Dealer(){
    //////
}

Dealer:: Dealer(string nom){
            nombre=nom;
}

string Dealer :: getNombre(){
    return nombre;
}
#endif