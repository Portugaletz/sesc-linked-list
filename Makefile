run:lol
	./lol
lol:prog.c
	gcc -std=c99 -l string.h -l stdlib.h prog.c -o lol
build:lol
