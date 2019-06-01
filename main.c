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

void gol_init(bool mundo0[TAM_Z][TAM_X][TAM_Y])
{
	// TODO: Poner el mundo a false
	for (int k= 0; k < TAM_Z ; k++){
		for (int i = 0; i < TAM_X ; i++){
			for (int j = 0; j < TAM_Y ; j++){
				mundo0[k][i][j] = 0;
			}
			printf("\n");
		}

	}
	/* TODO: Inicializar con el patrón del glider:
	*           . # .
	*           . . #
	*           # # #
	*/

	mundo0[0][0][1] = 1;
	mundo0[0][1][2] = 1;
	mundo0[0][2][0] = 1;
	mundo0[0][2][1] = 1;
	mundo0[0][2][2] = 1;

}

void gol_print(bool mundo[TAM_X][TAM_Y])
{
	for (int i = 0; i < TAM_X ; i++){
		for (int j = 0; j < TAM_Y; j++){
			printf ("%c ", mundo[i][j]?'#':'.');
		}
		printf("\n");
	}
}

void gol_step(bool mundo[TAM_Z][TAM_X][TAM_Y], int *current_world)
{
	int vecinas_vivas = 0;
	int i;
	int j;
	for ( i = 0; i < TAM_X; i++){
		for ( j = 0; j < TAM_Y; j++){
			vecinas_vivas = gol_count_neighbors(mundo[*current_world],i,j);
			if (gol_get_cell(mundo[*current_world],i,j)){
				mundo[(*current_world +1) % TAM_Z ][i][j] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}else{
				mundo[(*current_world +1) % TAM_Z ][i][j] = vecinas_vivas == 3;
			}
			vecinas_vivas = 0;
		}
		printf("\n");
	}

	*current_world = (*current_world + 1) % TAM_Z;

}

int gol_count_neighbors(bool mundo0[TAM_X][TAM_Y], int i, int j)
{

	int totales = 0;
	totales += gol_get_cell (mundo0, i-1, j-1);
	totales += gol_get_cell (mundo0, i-1, j);
	totales += gol_get_cell (mundo0, i-1, j+1);
	totales += gol_get_cell (mundo0, i, j-1);
	totales += gol_get_cell (mundo0, i, j+1);
	totales += gol_get_cell (mundo0, i+1, j-1);
	totales += gol_get_cell (mundo0, i+1, j);
	totales += gol_get_cell (mundo0, i+1, j+1);
	return totales;

}

bool gol_get_cell(bool mundo0[TAM_X][TAM_Y], int i, int j)
{
	if (i < 0 || i > TAM_X-1 || j < 0 || j > TAM_Y-1){
		return false;
	}else{

		return mundo0[i][j];
	}
}
