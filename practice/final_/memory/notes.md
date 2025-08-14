## exercise 1.2:  understanding stack vs. heap allocation

from what i understand, the variable ```c heap_var``` and ```c heap_array``` are pointers that point to memory on the heap, where all their elements are stored.  

the closest addresses would be on the stack because they are allocated on the same stack frame and therefore, will have consecutive memory addresses. on the other hand, heap uses dynamic allocation which can place memory any where on the heap.  

## exercise 2.1

for the function ```c create_message```:
- we have a memory leak because we lose reference of the first malloc() when msg get reassigned to the second malloc. 
- this issue is a memory leak because we lose access to the first memory block that stored 'hello'. 

**solution**
- free the allocation before reassigning -- that is, cleaning it up bu using ```c free(msg)```
- we can use a separate variable, as such:
  
```c
char* msg1 = malloc(50);
strcpy(msg1, "Hello");
char* msg2 = malloc(100);
strcpy(msg2, "Hello World");
free(msg1);  // Can still free the first one
return msg2;
```

for the function ```c process_data(int* data, int size)```:
- we have memory leak if we have an early return -- that is, when ```c size <= 0``` is true and therefore, we do not free the memory after calling malloc. 

**solution**
- to initialize, the variable ```c temp``` after the validation 
- have the caller be responsible for freeing the allocated memory, as such: 
  
```c
int main() {
    int original_data[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    // Call function - it returns allocated memory
    int* processed = process_data(original_data, size);
    
    // Check if function succeeded
    if (processed == NULL) {
        printf("Error: process_data failed\n");
        return 1;
    }
    
    // Use the processed data
    printf("Processed data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", processed[i]);
    }
    printf("\n");
    
    // CRITICAL: main() must free the memory returned by process_data
    free(processed);
    processed = NULL;  // Good practice: set to NULL after freeing
    
    return 0;
}

```

for the function ```c void string_processing()```:
```c 
void string_processing() {
    for (int i = 0; i < 10; i++) {
        char* str = malloc(20);        // Allocate memory
        sprintf(str, "String %d", i);  // Use the memory
        printf("%s\n", str);           // Print it
        free(str);                     // FREE IT before next iteration!
    }
}
```

what is happening in the code block above is that we are creating a new string pointer each loop, where every loop points to a different memory block. therefore, we must free the pointer in each iteration.  

**what does ```c sprintf()``` do?**
formatting, where it writes to a string; for example, ```c sprintf(str, "String %d", i)``` -> ```c String 0```, ```c String 1``` and then we can call ```c printf("%s\n", str)``` to print the entire string to the screen

## exercise 2.2: double free + dangling pointers

```c
// Find the bugs in these functions (from your midterm pattern!)

// Bug 1: Double free
void double_free_example() {
    int* ptr1 = malloc(sizeof(int));
    int* ptr2 = ptr1;  // Both point to same memory
    
    *ptr1 = 42;
    free(ptr1);
    free(ptr2);  // ERROR! Double free
}

// Bug 2: Use after free (dangling pointer)
void dangling_pointer_example() {
    int* ptr = malloc(sizeof(int));
    *ptr = 100;
    free(ptr);
    
    printf("%d\n", *ptr);  // ERROR! Using freed memory
    *ptr = 200;            // ERROR! Writing to freed memory
}

// Bug 3: Free stack memory
void free_stack_error() {
    int stack_var = 42;
    int* ptr = &stack_var;
    free(ptr);  // ERROR! Can't free stack memory
}

// Fix these by rewriting them correctly
```

## exercise 2.3: memory management in functions
```c
// This recreates the midterm pattern - fix the memory issues
int* create_and_modify_array(int start_value) {
    int* arr = malloc(4 * sizeof(int));
    
    for (int i = 0; i < 4; i++) {
        arr[i] = start_value + i * i;  // Like your midterm: 0, 1, 4, 9
    }
    
    return arr;
}

void memory_management_test() {
    int* a1 = create_and_modify_array(0);  // Creates [0, 1, 4, 9]
    a1[0] = 200;                           // Modify first element
    
    int* a2 = create_and_modify_array(1);  // Creates [1, 2, 5, 10]
    a2 = a1;  // PROBLEM! What happens to [1, 2, 5, 10]?
    
    // Print both arrays
    printf("a1: [%d, %d, %d, %d]\n", a1[0], a1[1], a1[2], a1[3]);
    printf("a2: [%d, %d, %d, %d]\n", a2[0], a2[1], a2[2], a2[3]);
    
    free(a1);
    free(a2);  // PROBLEM! What's wrong here?
}
```

the problem that i have found in the code block above is that we lose access to the memory block of the array that we created, which our variable pointer, a2, was pointing before reassigning it to point to the same memory as a1. that means, when we print out the results, the first array will appear twice on the screen. also, when we free the pointers, a1 and a2, there will be a double-free error because -- as i said before -- that a2 is now pointing to the same memory as a1, which we have already freed.  

**our solution** we need to free a2 before reassigning it to point to a1 in order to avoid a memory leak. at the end, we can either free a1 or a2 (since they both point to the same memory).

## exercise 3.2 ##
```c
// Write these functions with proper const correctness

// Function that finds max value (shouldn't modify array)
int find_max(const int* arr, int size);

// Function that searches for a value (shouldn't modify array or search value)  
int search(const int* arr, int size, int target);

// Function that copies a string (source shouldn't be modified)
char* string_copy(char* dest, const char* src);

```