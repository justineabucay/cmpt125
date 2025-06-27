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

## dynamic memory allocation on heap
- to allocate memory on heap segment: malloc()
- to release this heap memory: free()

hand tracing steps:
1. starting at main(), the two variables declared on the top are allocated to the stack frame of main()
    - on this stack, it includes a constant called SIZE aand in this memory, there is a number 5, and there is a memory that 8 byte long labeled intArray
        - intArrray is 8 byte long because it is a pointer that points to an integer, and we need enough space to accomodate memory address. 
2. now, we can calling getArray which has an argument of SIZE, and it is copied onto maxsize in the parameter. when executed, getArray has a stack frame that contains a memory labeled maxsize which is 4 bytes long because it has to accomodate an unsigned int, and it has the number 5 inside it. 
    - on the stack frame, we have a memory address labeled anArray, and it has 8 bytes of memory. 
        - in this space of memory, malloc will be returning a data that determines how many bytes we want on the heap. first, it evalautes the size of an integer, which is 4, and maxsize, which 5. so, 5 * 4 = 20 bytes, meaning on the heap, there will be 20 bytes. the memory address of the lowest byte or the first byte of the 20 bytes is being returned (i.e., data) and assigned to anArray.
    - determine whether the malloc() function is successful by checking for NULL.
3. the function getArray() returns the memory address of the first byte of the first cell of anArray to the variable intArray. 
4. at the end of the main(), we are releasing the moemory by calling the free() function with intArray in its parameters. now, we are setting intArray -- or in other words, setting the pointer labeled intArray to NULL.   

*always read starting from the right end*

        int * intArray; // intArray is the variable of a pointer that is pointing ot an integer

here, the function malloc() allocates 20 bytes on the heap and assigns the address of allocated memory in the pointer variable, anArray, which is pointing to the first integer in this block

        int * anArray = malloc( maxsize * sizeof(int) );

keep in mind, when we are calling malloc(): 

        // allocate memory for an array of size integers
        int * intArr = malloc(size * sizeof(int)); 

        // myArr is a ptr to an arr of size integers on the heap
        // check if allocation failed when the ptr (i.e., myArr) is NULL
        if (myArr != NULL) 

        // release myArr by using the function free() 
        free(myArr);

        // make a segmentation fault just in case we use myArr again by assigning it to NULL
        myArr = NULL; 

**when to use heap or stack**
- the size of the stack is very limited. whereas, heap provides us more control and enough memory space to handle large arrays. 



