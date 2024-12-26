#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAILLE_MOT 5

int tailleMot(char motSecret[]); // Prototype de la fonction tailleMot
void initTableau(int* lettreTrouvee, int tailleTableau); // Prototype de la fonction initTableau
int gagne(int* lettreTrouvee, int nombreLettres); // Prototype de la fonction gagne
char lireCaractere(); // Prototype de la fonction lireCaractere
int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee); // Prototype de la fonction rechercheLettre
void genererMotSecret(char* motSecret); // Prototype de la fonction genererMotSecret


/*
 * \brief Renvoie le nombre de lettres du mot
 * \param motSecret le mot dont on veut conna�tre le nombre de lettres
 * \return le nombre de lettres du mot
 */
int tailleMot(char motSecret[])
{
	/*int nombreLettres = 0;
	while (motSecret[nombreLettres] != '\0')
	{
		nombreLettres++;
	}
	return nombreLettres;*/

	int nombreLettres = 0;
	for (int i = 0; motSecret[i] != '\0'; i++)
	{
		nombreLettres++;
	}
	return nombreLettres;
}

/*
 * \brief Initialise un lettreTrouvee d'entiers � 0
 * \param lettreTrouvee le lettreTrouvee � initialiser
 * \param tailleTableau la taille du lettreTrouvee
 */
void initTableau(int* tableau, int tailleTableau)
{
	int i = 0;
	for (i = 0; i < tailleTableau; i++)
	{
		tableau[i] = 0;
	}
}


/*
 * \brief V�rifie si le joueur a gagn�
 * \param lettreTrouvee le lettreTrouvee de lettres trouv�es
 * \param nombreLettres le nombre de lettres du mot
 * \return 1 si le joueur a gagn�, 0 sinon
 */

 /*
 Le lettreTrouvee lettreTrouvee permet de conna�tre chaque lettre trouv�e dans le mot myst�re.
 S�il reste encore une case qui a la valeur 0, alors la partie n�est pas encore gagn�e.
 Dans ce cas, il faut v�rifier chaque case du lettreTrouvee et si une case contient la valeur 0,
 on doit assigner la valeur 0 � la variable  joueurGagne
 */
int gagne(int* lettresTrouvees, int nombreLettres)
{
	int i = 0;
	int joueurGagne = 1;

	for (i = 0; i < nombreLettres; i++)
	{
		if (lettresTrouvees[i] == 0)
		{
			joueurGagne = 0;
		}
	}
	return joueurGagne;
}

/*
 * \brief Lit un caract�re saisi par l'utilisateur
 * \return le caract�re saisi par l'utilisateur
 */
char lireCaractere()
{
	char caractere = 0;

	caractere = getchar(); // On lit le premier caract�re

	caractere = toupper(caractere); // On met la lettre en majuscule, si elle ne l'est pas d�j�

	/*
	Ce code est souvent utilis� pour "vider" le tampon d'entr�e,
	en particulier apr�s avoir lu des entr�es au clavier, pour s'assurer qu'aucun caract�re ind�sirable
	(comme des caract�res de nouvelle ligne laiss�s par un pr�c�dent scanf) ne reste dans le tampon d'entr�e.
	Le point-virgule (;) � la fin indique que le corps de la boucle est vide.
	Cela signifie que la boucle ne fait rien d'autre que lire des caract�res.
	*/
	while (getchar() != '\n'); // On lit les autres caract�res m�moris�s un � un jusqu'au \n (pour les effacer)

	return caractere;
}

/*
 * \brief Recherche une lettre dans le motSecret
 * \param lettre la lettre � rechercher (propos�e par l'utilisateur)
 * \param motSecret le mot dans lequel on recherche la lettre
 * \param lettreTrouvee le lettreTrouvee de lettres trouv�es
 * \return 1 si la lettre a �t� trouv�e, 0 sinon
 */

 /*
 On parcourt la cha�ne  motSecret  caract�re par caract�re.
 � chaque fois, on v�rifie si la lettre que le joueur a propos�e est une lettre du mot. Si la lettre correspond, alors on fait deux choses :
 1. on change la valeur du bool�en  bonneLettre  � 1, pour que la fonction retourne 1 car la lettre se trouvait effectivement dans motSecret ;
 2. on met � jour le lettreTrouvee lettreTrouvee � la position actuelle pour indiquer que cette lettre a �t� trouv�e.
 */
int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee) {
	int i = 0, bonneLettre = 0;

	// On parcourt motSecret pour v�rifier si la lettre propos�e par l'utilisateur est pr�sente
	for (i = 0; motSecret[i] != '\0'; i++)
	{
		if (lettre == motSecret[i]) // Si la lettre est pr�sente dans le mot
		{
			lettreTrouvee[i] = 1; // On met � jour le lettreTrouvee de lettres trouv�es
			bonneLettre = 1; // On met � jour la variable bonneLettre
		}
	}
	return bonneLettre;
}

/*
 * \brief G�n�re un mot al�atoire
 * \param motSecret le mot g�n�r� al�atoirement
 */
void genererMotSecret(char* motSecret) {
	// Liste de mots
	const char* mots[] = { "ROUGE", "JAUNE", "BLANC", "MAMAN", "EMAIL","PORTE", "SAIDA", "LUNDI" };

	// Nombre de mots dans la liste, ici 8
	// sizeof(mots) renvoie la taille en octets(total) de la liste de mots
	// sizeof(mots[0]) renvoie la taille en octets du premier mot de la liste
	int nombreMots = sizeof(mots) / sizeof(mots[0]);

	/*
	Dans le contexte de la fonction genererMotSecret,
	cette ligne de code est utilis�e pour s'assurer que chaque fois que le programme est ex�cut�,
	un mot diff�rent est potentiellement s�lectionn� de mani�re al�atoire.
	*/
	srand((unsigned int)time(NULL));// Initialiser le g�n�rateur de nombres al�atoires

	// rand() % nombreMots retourne un nombre entier compris entre 0 et nombreMots - 1.
	int index = rand() % nombreMots; // S�lectionner un index al�atoire
	//strcpy(motSecret, mots[index]); // Copier le mot s�lectionn� dans motSecret
	strcpy_s(motSecret, TAILLE_MOT + 1, mots[index]); // Copier le mot s�lectionn� dans motSecret
}
