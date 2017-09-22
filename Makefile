CC=g++
CFLAGS=-ggdb -std=c++11 -Wall -pedantic

all: SimpleCalc

SimpleCalc: main.c simplecalc.h simplecalc.c
	$(CC) $(CFLAGS) -o SimpleCalc main.c simplecalc.c

clean:
	rm -rf SimpleCalc
