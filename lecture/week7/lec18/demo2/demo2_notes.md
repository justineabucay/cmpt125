the difference between the first demo and this one here is,the first demo uses heap allocation and this one uses stack allocation:

        // heap allocation
        uint8_t *theArray = NULL;
        theArray = malloc(rows * cols * sizeof(uint8_t));

        // stack allocation
        uint8_t theArray[rows][cols];

**function: fillRandom()**

        void fillRandom(unsigned int rows, unsigned int cols, uint8_t theArray[][cols])

- variable length array: uint8_t theArray[][cols]
- array access: this program uses direct 2D indexing, while in the first one converts 2D to 1D index

        theArray[x + y * cols]  // Convert 2D to 1D index

        uint8_t theArray[][cols] // Direct 2D indexing

**function: printArray()**
- prints out each array, theArray[i][j], and adding a new line after each row

**function: main()**
- VLA, which determines the size of the array, is different to the first program:

        uint8_t theArray[rows][cols];  // VLA on stack