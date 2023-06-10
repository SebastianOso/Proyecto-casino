#include "Crash.h"
#include "Dealer.h"
#include "Jugador.h"
#include "Ruleta.h"
#include <iostream>
using namespace std;

int main() {
     
     //mensaje de bienvenida
     cout << "Bienvenido al casino 'Aurora' donde tenemos el clasico juego"
          << endl
          << "de la Ruleta al igual que tenemos el reciente juego de Crash,"
          << endl
          << "sientase libre de jugar el juego que quiera" << endl
          << "y a apostar el dinero con el que se sienta comodo" << endl
          << "Asi que empecemos" << endl
          << endl;

     //input de usuario para ver como se llama
     string nombrejug;
     cout << "Como te llamas? ";
     cin >> nombrejug;

     //input de usuario para saber cuanto dinero va a apostar 
     int bankrol;
     cout << "Cuanto dinero quieres meter para mas adelante apostar? ";
     cin >> bankrol;

     Jugador jogador1(nombrejug, bankrol);
     vector<string> nombres{"Roberto",  "Carlos",    "Jorge",
                              "Einstein", "Francisco", "Sebastian"};
     srand((unsigned)time(NULL));
     int number = rand() % 7;
     string nombru = nombres[number];

     Dealer dealer1(nombru);

     int ciclo = 1;
     while (ciclo == 1) {

          //aqui se presenta polimorfismo y la sobrecarga en el caso del constructor de los 
          //juegos ya que crash no requiere un dealer por lo que crash solo necesita al jugador
          //para ponerlo en el constructor del juego.

          vector<Juego *> juego = {new Crash(jogador1),
                                   new Ruleta(0, 35, jogador1, dealer1)};

          // opciones del menu
          int opcion;
          cout << "Que quieres jugar?" << endl
               << "1.- Crash" << endl
               << "2.- Ruleta" << endl
               << "3.- Salir" << endl
               << "Escoja un numero" << endl;
          cin >> opcion;

          // dependiendo de que escogio el usuario suceden diferentes cases
          switch (opcion) {

               case 1: {

                    int opcioncrash = 1;
                    while (opcioncrash == 1) {

                         if (Crash *crashObj = dynamic_cast<Crash *>(juego[0])) {
                              cout << crashObj->jugando()<< endl;//aqui se hace uso de sobreescritura de metodos
                         }


                         cout << "Este es el juego de Crash el cual consiste en que apuestas"<< endl
                              << "una cantidad de dinero y hay un multiplicador que va a aumentar su valor." << endl
                              << "El objetivo de este juego es" << endl
                              << "retirar tus ganancias antes de que choque la nave " << endl;

                         // el jugador aposto 9000
                         jogador1.printInfojugador();
                         vector<string> nombres{"Roberto",  "Carlos",    "Jorge",
                                                  "Einstein", "Francisco", "Sebastian"};
                         srand((unsigned)time(NULL));
                         int number = rand() % 7;
                         string nombru2 = nombres[number];

                         float bankrollactual = jogador1.getBankroll();
                         int apuestacrash;
                         cout << "Cuanto quieres apostar(numero entero)?: ";
                         cin >> apuestacrash;
                         cout << "Apostaste: " << apuestacrash << endl;
                         if (apuestacrash > bankrollactual){
                              cout << "No tienes dinero suficiente para apostar esa cantidad";
                              goto exit_loop;
                         }
                         bankrollactual -= apuestacrash;
                         jogador1.setBankroll(bankrollactual);

                         jogador1.printInfojugador();

                         double multiplifinal = 0.0;
                         if (Crash *crashObj = dynamic_cast<Crash *>(juego[0])) {
                              multiplifinal = crashObj->crearMultiplicador();
                         }

                         double multiplicadorActual = .9;

                         char resp;
                         resp = '\0';

                         while (true) {

                              if (multiplifinal == 1) {
                                   cout << "**Kabooom** Exploto la nave al arrancarla, pierdes tu dinero :( *musica triste*" << endl << endl;
                                   jogador1.printInfojugador();
                                   break;
                              }

                              if (multiplicadorActual >= multiplifinal) {
                                   cout << "**Kabooom** Choco la nave perdiste, te pasaste del multiplicador *musica triste*" << endl;
                                   //aqui se hace la sobrecarga de operadores para asi crear un nuevo jugador 
                                   //que en este caso gano más dinero que tu porque perdiste para hacer sentir mal
                                   Jugador jogadorransum(nombru2,(apuestacrash * multiplicadorActual)+2000);
                                   Jugador resultantesum;
                                   resultantesum = jogador1 + jogadorransum;

                                   cout << "Otro jugador ha ganado: " << resultantesum.getBankroll() << endl;
                         
                                   jogador1.printInfojugador();
                                   break;
                              }

                              if (resp == 's') {
                                   float pagar = 0.0;
                                   if (Crash *crashObj = dynamic_cast<Crash *>(juego[0])) {
                                        //aqui se hace sobre-escritura de metodos
                                        pagar = crashObj->pagarapuesta(multiplicadorActual, apuestacrash);
                                   }

                                   cout << "Ganaste: " << pagar << endl << endl;
                                   bankrollactual = bankrollactual + pagar;
                                   jogador1.setBankroll(bankrollactual);

                                   //aqui se hace la sobrecarga de operadores para asi crear un nuevo jugador 
                                   //que en este caso perdio más dinero que tu porque ganaste para hacerte sentir bien

                                   Jugador jogadorranres(nombru2,(apuestacrash * multiplicadorActual));
                                   Jugador resultanteres;
                                   resultanteres = jogador1 - jogadorranres;
                                   
                                   jogador1.printInfojugador();
                                   cout << "Otro jugador perdio: " << resultanteres.getBankroll() << endl;
                                   break;
                              }

                              multiplicadorActual += 0.1;

                              cout
                              << "                     `. ___" << endl
                              << "                    __,' __`.                _..----....____" << endl
                              << "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'" << endl
                              << "  _..-''-------'   `'   `'   `'       ``-''._   (,;') _,'/" << endl
                              << ",'________________                          `-._`-','" << endl
                              << " `._              ```````````------...___   '-.._'-:" << endl
                              << "    ```--.._      ,.                     ````--...__ -." << endl
                              << "            `.--. `-`                       ____    |  |`" << endl
                              << "              `. `.                       ,'`````.  ;  ;`" << endl
                              << "                `._`.        __________   `.      \\'__/`" << endl
                              << "                   `-:._____/______/___/____`.     \\  `" << endl
                              << "                               |       `._    `.    \\" << endl
                              << "                               `._________`-.   `.   `.___" << endl
                              << "                                                  `------'`" << endl;

                              cout << "Multiplicador actual: " << multiplicadorActual << endl;

                              cout << "Ganancia actual: " << apuestacrash * multiplicadorActual
                                   << endl;

                              cout << "Escribe 's' para parar el multiplicador" << endl
                                   << "o escribe otra letra para sumarle 0.1 al multiplicador: "
                                   << endl;
                              cin >> resp;
                         }

                         int seguircrash;
                         cout << "Desea seguir jugando crash?" << endl
                              << "1-Si" << endl
                              << "2-No" << endl
                              << "Escoja un numero" << endl;
                         cin >> seguircrash;

                         if (seguircrash == 1) {
                              continue;
                         }

                         if (seguircrash == 2) {
                              opcioncrash = 2;
                              break;
                         }
                    }

                    break;
               }

                    // en los demás cases se repite lo que paso en el case 1 pero con las
                    // clases de Helado_bote y Paleta

               case 2: {

                    // suponiendo que el usuario le salio el numero 17 e igual posto por ese
                    // numero

                    int opcionruleta = 1;
                    while (opcionruleta == 1) {

                         if (Ruleta *ruletaObj = dynamic_cast<Ruleta *>(juego[1])) {
                              //aqui se implementa la sobreescitura
                              cout << ruletaObj->jugando() << endl;
                         }

                         // el multiplicadro siempre va a ser 35 porque eso paga el numero si le
                         // atinas
                         vector<int> numsruleta = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
                                                  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                                                  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                                                  30, 31, 32, 33, 34, 35, 36};
                         float bankrollactual_r = jogador1.getBankroll();

                         //se hace el uso de la herencia de metodos para saber con que dealer esta el obeto de Ruleta
                         Dealer crupier=juego[1]->getDealer(); 

                         cout << "Hola soy: " << crupier.getNombre() << " y hoy sere tu crupier"
                              << endl;

                         if (Ruleta *ruletaObj = dynamic_cast<Ruleta *>(juego[1])) {
                              ruletaObj->imprimirTablero();
                         }
                         // crear numero random que para ponerselo al objeto ruleta
                         srand((unsigned)time(NULL));
                         int numrandomr = rand() % 39; // porque el tablero tiene 36 numeros + el 0 y el 00
                         int numeroruleta = numsruleta[numrandomr];
                         if (Ruleta *ruletaObj = dynamic_cast<Ruleta *>(juego[1])) {
                              ruletaObj->setNumero(numeroruleta);
                         }

                         int num = 0;
                         if (Ruleta *ruletaObj = dynamic_cast<Ruleta *>(juego[1])) {
                              num = ruletaObj->getNumero();
                         }       


                         double multapuesta = 0.0;
                         if (Ruleta *ruletaObj = dynamic_cast<Ruleta *>(juego[1])) {
                              ruletaObj->setMultiplicador(35);
                         }
                         if (Ruleta *ruletaObj = dynamic_cast<Ruleta *>(juego[1])) {
                              multapuesta = ruletaObj->getMultiplicador();
                         }
                         // el numero de multiplicador siempre va a ser 35

                         //input de a que numero le va  apostar
                         int numeroapostar;
                         cout << dealer1.getNombre() << ":A que numero le quieres apostar(solo uno): ";
                         cin >> numeroapostar;
                         cout << dealer1.getNombre() << ": Usted escogio el numero: " << numeroapostar << endl;

                         //input de cuanto le va a apostar a ese numero
                         float apuestaruleta;
                         cout << dealer1.getNombre()
                              << ": Cuanto dinero$ le quieres apostar a ese numero: ";
                         cin >> apuestaruleta;
                         cout << "Apostaste : " << apuestaruleta << endl << endl;
                         if (apuestaruleta > bankrollactual_r){
                              cout << "No tienes dinero suficiente para apostar esa cantidad";
                              goto exit_loop;
                         }

                         bankrollactual_r -= apuestaruleta;
                         jogador1.setBankroll(bankrollactual_r);

                         jogador1.printInfojugador();

                         cout << dealer1.getNombre() << ": Salio el numero: " << num
                              << endl;

                         if (numeroapostar == num) {

                              float pagar_r = 0.0;
                              if (Ruleta *rulObj = dynamic_cast<Ruleta *>(juego[1])) {
                                   pagar_r = rulObj->pagarapuesta(multapuesta, apuestaruleta);//aqui se hce sobreescritura de metodos
                              }

                              cout << "Ganaste: " << pagar_r << endl << endl;
                              bankrollactual_r = bankrollactual_r + pagar_r;
                              jogador1.setBankroll(bankrollactual_r);

                         } else {

                              cout << "No salio el numero apostado. Perdiste tu lana :(" << endl
                                   << endl;
                              jogador1.printInfojugador();
                         }

                         int seguirruleta;
                         cout << "Desea seguir jugando Ruleta?" << endl
                              << "1-Si" << endl
                              << "2-No" << endl
                              << "Escoja un número" << endl;
                         cin >> seguirruleta;

                         if (seguirruleta == 1) {
                              continue;
                         }
                         if (seguirruleta == 2) {
                              opcionruleta = 2;
                              break;
                         }
                    }
                    break;
               }

               case 3: {
                    cout << "Nos vemos pronto" << endl;    
                    goto exit_loop;
               }

               default:{
                    cout << "Pon un input valido" << endl;
                    // code to execute if opcion is not 1, 2, or 3
                    break;
               }
          }

          int seguir;
          cout << "Desea jugar otro juego?" << endl
               << "1-Si" << endl
               << "2-No" << endl
               << "Escoja un numero" << endl;
          cin >> seguir;

          switch (seguir) {
          case 1: {
               continue;
          }

          case 2: {
               cout << "Nos vemos pronto" << endl;
               jogador1.printInfojugador();
               goto exit_loop;
               break;
          }

          default: {
               cout << "Nos vemos pronto" << endl;
               jogador1.printInfojugador();
               ciclo = 2;
               break;
          }
          }
     }
     exit_loop: ;
     return 0;
}

