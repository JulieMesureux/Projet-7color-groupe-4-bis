#include "../head/GameState.h"

#include "../head/Glouton.h"

#include "../head/Modif.h"

#include <stdlib.h>

Color GP4_b_glouton(GameState* state, Color player){

    GameState copy = {.map = NULL, .size = state -> size} ;
    
    int Couleurs[7] = {0, 0, 0, 0, 0, 0, 0} ;
    int cases = 0 ; // Décompte du nombre de case

    create_empty_game_state(&copy, state -> size) ;

    for (int i = 3 ; i <= 9 ; i++){

           // Copie pour ne pas modifier le vrai plateau

        for(int x = 0 ; x < state -> size ; x++){     
            for(int y = 0 ; y < state -> size ; y++){
                set_map_value(&copy, x, y, get_map_value(state, x , y)) ;
            }
        }
         
        cases = 0 ;
        GP4_b_MAJ_plateau_non_opti(&copy, player, i) ; //Modification de la copie

        for(int x = 0 ; x < state -> size ; x++){
            for(int y = 0 ; y < state -> size ; y++){
                if (get_map_value(&copy, x, y) == player ){
                    cases ++ ;
                }
            }
        }

        Couleurs[i-3] = cases ; // Nombres de cases totale du joueur si on joue la couleur i
    }  

    int max = Couleurs[0] ;
    int i_max = 0 ;

    for (int i = 1 ; i < 7 ; i++){
        if (max < Couleurs[i]){
            max = Couleurs[i] ;
            i_max = i ;
        }
    }

    free((&copy) -> map) ;

    return i_max + 3 ;
}