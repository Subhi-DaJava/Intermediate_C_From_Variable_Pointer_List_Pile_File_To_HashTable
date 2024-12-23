#include "incremente.h"

/*
Ici, la premi�re fois qu'on appelle la fonction incremente, 
la variable nombre est cr��e. Elle est incr�ment�e � 1, et une fois la fonction termin�e la variable n'est pas supprim�e.
Lorsque la fonction est appel�e une seconde fois, la ligne de la d�claration de variable est tout simplement "saut�e". 
On ne recr�e pas la variable, on r�utilise la variable qu'on avait d�j� cr��e. Comme la variable valait 4, elle vaudra maintenant 5, puis 6, puis 7, etc.
*/

int incremente() {
	static int i = 0;
	i++;
	return i;
}

static int triple(int nombre) {
	return nombre * 3;
}

int incrementeTriple() {
	return triple(incremente());
}