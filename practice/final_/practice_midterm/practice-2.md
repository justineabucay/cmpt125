# CMPT 125 Final Exam Practice Test

**Suggested Time Limit: 90 minutes** (half of actual final exam)
*This covers the most important concepts from each problem*

---

## **Problem 1: Code Analysis and Debugging [35 points - 35 minutes]**

### **Part A: Recursion Analysis [8 points - 8 minutes]**

Analyze this recursive function:

```c
int mystery(int n) {
    if (n <= 1)
        return 2;
    else {
        printf("%d ", n);
        return mystery(n-2) + 3;
    }
}
```

**1)** What does `mystery(6)` return? Show the execution trace.
mystery(6):
n = 6, print 6; return mystery(4) + 3
mystery(4):
n = 4, print 4; return mystery(2) + 3
mystery(2):
n = 2, print 2; return mystery(0) + 3
mystery(0)
n = 0, return 2

mystery(6) = 2 + 3 + 3 + 3 = 11
**2)** Write an equivalent non-recursive (iterative) version of this function.
int n = 6;
int result = 2; // Start with base case value

// Keep going while n > 1
while (n > 1)
{
    printf("%d ", n); // Print current n
    n = n - 2;        // Reduce n by 2
    result += 3;      // Add 3 for this step
}

printf("result: %d\n", result);
---

### **Part B: Static Variables [6 points - 6 minutes]**

Will this code compile? If yes, what's the output? If no, explain the errors:
the output will just be "count: 1" printed 3 times on the screen

```c
#include <stdio.h>
void counter() {
    static int count = 0;
    count++;
    printf("Count: %d\n", count);
    if (count < 3)
        count *= 2;
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```

---

### **Part C: Memory Management Issues [8 points - 8 minutes]**

Will this code compile and run correctly? Explain any issues:
no, there will be an error because there will not be enough space in data. we need to call malloc in order to take care memory for 3 integers, which in total is 12 bytes. 

```c
#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int data[size];
    for (int i = 0; i < size; i++)
        data[i] = i * 2;
    return data;  // Returning local array
}

int main() {
    int* arr = createArray(3);
    printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
    free(arr);  // Freeing stack memory
    return 0;
}
```

---

### **Part D: Time Complexity Analysis [8 points - 8 minutes]**

Consider this function:

```c
char* buildString(int n) {
    char* result = malloc(n + 1);
    result[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(result, "x");  // strcat is O(length of result)
    }
    return result;
}
```

**1)** What does this function do?
we are concatenating "x" to the string result n amount of times and returning result at the end
**2)** What is the time complexity? Explain your reasoning.
the time complexity is O(n) because we are going through each element until we reach n
---

### **Part E: Fix the Bug [5 points - 5 minutes]**

Fix this function so it works correctly:

```c
int findMax(int* arr, unsigned int size, int* maxValue) {
    if (arr == NULL || maxValue == NULL) return -1;
    if (size == 0) return -1;
    
    *maxValue = arr[0];  // BUG: Should use pointer
    for (unsigned int i = 1; i < size; i++) {
        if (arr[i] > *maxValue)  // BUG: Wrong comparison
            *maxValue = arr[i];   // BUG: Wrong assignment
    }
    return 0;
}
```

---

## **Problem 2: Sorting Algorithms [25 points - 25 minutes]**

### **Part A: Insertion Sort Analysis [10 points - 10 minutes]**

**1)** Give an array of length 6 where Insertion Sort makes exactly **2 swaps**. Explain your answer.
array: [5, 4, 3, 6, 7, 8]

**2)** Give an array of length 5 where Insertion Sort makes the **maximum possible swaps**. How many swaps is that?
[4, 3, 2, 1, 0]; there will be the maximum swaps O(5^2) = 25
---

### **Part B: Selection Sort Variant [15 points - 15 minutes]**

Consider this modified Selection Sort that records the swaps:

```
For i = 0 to n-1:
    Find minimum element in A[i...n-1] at index j
    Swap A[i] with A[j]
    Record j in array swaps[i]
```

**Example:** Starting with `[7, 2, 9, 1, 5]`
- i=0: min at j=3, swap 7↔1 → `[1, 2, 9, 7, 5]`, swaps[0]=3
- i=1: min at j=1, swap 2↔2 → `[1, 2, 9, 7, 5]`, swaps[1]=1
- i=2: min at j=4, swap 9↔5 → `[1, 2, 5, 7, 9]`, swaps[2]=4
- i=3: min at j=3, swap 7↔7 → `[1, 2, 5, 7, 9]`, swaps[3]=3
- i=4: min at j=4, swap 9↔9 → `[1, 2, 5, 7, 9]`, swaps[4]=4

**Task:** Write a function that "reverses" this process:

```c
// Given sorted array A and swaps array, restore original array
void reverse_selection_sort(int* A, const int* swaps, int n) {
    // Your implementation
}
```

**Hint:** Apply the swaps in reverse order!

---

## **Problem 3: Linked Lists [30 points - 30 minutes]**

Given this linked list structure:
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node_t;

typedef struct {
    Node_t* head;
    Node_t* tail;
} LinkedList_t;
```

### **Part A: List Comparison [10 points - 10 minutes]**

Write a function that compares two linked lists for equality. **Important:** The function must run in O(min(len1, len2)) time.

```c
bool lists_equal(LinkedList_t* list1, LinkedList_t* list2) {
    // Your implementation - must be O(length of shorter list)
    int curr = list1->head; 
}
```

---

### **Part B: List Operations [15 points - 15 minutes]**

Implement these functions:

```c
// Add node to front - O(1) time
void add_to_front(LinkedList_t* list, int value) {
    // Your implementation
}

// Add node to back - O(1) time  
void add_to_back(LinkedList_t* list, int value) {
    // Your implementation
}

// Set value at index i - O(i) time
void set_at_index(LinkedList_t* list, int index, int value) {
    // Your implementation - assume valid index
}
```

---

### **Part C: Advanced Operation [5 points - 5 minutes]**

Write a function that removes every other node starting from index 1:

```c
// Example: [1,2,3,4,5] → [1,3,5] (removes indices 1,3)
void remove_every_other(LinkedList_t* list) {
    // Your implementation
}
```

---
