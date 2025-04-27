#include "../head/GameState.h"

#include "../head/Fait_n_importe_quoi.h"

#include <stdlib.h>
#include <stdio.h> 
#include <time.h>


Color GP4_b_fait_n_importe_quoi(GameState* state, Color player){
    
    srand( time( NULL ) );

    static int m = 0 ;
    m++ ;

    // POUR NE PAS QUE LE NOMBRE DE TIRAGE EXPLOSE
    if (m >= 25){
        m = 1 ;
    }

    Color couleur ;

    for (int i = 0 ; i < m ; i++){
        couleur = 3 + rand()%(7) ;
    }

    return couleur ;
}