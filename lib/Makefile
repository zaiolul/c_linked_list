CC = gcc
CFLAGS = -g -Wall -pedantic -Wextra

all: liblinkedlist.so

liblinkedlist.so: linkedlist.c ../includes/data.h
	gcc -c -fPIC linkedlist.c
	gcc -shared -o liblinkedlist.so linkedlist.o
	
clean:
	rm liblinkedlist.so
	rm linkedlist.o