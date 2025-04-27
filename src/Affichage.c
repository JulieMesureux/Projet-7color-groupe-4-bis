#include "../head/GameState.h"

#include "../head/Affichage.h"

#include <stdio.h>

#ifndef COULEUR
#define couleur(param) printf("\033[%sm",param)
#endif

void GP4_b_print_state(GameState* state){
    for (int y = 0; y < state -> size; y++){
        for ( int x = 0; x < state -> size; x++ ){
            Color valeur = get_map_value(state, x, y) ;
            
/////////   CORRESPONDANCE DES POINS A AFFICHER EN FONCTION DE LA VALEUR DE LA CASE   /////////

            if (valeur == PLAYER_1){
                couleur("31;1") ;
                printf(" 1 ") ;
                couleur("0") ;
            }
            else if (valeur == PLAYER_2){
                couleur("34;1") ;
                printf(" 2 ") ;
                couleur("0") ;
            }
            else if (valeur == RED){
                couleur("41") ;
                printf(" R ") ;
                couleur("0") ;
            }
            else if (valeur == GREEN){
                couleur("42") ;
                printf(" G ") ;
                couleur("0") ;
            }
            else if (valeur == BLUE){
                couleur("44") ;
                printf(" B ") ;
                couleur("0") ;
            }
            else if (valeur == MAGENTA){
                couleur("45") ;
                printf(" M ") ;
                couleur("0") ;
            }
            else if (valeur == YELLOW){
                couleur("43") ;
                printf(" Y ") ;
                couleur ("0") ;
            }
            else if (valeur == CYAN){
                couleur("46") ;
                printf(" C ") ;
                couleur("0") ;
            }
            else if (valeur == WHITE){
                couleur("47") ;
                printf(" W ") ;
                couleur("0") ;
            }
        }
        printf("\n") ;
    }

    printf("\n") ;
}