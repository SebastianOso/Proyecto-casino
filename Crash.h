#ifndef CRASH_H
#define CRASH_H
#include "Juego.h" 
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

class Crash : public Juego {
private:

  int multiplicador;

public:
  Crash(Jugador);
  double crearMultiplicador(); // recibe el ID
  double getMultiplicador();
  float pagarapuesta(double, int) override;
  string jugando();
  // poner en el costructor solo al jugador porque aqui no necesitas dealer
};

Crash ::Crash(Jugador jugadorsinho) : Juego("Crash", jugadorsinho) { 
  //se usa la herencia de manera correcta y sobrecarga de operadore
  ///
}


double Crash ::crearMultiplicador() {//es practicamente un setter pero a la vez no
  //Referencia:
  //Este codigo fue recuperado de: https://stackoverflow.com/questions/19652657/c-create-a-random-decimal-between-0-1-and-10
  //y se cambiaron 2 cosas pero la mayoria de esta funcion esta basada en ese articulo
  random_device rd;
  mt19937 gen(rd());

  //rango de valores minimos y maximos se excluyen al final
  double min = .99;
  double max = 10.1;

  uniform_real_distribution<double> dis(min, max);

  //se crea un numero decimal random
  double randomDecimal = dis(gen);
  //aqui se redondea el numero decimal
  randomDecimal = floor(randomDecimal * 10.0) / 10.0;

  return randomDecimal;
}


double Crash ::getMultiplicador() { 
  return multiplicador; 
}

float Crash ::pagarapuesta(double multipliact, int apu) {
  return (multipliact * apu);
}

string Crash::jugando(){
  return "Estas jugando Crash";
}

#endif