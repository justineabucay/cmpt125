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

---
## comprehension test

**question 1**
- p is pointing to the memory address of x

**question 2**
- the value of a is now 20 because ptr contains the memory address of x and puts the value 20 in that location

*answer: put 20 at the address that ptr is pointing to*

**question 3**
- the difference between these two printf statements is that the first one will print out the memory address. the second one will print out the actual value stored at that memory address. 
