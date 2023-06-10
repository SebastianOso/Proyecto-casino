#ifndef RULETA_H
#define RULETA_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Juego.h"
using namespace std;

class Ruleta:public Juego{ //aqui se ve que hereda las cosas de la superclase Juego
    private:
      int numero;
      double multiplicador;
        

    public:
        Ruleta(); 
        Ruleta(int,double,Jugador,Dealer);//poner constructor
        void imprimirTablero();
        string jugando();
        float pagarapuesta(double, int)override;//**aqui se hacer el override del metodo de la clase abstracta 
        int getNumero();
        double getMultiplicador();
        void setNumero(int);
        void setMultiplicador(double);

};

Ruleta :: Ruleta(){
    ///
}

Ruleta :: Ruleta(int _num,double multi,Jugador jugi,Dealer deal):Juego("Ruleta", deal, jugi){ //se usa la herencia de manera correcta
    ///
}



void Ruleta :: imprimirTablero(){
    cout << "Mesa de la ruleta" << std::endl
         << "-------------------------------------------------------------" << endl
         << "   | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |" << endl
         << " 0 | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |" << endl
         << "   | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 |" << endl
         << "-------------------------------------------------------------" << endl;
    
}

string Ruleta::jugando(){
  return "Estas jugando Ruleta";
}

float Ruleta :: pagarapuesta(double multabl, int apue){
    return (multabl*apue);
}

int Ruleta :: getNumero(){
  return numero;
}
double Ruleta :: getMultiplicador(){
  return multiplicador;
}
void Ruleta :: setNumero(int _num){
  numero = _num;
}
void Ruleta :: setMultiplicador(double mult){
  multiplicador = mult;
}

#endif