#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu_du_pendu_v2.h"
#include <ctype.h>

int main(int argc, char* argv[])
{
	char lettre = 0; // Stocke la lettre propos�e par l'utilisateur 

	// C'est le mot � d�couvrir, il est ici en clair pour l'instant, g�n�r� par l'ordinateur plus tard au hasard, 5 lettres max
	// TODO: g�n�rer un mot al�atoire avec le nombre de lettres souhait�
	//char motSecret[] = "ROUGE";

	/*
	est utilis�e pour d�clarer un tableau de caract�res (une cha�ne de caract�res)
	qui peut contenir un mot de taille TAILLE_MOT plus un caract�re nul ('\0').
	*/
	char motSecret[TAILLE_MOT + 1]; //+ 1 pour le caract�re nul
	genererMotSecret(motSecret); // G�n�ration du mot secret

	int coupsRestants = 10; // Compteur de coups restants (0 = perdu)

	int nombreLettres = tailleMot(motSecret); // Nombre de lettres du mot secret

	int* lettreTrouvee = NULL; // tableau de boolean, chaque case sera associ�e � une lettre trouv�e ou non.  

	lettreTrouvee = malloc(nombreLettres * sizeof(int)); // Allocation de la m�moire dynamique du tableau lettreTrouvee
	initTableau(lettreTrouvee, nombreLettres); // Initialisation du tableau lettreTrouvee

	printf("\n\t Bienvenue dans le jeu du pendu ! Vous etes pret(e) : ");

	// Je jeu commence ici
	while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
	{
		printf("\n\n\t Il vous reste %d coups a jouer", coupsRestants);
		printf("\n\t Quel est le mot secret ? ");

		// On affiche le mot avec les lettres d�j� trouv�es
		for (int i = 0; i < nombreLettres; i++)
		{
			if (lettreTrouvee[i]) // Si la lettre a �t� trouv�e
			{
				printf("%c", motSecret[i]); // On l'affiche
			}
			else
			{
				printf("*"); // Sinon, on affiche une �toile pour les lettres non trouv�es
			}
		}

		printf("\n\t Proposez une lettre : ");
		lettre = lireCaractere();

		// Si la lettre se trouve pas (Si la lettre n'a pas �t� trouv�e) dans le motSecret , on enl�ve un coup au joueur
		if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
		{
			coupsRestants--; // On enl�ve un coup au joueur
		}

	}

	// Afficher le r�sultat

	if (gagne(lettreTrouvee, nombreLettres))
	{
		printf("\n\n\t Bravo ! Vous avez trouve le mot secret ! Le mot secret etait bien : %s \n\n", motSecret);
	}
	else {
		printf("\n\n\t PENDU !!!! Le mot secret etait : %s \n\n", motSecret);
	}
	// On lib�re la m�moire allou�e dynamiquement
	free(lettreTrouvee);

	return 0;
}