#include "../head/GameState.h"

#include "../head/Listes_chainees.h"

#include "../head/Mixte.h"

#include "../head/Modif.h"

#include <stdlib.h>
#include <time.h>


Color GP4_b_mixte(GameState* state, Color player, element* front){

    int frontiere[] = {0, 0, 0, 0, 0, 0, 0} ; // Nombre de cases à la frontière pour chaque couleur
    int nbr_case[] = {0, 0, 0, 0, 0, 0, 0} ;
    
    // Création d'une copy du plateau qui pourra être modifiée
    GameState copy = {.size = state -> size, .map = NULL} ;
    create_empty_game_state(&copy, (&copy) -> size) ;

    element* copy_front ;

    // Nombre de frontières initialement
    int front_i = GP4_b_len_list(front) ;

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

        frontiere[c-3] = GP4_b_len_list(copy_front) - front_i ;

        for (int x = 0 ; x < state -> size ; x++){
            for (int y = 0 ; y < state -> size ; y++){
                if (get_map_value(state, x, y) == x){
                    nbr_case[c-3]++ ;
                }
            }
        }

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

    // Si les frontières n'évoluent pas
    if (max <= 0){
        max = nbr_case[0] ;
        c_max = 3 ;

        for (int c = 4 ; c < 10 ; c++){
            if (max < nbr_case[c-3]){
                max = nbr_case[c-3] ;
                c_max = c ;
            }
        }
    }

    return c_max ;
}