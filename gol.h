#ifndef _GOL_H_	
#define _GOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10

struct gol {
	bool **worlds[2];
	int size_x;
	int size_y;
};
enum current_world {
	CURRENT,
	NEXT
};

void gol_init(struct gol *gol);
void gol_print(const struct gol *gol);
void gol_step(struct gol *gol);
bool gol_alloc(struct gol *gol, int size_x, int size_y);
void gol_free(struct gol *gol);


#endif
