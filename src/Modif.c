#include "../head/GameState.h"

#include "../head/Modif.h"

#include <stdlib.h>
#include <stdio.h>


// Fait la même chose que get_map_value mais sans afficher de message d'erreur
// Cette fonction est particulièrement utile pour gérer les bords du plateau de jeu lorsqu'on le parcour

Color GP4_b_return_map_value (GameState* state, int x, int y){

	if (x >= state -> size || y >= state -> size || x < 0 || y < 0)
	{
		return ERROR;
	}
	return state -> map[y * state -> size + x];
}


void GP4_b_MAJ_plateau_non_opti(GameState* state, Color player , Color couleur){

    int modif = 1 ;

    while (modif != 0){      // Jusqu'a ce qu'il n'y est plus de modification apportée
        modif = 0 ;          // Initialisation du nombre de modifictaion pour ce parcour

        for (int x = 0; x < state -> size; x++){

            for (int y = 0; y < state -> size; y++){

                if (GP4_b_return_map_value(state, x, y) == couleur) {
                // Couleurs correspondantes à celle choisi par le joueur

                    if (GP4_b_return_map_value(state, x-1, y) == player || GP4_b_return_map_value(state, x, y-1) == player || GP4_b_return_map_value(state, x+1, y) == player || GP4_b_return_map_value(state, x, y+1) == player){
                    // Couleur dont le voisin est le joueur, j'utilise get_map_value pour que les bord soit gérés facilement
                        set_map_value(state, x, y, player) ;   // Modification de la valeur de la case conquise par le joueur
                        modif ++ ;                             // Decompte du nombre de modification de ce parcour du plateau
                    }
                }
            }
        }
    } 
}

