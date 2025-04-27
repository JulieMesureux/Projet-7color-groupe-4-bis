#include "../head/GameState.h"

#include "../head/Two_players_game.h"

#include"../head/Play.h"
#include "../head/Fin_de_partie.h"

#ifndef COULEUR
#define couleur(param) printf("\033[%sm",param)
#endif

#include <stdio.h>

void GP4_b_two_players_game(GameState* state) {

    Color player = PLAYER_1 ;
    Color vainqueur = EMPTY ;
    
    while(vainqueur == EMPTY){

        GP4_b_play(state, player,EMPTY) ; // Le joueur joue

        vainqueur = GP4_b_fin_de_partie(state,player) ;

        // CHANGEMENT DE JOUEUR

        if (player == PLAYER_1){
            player = PLAYER_2 ;
        }
        else{
            player = PLAYER_1 ;
        }
    }

    couleur("42;1") ;
    printf("\t                           ") ;
    couleur("0") ;
    printf("\n") ;
    couleur("42;1") ;
    printf("\t  Le joueur %d a gagné !!!  ", vainqueur) ;
    couleur("0") ;
    printf("\n") ;
    couleur("42;1") ;
    printf("\t                           ") ;
    couleur("0") ;
     printf("\n\n\n") ;
}