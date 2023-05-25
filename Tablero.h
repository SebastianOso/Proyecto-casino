#ifndef TABLERO
#define TABLERO
#include <iostream>
#include "Juego.h"
#include "Tablero.h"
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
#endif