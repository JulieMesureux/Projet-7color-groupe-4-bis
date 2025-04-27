#ifndef MODIF_H
#define MODIF_H

Color GP4_b_return_map_value (GameState* state, int x, int y);

void GP4_b_MAJ_plateau(GameState* state, Color player, element** front, Color couleur);

int GP4_b_est_une_frontiere(GameState* state, int x, int y) ;

void GP4_b_sup_if_not_front(GameState* state, element** front) ;

#endif