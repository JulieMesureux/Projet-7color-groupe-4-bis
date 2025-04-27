#include "../head/GameState.h"

#include "../head/Affichage.h"
#include "../head/Modif.h"

#include "../head/Play.h"

#include <stdio.h>

void GP4_b_play(GameState* state, Color player, Color coup){
    
    if (coup == EMPTY){ 

        GP4_b_print_state(state) ;

        char Coup ;       // Permet de stoker la lettre correspondant à la couleur que le joueur souhaite annexer
        Color Couleur ;


        printf("Au tour du joueur %d\n", player) ;

        printf("Couleur à annexer ? \t") ;
        scanf(" %c", &Coup) ;   // L'espace avant le scanf est essentiel sinon le joueur 1 n'est pas pris en compte !!!
        printf("\n\n") ;

        if (Coup == 'R' || Coup =='r'){
            Couleur = RED ;
        }
        else if (Coup == 'G'|| Coup =='g'){
            Couleur = GREEN ;
        }
        else if (Coup == 'B'|| Coup =='b'){
            Couleur = BLUE ;
        }
        else if (Coup == 'M'|| Coup =='m'){
            Couleur = MAGENTA ;
        }
        else if (Coup == 'Y'|| Coup =='y'){
            Couleur = YELLOW ;
        }
        else if (Coup == 'C'|| Coup =='c'){
            Couleur = CYAN ;
        }
        else if (Coup == 'W'|| Coup =='w'){
            Couleur = WHITE ;
        }

        //GP4_b_MAJ_plateau_non_opti(state, player, Couleur) ;

        GP4_b_MAJ_plateau_non_opti(state, player , Couleur) ;
    }
    else{
        //printf("Au tour du joueur %d\n\n", player) ;

        GP4_b_MAJ_plateau_non_opti(state, player , coup) ;

        //GP4_b_print_state(state) ;
    }
}