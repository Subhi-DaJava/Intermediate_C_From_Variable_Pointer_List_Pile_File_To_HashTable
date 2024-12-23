#include <stdio.h>
#include <stdlib.h>

void triplePointeur(int *pointeurSurNombre);
void triplePointeur2(int *pointeurSurNombre);
void decoupeMinutes(int* pointeurSurMinutes, int *pointeurSurHeures);


int main()
{
	int nombre = 5;

	printf("Valeur de nombre avant appel de la fonction : %d\n", nombre);
	
	triplePointeur(&nombre); // On passe l'adresse de nombre � la fonction, comme �a la fonction peut modifier la valeur de nombre
	
	printf("Valeur de nombre apr�s appel de la fonction : %d\n", nombre);

	// On peut aussi d�clarer un pointeur, initialiser ce pointeur avec l'adresse de nombre, et passer ce pointeur � la fonction

	int nombre2 = 10;
	int *pointeur = &nombre2;

	printf("\nValeur de nombre2 avant appel de la fonction : %d\n", nombre2);
	printf("Valeur point�e par pinteur avant appel de la fonction : %d\n", *pointeur);
	printf("Adresse de nombre2 : %p\n", (void*)&nombre2);

	triplePointeur2(pointeur); // On passe le pointeur � la fonction, comme �a la fonction peut modifier la valeur point�e par le pointeur

	printf("Valeur de nombre2 apr�s appel de la fonction : %d\n", nombre2);
	printf("Valeur point�e par pinteur apr�s appel de la fonction : %d\n", *pointeur);
	printf("Adresse de nombre2 : %p\n", pointeur);


	printf("\n\n *********************************** R�soudre D�coupe minutes et heures Probl�me *********************************************\n");

	int heures = 0, minutes = 90;

	printf("Heures : %d\nMinutes : %d\n", heures, minutes); // On affiche les valeurs avant l'appel de la fonction

	decoupeMinutes(&minutes, &heures);

	printf("Heures : %d\nMinutes : %d\n", heures, minutes); // On affiche les valeurs apr�s l'appel de la fonction

	
	return 0;
}

void triplePointeur(int *pointeurSurNombre)
{
	*pointeurSurNombre *= 3; // On multiplie la valeur point�e par 3
}

void triplePointeur2(int *pointeurSurNombre)
{
	*pointeurSurNombre *= 3; // On multiplie la valeur point�e par 3
}

void decoupeMinutes(int *pointeurSurMinutes, int *pointeurSurHeures)
{
	*pointeurSurHeures = *pointeurSurMinutes / 60;
	*pointeurSurMinutes = *pointeurSurMinutes % 60;
}