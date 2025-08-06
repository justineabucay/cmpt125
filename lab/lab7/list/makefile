all: td

td: testDriver.o List.o Node.o
	g++ -Wall -std=c++11 -o td testDriver.o List.o Node.o

testDriver.o: testDriver.cpp List.h Node.h
	g++ -Wall -std=c++11 -c testDriver.cpp

List.o: List.h List.cpp Node.h
	g++ -Wall -std=c++11 -c List.cpp

Node.o: Node.h Node.cpp
	g++ -Wall -std=c++11 -c Node.cpp

clean:
	rm -f td *.o