CC = gcc
CFLAGS = -g -Wall -pedantic -Wextra

all: AddressBook

AddressBook: 
	$(MAKE) -C lib
	$(MAKE) -C src
	gcc -L${CURDIR}/lib -Wl,-rpath=${CURDIR}/lib -llinkedlist src/main.o src/utils.o -o AddressBook 
	
	
clean:
	$(MAKE) clean -C lib
	$(MAKE) clean -C src
	rm AddressBook