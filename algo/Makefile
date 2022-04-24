run: main
	./main
	
main: main.o fonction.o
	gcc -Wall -o main main.o fonction.o

main.o: fonction.h main.c
	gcc -Wall -c main.c

fonction.o: fonction.h fonction.c
	gcc -Wall -c fonction.c
	
clean: 
	rm -f main.o
	rm -f main
	rm -f fonction.o
	rm -f fonction
	ls -l