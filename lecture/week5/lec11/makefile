fc: funcs.o main.o
	gcc -o fc funcs.o main.o

funcs.o: funcs.c funcs.h
	gcc -Wall -c funcs.c funcs.h

main.o: main.c funcs.h
	gcc -Wall -c main.c funcs.h

clean:
	rm -f fc *.o
	
