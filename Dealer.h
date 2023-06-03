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
        string getNombre();
};

Dealer:: Dealer(){
            //poner una lista para que escoja nombres randoms de dfealers
            //siempre se va a usar un dealer con constructor default
            //ya que el usuario no le puede poner nombre al dealer del juego
            vector<string> nombres{"Roberto", "Carlos", "Jorge", "Einstein", "Francisco", "Sebastian"};
            srand((unsigned) time(NULL));
            int number = rand() % 39;
            string nom = nombres[number];
            nombre=nom;
}

string Dealer :: getNombre(){
    return nombre;
}
#endif