# handtrace get_name.c to find the bug
## to find the bug:
- main() has stack frame allocated to a variable called name. we have the allocation of the variable called name, a pointer that is pointing to a char with 8 bytes of memory. 
- now, we are on the stack frame of the function get_name(), which has a constant called 'size' that is given a memory space within the stack frame and has the value 1024 inserted to that memory space. 
- line is an array of char which has 1024 cells from size.
- fget(), a function that allows us to enter strings or arrays of characters, is used to check for failure.
    - fget() expects parameters like the following: 
        - arr: the memory address of the first element
        - size: the maximum size of characters
        - stdin (i.e., reading from the keyboard)
- this function returns line or the memory address of the first byte of line. in other wise, when we are returning a value, it is releasing the stack frame of a function, making it inaccessible. 
- now, name contains the memory address of the first byte copied from get_name(). however, because the stack frame of get_name() is no longer accessible, it is overwriting its values with garbage and therefore, is a bug. 
- to summarize: never return a pointer that points to memory inside the stack frame of a function.

## fixing the bug: solution #1
**example: get_name_parent.c**
- have the caller allocate the array and pass a pointer to it. now, get_name() receives a pointer to an array allocated in the stack frame of main(), which exists longer than the stack frame of get_name().
- however, we do not know how large the array is calling and sometimes, it may not be possible to allocate memory in main().

## fixing the bug: solution #2 = dynamic memory allocation 
**example: get_name_dynamic.c**
- using malloc to allocate memory on the heap and returns a pointer to it. this memory address is accessible until the system calls free(). before then, any function may access the memory as as long as it knows its memory address
- in this example, get_name() calls malloc() to return the memory address of the first byte on the heap and checks if it worked 
- to check if the memory has been released on the heap (or a memory leak occurred): valgrind -q --leak-check=full ./<//executable//> 