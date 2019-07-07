#include <stdio.h>
#include "gol.h"

static int count_neighbors(struct gol *gol, int i, int j);
static bool get_cell(struct gol *gol, int i, int j);

bool gol_alloc(struct gol *gol, int size_x, int size_y) {
	for( int world = CURRENT; world <= NEXT; world++ ) {
		gol->worlds[world] = malloc(size_x * sizeof(bool(*)));
		if (!gol->worlds[world]) {
			printf("Error in memory allocation");
			free(gol->worlds[world]);
			return false;
		}
		for (int x = 0; x < size_x; x++) {
			gol->worlds[world][x] = malloc(size_y * sizeof(bool));
			if (!gol->worlds[world][x]) {
				printf("Error in memory allocation");
				free(gol->worlds[world][x]);
				return false;
			}
		}
	}
	gol->size_x = size_x;
	gol->size_y = size_y;
	return true;
}

void gol_free(struct gol *gol) {
	for( int world = CURRENT; world <= NEXT; world++ ) {
		for (int x = 0; x < gol->size_x; x++) {
			free(gol->worlds[world][x]);
		}
		free(gol->worlds[world]);
	}
}

void gol_init(struct gol *gol)
{

	for (int x = 0; x < gol->size_x; x++) {
		for (int y = 0; y < gol->size_y; y++) {
			gol->worlds[CURRENT][x][y] = 0;
		}
	}


	/* TODO: Inicializar con el patrón del glider:
	*           . # .
	*           . . #
	*           # # #
	*/
	gol->worlds[CURRENT][0][1] = 1;
	gol->worlds[CURRENT][1][2] = 1;
	gol->worlds[CURRENT][2][0] = 1;
	gol->worlds[CURRENT][2][1] = 1;
	gol->worlds[CURRENT][2][2] = 1;

}

void gol_print(const struct gol *gol)
{
	for (int i = 0; i < gol->size_x ; i++){
		for (int j = 0; j < gol->size_y; j++){
			printf ("%c ", gol->worlds[CURRENT][i][j]?'#':'.');
		}
		printf("\n");
	}
}

void gol_step(struct gol *gol)
{
	int vecinas_vivas = 0;
	for ( int i = 0; i < gol->size_x; i++){
		for ( int j = 0; j < gol->size_y; j++){
			vecinas_vivas = count_neighbors(gol,i,j);
			if (gol->worlds[CURRENT][i][j]){
				gol->worlds[NEXT][i][j] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}else{
				gol->worlds[NEXT][i][j] = vecinas_vivas == 3;
			}
			vecinas_vivas = 0;
		}
		printf("\n");
	}

	bool **world_aux = gol->worlds[CURRENT];
	gol->worlds[CURRENT] = gol->worlds[NEXT];
	gol->worlds[NEXT] = world_aux;

}

static int count_neighbors(struct gol *gol, int x, int y)
{

	int totales = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for(int e = y - 1; e <= y + 1; e++) {
			if (e != y || i != x)
				totales += get_cell(gol, i, e);
		}
	}
	return totales;

}

static bool get_cell(struct gol *gol, int i, int j)
{
	if (i < 0 || i > gol->size_x - 1 || j < 0 || j > gol->size_y - 1){
		return false;
	}else{

		return gol->worlds[CURRENT][i][j];
	}
}
