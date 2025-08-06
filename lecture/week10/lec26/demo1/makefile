testRect: testDriver.o Rectangle.o
	g++ -Wall testDriver.o Rectangle.o -o testRect

Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -Wall -c Rectangle.cpp

testDriver.o: testDriver.cpp Rectangle.h
	g++ -Wall -c testDriver.cpp

clean:
	rm -f testRect *.o
