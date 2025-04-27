#include "../head/GameState.h"

#include "../head/Listes_chainees.h"

#include "../head/Modif.h"

#include <stdlib.h>
#include <stdio.h>


// Fait la même chose que get_map_value mais sans afficher de message d'erreur
// Cette fonction est particulièrement utile pour gérer les bords du plateau de jeu lorsqu'on le parcourt

Color GP4_b_return_map_value (GameState* state, int x, int y){

	if (x >= state -> size || y >= state -> size || x < 0 || y < 0)
	{
		return ERROR;
	}
	return state -> map[y * state -> size + x];
}

// Indique si une case (x,y) est à la frontière(1) ou non (0)
int GP4_b_est_une_frontiere(GameState* state, int x, int y){

	// Eléments voisins
	Color gauche = GP4_b_return_map_value(state, x-1, y) ;
	Color droite = GP4_b_return_map_value(state, x+1, y) ;
	Color haut = GP4_b_return_map_value(state, x, y-1) ;
	Color bas = GP4_b_return_map_value(state, x, y+1) ;

	int est_une_front = 0 ;

	if (gauche >= 3){
		est_une_front = 1 ;
	}
	
	if (droite >= 3){
		est_une_front = 1 ;
	}

	if (haut >= 3){
		est_une_front = 1 ;
	}

	if (bas >= 3){
		est_une_front = 1 ;
	}
	
	return est_une_front ;
}

// Mise à jour la liste des frontières
void GP4_b_sup_if_not_front(GameState* state, element** front){

	element* tmp = *front ;
	element* next_tmp = tmp -> next ;
	
	while (next_tmp != NULL){

		// Si l'élément n'est pas une frontière
		if (GP4_b_est_une_frontiere(state, next_tmp -> x, next_tmp -> y) == 0){
			tmp -> next = next_tmp -> next ;
			free(next_tmp) ;
			next_tmp = tmp -> next ;
		}
		else{
			tmp = next_tmp ;
			next_tmp = next_tmp -> next ;
		}
	}

	// Premier élément
	if (GP4_b_est_une_frontiere(state, (*front) -> x, (*front) -> y) == 0){
		GP4_b_supp_first(front) ;
	}
}

// Mise à jour du plateau en s'inspirant du parcourt en profondeur de graph
void GP4_b_MAJ_plateau(GameState* state, Color player , element** front, Color couleur){
	
	// Liste temporaire pour le parcourt
	element* tmp = NULL;
	GP4_b_copy_list(*front,  &tmp) ;
	
	//Parcourt et modifications
	int x ;
	int y ;

	while (tmp != NULL){ // Tant qu'il reste des éléments à parcourir

		// Element regardé et donc supprimé de la liste de parcourt
		x = tmp -> x ;
		y = tmp -> y ;

		GP4_b_supp_first(&tmp) ;
		
		if (GP4_b_return_map_value(state, x-1, y) == couleur){  // A gauche
			set_map_value(state, x-1, y, player) ; // Modification de la case
			// Mémorisation de la case
			GP4_b_insert_first(&tmp, x-1, y) ; // Pour le parcourt
			GP4_b_insert_first(front, x-1, y) ; // Pour les frontières
		}

		if (GP4_b_return_map_value(state, x+1, y) == couleur){  // A droite
			set_map_value(state, x+1, y, player) ; // Modification de la case
			// Mémorisation de la case
			GP4_b_insert_first(&tmp, x+1, y) ; // Pour le parcourt
			GP4_b_insert_first(front, x+1, y) ; // Pour les frontières
		}

		if (GP4_b_return_map_value(state, x, y-1) == couleur){  // En haut
			set_map_value(state, x, y-1, player) ; // Modification de la case
			// Mémorisation de la case
			GP4_b_insert_first(&tmp, x, y-1) ; // Pour le parcourt
			GP4_b_insert_first(front, x, y-1) ; // Pour les frontières
		}

		if (GP4_b_return_map_value(state, x, y+1) == couleur){  // En bas
			set_map_value(state, x, y+1, player) ; // Modification de la case
			// Mémorisation de la case
			GP4_b_insert_first(&tmp, x, y+1) ; // Pour le parcourt
			GP4_b_insert_first(front, x, y+1) ; // Pour les frontières
		}
	}

	// Mise à jour de la liste des éléments de la frontière
	GP4_b_sup_if_not_front(state, front) ;
}

