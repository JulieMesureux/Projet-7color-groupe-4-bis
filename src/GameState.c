#include "../head/GameState.h"

#include "../head/AI_game.h"
#include"../head/Two_players_game.h"
#include"../head/One_player_game.h"
#include"../head/AI_game.h"
#include"../head/competition.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>   //Permet d'utiliser une fonction de génération aléatoire de nombre


GameState state = {.map = NULL, .size = 0} ; //Initialisation de la structure contenant le pointeur vers le plateau de jeu et de sa taille

// Cette fonction a pour objectif d'allouer dans la heap la place pour notre plateau de jeu //

void create_empty_game_state (GameState* state, int size){

	Color* map ;
	map = malloc(sizeof(Color) * size * size) ;  // Allocation d'un espace de taille size*size pour des entiers
	state -> map = map ;                         // On enregistre l'adresse du plateau créé
	state -> size = size ;                       // On met a jour la taille du plateau
}


// Cette fonction assigne une couleur donnée à la case donnée //

void set_map_value (GameState* state, int x, int y, Color value){ 

	int* plateau = state -> map ;
	int size = state -> size ;
	plateau[ x + y * size] = value ;    // On ne stock pas vraiment la couleur mais l'entier associé
}                                       // L'indice de la case sur le plateau est égal a x + y*size


// Cette fonction retourne la couleur de la case (x,y) //

Color get_map_value (GameState* state, int x, int y){

	if (state -> map == NULL || x > state -> size || y > state -> size || x < 0 || y < 0)
	{
		printf("[ERROR] map not big enough or not initialized %p %i access (%i %i)", state -> map, state -> size, x, y);
		return ERROR;
	}
	return state -> map[y * state -> size + x];
}


// Cette fonction remplie le plateau de jeu et place les joueurs //

void fill_map(GameState* map){

    srand( time( NULL ) );

	for (int x = 0; x < map -> size ; x++){
		for (int y = 0; y < map -> size ; y++){
			Color couleur = 3 + rand()%(7) ;     // Permet de générer une valeur aléatoire entre 3 et 9 correspondant aux couleurs
			set_map_value(map, x, y, couleur) ;  // Assigne la valeur générée à la case (x, y)
		}
	}

	set_map_value(map, 0, map -> size - 1, PLAYER_1) ;    // Mise en place du joueur 1
	set_map_value(map, map -> size - 1, 0, PLAYER_2) ;    // Mise en place du joueur 2
}


////////////////////////////////
///    DEBUT DE LA PARTIE    ///
////////////////////////////////

int main(int argc, char** argv){

	// L'appel de 7color est ./7color "taille du plateau" "Nombre de joueur" "Type de L'IA n°1 (pour 1 ou 0 joueur)" "Type de l'IA n°2 (pour 0 joueur)" "Nombre d'affrontements (dans le cas d'une compétition entre IA)"

	int size = 0 ;

	// TAILLE DU PLATEAU DE JEU

	if (argc == 1){  // Si la taille du plateau n'est pas précisée
		printf("Taille de la map ? \t") ;
		scanf(" %d", &size) ;
		printf("\n\n") ;
	}
	else {           // Si la taille du plateau est précisée    
		char* s_size = argv[1] ;
		sscanf(s_size, "%d",&size) ;
	}

	// CREATION DU PLATEAU DE JEU

	create_empty_game_state(&state, size) ;
	fill_map (&state) ;

	// MODE DE JEU

	int nbr_joueur = -1;

	if (argc <= 2){  // Le nombre de joueur n'est pas précisé

		printf("Nombre de joueurs ?\t") ;
		scanf(" %d", &nbr_joueur) ;
		printf("\n\n") ;
	}

	if(argc > 2){
		char* s_nbr_joueur = argv[2] ;
		sscanf(s_nbr_joueur, "%d", &nbr_joueur) ;
	}

	if  (nbr_joueur == 2){    // Partie classique à deux joueurs
		GP4_b_two_players_game(&state) ;
	}
	
	else if (nbr_joueur == 1){ // Partie contre une IA

		int IA ;

		if (argc == 3){  // On n'a pas précisé l'IA
			printf("CONTRE QUI VOULAIT VOUS JOUER ?\n \tFait n'importe quoi = 0\n \tAléatoire = 1\n \tGlouton = 2\n \tHégémoqique = 3\n \tMixte = 4\n\n") ;

			printf("IA n° ") ;
			scanf(" %d", &IA) ;
			printf("\n") ;
			
			GP4_b_one_player_game(&state, IA) ;
		}

		else if (argc == 4){ // On a précisé l'IA
			char* s_IA= argv[3] ;
			sscanf(s_IA, "%d", &IA) ;

			GP4_b_one_player_game(&state, IA) ;
		}
	}

	else if (nbr_joueur == 0){ // Faire s'affronter les IA

		int IA_1 ;
		int IA_2 ;

		if (argc == 3 || argc == 4){  // On n'a pas précisé les deux IA

			printf("QUELLES IA DOIVENT JOUER ?\n \tFait n'importe quoi = 0\n \tAléatoire = 1\n \tGlouton = 2\n \tHégémoqique = 3\n \tMixte = 4\n\n") ;

			printf("IA n° 1 = ") ; 
			scanf(" %d", &IA_1) ;
			printf("\n") ;
			printf("IA n° 2 = ") ; 
			scanf(" %d", &IA_2) ;
			printf("\n") ;

			GP4_b_AI_game(&state, IA_1, IA_2) ;
		}

		else if (argc == 5){
			char* s_IA_1 = argv[3] ;
			char* s_IA_2 = argv[4] ;

			sscanf(s_IA_1, "%d", &IA_1) ;
			sscanf(s_IA_2, "%d", &IA_2) ;

			GP4_b_AI_game(&state, IA_1, IA_2) ;
		}

		else if (argc == 6) { // COMPETITION ENTRE DEUX IA
			char* s_IA_1 = argv[3] ;
			char* s_IA_2 = argv[4] ;

			sscanf(s_IA_1, "%d", &IA_1) ;
			sscanf(s_IA_2, "%d", &IA_2) ;

			int nbr_parties ;

			char* s_nbr_parties = argv[5] ;

			sscanf(s_nbr_parties, "%d", &nbr_parties) ;

			GP4_b_competition(&state, IA_1, IA_2, nbr_parties) ;
		}
	}

	free(state.map) ;

	state.map = NULL ;
    state.size = 0 ;
}