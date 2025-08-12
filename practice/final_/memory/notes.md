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
formatting, where it writes to a string; for example, ```c sprintf(str, "String %d", i)``` -> ```c String 0```, ```c String 1```
