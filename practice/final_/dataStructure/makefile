test: testDriver.o dataStructure.o
	gcc -o test testDriver.o dataStructure.o

dataStructure.o: dataStructure.c dataStructure.h
	gcc -Wall -c dataStructure.c

testDriver.o: testDriver.c dataStructure.h
	gcc -Wall -c testDriver.c

clean: 
	rm -f test *.o *.gch

