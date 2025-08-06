all: td

td: testDriver.o List.o
	g++ -Wall -o td testDriver.o List.o

testDriver.o: testDriver.cpp List.h
	g++ -Wall -c testDriver.cpp

List.o: List.h List.cpp
	g++ -Wall -c List.cpp

clean:
	rm -f td *.o