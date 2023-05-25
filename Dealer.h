#ifndef DEALER
#define DEALER
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dealer{
    private:
        string nombre;
    public:
        Dealer();
        string getNombre();
};

Dealer:: Dealer(){
            //poner una lista para que escoja nombres randoms de dfealers
            //siempre se va a usar un dealer con constructor default
}

string Dealer :: getNombre(){
    return nombre;
}
#endif