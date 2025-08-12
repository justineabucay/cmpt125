test: memory.o testDriver.o
	gcc -o test memory.o testDriver.o

memory.o: memory.c memory.h
	gcc -Wall -c memory.c memory.h

testDriver.o: testDriver.c memory.h
	gcc -Wall -c testDriver.c memory.h

clean:
	rm -f test *.o *.gch