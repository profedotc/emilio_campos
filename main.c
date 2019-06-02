#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;
	int current_world = 0;
	//TODO: Declara dos mundos
	bool mundo[TAM_Z][TAM_X][TAM_Y];

	//TODO: inicializa el mundo
	gol_init(mundo);
	do {

			printf("\033cIteration %d\n", i++);
			//TODO: Imprime el mundo
			gol_print(mundo[current_world]);
			//Itera
			gol_step(mundo, &current_world);


	} while (getchar() != 'q');

	return EXIT_SUCCESS;

}
