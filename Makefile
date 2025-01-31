main: main.c Makefile
	gcc -o main main.c -lSDL2 -lSDL2_mixer -lncursesw

clean:
	rm -f main

