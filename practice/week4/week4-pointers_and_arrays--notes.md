# what is a pointer?


**variables + memory**
- variables have names + values that can be changed
- computer assigns specific memory blocks to hold the values of the variable
- in a 32-bit system, an integer takes 4 bytes of memory

we can test out the size of a value using the following function sizeof()

        #include <stdio.h>

        int main()  
        {  
            printf("size of a short is %d\\n", sizeof(short));  
            printf("size of a int is %d\\n", sizeof(int));  
            printf("size of a long is %d\\n", sizeof(long));  
        }

**two types of values**
- **rvalue**: the actual value stored in memory, and they usually appear on the right side of the assignment
- **lvalue**: the represent the location (i.e., memory address) where the value is stored 

        lvalue = 0x1000; // the house address
        rvalue = 42; // the actual value

for example: 

        a = b;          // lvalue = rvalue (address = value)
        a = 15;         // lvalue = rvalue (address = literal)
        a = a + b;      // lvalue = rvalue (address = expression result)

**why does this matters?**

        int x = 42; 
        int *ptr;

        ptr = &x;       // storing the lvalue of x in ptr 
                        // now, ptr contains the memory address of x

        *ptr = 99;      // use the memory address of x as an lvalue
                        // put 99 at the address
                        // now, x has the value of 99 

**pointers**
- pointer: a variable that stores memory addresses, usually declared w/ as the following:

        int *ptr;

**key operators**
- & (address): gets the memory address of a variable

        ptr = &k;

- * (deference): accesses the value at the address the pointer holds

        *ptr = 7;

## comprehension test

**question 1**
- p is pointing to the memory address of x

**question 2**
- the value of a is now 20 because ptr contains the memory address of x and puts the value 20 in that location

*answer: put 20 at the address that ptr is pointing to*

**question 3**
- the difference between these two printf statements is that the first one will print out the memory address. the second one will print out the actual value stored at that memory address. 

---
# pointer types and arrays

**pointer arithmetic**  

        int *ptr = 2;       // copies 4 bytes (size of int)
        ptr + 1;            // adds 4 bytes, not 1 

**ways to access array**
 
        arr[0], arr[1];     // array notation
        *(ptr+0), *(ptr+1); // pointer notation

**array name as address**
- array name is equivalent to the memory address of the first element of the array

        my_array = &my_array[0]

you can always change where a pointer is pointing to because it is a variable. however, we cannot change where an array points to because it is a constant, meaning that the array has a fixed memory block<br>

however, we can always change the content of an array, such as that below:

        int *ptr;
        ptr = my_array;         // ptr is pointing to the memory address of the array
        ptr = &my_array[0];     // same thing -- it is pointing to the memory address of the array
        *(ptr + 2) = 99;        // change the content at the address
        my_array[2] = 99;       // again, same thing as above -- that is, it is modifying the content of the arr
        

to know the size of an array:

        int arr[5];             // initializing an array of 5 integers, where the size of an integer is 4 bytes and therefore, 5 * 4 = 20 bytes

## comprehension test

**question 1**
- p + 3 will point to memory address 1012 because we know an array will be located at a memory address of at least 1000. knowing this, because int has 4 bytes of memory, and the ptr is traversing 3 positions from element, 4 * 3 = 12 + 1000 = 1012

**question 2**
- the value 30 can be access using *(ptr + 3) and arr[3] 

*answer: arr[2], *(ptr +2) and ptr[2]*

**question 3**
- we cannot have an array as a pointer because both arrays are not variables and haved fixed memory blocks

**question 4**
- the differense is that the first one is point to the actual value located at that address, and the second one is actually add 2 to the value located at that address

**question 5**
- cp + 5 will point to 505. when it is double *dp, it is 540

**question 6**
- the array name is a constant, not a pointer, because a pointer is a variable that we can modify. an array, on the other hand, has a fixed memory block.


---

## pointers + strings 

**what are strings?**
- strings are an array of characters that are always terminated by a null '\0'
- keep in mind that '\0' is different from NULL, which are meant for pointers

three ways to create the same string:

        // Method 1: Manual character assignment (tedious!)
        char my_string[40];
        my_string[0] = 'T';
        my_string[1] = 'e';
        my_string[2] = 'd';
        my_string[3] = '\0';

        // Method 2: Array initialization
        char my_string[40] = {'T', 'e', 'd', '\0'};

        // Method 3: String literal (easiest!)
        char my_string[40] = "Ted";  // Automatically adds '\0'

**pointers + string maniputation: string copying**

        char +pA = strA     // pA points to the first character of strA
        char +pB = strB     // pB points to the first character of strB

        while(*pA != '\0)   // while not at the end of the string
        {
            *pB++ = *pA++;  // copy character and move both pointers forward

        }

        *pB = '\0';         // terminate 

to break down the line *pB++ = *pA++
1. pA* = retrieves the character pointed to by pA
2. *pB = then, store that character where pB points
3. pA++ = move pA to the next character
4 pB++ = move pB to next position

**function parameter + strings**
- when we passa string to a function, we are passing the address of the first character

        // Function prototype
        int puts(const char *s);    // promises not to modify the string

        // When you call:
        puts(strA);                 // Passes address of strA[0]
        puts(pA);                   // Passes same address (if pA = strA)

**why use pointers for arrays**
- the reason why we use pointers for arrays is that it only passes the address of the array. when we do not use a pointer, it copies the entire array -- which might take a lot of memory 

        // Efficient - only passes address
        void process_array(int *arr, int size);

        // Call it
        int big_array[5000];
        process_array(big_array, 5000);  // Only address is passed!