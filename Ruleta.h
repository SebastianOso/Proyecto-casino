#ifndef RULETA
#define RULETA
#include <iostream>
#include "Juego.h"
#include "Tablero.h"
#include <vector>
using namespace std;

class Ruleta:public Juego{
    private:
        vector <Tablero> tablero;
        Jugador jogo;
    public:
        Ruleta();//en este crear los numeros del tablero con su numero y color al igual que las demas opciones del tablero 
        Ruleta(Jugador j,Dealer d) : Juego("Ruleta", d, j){} //no se necesita poner el vector en el constructor ya que
                                                             //ya se inicializo el vector en los atributos
        void imprimirTablero();
        Tablero getobjetoTablero();
        int pagarapuesta();
    //poner en el costructor solo al jugador porque aqui no necesitas dealer

};

#endif