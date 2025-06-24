rect: testDriver.o InRectangle.o
	gcc -o rect testDriver.o InRectangle.o -lm

testDriver.o: testDriver.c InRectangle.h
	gcc -Wall -c testDriver.c

InRectangle.o: InRectangle.c InRectangle.h
	gcc -Wall -c InRectangle.c

clean:
	rm -f rect *.o