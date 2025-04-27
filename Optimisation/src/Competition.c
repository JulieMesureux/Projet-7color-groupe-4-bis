#include "../head/GameState.h"

#include "../head/Listes_chainees.h"

#include "../head/AI_game.h"
#include "../head/competition.h"

#include <stdio.h>
#include <stdlib.h>

void GP4_b_competition(GameState* state, int IA_1, int IA_2, int nbr_de_parties, element** front1, element** front2){

    long int victoires[] = {0,0} ;
    int vainqueur = 0 ;
    
    for (int i = 0 ; i < nbr_de_parties ; i++){
        
        if (i>0){
            // Initialisation d'un nouveau plateau
            fill_map(state) ;

            // Initialisation de nouvelle liste de frontières

            GP4_b_supprime_liste(front1) ;
            GP4_b_supprime_liste(front2) ;

            GP4_b_insert_first(front1, 0, state -> size -1) ;
            GP4_b_insert_first(front2, state -> size -1, 0) ;
        }
        
        vainqueur = GP4_b_AI_game(state, IA_1, IA_2, front1, front2) ;
        victoires[vainqueur - 1]++ ;
    }

    printf("Nombre de victoires du joueur 1 = %ld\t Soit %f %% de victoires\n", victoires[0], (float) victoires[0]/nbr_de_parties *100) ;
    printf("Nombre de victoires du joueur 2 = %ld\t Soit %f %% de victoires\n", victoires[1], 100 - (float) victoires[0]/nbr_de_parties*100) ;
}