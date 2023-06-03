#include "Jugador.h"
#include "Crash.h"
#include "Dealer.h"
#include "Tablero.h"
#include "Ruleta.h"
#include <iostream>
using namespace std;


int main(){

    Jugador jogador1("sebastian",9000);
    Crash crash1(jogador1);
    //el jugador aposto 9000
    int apuesta = 9000;

    string id = crash1.crearID();
    int multiplifinal = crash1.crearMultiplicador();

    cout << "El string hexadecimal del crash es: " << crash1.getID() << endl
         << "El multiplicador es: " << crash1.getMultiplicador() << endl
         << "Ganaste " << crash1.pagarapuesta(multiplifinal,apuesta) << endl;

    Dealer dealer;

    Tablero num1(1,"rojo",35);
    Tablero num2(2,"negro",35);
    Tablero num3(3,"rojo",35);
    Tablero num4(4,"negro",35);
    Tablero num5(5,"rojo",35);
    Tablero num6(6,"negro",35);
    Tablero num7(7,"rojo",35);
    Tablero num8(8,"negro",35);
    Tablero num9(9,"rojo",35);
    Tablero num10(10,"negro",35);
    Tablero num11(11,"negro",35);
    Tablero num12(12,"rojo",35);
    Tablero num13(13,"negro",35);
    Tablero num14(14,"rojo",35);
    Tablero num15(15,"negro",35);
    Tablero num16(16,"rojo",35);
    Tablero num17(17,"negro",35);
    Tablero num18(18,"rojo",35);
    Tablero num19(19,"rojo",35);
    Tablero num20(20,"negro",35);
    Tablero num21(21,"rojo",35);
    Tablero num22(22,"negro",35);
    Tablero num23(23,"rojo",35);
    Tablero num24(24,"negro",35);
    Tablero num25(25,"rojo",35);
    Tablero num26(26,"negro",35);
    Tablero num27(27,"rojo",35);
    Tablero num28(28,"negro",35);
    Tablero num29(29,"negro",35);
    Tablero num30(30,"rojo",35);
    Tablero num31(31,"negro",35);
    Tablero num32(32,"rojo",35);
    Tablero num33(33,"negro",35);
    Tablero num34(34,"rojo",35);
    Tablero num35(35,"negro",35);
    Tablero num36(36,"rojo",35);

    vector<Tablero> tabs;
    tabs.push_back(num1);
    tabs.push_back(num2);
    tabs.push_back(num3);
    tabs.push_back(num4);
    tabs.push_back(num5);
    tabs.push_back(num6);
    tabs.push_back(num7);
    tabs.push_back(num8);
    tabs.push_back(num9);
    tabs.push_back(num10);
    tabs.push_back(num11);
    tabs.push_back(num12);
    tabs.push_back(num13);
    tabs.push_back(num14);
    tabs.push_back(num15);
    tabs.push_back(num16);
    tabs.push_back(num17);
    tabs.push_back(num18);
    tabs.push_back(num19);
    tabs.push_back(num20);
    tabs.push_back(num21);
    tabs.push_back(num22);
    tabs.push_back(num23);
    tabs.push_back(num24);
    tabs.push_back(num25);
    tabs.push_back(num26);
    tabs.push_back(num27);
    tabs.push_back(num28);
    tabs.push_back(num29);
    tabs.push_back(num30);
    tabs.push_back(num31);
    tabs.push_back(num32);
    tabs.push_back(num33);
    tabs.push_back(num34);
    tabs.push_back(num35);
    tabs.push_back(num36);

    //suponiendo que el usuario le salio el numero 17 e igual posto por ese numero

    Ruleta ruleta1(jogador1,dealer,tabs);

    int apuestarul = 800;

    ruleta1.imprimirTablero();
    
    int multapuesta = num17.getMultiplicador();


    cout << "El multiplicador es: " << multapuesta << endl
         << "Ganaste " << ruleta1.pagarapuesta(multapuesta,800) << endl;




}