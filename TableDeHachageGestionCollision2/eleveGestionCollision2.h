#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 10

typedef struct Eleve Eleve;
struct Eleve {
	char prenom[50];
	char nom[50];
	int age;
	char sexe[50];
	double moyenne;
	Eleve *suivant; // Pointeur vers l'�l�ve suivant dans la liste cha�n�e
};

typedef struct TableHachage TableHachage;
struct TableHachage {
	int taille;
	Eleve *table[TAILLE];
};


int hachage(const char *chaine);
Eleve *creerEleve(const char *prenom, const char *nom, int age, const char *sexe, double moyenne);
void initialiserTableHachage(TableHachage *table);
void ajouterEleve(TableHachage *table, Eleve *eleve);
Eleve *rechercherTableHachage(TableHachage *tableau, char *chaine);

// Fonction de hachage
int hachage(const char *chaine) {

	int i = 0, nombreHache = 0;

	for (i = 0; chaine[i] != '\0'; i++) {
		nombreHache += chaine[i];
	}

	nombreHache %= TAILLE;

	return nombreHache;
}

// Fonction pour cr�er un �l�ve
Eleve *creerEleve(const char *prenom, const char *nom, int age, const char *sexe, double moyenne) {

	Eleve *eleve = malloc(sizeof(Eleve));

	if (eleve == NULL) {
		exit(1);
	}

	strcpy_s(eleve -> prenom, sizeof(eleve -> prenom), prenom);
	strcpy_s(eleve -> nom, sizeof(eleve -> nom), nom);
	eleve -> age = age;
	strcpy_s(eleve -> sexe, sizeof(eleve -> sexe), sexe);
	eleve -> moyenne = moyenne;
	eleve->suivant = NULL; // Initialiser le pointeur suivant � NULL
	return eleve;
}

// Fonction puor initialiser la table de hachage
void initialiserTableHachage(TableHachage *table) {
	table -> taille = 0;
	for (int i = 0; i < TAILLE; i++) {
		table -> table[i] = NULL;
	}
}

// Fonction pour ajouter un �l�ve dans la table de hachage
void ajouterEleve(TableHachage *table, Eleve *eleve) {
	// V�rifier si la table de hachage est pleine
	int isFull = 1;
	for (int i = 0; i < TAILLE; i++) {
		if (table -> table[i] == NULL) {
			isFull = 0;
			break;
		}
	}

	if (isFull) {
		printf("Erreur : La table de hachage est pleine, impossible d'ajouter l'eleve.\n");
		return;
	}

	char nomComplet[100];
	// Concat�ner le pr�nom et le nom
	snprintf(nomComplet, sizeof(nomComplet), "%s %s", eleve -> prenom, eleve -> nom);
	int index = hachage(nomComplet);

	// Ajouter l'�l�ve � la fin de la liste cha�n�e � l'indice calcul�
	if (table -> table[index] == NULL) {
		table -> table[index] = eleve;
		table -> taille++;
	}
	else {
		Eleve *courant = table -> table[index];
		while (courant -> suivant != NULL) {
			courant = courant -> suivant;
		}
		courant -> suivant = eleve;
		table -> taille++;
	}
}

Eleve *rechercherTableHachage(TableHachage *tableau, char *chaine) {
	int index = hachage(chaine);
	
	Eleve *courant = tableau -> table[index];
	
	char nomComplet[100];

	while (courant != NULL) {
		// Concat�ner le pr�nom et le nom
		snprintf(nomComplet, sizeof(nomComplet), "%s %s", courant -> prenom, courant -> nom);
		// V�rifier si l'�l�ve trouv� correspond � la cha�ne recherch�e
		if (strcmp(nomComplet, chaine) == 0) {
			return courant;
		}

		courant = courant -> suivant;
	}

	printf("\t Desole, Eleve dont le nom : {%s} non trouve.\n", chaine);

	return NULL;
}



