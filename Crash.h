#ifndef CRASH
#define CRASH
#include <iostream>
#include "Juego.h"
#include <vector>
using namespace std;

class Crash:public Juego{
    private:

        string crash_id;
        int multiplicador;
        Jugador jogador;

    public:

        Crash(Jugador j) : Juego("Crash", j){}
        void crearID();
        void crearMultiplicador(string);//recibe el ID 
        int getMultiplicador();
        string getID();
        int pagarapuesta();
    //poner en el costructor solo al jugador porque aqui no necesitas dealer

};
/*
Crash(Jugador j) : Juego("Crash", j){}
*/
void Crash :: crearID(){
    //string IDdeCrash = "un string hexadecimal";
    //crash_id = IDdeCrash
}

void Crash :: crearMultiplicador(string){
    //hacer la operacion de pasar string hexadecimal a decimal
}

string Crash :: getID(){
    return crash_id;
}

int Crash :: getMultiplicador(){
    return multiplicador;
}

int Crash :: pagarapuesta(){

}

#endif