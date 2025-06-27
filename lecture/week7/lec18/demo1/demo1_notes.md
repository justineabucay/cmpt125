**1D_array_1.c**

**what the program does**
it creates a 2D array represented as a 1D array in memory and fills it with random values (0-255) and prints it in a 2D format

**function: fillRandom()** - fills the array with random numbers between 0-255
- uint8_t: 8-bit unsigned integer with the values 0-255
- srand(time(NULL)): seeds the random number generator with current time
- LIMIT = 256: rand() % 256 gives values 0-225
- the loop runs rows * cols 

**function: printArray()** prints the 1D array as if it were a 2D array
- row-major order: x + y * cols, which concerts 2D coordinates (x, y) to 1D array index

**function: main()** 
- atoi(): concerts string arguments to integers