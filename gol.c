#include <stdio.h>
#include <stdlib.h>
#include "gol.h"


static int count_neighbors(struct gol *gol, int i, int j);

static bool get_cell(const struct gol *gol, enum world_type wtype, int i, int j);
static void set_cell(struct gol *gol, enum world_type wtype, int i, int j, bool value);
static void fix_coords(const struct gol *gol, int *i, int *j);



bool gol_alloc(struct gol *gol, int size_x, int size_y) {
	for( int world = CURRENT; world <= NEXT; world++ ) {
		gol->worlds[world] = (bool *)malloc(size_x * size_y * sizeof(bool));
		if (!gol->worlds[world]) {
			printf("Error in memory allocation");
			//free(gol->worlds[world]);
			return false;
		}
	}
	gol->size_x = size_x;
	gol->size_y = size_y;
	return true;
}

void gol_free(struct gol *gol) {
	for( int world = CURRENT; world <= NEXT; world++ )
		free(gol->worlds[world]);
}

void gol_init(struct gol *gol)
{

	for (int x = 0; x < gol->size_x; x++) {
		for (int y = 0; y < gol->size_y; y++) {
			set_cell(gol, CURRENT, x, y, 0);
		}
	}


	/* TODO: Inicializar con el patrón del glider:
	*           . # .
	*           . . #
	*           # # #
	*/
 	set_cell(gol, CURRENT, 0, 1, 1);
    	set_cell(gol, CURRENT, 1, 2, 1);
    	set_cell(gol, CURRENT, 2, 0, 1);
    	set_cell(gol, CURRENT, 2, 1, 1);
    	set_cell(gol, CURRENT, 2, 2, 1);
	

}

void gol_print(const struct gol *gol)
{
	for (int i = 0; i < gol->size_x ; i++){
		for (int j = 0; j < gol->size_y; j++){
			printf ("%c ", get_cell(gol, CURRENT, i, j)?'#':'.');

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
			if (get_cell(gol, CURRENT, i, j)){
				set_cell(gol, NEXT, i, j, vecinas_vivas == 2 || vecinas_vivas == 3);
			}else{
				set_cell(gol, NEXT, i, j, vecinas_vivas == 3);
			}
			vecinas_vivas = 0;
		}
		printf("\n");
	}

	bool *world_aux = gol->worlds[CURRENT];
	gol->worlds[CURRENT] = gol->worlds[NEXT];
	gol->worlds[NEXT] = world_aux;

}

static int count_neighbors(struct gol *gol, int x, int y)
{

	int totales = 0;

 	totales += get_cell(gol, CURRENT, x-1, y-1);
    	totales += get_cell(gol, CURRENT, x-1, y);
    	totales += get_cell(gol, CURRENT, x-1, y+1);
    	totales += get_cell(gol, CURRENT, x, y-1);
    	totales += get_cell(gol, CURRENT, x, y+1);
    	totales += get_cell(gol, CURRENT, x+1, y-1);
    	totales += get_cell(gol, CURRENT, x+1, y);
    	totales += get_cell(gol, CURRENT, x+1, y+1);

    	return totales;

}


static void fix_coords(const struct gol *gol, int *i, int *j) {

    if (*i >= gol->size_x)
	*i = 0;
    else if (*i < 0)
	*i = gol->size_x - 1;

    if (*j >= gol->size_y)
	*j = 0;
    else if (*j < 0)
	*j = gol->size_y - 1;
}

static bool get_cell(const struct gol *gol, enum world_type wtype, int i, int j)
{
	fix_coords(gol, &i, &j);
	return gol->worlds[wtype][j+i*gol->size_y];

}



static void set_cell(struct gol *gol, enum world_type wtype, int i, int j, bool value)
{

    	fix_coords(gol, &i, &j);
	gol->worlds[wtype][j + i * gol->size_y] = value;
	//*(self->worlds[wtype] + j + i * self->size_y) = value;	
}
	
