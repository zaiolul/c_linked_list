CC = gcc
#CFLAGS = -g -Wall -pedantic -Wextra
CFLAGS = -w

AddressBook: main.o linkedlist.o utils.o
	gcc main.o linkedlist.o utils.o -o AddressBook

main.o: main.c includes/linkedlist.h includes/utils.h 
	gcc -c main.c

linkedlist.o: linkedlist.c includes/data.h
	gcc -c linkedlist.c

utils.o: utils.c 
	gcc -c utils.c

clean:
	rm linkedlist.o main.o utils.o 