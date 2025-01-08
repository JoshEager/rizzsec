CC = gcc
OBJFILES = main.o io.o crypt.o hashmap.o
SRCFILES = main.c io.c crypt.c hashmap.c
BINARY = rizzsec

all: $(BINARY)

$(BINARY): $(OBJFILES)
	$(CC) $^ -o $@

$(OBJFILES): $(SRCFILES)
	$(CC) -c $^ -ggdb -O0 -Wextra -Wall -Werror

clean: 
	rm -r *.o $(BINARY)
 