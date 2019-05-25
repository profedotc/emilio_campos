#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10

void gol_init(bool mundo0[TAM_X][TAM_Y]);
void gol_print(bool mundo0TAM_X[][TAM_Y]);
void gol_step(bool mundo0[TAM_X][TAM_Y], bool mundo1[TAM_X][TAM_Y]);
int gol_count_neighbors(bool mundo0[TAM_X][TAM_Y], int i, int j);
bool gol_get_cell(bool mundo0[TAM_X][TAM_Y], int i, int j);
void gol_copy(bool mundo0[TAM_X][TAM_Y], bool mundo1[TAM_X][TAM_Y]);


int main()
{
	int i = 0;
	//TODO: Declara dos mundos
	bool mundo0[TAM_X][TAM_Y];
	bool mundo1[TAM_X][TAM_Y];

	//TODO: inicializa el mundo
	gol_init(mundo0);
	do {

			printf("\033cIteration %d\n", i++);
			//TODO: Imprime el mundo
			gol_print(mundo0);
			//Itera
			gol_step(mundo0, mundo1);


	} while (getchar() != 'q');

	return EXIT_SUCCESS;

}

void gol_init(bool mundo0[TAM_X][TAM_Y])
{
	// TODO: Poner el mundo a false
	for (int i = 0; i < TAM_X ; i++){
		for (int j = 0; j < TAM_Y ; j++){
			mundo0[i][j] = 0;
		}
		printf("\n");
	}


	/* TODO: Inicializar con el patrón del glider:
	*           . # .
	*           . . #
	*           # # #
	*/

	mundo0[0][1] = 1;
	mundo0[1][2] = 1;
	mundo0[2][0] = 1;
	mundo0[2][1] = 1;
	mundo0[2][2] = 1;

}

void gol_print(bool mundo0[TAM_X][TAM_Y])
{
	for (int i = 0; i < TAM_X ; i++){
		for (int j = 0; j < TAM_Y; j++){
			printf ("%c ", mundo0[i][j]?'#':'.');
		}
		printf("\n");
	}
}

void gol_step(bool mundo0[TAM_X][TAM_Y], bool mundo1[TAM_X][TAM_Y])
{
	int vecinas_vivas = 0;
	int i;
	int j;
	for ( i = 0; i < TAM_X; i++){
		for ( j = 0; j < TAM_Y; j++){
			vecinas_vivas = gol_count_neighbors(mundo0,i,j);
			if (gol_get_cell(mundo0,i,j)){
				mundo1[i][j] = (vecinas_vivas == 3) || (vecinas_vivas == 2);
			}else{
				mundo1[i][j] = vecinas_vivas == 3;
			}
			vecinas_vivas = 0;
		}
		printf("\n");
	}


	//volcamos mundo1 en mundo0, actualizacion.
	gol_copy(mundo0, mundo1);

}

int gol_count_neighbors(bool mundo0[TAM_X][TAM_Y], int i, int j)
{

	int totales = 0;
	if ( gol_get_cell (mundo0, i-1, j-1)){
		totales++;
	}
	if (gol_get_cell (mundo0, i-1, j)){
		totales++;
	}
	if (gol_get_cell (mundo0, i-1, j+1)){
		totales++;
	}
	if (gol_get_cell (mundo0, i, j-1)){
		totales++;
	}
	if (gol_get_cell (mundo0, i, j+1)){
		totales++;
	}
	if (gol_get_cell (mundo0, i+1, j-1)){
		totales++;
	}
	if (gol_get_cell (mundo0, i+1, j)){
		totales++;
	}
	if (gol_get_cell (mundo0, i+1, j+1)){
		totales++;
	}
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


void gol_copy(bool mundo0[TAM_X][TAM_Y], bool mundo1[][TAM_Y])
{

	int i;
	int j;

	for (i = 0; i < TAM_X; i++){
		for (j = 0; j < TAM_Y; j++){
		mundo0[i][j] = mundo1[i][j];
		}
	}

}
