.PHONY: clean 

CC = gcc
	CFGLAS = -Wall


##debug: CFLAGS += -g
##	debug: gol

gol: main.o gol.o
	$(CC) $(CFLAGS) main.o gol.o -o gol

main.o: main.c gol.h
	$(CC) $(CFLAGS) -c main.c

gol.o: gol.c
	$(CC) $(CFLAGS) -c gol.c

clean: 
	rm -f *.o gol
