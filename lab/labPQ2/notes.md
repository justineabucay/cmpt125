

## List.h - Header File

```cpp
#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {

private:
    /* Data Members */
    Node * head = nullptr;           // Pointer to first node
    Node * tail = nullptr;           // Pointer to last node  
    unsigned int elementCount = 0;   // Current number of elements
    
    /* Private Helper */
    Node* getNodeAt(unsigned int position) const;  // Get node at position
	
public:
    // Constructors and Destructor
    List();                                    // Default constructor
    List(const List& other);                  // Copy constructor
    ~List();                                  // Destructor
    
    // Assignment operator
    List& operator=(const List& other);

    // Basic Information Methods
    unsigned int getElementCount() const;
    unsigned int size() const;                
    bool isEmpty() const;

    // Insertion Methods
    bool append(int newElement);
    bool prepend(int newElement);
    bool insertAt(unsigned int position, int newElement);
    bool insertSorted(int newElement);        

    // Removal Methods
    bool removeAtFront();
    bool removeAtBack();
    bool removeAt(unsigned int position);
    bool remove(int element);                 
    bool removeAll(int element);              
    void clear();                            

    // Access/Retrieval Methods
    bool getFrontElement(int* frontElement) const;
    bool getBackElement(int* backElement) const;
    bool getAt(unsigned int position, int* element) const;
    int indexOf(int element) const;           
    bool contains(int element) const;

    // Utility Methods
    void reverse();                          
    List* copy() const;                      
    void sort();                            
    
    // Statistical Methods
    bool getMax(int* maxElement) const;
    bool getMin(int* minElement) const;
    
    // List Operations
    bool equals(const List& other) const;
    void merge(const List& other);          
    
    // Display Methods
    void printList() const;
    void printReverse() const;              
};

#endif
```

---

## Method Explanations

### **Constructor & Destructor Methods**

#### **Default Constructor: `List()`**
```cpp
List::List() {}
```
**What it does:** Creates an empty list with `head = nullptr`, `tail = nullptr`, `elementCount = 0`  
**Time Complexity:** O(1)  
**Example:** `List myList;` creates an empty list

#### **Copy Constructor: `List(const List& other)`**
```cpp
List::List(const List& other) {
    if (other.head == nullptr) return;
    
    Node* otherCurrent = other.head;
    while (otherCurrent != nullptr) {
        append(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
}
```
**What it does:** Creates a deep copy of another list by traversing it and appending each element  
**Time Complexity:** O(n) where n is the size of the other list  
**Example:** `List list2(list1);` creates a copy of list1

#### **Destructor: `~List()`**
```cpp
List::~List() {
    clear();
}
```
**What it does:** Automatically called when list goes out of scope; removes all nodes to prevent memory leaks  
**Time Complexity:** O(n)  
**Note:** Uses `clear()` method to safely delete all nodes

---

### **Basic Information Methods**

#### **Get Element Count: `getElementCount()` & `size()`**
```cpp
unsigned int List::getElementCount() const {
    return elementCount;
}

unsigned int List::size() const {
    return elementCount;
}
```
**What it does:** Returns the number of elements in the list  
**Time Complexity:** O(1) - just returns stored counter  
**Example:** `int count = myList.size();`

#### **Is Empty: `isEmpty()`**
```cpp
bool List::isEmpty() const {
    return elementCount == 0;
}
```
**What it does:** Checks if the list has no elements  
**Time Complexity:** O(1)  
**Example:** `if (myList.isEmpty()) { /* handle empty list */ }`

---

### **Insertion Methods**

#### **Append: `append(int newElement)`**
```cpp
bool List::append(int newElement) {
    Node * newNode = new(std::nothrow) Node(newElement);
    if(newNode){
        if(head == nullptr)           // Empty list case
            head = newNode;
        if(tail != nullptr)           // Link old tail to new node
            tail->next = newNode;
        tail = newNode;               // Update tail
        elementCount++; 
        return true;
    }
    return false; 
}
```
**What it does:** Adds element to the **end** of the list  
**Time Complexity:** O(1) - direct access via tail pointer  
**Visual:** `[3,7,9] → append(5) → [3,7,9,5]`  
**Returns:** `true` if successful, `false` if memory allocation failed

