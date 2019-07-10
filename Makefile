.PHONY: all clean debug release test

all: debug

release: CFLAGS += -O3
release: gol

CFGLAS = -Wall

test: CFLAGS = -Wall -O0
test: mem_test

debug: CFLAGS += -g -O0
debug: gol

gol: main.o gol.o
	$(CC) $(CFLAGS) main.o gol.o -o gol

main.o: main.c gol.h
	$(CC) $(CFLAGS) -c main.c

gol.o: gol.c
	$(CC) $(CFLAGS) -c gol.c

mem_test: mem_test.o gol.o
	$(CC) $(CFLAGS) mem_test.o gol.o -o mem_test

mem_test.o: mem_test.c gol.h
	$(CC) $(CFLAGS) -c mem_test.c

test:
	valgrind --leak-check=full ./mem_test


clean: 
	rm -f *.o gol
