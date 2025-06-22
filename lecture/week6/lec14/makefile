oA: oddArrays.o testDriver.o
	gcc -o oA oddArrays.o testDriver.o

oddArrays.o: oddArrays.c 
	gcc -Wall -c oddArrays.c

testDriver.o: testDriver.c oddArrays.h
	gcc -Wall -c testDriver.c oddArrays.h

clean:
	rm -f oA *.o