#include "../head/GameState.h"

#include "../head/Listes_chainees.h"

#include <stdlib.h>
#include <stdio.h>

// Ce programme réunit toutes les fonctions permettant de manipuler les listes chaînées

// Ajout d'un élément au début de le liste
void GP4_b_insert_first(element** head, int x, int y){
    // Espace pour le nouvel élément de la liste
    element* Case = malloc(sizeof(element)) ;
    // Ajout du nouvel élément
    Case -> x = x ;
    Case -> y = y ;
    Case -> next = *head ;
    //Changement du pointeur vers le premier élément
    *head = Case ;
}

void GP4_b_supp_first(element** head){
    
    element* suivant ;

    suivant = (*head) -> next ;
    free(*head) ;      // Suppression du premier élément
    *head = suivant ;      // Mise à jour de la tête de liste
}

//Supprime entièrement une liste chaînée
void GP4_b_supprime_liste(element** head){

    while (*head != NULL){ // Tant qu'il reste un élément dans la liste
        GP4_b_supp_first(head) ;  // Suppression du premier élément
    }
}

// Donne le nombre d'élément d'une liste
int GP4_b_len_list(element* head){
    int len = 0 ;
    element* tmp = head ;
    while (tmp != NULL){
        len++ ;
        tmp = tmp -> next ;
    }

    return len ;
}

// Permet d'effectuer une copie d'une liste chaînée
void GP4_b_copy_list(element* head, element** head_copy){

    //Remplissage de la copie
    element* a_copier = head ;
    element* copie = NULL ;
    element* new_element = NULL;
   /* if (a_copier == NULL)
        *head_copy = NULL;*/

    //Copie des éléments un par un jusqu'au dernier
    while (a_copier != NULL){
        if (a_copier == head){ // On est en train de copier le premier element
            copie = malloc(sizeof(element)) ; // Création d'un nouvel element
            
            *head_copy = copie ; // On enregistre la tête de liste de la copie
            
            // Copie de l'élément de la liste
            copie -> x = a_copier -> x ;
            copie -> y = a_copier -> y ;
            copie -> next = NULL ;
        }

        else {
            new_element = malloc(sizeof(element)) ;
            copie -> next = new_element ; // Établissement du lien entre les éléments
            copie = new_element ;

            // Copie de l'élément de la liste
            copie -> x = a_copier -> x ;
            copie -> y = a_copier -> y ;
            copie -> next = NULL ; // Mettre temporairement le prochain élément à NULL permet de gérer le dernier élément. 
        }

        a_copier = a_copier -> next ;
    }
}

void GP4_b_print_liste (element* head){
    
    element* current = head ;

    while(current != NULL){
        printf("(%d  %d)  ", current -> x, current -> y) ;
        current = current -> next ;
    }

    printf("\n") ;

}