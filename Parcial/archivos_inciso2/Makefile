CC=c99
CFLAGS= -Wall -Wextra -pedantic -std=c99 -Werror -Og -ggdb -m32 -ffreestanding -fno-pie -fno-zero-initialized-in-bss -fno-stack-protector
NASM=nasm
NASMFLAGS=-f elf32 -g -F DWARF 

all: main 

main: main.c sum_asm.o
	$(CC) $(CFLAGS) $^ -o $@

sum_asm.o: sum.asm sum.h
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f main
	rm -f results

