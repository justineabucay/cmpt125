# CMPT 125 Practice Test - Key Concepts

**Suggested Time Limit: 50 minutes** (similar to your actual exam format)
*Allocate time based on mark values: ~1 minute per mark*

---

## Question 1: Array Indexing and Memory [3 marks - 3 minutes]

You are modeling a 2D raster image of width = 10 and height = 6 using a 1D C array.

**a** What index would pixel coordinates (7, 4) map to in your 1D array? Show your work.  

formula: int index = x + y * width.  
index = 7 + 4 * 10. 
index = 7 + 40. 
index = 47. 

**b** Write the general formula for converting 2D coordinates (x, y) to a 1D array index.
formula: int index = x + y * width. 
---

## Question 2: Time Complexity [2 marks - 2 minutes]

What is the time complexity (Big O notation) for each of the following operations:

**a** Inserting at the beginning of a singly linked list
O(1) 

**b** Finding the maximum element in an unsorted array of size n
O(n); tranverse through each element of the array
---

## Question 3: Dynamic Memory Allocation [6 marks - 6 minutes]

Write syntactically correct C code that:
- Dynamically allocates memory for an array called `dataArray` of 50 integers
- Includes proper error checking
- Specify which memory segment this array will be allocated in

```c
// Your code here:
const int SIZE = 50;
int *dataArray = malloc(SIZE * sizeof(int)); 
if(dataArray == NULL){
    printf("oh no! the allocation failed!");
    return 0;       // failed
}

this array  will be allocated on the heap region, where we can access it anywhere in our code through the pointer variable, dataArray.

```

---

## Question 4: Recursion [8 marks - 8 minutes]

Write a recursive function `sumArrayR` that calculates the sum of all elements in an integer array. The function should have the signature:

```c
int sumArrayR(int* arr, unsigned int size);
```

Include proper base case(s) and recursive case.

```c
// Your function here:
// base case


if(size == 0)
    return 0;
return arr[size-1] + sumArray(arr, size-1);

```

---

## Question 5: Struct and Function Implementation [12 marks - 12 minutes]

Given the following data types:
```c
typedef struct {
    int* data;
    unsigned int size;
    unsigned int elementCount;
} intArray_t;

typedef enum {
    INTARR_OK,
    INTARR_ERROR,
    INTARR_BADPARAM
} intArrayResult_t;
```

Write a function `intArray_findMax` that:
- Finds the maximum value in the array
- Sets `*maxValue` to the result and returns `INTARR_OK`
- Returns `INTARR_BADPARAM` if `ia` is NULL or `ia->data` is NULL
- Returns `INTARR_ERROR` if the array is empty
- Time complexity: **O(n)**

```c
intArrayResult_t intArray_findMax(intArray_t* ia, int* maxValue) {
    // Your implementation:
    if(ia == NULL || ia->data == NULL) return INTARR_BADPARAM; 
    if(ia->elementCount == 0) return INTARR_ERROR;

    maxValue = ia->data[0]; 
    for(unsigned int i = 1; i < ia->elementCount; i++){
        if(ia->data[i] > *maxValue)
            *maxValue = ia->data[i];
    }
    
    return INTARR_OK;
    
}
```

---

## Question 6: Code Analysis [8 marks - 8 minutes]

Analyze this C code fragment:

```c
int mystery(int arr[], unsigned int size) {
    const unsigned int CELLS = 5;
    int result[CELLS];
    
    for (unsigned int i = 0; i < CELLS; i++)
        result[i] = 0;
    
    for (unsigned int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0)
            result[arr[i] % CELLS]++;
    }
    
    int total = 0;
    for (unsigned int i = 0; i < CELLS; i++)
        total += result[i];
    
    return total;
}
```

**a)** What does this function return when called with array `{3, 6, 9, 12, 15, 18}` and size `6`?
it will return total which we know is 6
**b)** Briefly explain what this function does in general.
basically, this function returns total. first, we have declared an array called resultwith the size of CELLS (i.e., 5) and we initialize each element in result to 0. in the second loop, each element of arr passes the condition because they are all divisible by 3. therefore, each element is at least incremented once, while the element at index 2 is incremented twice; our array looks like this: [1, 1, 2, 1, 1], with a total of 6
---

## Question 7: Input Validation Loop [11 marks - 11 minutes]

Write a complete C program that:
- Reads integers from the user until EOF
- Only accepts integers in the range [1, 100] (inclusive)
- For invalid inputs, prints: `"<value> is out of range!"`
- After EOF, prints the count of valid numbers entered
- If no valid numbers were entered, prints: `"No valid numbers entered."`

```c
#include <stdio.h>

int main(void) {
    // Your complete program:
    int result = 0; 
    int valid = 0;
    while(scanf("%d", &result) == 1){
        if(result >= 1 && result <= 100)
            valid++;
        else
            printf("<%d> is out of range!\n", result); 
    }

    printf("the number of valid numbers enters is...<%d>\n", valid);

    
    return 0;
}
```
**solution.**
```c
#include <stdio.h>

int main(void) {
    // Your complete program:
    int result = 0; 
    int valid = 0;
    while(scanf("%d", &result) == 1){
        if(result >= 1 && result <= 100)
            valid++;
        else
            printf("<%d> is out of range!\n", result); 
    }

// missing this part
if(valid==0)        
    printf("no valid numbers entered\n");
else
    printf("the number of valid numbers enters is...<%d>\n", valid);

    
    return 0;
}
```

---

## Key Concepts to Focus On:

1. **Array indexing formulas** (2D to 1D conversion)
2. **Time complexity analysis** (Big O notation)
3. **Dynamic memory allocation** with error checking
4. **Recursive function design** (base cases + recursive cases)
5. **Struct manipulation** and function return values
6. **Input validation loops** with scanf and EOF handling
7. **Variable scope** in loops and functions
8. **Pointer notation** vs array notation
9. **Memory segments** (stack, heap, etc.)
10. **Code tracing** and logic analysis

