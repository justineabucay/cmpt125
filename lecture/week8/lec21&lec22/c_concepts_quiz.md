# C Programming Concepts Comprehension Quiz

## Question 1: Basic Struct Understanding
Given this struct definition:
```c
typedef struct {
    char* name;
    int age;
    float salary;
} employee_t;
```

**Part A**: If you create an instance on the stack with `employee_t emp;`, how would you set the age to 25?

emp.age = 25;

**Part B**: If you have a pointer `employee_t* emp_ptr = malloc(sizeof(employee_t));`, how would you set the age to 25?

emp_ptr->age = 25; 

---

## Question 2: Memory Management
Consider this code:
```c
employee_t* create_employee() {
    employee_t emp;
    emp.age = 30;
    emp.salary = 50000.0;
    return &emp;  // What's wrong here?
}
```

**What is the problem with this function, and how would you fix it?**
the problem with this function is that it returns a ptr to a local variable on the stack. when the function returns, the stack frame is destroyed, making the ptr invalid
---

## Question 3: Shallow vs Deep Copy
Given this struct:
```c
typedef struct {
    int* data;
    int size;
} array_wrapper_t;
```

And this code:
```c
array_wrapper_t original;
original.size = 5;
original.data = malloc(5 * sizeof(int));
// ... fill with data ...

array_wrapper_t copy = original;  // What type of copy is this?
```

**Part A**: Is this a shallow or deep copy?
it is a shallow copy because only the struct fields are copied, not the data they point to

**Part B**: What happens if we call `free(original.data)` after this copy?
copy.data becomes a dangling ptr pt'ing to free memory

**Part C**: Write code to perform a proper deep copy.

    array_wrapper_t copy;
    copy.size = original.size;
    copy.data = malloc(original.size * sizeof(int));
    if(copy.data != NULL)
        memcpy(copy.data, original.data, original.size * sizeof(int));

---

## Question 4: Linked List Operations
Given this linked list structure:
```c
typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* head = NULL;
int count = 0;
```

**Part A**: What's wrong with this prepend function?
the order is wrong, where newNode->next = head should be before head = newNode, *which creates a self-loop*

```c
void prepend(int val) {
    node_t* newNode = malloc(sizeof(node_t));
    newNode->value = val;
    head = newNode;
    newNode->next = head;
    count++;
}
```

**Part B**: Fix the prepend function.

```c
void prepend(int val) {
    node_t* newNode = malloc(sizeof(node_t));
    newNode->value = val;
    newNode->next = head;
    head = newNode;
    count++;
}
```

**Part C**: Why do we need to check if `head == NULL` when implementing append, but not when implementing prepend?
we need to check if head is empty when implementing append because we need to traverse through the entire list to get to the last element. whereas, implementing prepend has head at the very front and therefore, we do not need to traverse through the list at all. 

---

## Question 5: Time Complexity
For a singly headed singly linked list (SHSL) with n elements:

**Part A**: What is the time complexity of inserting at the front? (O)1: constant time b/c head is at the front

**Part B**: What is the time complexity of inserting at the end? (O)n on SHSL: linear time b/c we are traversing through the list. where as, on DHSL, it is (O)n because we have a head and tail on both sides. 

**Part C**: How does adding a tail pointer (making it DHSL) change the time complexity of inserting at the end?

because we do not need to traverse through the entire list each time which makes insertion O(1)
---

## Question 6: Code Analysis
Analyze this traverse function:
```c
void print_list() {
    node_t* current = head;
    while (current->next != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}
```

**Part A**: What will this function NOT print?
it will not print the last element because the loop stops when current->next is NULL,so the last node is never printed

**Part B**: What happens if the list is empty?
current->next would cause a seg fault

**Part C**: Fix the function to work correctly in all cases.
```c
void print_list() {
    node_t* current = head;
    while (current != NULL) {  // Changed condition
        printf("%d ", current->value);
        current = current->next;
    }
}
```

---

## Question 7: Pointer Aliasing
Consider this scenario:
```c
typedef struct {
    int* numbers;
    int count;
} number_set_t;

number_set_t set1, set2;
set1.count = 3;
set1.numbers = malloc(3 * sizeof(int));
set1.numbers[0] = 10;
set1.numbers[1] = 20;
set1.numbers[2] = 30;

set2 = set1;  // Copy

set1.numbers[0] = 999;  // Modify original
```

**What value will `set2.numbers[0]` have after this code runs, and why?**
it will point to the same memory location due to shallow copy, so modifying one would affect the other

---

## Question 8: Generalization Principle
You're implementing a remove function for a linked list:
```c
void remove_first_occurrence(int target) {
    // Remove the first node that contains 'target'
}
```

**List three different scenarios you must test to ensure your function works correctly according to the generalization principle.**
check if list is empty, check if it has a single element, and check if it has multiple elements

---

## Question 9: Design Decision
You're designing a data structure to store a collection of student records where you frequently need to:
- Add new students (usually at the end)
- Remove students (could be anywhere)
- Print all students in order

