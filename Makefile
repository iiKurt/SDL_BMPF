CC=gcc

CFLAGS=-g -Wall `sdl-config --cflags`
LDFLAGS=`sdl-config --libs`

CFLAGS2=-g -Wall `sdl2-config --cflags`
LDFLAGS2=`sdl2-config --libs`

all: main

bmp2xbm:
	gcc -Wall -pedantic bmp2xbm.c -o $@

main:
	gcc $(CFLAGS) BMPF.c main.c -o $@ $(LDFLAGS)

clean:
	rm -rf *.o *.a main
