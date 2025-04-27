#include "../head/GameState.h"

#include "../head/AI_game.h"
#include "../head/competition.h"

#include <stdio.h>
#include <stdlib.h>

void GP4_b_competition(GameState* state, int IA_1, int IA_2, int nbr_de_parties){
    
    long int victoires[] = {0,0} ;
    int vainqueur = 0 ;
    
    for (int i = 0 ; i < nbr_de_parties ; i++){
        if (i > 0){
            fill_map(state) ;
        }

        vainqueur = GP4_b_AI_game(state, IA_1, IA_2) ;
        victoires[vainqueur - 1]++ ;
    }

    printf("Nombre de victoires du joueur 1 = %ld\t Soit %f %% de victoires\n", victoires[0], (float) victoires[0]/nbr_de_parties *100) ;
    printf("Nombre de victoires du joueur 2 = %ld\t Soit %f %% de victoires\n", victoires[1], 100 - (float) victoires[0]/nbr_de_parties*100) ;
}