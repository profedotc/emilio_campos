#ifndef _GOL_H_	
#define _GOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10
#define TAM_Z 2

struct gol {
	bool worlds[TAM_Z][TAM_X][TAM_Y];
	int current_world;
};
void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);


#endif
