# Proyecto-casino

## Contexto:
Este programa esta hecho para todos los amantes de las apuestas que deseen jugar en un casino en su computadora sin la necesidad de perder el dinero en la vida real, con los juegos de casino de: ruleta y  el recientemente incluido en el casino online "Crash".

De esta manera el usuario puede aprender a jugar o simplemente pasar el rato jugando los juegos de azar

## Como se va a resolver:
Se va a resolver haciendo una clase padre que se llamará "Juego" y este va a tener atributos como: dealer y jugadores, por lo tanto después de esta clase vamos a tener las clases de "Ruleta" y "crash" que van a heredar los metodos de la clase madre de "Juego", al igual que también se van a hacer uso de composición, creando clases de "Jugador" y tambien se puede hacer agregacion con una clase que se llame "Dealer" esto porque en los juegos se necesita de un jugador pero los juegos de casino no todos necesariamente tienen un dealer, y en general después de esto simplemente en el cpp es hacer un cilo while para jugar y hacer los algoritmos para que el usuario juegue ruleta o crash
