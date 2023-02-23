BIN:=address_book
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)
CFLAGS:= -Wall
CPPFLAGS:=-I../includes
LDFLAGS:=-L../lib -llinkedlist

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)


#if you need to specify some rules for .o files building
%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(BIN) $(OBJS)