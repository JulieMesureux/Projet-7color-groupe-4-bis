#include "../head/GameState.h"

#include "../head/Hegemonique.h"

#include "../head/Modif.h"

#include <stdio.h>
#include <stdlib.h>

Color GP4_b_hegemonique(GameState* state, Color player){

    int frontiere[] = {0, 0, 0, 0, 0, 0, 0} ; // Nombre de cases à la frontière pour chaque couleur
    int est_une_frontiere = 0 ;
    int nbr_frontiere ;
    Color couleur ;
    
    // Création d'une copy du plateau qui pourra être modifiée
    GameState copy = {.size = state -> size, .map = NULL} ;
    create_empty_game_state(&copy, (&copy) -> size) ;

    // Decompte de l'évolutions des frontières pour chaque couleur
    for (int c = 3 ; c < 10 ; c++){

        nbr_frontiere = 0;

        // Initialisation de la copy
        for (int x = 0 ; x < state -> size ; x++){
            for (int y = 0 ; y < state -> size ; y++){
                set_map_value(&copy, x, y, get_map_value(state, x, y)) ;
            }
        }

        // Coup fictif du joueur
        GP4_b_MAJ_plateau_non_opti(&copy, player, c) ;

        // Decompte du nombre de case à la frontière après modifications
        for (int x = 0 ; x < (&copy) -> size ; x++){
            for (int y = 0 ; y < (&copy) -> size ; y++){

                est_une_frontiere = 0 ;

                if (get_map_value(&copy, x, y) == player){
                    if ( x-1 >= 0){
                        couleur = get_map_value(&copy, x-1, y) ;
                        if (couleur > 2){
                            est_une_frontiere = 1 ;
                        }
                    }
                    if ( y-1 >= 0 ){
                        couleur = get_map_value(&copy, x, y-1) ;
                        if (couleur > 2 ){
                            est_une_frontiere = 1 ;
                        }
                    }
                    if ( x+1 < (&copy) -> size) {
                        couleur = get_map_value(&copy, x+1, y) ;
                        if(couleur > 2 ) {
                            est_une_frontiere = 1 ;
                        }
                    }
                    if ( y+1 < (&copy) -> size) {
                        couleur = get_map_value(&copy, x, y+1) ;
                        if (couleur > 2 ) {
                            est_une_frontiere = 1 ;
                        }
                    }
                }

                if (est_une_frontiere == 1 ){
                    nbr_frontiere ++ ;
                }
            }
        }

        frontiere[c-3] = nbr_frontiere ;
    }

    free((&copy) -> map) ;

    // On trouve le max de la liste frontiere

    int max = frontiere[0] ;
    Color c_max = 3;

    for (Color c = 4 ; c <= 9 ; c++){
        if (frontiere[c-3] > max){
            max = frontiere[c-3] ;
            c_max = c ;
        }
    }

    return c_max ;
}