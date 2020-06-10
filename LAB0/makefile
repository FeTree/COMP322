CC=gcc
CFLAGS=-I.

h: main.o hello.o world.o
	gcc -o h main.o hello.o world.o

main.o : main.c 
	gcc -c main.c

hello.o : hello.c
	gcc -c hello.c

world.o : world.c 
	gcc -c world.c