#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Jugador{
    private:
        string nombre;
        float bankroll; // es el dinero total destinado a apostar
    public:
        Jugador();
        Jugador(string,int);
        string getNombre();
        float  getBankroll();
        void setNombre(string nomb);
        void setBankroll(float bank);
        void printInfojugador();
        Jugador operator+(Jugador& jugi1);
        Jugador operator-(Jugador& jugi1);
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

float Jugador :: getBankroll(){
    return bankroll;
}

void Jugador :: setNombre(string nomb){
    nombre = nomb;
}
        
void Jugador :: setBankroll(float bank){
    bankroll = bank;
}
        
void Jugador :: printInfojugador(){
    cout << "Nombre: " << nombre << endl;
    cout << "Dinero en cuenta: " << bankroll << endl<<endl;
}

//aqui esta la sobrecarga de operadores
Jugador Jugador::operator+(Jugador& jugi1){ 
  Jugador j3;
  j3.bankroll=this->bankroll + jugi1.getBankroll();
  return j3;
}

Jugador Jugador::operator-(Jugador& jugi1){
  Jugador j3;
  j3.bankroll=this->bankroll - jugi1.getBankroll();
  return j3;
}


#endif