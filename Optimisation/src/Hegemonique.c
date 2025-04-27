#include "../head/GameState.h"

#include "../head/Listes_chainees.h"

#include "../head/Hegemonique.h"

#include "../head/Modif.h"

#include <stdio.h>
#include <stdlib.h>

Color GP4_b_hegemonique(GameState* state, Color player, element* front){

    int frontiere[] = {0, 0, 0, 0, 0, 0, 0} ; // Nombre de cases à la frontière pour chaque couleur
    
    // Création d'une copy du plateau qui pourra être modifiée
    GameState copy = {.size = state -> size, .map = NULL} ;
    create_empty_game_state(&copy, (&copy) -> size) ;

    element* copy_front ;

    // Decompte de l'évolutions des frontières pour chaque couleur
    for (int c = 3 ; c < 10 ; c++){

        // Initialisation de la copie
        for (int x = 0 ; x < state -> size ; x++){
            for (int y = 0 ; y < state -> size ; y++){
                set_map_value(&copy, x, y, get_map_value(state, x, y)) ;
            }
        }

        GP4_b_copy_list(front, &copy_front) ;

        // Coup fictif du joueur
        GP4_b_MAJ_plateau(&copy, player, &copy_front, c) ;

        frontiere[c-3] = GP4_b_len_list(copy_front) ;

        GP4_b_supprime_liste(&copy_front) ;
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