#### **Prepend: `prepend(int newElement)`**
```cpp
bool List::prepend(int newElement) {
    Node * newNode = new(std::nothrow) Node(newElement);
    if(newNode){
        if(tail == nullptr)           // Empty list case
            tail = newNode;
        if(head != nullptr)           // Link new node to old head
            newNode->next = head;
        head = newNode;               // Update head
        elementCount++;        
        return true;
    }
    return false; 
}
```
**What it does:** Adds element to the **beginning** of the list  
**Time Complexity:** O(1) - direct access via head pointer  
**Visual:** `[3,7,9] → prepend(1) → [1,3,7,9]`

#### **Insert At: `insertAt(unsigned int position, int newElement)`**
```cpp
bool List::insertAt(unsigned int position, int newElement) {
    if (position == 0) return prepend(newElement);        // Insert at front
    if (position >= elementCount) return append(newElement); // Insert at back
    
    Node* newNode = new(std::nothrow) Node(newElement);
    if (!newNode) return false;
    
    Node* prev = getNodeAt(position - 1);    // Find node before insertion point
    newNode->next = prev->next;              // Link new node to next
    prev->next = newNode;                    // Link previous to new node
    elementCount++;
    return true;
}
```
**What it does:** Inserts element at specific position (0-indexed)  
**Time Complexity:** O(n) - must traverse to position  
**Visual:** `[3,7,9] → insertAt(1, 5) → [3,5,7,9]`  
**Edge Cases:** Position 0 becomes prepend, position ≥ size becomes append

#### **Insert Sorted: `insertSorted(int newElement)`**
```cpp
bool List::insertSorted(int newElement) {
    if (isEmpty() || newElement <= head->data) {
        return prepend(newElement);
    }
    if (newElement >= tail->data) {
        return append(newElement);
    }
    
    Node* current = head;
    unsigned int position = 0;
    
    while (current->next != nullptr && current->next->data < newElement) {
        current = current->next;
        position++;
    }
    
    return insertAt(position + 1, newElement);
}
```
**What it does:** Inserts element in correct position to maintain sorted order  
**Time Complexity:** O(n) - must find correct position  
**Example:** `[1,3,7,9] → insertSorted(5) → [1,3,5,7,9]`

---

### **Removal Methods**

#### **Remove at Front: `removeAtFront()`**
```cpp
bool List::removeAtFront() {
    if (head == nullptr) return false;
    
    Node* toBeRemoved = head;
    head = head->next;                    // Move head to next node
    
    if (head == nullptr) {                // List became empty
        tail = nullptr;
    }
    
    delete toBeRemoved;                   // Free memory
    elementCount--;
    return true;
}
```
**What it does:** Removes the first element  
**Time Complexity:** O(1)  
**Visual:** `[3,7,9] → removeAtFront() → [7,9]`

#### **Remove at Back: `removeAtBack()`**
```cpp
bool List::removeAtBack() {
    if (tail == nullptr) return false;
    
    if (head == tail) {                   // Only one element
        delete head;
        head = tail = nullptr;
        elementCount--;
        return true;
    }
    
    Node* current = head;                 // Find second-to-last node
    while (current->next != tail) {
        current = current->next;
    }
    
    delete tail;
    tail = current;                       // Update tail
    tail->next = nullptr;
    elementCount--;
    return true;
}
```
**What it does:** Removes the last element  
**Time Complexity:** O(n) - must traverse to find second-to-last node  
**Visual:** `[3,7,9] → removeAtBack() → [3,7]`  
**Note:** Slower than front removal due to singly-linked nature

