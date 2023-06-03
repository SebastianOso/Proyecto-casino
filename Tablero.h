#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
using namespace std;

class Tablero{
    private:

        int numero;
        string color;
        int multiplicador;

    public:
        Tablero();
        Tablero(int,string, int);
        int getNumero();
        string getColor();
        int getMultiplicador();
        void setNumero(int);
        void setColor(string);
        void setMultiplicador(int);
        //aqui no se necesita hacer otros metodos solo se necesitan getters y setters y en la clase ruleta
        //se crea el vector de los numeros de la ruleta
};

Tablero :: Tablero(){
    //nose
}

Tablero :: Tablero(int numu,string colo, int multipli){
    numero = numu;
    color = colo;
    multiplicador = multipli;
}

int Tablero :: getNumero(){
    return numero;
}

string Tablero :: getColor(){
    return color;
}

int Tablero :: getMultiplicador(){
    return multiplicador;
}

void Tablero :: setNumero(int nu){
    numero = nu;
}

void Tablero :: setColor(string colo){
    color = colo;
}

void Tablero :: setMultiplicador(int mu){
    multiplicador = mu;
}

#endif
