# Final Exam Practice - Answer Review and Solutions

## **Your Answer Review:**

### **Part A: Recursion Analysis** ✅ **EXCELLENT**
- ✅ Trace is perfect: 6→4→2→0, then 2+3+3+3=11
- ✅ Iterative version is correct!

### **Part B: Static Variables** ❌ **INCORRECT**
**Your Answer:** "count: 1" printed 3 times
**Issue:** You missed how static variables work and the `count *= 2` line!

**Correct Trace:**
```
Call 1: count=0→1, print "Count: 1", 1<3 so count=1*2=2
Call 2: count=2→3, print "Count: 3", 3<3 is false, no change
Call 3: count=3→4, print "Count: 4", 4<3 is false, no change
```
**Correct Output:**
```
Count: 1
Count: 3  
Count: 4
```

### **Part C: Memory Management** ❌ **PARTIALLY WRONG**
**Your Answer:** "not enough space in data, need malloc"
**Issue:** The problem isn't space - it's **returning a pointer to local array**!

**Correct Issues:**
1. **Dangling pointer:** `data[]` is on the stack, destroyed when function exits
2. **Undefined behavior:** `arr` points to invalid memory
3. **Invalid free():** Can't free stack memory with `free()`

### **Part D: Time Complexity** ❌ **INCORRECT**
**Your Answer:** O(n)
**Issue:** You missed that `strcat()` is O(length of current string)!

**Correct Analysis:**
- First iteration: strcat on length 0 → O(1)
- Second iteration: strcat on length 1 → O(2)  
- Third iteration: strcat on length 2 → O(3)
- ...
- nth iteration: strcat on length n-1 → O(n)
- **Total:** O(1+2+3+...+n) = **O(n²)**

### **Part E: Fix the Bug** ✅ **CORRECT**
Perfect! You properly used `*maxValue` to dereference the pointer.

### **Part A: Insertion Sort** ❌ **ISSUES**
**Problem 1:** [5,4,3,6,7,8] makes more than 2 swaps
**Problem 2:** Max swaps for length 5 is not 25, it's 10

---

## **Complete Solutions:**

### **Part B: Static Variables - Corrected**
```c
// Output:
Count: 1
Count: 3
Count: 4
```

### **Part C: Memory Management - Corrected**
```c
// Issues:
// 1. Returning pointer to local array (dangling pointer)
// 2. Undefined behavior when accessing arr[0], arr[1]  
// 3. free() on stack memory is invalid

// Fix:
int* createArray(int size) {
    int* data = malloc(size * sizeof(int));  // Use heap
    if (data == NULL) return NULL;
    for (int i = 0; i < size; i++)
        data[i] = i * 2;
    return data;  // Safe to return heap pointer
}
```

### **Part D: Time Complexity - Corrected**
```c
// Function creates string of n 'x' characters
// Time complexity: O(n²) due to strcat being O(current string length)
// Each strcat call gets progressively slower: O(1)+O(2)+...+O(n) = O(n²)
```

### **Problem 2: Sorting Algorithms Solutions**

#### **Part A: Insertion Sort**
```c
// 1) Array with exactly 2 swaps (length 6):
[1, 3, 2, 4, 5, 6]
// Trace: 3 and 2 need to swap, that's it! (2 swaps total)

// 2) Maximum swaps for length 5:
[5, 4, 3, 2, 1]  // Reverse sorted
// Max swaps = 4 + 3 + 2 + 1 = 10 swaps
// Formula: n(n-1)/2 where n=5 → 5*4/2 = 10
```

#### **Part B: Selection Sort Reverse**
```c
void reverse_selection_sort(int* A, const int* swaps, int n) {
    // Apply swaps in REVERSE order (from last to first)
    for (int i = n-1; i >= 0; i--) {
        // Swap A[i] with A[swaps[i]]
        int temp = A[i];
        A[i] = A[swaps[i]];
        A[swaps[i]] = temp;
    }
}
```

### **Problem 3: Linked Lists Solutions**

#### **Part A: List Comparison**
```c
bool lists_equal(LinkedList_t* list1, LinkedList_t* list2) {
    // Handle NULL cases
    if (list1 == NULL || list2 == NULL) return false;
    
    Node_t* current1 = list1->head;
    Node_t* current2 = list2->head;
    
    // Traverse both lists simultaneously
    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return false;  // Data mismatch
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    
    // Both should reach NULL at same time (same length)
    return (current1 == NULL && current2 == NULL);
}
```

#### **Part B: List Operations**
```c
// Add node to front - O(1) time
void add_to_front(LinkedList_t* list, int value) {
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->data = value;
    new_node->next = list->head;
    
    list->head = new_node;
    
    // If list was empty, update tail too
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

// Add node to back - O(1) time  
void add_to_back(LinkedList_t* list, int value) {
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->data = value;
    new_node->next = NULL;
    
    if (list->tail == NULL) {
        // Empty list
        list->head = list->tail = new_node;
    } else {
        // Add to end
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Set value at index i - O(i) time
void set_at_index(LinkedList_t* list, int index, int value) {
    Node_t* current = list->head;
    
    // Traverse to index i
    for (int i_current = 0; i_current < index; i_current++) {
        current = current->next;
    }
    
    // Set the value
    current->data = value;
}
```

#### **Part C: Advanced Operation**
```c
// Remove every other node starting from index 1
void remove_every_other(LinkedList_t* list) {
    if (list->head == NULL || list->head->next == NULL) {
        return;  // List too short
    }
    
    Node_t* current = list->head;
    
    while (current != NULL && current->next != NULL) {
        Node_t* to_remove = current->next;
        current->next = to_remove->next;
        
        // Update tail if we're removing the last node
        if (to_remove == list->tail) {
            list->tail = current;
        }
        
        free(to_remove);
        current = current->next;  // Skip one node
    }
}
```

---
