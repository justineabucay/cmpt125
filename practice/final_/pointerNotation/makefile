test: pointer.o testDriver.o
	gcc -o test pointer.o testDriver.o

pointer.o: pointer.c pointer.h
	gcc -Wall -c pointer.c

testDriver.o: testDriver.c pointer.h
	gcc -Wall -c testDriver.c

clean:
	rm -f test *.o *.gch
	
