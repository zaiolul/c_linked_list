CC = gcc
CFLAGS = -g -Wall -pedantic -Wextra
AddressBook: main.o linkedlist.o
	gcc main.o linkedlist.o -o AddressBook

main.o: main.c includes/linkedlist.h
	gcc -c main.c
linkedlist.o: linkedlist.c includes/data.h
	gcc -c linkedlist.c