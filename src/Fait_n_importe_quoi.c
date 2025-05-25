#include "../head/GameState.h"

#include "../head/Fait_n_importe_quoi.h"

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>


Color GP4_b_fait_n_importe_quoi(GameState* state, Color player){
    
    srand( time( NULL ) );

    static int m = 0 ;
    m++ ;
    // ????
    // Le srand est censé être fait une fois pour toutes.
    // Au vu du code, je pense que tu as été inspirée par le code de Gabriel et Julien (le choix de m et le "pour pas que le nombre de tirages explose")
    // dans leur cas, c'est pour la seconde IA qu'ils font cela, car cela évite que le code crash si l'ia n'a pas de coup valide
    // tu peux faire autant de tirages que tu veux
    // et srand, c'est pour donner le premier élément de la suite pseudo aléatoire

    //dans le main : srand(time(NULL));
    //cette fonction : return 3 + rand()%7;
    // RIEN DE PLUS ! ;)
    //si tu initialise srand(time(NULL)) à chaque tirage, il est normal d'avoir plusieurs fois la même valeur (même milliseconde)
    //donc je comprends pourquoi tu changes le nombre de tirages à chaque fois

    // POUR NE PAS QUE LE NOMBRE DE TIRAGE EXPLOSE
    if (m >= 25){
        m = 1 ;
    }

    Color couleur ;

    for (int i = 0 ; i < m ; i++){
        couleur = 3 + rand()%(7) ; // pourquoi faire autants de tirages lorsqu'un seul suffit.
    }

    return couleur ;
}