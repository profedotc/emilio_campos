#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
	int i = 0;
	int current_world = 0;
	//TODO: Declara dos mundos
	//bool mundo[TAM_Z][TAM_X][TAM_Y];
	struct gol gol;

	bool success = gol_alloc(&gol, 10, 10);
	if (!success) {
		EXIT_FAILURE;
	}

	//TODO: inicializa el mundo
	gol_init(&gol);
	do {

			printf("\033cIteration %d\n", i++);
			//TODO: Imprime el mundo
			gol_print(&gol);
			//Itera
			gol_step(&gol);


	} while (getchar() != 'q');

	gol_free(&gol);

	return EXIT_SUCCESS;

}
