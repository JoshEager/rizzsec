CC = gcc
OBJFILES = main.o io.o crypt.o hashmap.o
SRCFILES = src/main.c src/io.c src/crypt.c src/hashmap.c
BINARY = rizzsec

all: $(BINARY)

$(BINARY): $(OBJFILES)
	$(CC) $^ -o $@

$(OBJFILES): $(SRCFILES)
	$(CC) -c $^ -ggdb -O0 -Wextra -Wall -Werror

clean: 
	rm -r *.o $(BINARY)
 