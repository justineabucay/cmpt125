CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Default target
all: testDriver

# Build the test program
testDriver: dataStructure.o testDriver.o
	$(CC) dataStructure.o testDriver.o -o testDriver

# Compile object files
dataStructure.o: dataStructure.c dataStructure.h
	$(CC) $(CFLAGS) -c dataStructure.c

testDriver.o: testDriver.c dataStructure.h
	$(CC) $(CFLAGS) -c testDriver.c

# Run tests
test: testDriver
	./testDriver

# Clean up
clean:
	rm -f *.o testDriver *.json

.PHONY: all test clean