#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chaineLongueur(const char* chaine);

int main() {

	// Afficher le code ASCII d'un caract�re et le caract�re correspondant
	char c = 'A';

	printf("ASCII value of %c = %d\n", c, c);

	// Entrer un caractre et afficher 

	char ch = 0;

	printf("\nEnter a character: \n");
	
	scanf_s("%c", &ch);
	
	printf("ASCII value of %c = %d\n", ch, ch);

	// 1. Chaine de caract�res

	char str[6]; // 5 caract�res + 1 caract�re de fin de chaine
	
	// Initialisation de la cha�ne (on �crit les caract�res un � un en m�moire)
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = '\0';

	printf("\nThe string is: %s\n", str);


	// 2. Chaine de caract�res, methode plus simple

	char str2[] = "Hello World C!"; // 14 caract�res + 1 caract�re de fin de chaine, automatiquement ajoute et calcul� par le compilateur

	printf("\nThe string is: %s\n", str2);

	// 3. Chaine de caract�res

	char str3[6] = { 'H', 'e', 'l', 'l', 'o', '\0' }; // 5 caract�res + 1 caract�re de fin de chaine

	printf("\nThe string is: %s\n", str3);

	// Entrer une chaine de caract�res et afficher

	char str4[100];

	printf("\nHello, comment t'appelles tu ? \n");

	scanf_s("%s", str4, 100);

	printf("Hi, %s, beinvenu au programme C !\n", str4);

	// Biblioteque de Chaine de caract�res
	// 1. strlen() : longueur de la chaine

	char str5[] = "Hello World C!";

	int lenStr5 = strlen(str5);

	printf("\nLa longueur de la chaine '%s' est %d caracteres.\n", str5, lenStr5);

	// Test, ecrire manuellement la longueur de la chaine

	printf("\nMethode manuelle\n");
	
	char str6[] = "Hello World C!";
	int compteur = chaineLongueur(str6);

	printf("\nLa longueur de la chaine '%s' est %d caracteres.\n", str6, compteur);


	return 0;
}

int chaineLongueur(const char* chaine) {
	
	int nombreCaracteres = 0;
	char caractereActuel = chaine[0];

	while (caractereActuel != '\0') {
		caractereActuel = chaine[nombreCaracteres];
		nombreCaracteres++;
	}

	return nombreCaracteres - 1;

}