**Part A**: Would you choose an array or a linked list? Justify your choice.
i would choose a linked list because we can modify the size. also, we add and remove items from anywhere.

**Part B**: If you chose a linked list, would you use SHSL or DHSL? Why?
i would choose DHSL because we allows us to access the end from tail insertion

---

## Question 10: Memory Layout
Given this struct:
```c
typedef struct {
    char flag;     // 1 byte
    int number;    // 4 bytes  
    char letter;   // 1 byte
} mixed_t;
```

**Part A**: On a 64-bit system, would this struct likely be exactly 6 bytes in memory? Why or why not?
no, it would be larger because of memory alignment padding

**Part B**: What concept from the lectures explains any size difference?
padding: the compiler adds empty bytes b/w fields to align them on favourable memory boundaries

---

## Bonus Question: Critical Thinking
**Explain why passing a struct by value to a function (like `void process(employee_t emp)`) is generally not recommended, and what you should do instead.**

## ANSWERS

### Question 1: Basic Struct Understanding
**Part A**: `emp.age = 25;` (use dot operator for direct access)
**Part B**: `emp_ptr->age = 25;` (use arrow operator for pointer access)

### Question 2: Memory Management
**Problem**: The function returns a pointer to a local variable on the stack. When the function returns, the stack frame is destroyed, making the pointer invalid (dangling pointer).

**Fix**: Allocate on the heap:
```c
employee_t* create_employee() {
    employee_t* emp = malloc(sizeof(employee_t));
    if (emp != NULL) {
        emp->age = 30;
        emp->salary = 50000.0;
    }
    return emp;
}
```

### Question 3: Shallow vs Deep Copy
**Part A**: Shallow copy - only the struct fields are copied, not the data they point to.

**Part B**: `copy.data` becomes a dangling pointer pointing to freed memory. Using it would cause undefined behavior.

**Part C**: Deep copy:
```c
array_wrapper_t copy;
copy.size = original.size;
copy.data = malloc(original.size * sizeof(int));
if (copy.data != NULL) {
    memcpy(copy.data, original.data, original.size * sizeof(int));
}
```

### Question 4: Linked List Operations
**Part A**: The order is wrong. `head = newNode;` should come before `newNode->next = head;`, but since head is already changed, this creates a self-loop.

**Part B**: Fixed function:
```c
void prepend(int val) {
    node_t* newNode = malloc(sizeof(node_t));
    if (newNode != NULL) {
        newNode->value = val;
        newNode->next = head;  // Connect to current head first
        head = newNode;        // Then update head
        count++;
    }
}
```

**Part C**: For prepend, setting `newNode->next = head` works whether head is NULL or points to a node. For append, we need to find the last node, but if head is NULL, there's no node to traverse to.

### Question 5: Time Complexity
**Part A**: O(1) - constant time (always insert at the front)
**Part B**: O(n) - linear time (must traverse to the end)
**Part C**: With a tail pointer, insertion at the end becomes O(1) because we don't need to traverse.

### Question 6: Code Analysis
**Part A**: It won't print the last element (the while loop stops when `current->next` is NULL, so the last node is never printed).

**Part B**: If the list is empty (head is NULL), `current->next` would cause a segmentation fault.

**Part C**: Fixed function:
```c
void print_list() {
    node_t* current = head;
    while (current != NULL) {  // Changed condition
        printf("%d ", current->value);
        current = current->next;
    }
}
```

### Question 7: Pointer Aliasing
**Answer**: `set2.numbers[0]` will have the value 999. Both `set1.numbers` and `set2.numbers` point to the same memory location due to the shallow copy, so modifying through one affects the other.

### Question 8: Generalization Principle
Three scenarios to test:
1. **Empty list**: What happens when trying to remove from an empty list?
2. **Single element**: What happens when the target is the only element?
3. **Multiple elements**: Target at beginning, middle, end, or not found.

### Question 9: Design Decision
**Part A**: Linked list would be better because:
- Frequent additions (especially at the end)
- Removals from anywhere (arrays require shifting elements)
- Dynamic size is beneficial

**Part B**: DHSL (Doubly Headed Singly Linked) because:
- Frequent additions at the end benefit from O(1) tail insertion
- The extra complexity of maintaining tail pointer is worth it for this use case

### Question 10: Memory Layout
**Part A**: No, it would likely be larger than 6 bytes due to memory alignment padding.

**Part B**: **Padding** - the compiler adds empty bytes between fields to align them on favorable memory boundaries (usually 4 or 8-byte boundaries for better CPU performance).

### Bonus Question: Critical Thinking
**Problems with passing by value**:
1. **Performance**: Large structs take time and memory to copy
2. **No modifications**: Changes inside the function don't affect the original
3. **Memory waste**: Unnecessary duplication of data

**Better approach**: Pass by pointer (`void process(employee_t* emp)`) to avoid copying and allow modifications.