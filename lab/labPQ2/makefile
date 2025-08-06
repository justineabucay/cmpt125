all: td

td: testDriver.o List.o Node.o
	g++ -Wall -o td testDriver.o List.o Node.o

testDriver.o: testDriver.cpp List.h Node.h
	g++ -Wall -c testDriver.cpp

List.o: List.h List.cpp Node.h
	g++ -Wall -c List.cpp

Node.o: Node.h Node.cpp
	g++ -Wall -c Node.cpp

clean:
	rm -f td *.o
