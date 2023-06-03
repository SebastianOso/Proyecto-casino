#ifndef RULETA_H
#define RULETA_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Juego.h"
#include "Tablero.h"
using namespace std;

class Ruleta:public Juego{
    private:
        vector <Tablero> tabiruleta;

    public:
        Ruleta(); 
        Ruleta(Jugador,Dealer,vector <Tablero>);
        void imprimirTablero();

        Tablero getobjetoTablero(){
            srand((unsigned) time(NULL));
            int numero = rand() % 39;//porque el tablero tiene 36 numeros + el 0 y el 00 
            return tabiruleta[numero];
        }

        int pagarapuesta(int, int);
        //poner en el costructor solo al jugador porque aqui no necesitas dealer

};

Ruleta :: Ruleta(){
    ///
}

Ruleta :: Ruleta(Jugador jrul,Dealer del,vector <Tablero> tabl) : Juego("Ruleta", del, jrul){
    tabiruleta = tabl;
}

void Ruleta :: imprimirTablero(){
    cout << "Mesa de la ruleta" << std::endl
         << "-------------------------------------------------------------" << endl
         << " 00| 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |" << endl
         << " 0 | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |" << endl
         << "   | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 |" << endl
         << "-------------------------------------------------------------" << endl;
    
}


int Ruleta :: pagarapuesta(int multabl, int apue){
    return (multabl*apue);
}

#endif