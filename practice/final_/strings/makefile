test: strings.o testDriver.o
	gcc -o test strings.o testDriver.o

strings.o: strings.c strings.h
	gcc -Wall -c strings.c 

testDriver.o:testDriver.c strings.h
	gcc -Wall -c testDriver.c 

clean: 
	rm -f test *.o *.gch