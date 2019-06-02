#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10
#define TAM_Z 2

void gol_init(bool mundo[TAM_Z][TAM_X][TAM_Y]);
void gol_print(bool mundo[TAM_X][TAM_Y]);
void gol_step(bool mundo[TAM_Z][TAM_X][TAM_Y], int *current_world);
int gol_count_neighbors(bool mundo[TAM_X][TAM_Y], int i, int j);
bool gol_get_cell(bool mundo[TAM_X][TAM_Y], int i, int j);
