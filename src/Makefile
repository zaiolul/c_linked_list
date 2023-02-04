CC = gcc
CFLAGS = -g -Wall -pedantic -Wextra
#CFLAGS = -w

all: utils.o main.o 

main.o: main.c utils.o
	gcc -c main.c -o main.o 

utils.o: utils.c 
	gcc -c utils.c -o utils.o

clean:
	rm main.o utils.o