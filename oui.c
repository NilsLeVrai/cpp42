#include <stdio.h>

int main()
{

	int nombre = 42;
	int *pointeur = &nombre;

	printf("Adresse de la variable 'nombre': %p\n", &nombre);
	printf("Adresse du pointeur 'pointeur': %p\n", &pointeur);
	printf("Valeur du pointeur 'pointeur': %p\n", pointeur);
	printf("Valeur de la variable 'nombre': %d\n", nombre);
	printf("Valeur de la variable pointee par 'pointeur': %d\n", *pointeur);
	*pointeur = 23;

	printf("Adresse de la variable 'nombre': %p\n", &nombre);
	printf("Adresse du pointeur 'pointeur': %p\n", &pointeur);
	printf("Valeur du pointeur 'pointeur': %p\n", pointeur);
	printf("Valeur de la variable 'nombre': %d\n", nombre);
	printf("Valeur de la variable pointee par 'pointeur': %d\n", *pointeur);

	return 0;
}