#ifndef JUEGO
#define JUEGO
#include <iostream>
#include <string>
#include <vector>
#include "Dealer.h"
#include "Jugador.h"
using namespace std;


class Juego{
    private:
        string nombre;
        Dealer dealer;
        Jugador jugador;
    public:
        Juego();
        Juego(string nombr,Jugador jugad);
        Juego(string, Dealer, Jugador);
        //no se necesita el getDealer ni el getJugador ya que pienso que no es necesario para el juego pero
        //por si acaso los pongo
        string getNombre();
        Dealer getDealer();
        Jugador getJugador();
        void setDealer(Dealer);
        void setJugador(Jugador);
        void setNombre(string);
        virtual int pagarapuesta();
};

Juego :: Juego(){
    Jugador jogi;
    Dealer deale;
    jugador = jogi;
    dealer = deale;
}

Juego :: Juego(string nombr,Jugador jugad){
    nombre = nombr;
    jugador = jugad;
}

Juego :: Juego(string nombr, Dealer deal, Jugador jugad){
    nombre = nombr;
    dealer = deal;
    jugador = jugad;
}

string Juego :: getNombre(){
    return nombre;
}

Dealer Juego :: getDealer(){
    return dealer;
}
        
Jugador Juego ::getJugador(){
    return jugador;
}

void Juego ::setDealer(Dealer deal){
    dealer = deal;
}
        
void Juego ::setJugador(Jugador juga){
    jugador = juga;
}

void Juego ::setNombre(string nom){
    nombre = nom;
}

#endif