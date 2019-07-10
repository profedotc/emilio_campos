#include <stdio.h>
#include <stdbool.h>
#include "gol.h"

int main()
{
        int i = 0;
        struct gol gol;

	bool success = gol_alloc(&gol, 20, 10);
	if (!success) {
		EXIT_FAILURE;
	}
        gol_init(&gol);

        do {
                i++;
                gol_step(&gol);
        } while (i < 40);

        gol_free(&gol);

        return EXIT_SUCCESS;
}