#### **Remove At: `removeAt(unsigned int position)`**
```cpp
bool List::removeAt(unsigned int position) {
    if (position >= elementCount) return false;
    if (position == 0) return removeAtFront();
    if (position == elementCount - 1) return removeAtBack();
    
    Node* prev = getNodeAt(position - 1);
    Node* toBeRemoved = prev->next;
    prev->next = toBeRemoved->next;       // Bridge the gap
    delete toBeRemoved;
    elementCount--;
    return true;
}
```
**What it does:** Removes element at specific position  
**Time Complexity:** O(n) - must traverse to position  
**Visual:** `[3,7,9,5] → removeAt(2) → [3,7,5]`

#### **Remove: `remove(int element)`**
```cpp
bool List::remove(int element) {
    if (head == nullptr) return false;
    
    if (head->data == element) {          // Element is first
        return removeAtFront();
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data != element) {
        current = current->next;          // Find element
    }
    
    if (current->next == nullptr) return false; // Not found
    
    Node* toBeRemoved = current->next;
    current->next = toBeRemoved->next;
    
    if (toBeRemoved == tail) {            // Removing last element
        tail = current;
    }
    
    delete toBeRemoved;
    elementCount--;
    return true;
}
```
**What it does:** Removes first occurrence of a specific value  
**Time Complexity:** O(n) - must search for element  
**Visual:** `[3,7,9,7] → remove(7) → [3,9,7]` (only first 7 removed)

#### **Remove All: `removeAll(int element)`**
```cpp
bool List::removeAll(int element) {
    bool removedAny = false;
    
    // Remove from front while it matches
    while (head != nullptr && head->data == element) {
        removeAtFront();
        removedAny = true;
    }
    
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == element) {
            Node* toBeRemoved = current->next;
            current->next = toBeRemoved->next;
            
            if (toBeRemoved == tail) {
                tail = current;
            }
            
            delete toBeRemoved;
            elementCount--;
            removedAny = true;
        } else {
            current = current->next;
        }
    }
    
    return removedAny;
}
```
**What it does:** Removes ALL occurrences of a specific value  
**Time Complexity:** O(n)  
**Visual:** `[7,3,7,9,7] → removeAll(7) → [3,9]`

#### **Clear: `clear()`**
```cpp
void List::clear() {
    while (!isEmpty()) {
        removeAtFront();
    }
}
```

```cpp
void List::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}
```
**What it does:** Removes all elements, making the list empty  
**Time Complexity:** O(n)  
**Usage:** Called by destructor and assignment operator

---

### **Access/Retrieval Methods**

#### **Get Front Element: `getFrontElement(int* frontElement)`**
```cpp
bool List::getFrontElement(int* frontElement) const {
    if (head == nullptr) return false;
    *frontElement = head->data;
    return true;
}
```
**What it does:** Gets the first element without removing it (peek operation)  
**Time Complexity:** O(1)  
**Example:** `int first; if(list.getFrontElement(&first)) { /* use first */ }`

#### **Get At: `getAt(unsigned int position, int* element)`**
```cpp
bool List::getAt(unsigned int position, int* element) const {
    Node* node = getNodeAt(position);
    if (!node) return false;
    
    *element = node->data;
    return true;
}
```
**What it does:** Gets element at specific position without removing it  
**Time Complexity:** O(n) - uses helper method `getNodeAt()`  
**Example:** `int third; if(list.getAt(2, &third)) { /* use third element */ }`

#### **Index Of: `indexOf(int element)`**
```cpp
int List::indexOf(int element) const {
    Node* current = head;
    for (unsigned int i = 0; i < elementCount; i++) {
        if (current->data == element) {
            return static_cast<int>(i);
        }
        current = current->next;
    }
    return -1; // Not found
}
```
**What it does:** Finds the position of first occurrence of element  
**Time Complexity:** O(n)  
**Returns:** Position (0-indexed) or -1 if not found  
**Example:** `int pos = list.indexOf(7); // Returns position or -1`

#### **Contains: `contains(int element)`**
```cpp
bool List::contains(int element) const {
    return indexOf(element) != -1;
}
```
**What it does:** Checks if element exists in the list  
**Time Complexity:** O(n) - uses `indexOf()` internally  
**Example:** `if (list.contains(5)) { /* element exists */ }`

