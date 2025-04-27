FLAGS=-Wall -Werror -lm -g

7color : o/GameState.o o/Affichage.o o/Fin_de_partie.o o/Modif.o o/Play.o o/Two_players_game.o o/One_player_game.o o/AI_game.o o/competition.o o/Fait_n_importe_quoi.o o/Aleatoire.o o/Glouton.o o/Hegemonique.o o/Mixte.o
	gcc $(FLAGS) o/GameState.o o/Affichage.o o/Fin_de_partie.o o/Modif.o o/Play.o o/Two_players_game.o o/One_player_game.o o/AI_game.o o/competition.o o/Fait_n_importe_quoi.o o/Aleatoire.o o/Glouton.o o/Hegemonique.o o/Mixte.o -o 7color

o/GameState.o: src/GameState.c head/GameState.h head/Two_players_game.h head/One_player_game.h head/competition.h
	gcc $(FLAGS) -c src/GameState.c -o o/GameState.o

o/Affichage.o : src/Affichage.c head/Affichage.h head/GameState.h
	gcc $(FLAGS) -c src/Affichage.c -o o/Affichage.o

o/Fin_de_partie.o : src/Fin_de_partie.c head/Fin_de_partie.h head/GameState.h
	gcc $(FLAGS) -c src/Fin_de_partie.c -o o/Fin_de_partie.o

o/Modif.o : src/Modif.c head/Modif.h head/GameState.h
	gcc $(FLAGS) -c src/Modif.c -o o/Modif.o

o/Play.o : src/Play.c head/Play.h head/GameState.h head/Affichage.h head/Modif.h
	gcc $(FLAGS) -c src/Play.c -o o/Play.o

o/Two_players_game.o : src/Two_players_game.c head/Two_players_game.h head/GameState.h head/Play.h head/Fin_de_partie.h
	gcc $(FLAGS) -c src/Two_players_game.c -o o/Two_players_game.o

o/One_player_game.o : src/One_player_game.c head/One_player_game.h head/GameState.h head/Play.h head/Fin_de_partie.h head/Fait_n_importe_quoi.h head/Aleatoire.h head/Glouton.h head/Hegemonique.h head/Mixte.h
	gcc $(FLAGS) -c src/One_player_game.c -o o/One_player_game.o

o/AI_game.o : src/AI_game.c head/AI_game.h head/GameState.h head/Play.h head/Fin_de_partie.h head/Fait_n_importe_quoi.h head/Aleatoire.h head/Glouton.h head/Hegemonique.h head/Mixte.h
	gcc $(FLAGS) -c src/AI_game.c -o o/AI_game.o

o/competition.o : src/Competition.c head/competition.h head/GameState.h head/AI_game.h
	gcc $(FLAGS) -c src/Competition.c -o o/competition.o

o/Fait_n_importe_quoi.o : src/Fait_n_importe_quoi.c head/Fait_n_importe_quoi.h head/GameState.h
	gcc $(FLAGS) -c src/Fait_n_importe_quoi.c -o o/Fait_n_importe_quoi.o

o/Aleatoire.o : src/Aleatoire.c head/Aleatoire.h head/GameState.h
	gcc $(FLAGS) -c src/Aleatoire.c -o o/Aleatoire.o

o/Glouton.o : src/Glouton.c head/Glouton.h head/GameState.h
	gcc $(FLAGS) -c src/Glouton.c -o o/Glouton.o

o/Hegemonique.o : src/Hegemonique.c head/Hegemonique.h head/GameState.h
	gcc $(FLAGS) -c src/Hegemonique.c -o o/Hegemonique.o

o/Mixte.o : src/Mixte.c head/Mixte.h head/GameState.h
	gcc $(FLAGS) -c src/Mixte.c -o o/Mixte.o