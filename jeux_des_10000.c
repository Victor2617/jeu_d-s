#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _CRA_SECURE_NO_WARNINGS

printf(" ------- Bienvenue au jeu des 10000 ! ------- \n\n ");

// Tableau de noms de joueurs
char** playerNames;

// Tableau de scores de joueurs
int* playerScores;

// Nombre de joueurs
int numPlayers;

// Score du joueur en cours
int currentPlayerScore;

// Nom du joueur en cours
char* currentPlayerName;

int main(void) {
	// Demande le nombre de joueurs
	printf("Combien de joueurs ? ");
	scanf("%d", &numPlayers);

	// Alloue de la mémoire pour le tableau de noms de joueurs
	playerNames = malloc(numPlayers * sizeof(char*));
	for (int i = 0; i < numPlayers; i++) {
		playerNames[i] = malloc(256 * sizeof(char));
	}

	// Demande aux joueurs d'entrer leur nom
	for (int i = 0; i < numPlayers; i++) {
		printf("Entrez le nom du joueur %d : ", i + 1);
		scanf("%s", playerNames[i]);
	}

	// Libère la mémoire allouée pour le tableau de noms de joueurs
	for (int i = 0; i < numPlayers; i++) {
		free(playerNames[i]);
	}
	free(playerNames);

	return 0;
}

// Fonction qui simule le lancer de deux dés
void rollDice(int* dice1, int* dice2) {
	*dice1 = rand() % 6 + 1;
	*dice2 = rand() % 6 + 1;
}

// Fonction qui calcule les points du joueur en cours en utilisant la règle du jeu
int calculatePoints(int dice1, int dice2) {
	int points = 0;
	if (dice1 == dice2) {
		// Si les deux dés ont la même valeur, le joueur obtient le double de cette valeur
		points = dice1 * 2;
	}
	else {
		// Sinon, le joueur obtient la somme des valeurs des deux dés
		points = dice1 + dice2;
	}
	return points;
}

int main(void) {
	// Initialise le générateur de nombres aléatoires
	srand(time(NULL));

	// Demande le nombre de joueurs
	printf("Combien de joueurs ? ");
	scanf("%d", &numPlayers);

	// Alloue de la mémoire pour le tableau de noms de joueurs et le tableau de scores de joueurs
	playerNames = malloc(numPlayers * sizeof(char*));
	playerScores = malloc(numPlayers * sizeof(int));
	for (int i = 0; i < numPlayers; i++) {
		playerNames[i] = malloc(256 * sizeof(char));
		playerScores[i] = 0;
	}

	// Demande aux joueurs d'entrer leur nom
	for (int i = 0; i < numPlayers; i++) {
		printf("Entrez le nom du joueur %d : ", i + 1);
		scanf("%s", playerNames[i]);
	}

	int dice1, dice2;
	int points;

	// Répète tant qu'aucun joueur n'a atteint un score de 10000
	while (1) {
		// Pour chaque joueur...
		for (int i = 0; i < numPlayers; i++) {
			currentPlayerName = playerNames[i];
			currentPlayerScore = playerScores[i];

			// Affiche le nom du joueur en cours
			printf("%s, c'est votre tour !\n", currentPlayerName);

			// Demande au joueur de lancer les dés
			printf("Appuyez sur la touche * pour lancer les dés...\n");
			getchar();  // Attend une touche du clavier
			rollDice(&dice1, &dice2);

			int calculatePoints(int dice1, int dice2); {
				int points = 0;
				if (dice1 == 1 || dice2 == 1) {
					// Si le joueur a tiré 1 sur au moins un dé, son tour se termine et il ne gagne aucun point
					points = 0;
				}
				else if (dice1 == 2 && dice2 == 2) {
					// Si le joueur a tiré 2 sur tous les dés, il gagne 200 points
					points = 200;
				}
				else if (dice1 == 3 && dice2 == 3) {
					// Si le joueur a tiré 3 sur tous les dés, il gagne 300 points
					points = 300;
				}
				else if (dice1 == 4 && dice2 == 4) {
					// Si le joueur a tiré 4 sur tous les dés, il gagne 400 points
					points = 400;
				}
				else if (dice1 == 5 && dice2 == 5) {
					// Si le joueur a tiré 5 sur tous les dés, il gagne 500 points
					points = 500;
				}
				else if (dice1 == 6 && dice2 == 6) {
					// Si le joueur a tiré 6 sur tous les dés, il gagne 600 points
					points = 600;
				}
				else if (dice1 == dice2) {
					// Si le joueur a tiré un triple, il gagne la valeur du triple multipliée par 100 points
					points = dice1 * 100;
				}
				else {
					// Sinon, le joueur obtient la somme des valeurs des deux dés
					points = dice1 + dice2;
				}
				return points;
			}
		}
