#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Jugador{
    private:
        string nombre;
        int bankroll; // es el dinero total destinado a apostar
    public:
        Jugador();
        Jugador(string,int);
        string getNombre();
        int getBankroll();
        void setNombre(string nomb);
        void setBankroll(int bank);
        int restarapuesta(int); //actualiza el bankroll dependiendo de cuanto aposto
        void printInfojugador();
        //no se necesita el getDealer ni el getJugador ya que pienso que no es necesario para 
};

Jugador :: Jugador(){
    nombre = "";
    bankroll = 0;
}

Jugador :: Jugador(string nomc,int bankc){
    nombre = nomc;
    bankroll = bankc;
}

string Jugador :: getNombre(){
    return nombre;
}

int Jugador :: getBankroll(){
    return bankroll;
}

void Jugador :: setNombre(string nomb){
    nombre = nomb;
}
        
void Jugador :: setBankroll(int bank){
    bankroll = bank;
}

int Jugador :: restarapuesta(int apo){
    bankroll = bankroll-apo;
    return bankroll;
}
        
void Jugador :: printInfojugador(){
    cout << "Nombre: " << nombre << endl;
    cout << "Dinero en cuenta: " << bankroll << endl;
}

#endif