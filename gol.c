#include <stdio.h>
#include "gol.h"

void gol_init(struct gol *gol)
{
	gol->current_world = 0;
	// TODO: Poner el mundo a false
	for (int k = 0; k < TAM_Z ; k++){
		for (int i = 0; i < TAM_X ; i++){
			for (int j = 0; j < TAM_Y ; j++){
				gol->worlds[gol->current_world][i][j] = 0;
			}
			printf("\n");
		}

	}
	/* TODO: Inicializar con el patrón del glider:
	*           . # .
	*           . . #
	*           # # #
	*/
	gol->current_world = 0;
	gol->worlds[gol->current_world][0][1] = 1;
	gol->worlds[gol->current_world][1][2] = 1;
	gol->worlds[gol->current_world][2][0] = 1;
	gol->worlds[gol->current_world][2][1] = 1;
	gol->worlds[gol->current_world][2][2] = 1;

}

void gol_print(struct gol *gol)
{
	for (int i = 0; i < TAM_X ; i++){
		for (int j = 0; j < TAM_Y; j++){
			printf ("%c ", gol->worlds[gol->current_world][i][j]?'#':'.');
		}
		printf("\n");
	}
}

void gol_step(struct gol *gol)
{
	int vecinas_vivas = 0;
	for ( int i = 0; i < TAM_X; i++){
		for ( int j = 0; j < TAM_Y; j++){
			vecinas_vivas = gol_count_neighbors(gol,i,j);
			if (gol_get_cell(gol,i,j)){
				gol->worlds[(gol->current_world +1) % TAM_Z ][i][j] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}else{
				gol->worlds[(gol->current_world +1) % TAM_Z ][i][j] = vecinas_vivas == 3;
			}
			vecinas_vivas = 0;
		}
		printf("\n");
	}

	gol->current_world = (gol->current_world + 1) % TAM_Z;

}

int gol_count_neighbors(struct gol *gol, int i, int j)
{

	int totales = 0;
	totales += gol_get_cell (gol, i-1, j-1);
	totales += gol_get_cell (gol, i-1, j);
	totales += gol_get_cell (gol, i-1, j+1);
	totales += gol_get_cell (gol, i, j-1);
	totales += gol_get_cell (gol, i, j+1);
	totales += gol_get_cell (gol, i+1, j-1);
	totales += gol_get_cell (gol, i+1, j);
	totales += gol_get_cell (gol, i+1, j+1);
	return totales;

}

bool gol_get_cell(struct gol *gol, int i, int j)
{
	if (i < 0 || i > TAM_X-1 || j < 0 || j > TAM_Y-1){
		return false;
	}else{

		return gol->worlds[gol->current_world][i][j];
	}
}
