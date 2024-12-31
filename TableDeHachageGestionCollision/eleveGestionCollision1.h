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
	eleve->moyenne = moyenne;

	return eleve;
}

// Fonction puor initialiser la table de hachage
void initialiserTableHachage(TableHachage *table) {
	table -> taille = TAILLE;
	for (int i = 0; i < TAILLE; i++) {
		table -> table[i] = NULL;
	}
}

// Fonction pour ajouter un �l�ve dans la table de hachage
/*
* else {
		int i = 1;
		while (table -> table[index] != NULL) {
			index = (index + i) % TAILLE;
			i++;
		}
		table -> table[index] = eleve;
	}
Ce code est une impl�mentation de la gestion des collisions dans une table de hachage en utilisant la m�thode du "probing lin�aire".

 une condition pour v�rifier si toutes les cases ont �t� parcourues sans trouver de case libre
	1.	Initialisation de originalIndex : Cette variable stocke l'indice de d�part pour d�tecter si nous avons parcouru tout le tableau.
	2.	Condition de boucle while : La boucle continue tant que la case � l'indice index est occup�e.
	3.	V�rification de la boucle compl�te : Si l'indice index revient � originalIndex, 
	cela signifie que toutes les cases ont �t� parcourues et que la table est pleine. 
	Dans ce cas, un message d'erreur est affich� et la fonction retourne sans ajouter l'�l�ve.
*/

//Method original
// void ajouterEleve(TableHachage *table, Eleve *eleve) {
//
//	char nomComplet[10];
//	// Concat�ner le pr�nom et le nom
//	snprintf(nomComplet, sizeof(nomComplet), "%s %s", eleve -> prenom, eleve -> nom);
//
//	int index = hachage(nomComplet);
//
//	if (table -> table[index] == NULL) {
//		table -> table[index] = eleve;
//	}
//	else {
//		int i = 1;
//		while (table -> table[index] != NULL) {
//			index = (index + i) % TAILLE;
//			i++;
//		}
//		table -> table[index] = eleve;
//	}
//}

void ajouterEleve(TableHachage *table, Eleve *eleve) {
	char nomComplet[100];
	// Concat�ner le pr�nom et le nom
	snprintf(nomComplet, sizeof(nomComplet), "%s %s", eleve -> prenom, eleve -> nom);
	
	int index = hachage(nomComplet);
	
	int originalIndex = index;

	while (table -> table[index] != NULL) 
	{
		index = (index + 1) % TAILLE;
		if (index == originalIndex)
		{
			// Si nous avons parcouru tout le tableau et sommes revenus au point de d�part
			printf("Erreur : La table de hachage est pleine, impossible d'ajouter l'eleve.\n");
			return;
		}
	}

	table -> table[index] = eleve;
	
}


/*
* Le probl�me que vous rencontrez est probablement d� � une collision dans la table de hachage lorsque TAILLE est d�fini � 10. 
Avec une taille de table plus petite, il y a plus de chances que plusieurs �l�ves aient le m�me indice de hachage, 
ce qui peut entra�ner des collisions et des erreurs lors de la recherche.
Pour corriger ce probl�me, nous devons nous assurer que la fonction rechercherTableHachage g�re 
correctement les collisions en utilisant la m�me m�thode de hachage lin�aire que celle utilis�e dans ajouterEleve.
*/

// M�thode originale pour rechercher un �l�ve
//Eleve *rechercherTableHachage(TableHachage *tableau, char *chaine) {
//
//	int index = hachage(chaine);
//
//	if (tableau -> table[index] == NULL) {
//		printf("\t Desole, Eleve dont le nom : {%s} non trouve.\n", chaine);
//		return NULL;
//	}
//
//	return tableau -> table[index];;
//}


Eleve *rechercherTableHachage(TableHachage *tableau, char *chaine) {
	int index = hachage(chaine);
	int originalIndex = index;
	char nomComplet[100];
	
	while (tableau -> table[index] != NULL) {
		// Concat�ner le pr�nom et le nom
		snprintf(nomComplet, sizeof(nomComplet), "%s %s", tableau -> table[index] -> prenom, tableau -> table[index] -> nom);
		
		// V�rifier si l'�l�ve trouv� correspond � la cha�ne recherch�e
		if (strcmp(nomComplet, chaine) == 0) {
			return tableau -> table[index];
		}

		index = (index + 1) % TAILLE;
		
		if (index == originalIndex) {
			// Si nous avons parcouru tout le tableau et sommes revenus au point de d�part
			break;
		}
	}

	printf("\t Desole, Eleve dont le nom : {%s} non trouve.\n", chaine);
	
	return NULL;
}



