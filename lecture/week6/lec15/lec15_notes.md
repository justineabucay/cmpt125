# dynamic memory allocation

## stack frame
- assigned to each executing function (i.e., callee), where it containts the function's local variables, constants and parameters
    - it contains the return address of the instruction in the caller to execute once it has returned back to the caller

**illustrating the memory allocation + deallocation of stack frames** 
- main() has a constant called SIZE set to 5 cells that takes in 4 bytes (i.e., integer)
- SIZE is set as the size of intArray, which is now 20 bytes long because 5 * 4 = 20 
- now, we called the function printArray, passing the memory address of intArray (i.e., first element of the array) and copying it into the argument to use locally, etc. 
    - the function is also assigned a stack frame, meaning that any execution inside the scope of this function cannot access main() and vice versa. 
    - at the end of the function, the execution flow returns back to the caller and releases automatically until it is called again. 
*a memory address is seen as an array of 8 bytes*

## dynamic memory allocation using heap
- to allocate memory on heap segment: malloc()
- to release this heap memory: free()

*always read starting from the right end*

        int * intArray; // intArray is the variable of a pointer that is pointing ot an integer

here, the function malloc() allocates 20 bytes on the heap and assigns the address of allocated memory in the pointer variable, anArray, which is pointing to the first integer in this block

        int * anArray = malloc( maxsize * sizeof(int) );

