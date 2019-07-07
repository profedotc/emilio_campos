CC = gcc

.PHONY: main_test
all: main main_test

release: CFLAGS += -O3
release: gol

CFGLAS = -Wall -WextraA

test: FLAGS += -g -O3
test: main_test

main_test: main_test.o gol.o
	$(CC) $(FLAGS) main_test.o gol.o -o main_test
	valgrind --leak-check=full ./main_test

main_test.o: main_test.c gol.o
	$(CC) $(FLAGS) -c main_test.c


debug: CFLAGS += -g -O0
debug: gol

gol: main.o gol.o
	$(CC) $(CFLAGS) main.o gol.o -o gol

main.o: main.c gol.h
	$(CC) $(CFLAGS) -c main.c

gol.o: gol.c
	$(CC) $(CFLAGS) -c gol.c

clean: 
	rm -f *.o gol
