#include "../head/GameState.h"

#include "../head/Aleatoire.h"

#include <stdlib.h>
#include <time.h>

Color GP4_b_aleatoire(GameState* state, Color player){
    
    int a_cote[7] = {0, 0, 0, 0, 0, 0, 0} ;

    int fait_evoluer = 0 ;
    
    // Repérage des couleurs voisine du territoire du joueur
    for (Color c = 3; c <= 9; c++){
    
        for(int i = 0; i < state -> size ; i++){
            for (int j = 0; j < state -> size; j++){
                if (get_map_value(state, i , j) == c){
                    if (j-1 >= 0){
                        if (get_map_value(state, i, j-1) == player){
                            fait_evoluer = 1 ;
                            i = state->size ;  // interruption de la boucle
                            j = state->size ;
                        }
                    }
                    if (i-1 >= 0){
                        if (get_map_value(state, i-1, j) == player){
                            fait_evoluer = 1 ;
                            i = state->size ;  // interruption de la boucle
                            j = state->size ;
                        }
                    }
                    if (j+1 <  state -> size){
                        if (get_map_value(state, i, j+1) == player){
                            fait_evoluer = 1 ;
                            i = state->size ;  // interruption de la boucle
                            j = state->size ;
                        }
                    }
                    if (i+1 < state -> size){
                        if (get_map_value(state, i+1, j) == player){
                            fait_evoluer = 1 ;
                            i = state->size ;  // interruption de la boucle
                            j = state->size ;
                        }
                    }
                }
            }
        }

        if(fait_evoluer == 1){
            a_cote[c-3] = 1 ;
        }
        fait_evoluer = 0 ;
    }

    static int m = 0 ;
    m++ ;

    // POUR NE PAS QUE LE NOMBRE DE TIRAGE EXPLOSE
    if (m >= 50){
        m = 1 ;
    }

    Color coup ;

    srand(time(NULL)) ;
    for (int i = 0 ; i < m ; i++){
        coup  = 3 + rand()%7 ;
    }

    //On tire une couleur au hazard en s'assurant tout d'abord que le territoire du joueur est en contact avec au moins une couleur 

    if (a_cote[0] != 0 || a_cote[1] != 0 || a_cote[2] != 0 || a_cote[3] != 0 || a_cote[4] != 0 || a_cote[5] != 0 || a_cote[6] != 0 ){
        
        // Tirage tant que l'on a pas choisi une couleur qui ferait évoluer le territoir du joueur
        while(a_cote[coup - 3] == 0){
            m++ ;
            coup  = 3 + rand()%7 ;
        }
    }
    
    // Si le territoire du joueur est encerclé par celui de l'autre joueur, on resort juste la première couleru tirée au sort

    return coup ;
}