---

### **Utility Methods**

#### **Reverse: `reverse()`**
```cpp
void List::reverse() {
    if (elementCount <= 1) return;
    
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    tail = head;                          // Old head becomes new tail
    
    while (current != nullptr) {
        next = current->next;             // Save next
        current->next = prev;             // Reverse link
        prev = current;                   // Move pointers
        current = next;
    }
    
    head = prev;                          // Last node becomes new head
}
```
**What it does:** Reverses the order of all elements in the list  
**Time Complexity:** O(n)  
**Visual:** `[1,2,3,4] → reverse() → [4,3,2,1]`  
**Method:** Uses three pointers to reverse all next links

#### **Sort: `sort()`**
```cpp
void List::sort() {
    if (elementCount <= 1) return;
    
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                // Swap data values
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}
```
**What it does:** Sorts elements in ascending order  
**Time Complexity:** O(n²) - uses bubble sort algorithm  
**Visual:** `[5,1,9,3] → sort() → [1,3,5,9]`  
**Note:** Swaps data values rather than rearranging nodes

---

### **Statistical Methods**

#### **Get Max: `getMax(int* maxElement)`**
```cpp
bool List::getMax(int* maxElement) const {
    if (head == nullptr) return false;
    
    *maxElement = head->data;
    Node* current = head->next;
    
    while (current != nullptr) {
        if (current->data > *maxElement) {
            *maxElement = current->data;
        }
        current = current->next;
    }
    
    return true;
}
```
**What it does:** Finds the largest element in the list  
**Time Complexity:** O(n) - must check all elements  
**Example:** `int max; if(list.getMax(&max)) { /* use max value */ }`

---

### **List Operations**

#### **Equals: `equals(const List& other)`**
```cpp
bool List::equals(const List& other) const {
    if (elementCount != other.elementCount) return false;
    
    Node* thisCurrent = head;
    Node* otherCurrent = other.head;
    
    while (thisCurrent != nullptr) {
        if (thisCurrent->data != otherCurrent->data) {
            return false;
        }
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
    
    return true;
}
```
**What it does:** Compares two lists for identical content and order  
**Time Complexity:** O(n) - must compare all elements  
**Example:** `if (list1.equals(list2)) { /* lists are identical */ }`

#### **Merge: `merge(const List& other)`**
```cpp
void List::merge(const List& other) {
    Node* current = other.head;
    while (current != nullptr) {
        append(current->data);
        current = current->next;
    }
}
```
**What it does:** Appends all elements from another list to this list  
**Time Complexity:** O(m) where m is the size of the other list  
**Visual:** `[1,3] + [5,7] → merge() → [1,3,5,7]`

---

### **Private Helper Methods**

#### **Get Node At: `getNodeAt(unsigned int position)`**
```cpp
Node* List::getNodeAt(unsigned int position) const {
    if (position >= elementCount) return nullptr;
    
    Node* current = head;
    for (unsigned int i = 0; i < position; i++) {
        current = current->next;
    }
    return current;
}
```
**What it does:** Internal helper that traverses to a specific position  
**Time Complexity:** O(n)  
**Usage:** Used by `insertAt()`, `removeAt()`, `getAt()`, etc.  
**Returns:** Pointer to node at position, or `nullptr` if invalid position

## Usage Examples

```cpp
// Create and populate list
List myList;
myList.append(5);
myList.prepend(3);
myList.insertAt(1, 4);        // [3, 4, 5]

// Access elements
int first, last;
myList.getFrontElement(&first);  // first = 3
myList.getBackElement(&last);    // last = 5

// Search and modify
if (myList.contains(4)) {
    myList.remove(4);            // [3, 5]
}

// Utility operations
myList.reverse();                // [5, 3]
myList.sort();                   // [3, 5]

// Display
myList.printList();              // "This list has 2 elements: { 3, 5 }"
```
