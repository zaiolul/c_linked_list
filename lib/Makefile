LIB:=liblinkedlist.so
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)
CFLAGS:=-Wall -fpic
LDFLAGS:=-shared

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
clean:
	$(RM) $(LIB) $(OBJS)