#include "../head/GameState.h"

#include "../head/One_player_game.h"

#include"../head/Play.h"
#include "../head/Fin_de_partie.h"

#include "../head/Play.h"
#include "../head/Fin_de_partie.h"
#include "../head/Fait_n_importe_quoi.h"
#include "../head/Aleatoire.h"
#include "../head/Glouton.h"
#include "../head/Hegemonique.h"
#include "../head/Mixte.h"

#ifndef COULEUR
#define couleur(param) printf("\033[%sm",param)
#endif

#include <stdio.h>

void GP4_b_one_player_game(GameState* state, int AI) {

    Color player = PLAYER_1 ;
    Color vainqueur = EMPTY ;
    Color coup;
    
    while(vainqueur == EMPTY){
        
        if (player == PLAYER_1){
            GP4_b_play(state, player,EMPTY) ; // Le joueur réel joue
        }

        else{    // L'IA joue

            if (AI == 0){
                coup = GP4_b_fait_n_importe_quoi(state, player) ;
                GP4_b_play(state, player,coup) ;
            }
    
            else if (AI == 1){
                coup = GP4_b_aleatoire(state, player) ;
                GP4_b_play(state, player,coup) ;
            }
    
            else if (AI == 2){
                coup = GP4_b_glouton(state, player) ;
                GP4_b_play(state, player,coup) ;
            }
    
            else if (AI == 3){
                coup = GP4_b_hegemonique(state, player) ;
                GP4_b_play(state, player,coup) ;
            }
    
            else if (AI == 4){
                coup = GP4_b_mixte(state, player) ;
                GP4_b_play(state, player,coup) ;
            }
        }

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