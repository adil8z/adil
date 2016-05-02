all: matrix

matrix: lab5.o init.o multiply.o printmat.o
	gcc -Wall lab5.o init.o multiply.o printmat.o -o matrix -lpthread

lab5.o: lab5.c
	gcc -c -Wall lab5.c -lpthread

init.o: init.c
	gcc -c -Wall init.c

multiply.o: multiply.c
	gcc -c -Wall multiply.c

printmat.o: printmat.c
	gcc -c -Wall printmat.c

clean:
	rm -rf *.o matrix

