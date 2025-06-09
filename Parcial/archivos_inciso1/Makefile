CC=c99
CFLAGS= -Wall -Wextra -pedantic -O0 -g -lm -Wno-unused-variable -Wno-unused-parameter --std=c99
NASM=nasm
NASMFLAGS=-f elf64 -g -F DWARF 

all: main 

main: main.c sum_asm.o
	$(CC) $(CFLAGS) $^ -o $@

sum_asm.o: sum.asm sum.h
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f main
	rm -f results

