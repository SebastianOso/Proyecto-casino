#ifndef CRASH_H
#define CRASH_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Juego.h"

using namespace std;

class Crash:public Juego{
    private:

        string crash_id;
        int multiplicador;

    public:

        Crash(Jugador);
        string crearID();
        int crearMultiplicador();//recibe el ID 
        int getMultiplicador();
        string getID();
        int pagarapuesta(int,int) override;
    //poner en el costructor solo al jugador porque aqui no necesitas dealer

};

Crash :: Crash(Jugador jugadorsinho) : Juego("Crash", jugadorsinho){
}

// el metodo de crearID y el de crear multiplicador es mas o menos como lo hace el source code
// de la pagina del casino en linea roobet
string Crash :: crearID(){
    
    //se va a hacer un string con las letras(a,b,c,d,e,f) y numeros(del 0 al 9) ya que estos son los
    //caracteres que tienen en hexadecimal 
    
    string strtorand = "abcdef0123456789";
    string inputtohex = ""; //esta vacio este string porque mas adelante se le incluiran 10 caracteres de strtorand
                            //todo esto para que con la funcion sha256 cree un string hexadecimal

    srand((unsigned) time(NULL)); //ayuda a generar un numero random y que no siempre sea el mismo

    for (int i = 1; i <= 64; i++) {
        int random = rand() % 17;
        inputtohex += strtorand[random];
    }
    crash_id = inputtohex;
    inputtohex.clear();//se limpia la variable para que el string quede vacio
    return crash_id;
}

int Crash :: crearMultiplicador(){
    
    if (std::stoi(crash_id, nullptr, 16) % 33 == 0) {
        multiplicador = 1;
        return multiplicador;
    }

    string crashstr = crash_id.substr(0, 13);

    int hfinal = std::stoi(crashstr, nullptr, 16);//despues de que se creo nuestro string hexadecimal
                                                  //lo que sigue es pasarlo de hexadecimal a decimal  
                                                  //y asi es como se obtiene nuestro multiplicador del cohete
    long long e = pow(2, 52);

    double result = ((100.0 * e - hfinal) / (e - hfinal)) / 100.0;

    multiplicador = result;
    return multiplicador;
}

string Crash :: getID(){
    return crash_id;
}

int Crash :: getMultiplicador(){
    return multiplicador;
}

int Crash :: pagarapuesta(int multipliact, int apu){
    return (multipliact*apu);
}
#endif