# Makefile for DHSL Data Structure Project
# Compiles the doubly-headed singly-linked list implementation with test driver

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
TARGET = test_driver
OBJS = dataStructure.o test_driver.o

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile dataStructure.c
dataStructure.o: dataStructure.c dataStructure.h
	$(CC) $(CFLAGS) -c dataStructure.c

# Compile test_driver.c
test_driver.o: test_driver.c dataStructure.h
	$(CC) $(CFLAGS) -c test_driver.c

# Run the test driver
run: $(TARGET)
	./$(TARGET)

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything from scratch
rebuild: clean all

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the test driver (default)"
	@echo "  run      - Build and run the test driver"
	@echo "  clean    - Remove compiled files"
	@echo "  rebuild  - Clean and build everything"
	@echo "  help     - Show this help message"

# Declare phony targets
.PHONY: all run clean rebuild help