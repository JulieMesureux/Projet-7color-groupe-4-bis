#include "../head/GameState.h"

#include "../head/Fin_de_partie.h"

#include <stdio.h>

Color GP4_b_fin_de_partie(GameState* state, Color player){

    int size = state -> size ;

    int nbr_case_player = 0 ;  // Total des cases possédées par le joueur
    
    for (int x = 0; x < state -> size; x++){
        for (int y = 0; y < state -> size; y++){
            if (get_map_value(state, x, y) == player ){
                nbr_case_player = nbr_case_player + 1 ;
            }
        }
    }

    // On compare le nombre total de cases du joueur avec la moitié du nombre de cases totales du plateau
    
    if (nbr_case_player >= (float) size*size / 2.0){
        return player ;
    }
    
    return EMPTY ;       // La fonction retourne le vainqueur ou EMPTY s'il n'y en a pas encore
}
