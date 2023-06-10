#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <string>
#include <vector>
#include "Dealer.h"
#include "Jugador.h"
using namespace std;


class Juego{
    protected:
        string nombre;
        Dealer dealer;
        Jugador jugador;

    public:
        Juego();
        Juego(string,Jugador);//constructor de  la clase juego que se va a usar en Crash ya que ese juego no tiene dealer
        Juego(string, Dealer, Jugador);//constructor de la clase juego que se va a usar en el juego de la ruleta
        //no se necesita el getDealer ni el getJugador ya que pienso que no es necesario para el juego pero
        //por si acaso los pongo
        string jugando();
        string getNombre();
        Dealer getDealer();
        Jugador getJugador();
        void setDealer(Dealer);
        void setJugador(Jugador);
        void setNombre(string);
        virtual float pagarapuesta(double,int)=0;
};

Juego :: Juego(){
    Jugador jogi;
    Dealer deale;
    nombre = " ";
    jugador = jogi;
    dealer = deale;
}

Juego :: Juego(string nombr,Jugador jugad){
    nombre = nombr;
    jugador = jugad;
}

Juego :: Juego(string nombru, Dealer deale, Jugador jugadu){
    nombre = nombru;
    dealer = deale;
    jugador = jugadu;
}

string Juego ::jugando(){
    return "Estas Jugando";
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

void Juego ::setNombre(string nomb){
    nombre = nomb;
}

#endif