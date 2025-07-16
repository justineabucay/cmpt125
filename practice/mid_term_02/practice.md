## question 1
```c
    float intArray_average(intArray_t * ia); // function declaration
```

## question 2
```c
    float printArray(int * anArray, unsigned int SIZE, unsigned int index){
        if(anArray == NULL || index == SIZE) return; 

        printf("%d ", anArray[index]);

        printArray(anArray, index + 1, SIZE);
    }
```


## question 3 
```c
    if(ia == NULL) returns INTARR_BADPARAM;
    if(ia->data == NULL) returns INTARR_BADPARAM;

    if(ia->elementCount > 0){
        for(unsigned int i = 0; i < ia->elementCount; i++){
            if(ia->data[i] == targetElement){
                *index = i; 
                return INTARR_OK;
            }
        }
    }

    return INSTARR_BADPARAM; 
```

====

## part 1
1. d
2. b
3. b
4. b
5. d

## part 2 
### question 1 
```c
    int countTarget(intArray_t * ia, int targetElement);
```

### question 2
```c
int countTarget(intArray_t * ia, int targetElement){
    int countOccurence = 0;
    if(ia == NULL || ia->countElements == 0) return 0; 

    if(ia->data == NULL) return 0;

    for(unsigned int = 0; i < ia->countElements; i++){
        if(ia->data[i] == targetElement) countOccurence++: 
    }

    return countOccurence; 
}
```

### question 3
```c
    int* intArray_findAll(intArray_t *ia, int targetElement, unsigned int *count){
        *count = 0; 

        if(ia == NULL || count == NULL) return NULL; 

        if(ia->data == NULL) return NULL: 

        if(ia>elementCount == 0) return NULL;

        unsigned int occurences = 0; 
        for(unsigned int = 0; i < ia->countElements; i++){
            if(ia->data[i] == targetElement) occurences++: 
        }

        if(occurences == 0) return NULL;

        int *indices = malloc(occurences * sizeof(int));
        if(indices == NULL) return NULL;

        unsigned int indexPos = 0;
        for(unsigned int i = 0; i < ia->countElements; i++){
            if(ia->data[i] == targetElement){
                indices[indexPos] = i;
                indexPos++;
            }
        }

        *count = occurence;

        return indices;

    }
```

### question 4
#### test case #1
removing element at index 1
test data: 2, 10, 20, 30
expected results: 2, 20, 30

removing e

### question 5
line 1: O(1)
line 2: O(n)
line 3: O(1)
line 5: O(n)
line 6: O(n)
line 7-8: O(1)

nested statements: O(n^2)
sequential statements: O(n)

total: O(n^2)



### question 4
#### test case #1
overwrite element at index 2 with 5
- test data:
    - array contains: [0, 1, 4, 5] 
    - newElement = 5
    - index = 2
- expected result:
    - function returns INTARR_OK
    - array should contain: [0, 1, 5, 5]

#### test case #2
overwrites element in a single-size array
- test data:
    - array contains: [1]
    - newElement = 2
    - index = 0
- expected result:
    - function returns INTARR_OK
    - array should contain: [2]

#### test case #3
ia is NULL
- test data:
    - array is NULL
    - index = 2
    - newElement = 1
- expected result:
    - function returns INTARR_BADPARAM
    - no operations should be performed

#### test case #4
index is out of bounds
- test data:
    - array contains: [1, 3, 4]
    - newElement = 5
    - index = 3
- expected result: function returns INTARR_BADPARAM
- no operations should be performed

=== 
### question 1
- bugs found in the code: 
    - we are not validation whether the allocation of malloc is successful
    - it is forgetting to free msg2
    - also, it does not set both msg1 and msg2 to NULL
- corrected version
```c
    char* createMessage(int count) {
    char message[100];
    sprintf(message, "Processing %d items", count);
    
    char* result = malloc(strlen(message)) + 1; // '+ 1' for null terminator
    if(result == NULL) return NULL;
    strcpy(result, message);
    return result;
}

void processData() {
    char* msg1 = createMessage(42);
    char* msg2 = createMessage(100);
    
    printf("Messages: %s and %s\n", msg1, msg2);
    
    free(msg1);
    free(msg2);
    msg1 = NULL;
    msg2 = NULL;
}
```

### question 2
- the time complexity of this function is O(n^3) because it has 2 nested loops, which is not ideal
- this implementation does not check whether arr is empty or is valid. also, it make it do a second search after the first one. numElements is passed by value, so changes do not persist and therefore, it should be a pointer (i.e., int* numElements)

```c
bool findAndReplaceAll(int* arr, int* numElements, int oldValue, int newValue){
    if(arr == NULL || numElements == NULL *numElements <= 0) return false; 

    bool found = false; 
    for(unsigned int i = 0; i < *numElements; i++){
        if(arr[i] == oldValue)
            arr[i] = newValue; 
            found = true; 
    }

    int writeIndex = 0; 
    for(unsigned int readIndex = 0; readIndex <  *numElements; readIndex++){
        bool isDuplicate = false; 
        for(int j = 0; j < writeIndex  && !isDuplicate; j++){
            if(arr[j] == arr[readindex]){
                isDuplicate = true;
           
            }
        }

        if(!isDuplicate){
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    *numElements = writeIndex; 
    return found;
}
```

### question 3

```c

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;  // DHSL
    int count;
} list_t;

int removeEveryNth(list_t* list, int n) {
    // Validate parameters
    if (list == NULL || n <= 0) {
        return 0;
    }
    
    // Handle empty list
    if (list->head == NULL) {
        return 0;
    }
    
    // Handle n == 1 (remove all)
    if (n == 1) {
        int removedCount = list->count;
        while (list->head != NULL) {
            node_t* nodeToRemove = list->head;
            list->head = list->head->next;
            free(nodeToRemove);
        }
        list->tail = NULL;
        list->count = 0;
        return removedCount;
    }
    
    int counter = 1;
    int removedCount = 0;
    node_t* current = list->head;
    node_t* previous = NULL;
    
    while (current != NULL) {
        if (counter == n) {
            // Remove this node
            node_t* nodeToRemove = current;
            
            // Update links
            if (previous == NULL) {
                // Removing head
                list->head = current->next;
                if (list->head == NULL) {
                    list->tail = NULL;  // List is now empty
                }
            } else {
                previous->next = current->next;
                // Update tail if we're removing the last node
                if (current == list->tail) {
                    list->tail = previous;
                }
            }
            
            // Move to next and clean up
            current = current->next;
            free(nodeToRemove);
            removedCount++;
            list->count--;
            counter = 1;  // Reset counter
        } else {
            // Move to next node
            previous = current;
            current = current->next;
            counter++;
        }
    }
    
    return removedCount;
}
```


tracing through the code above (part 2)
list: 1, 2, 3, 4, 5, 6
n: 2
iteration #1 current = 1, previous = NULL; move to next node: previous = 1, current = 2, counter = 2
interation #2 current = 2, previous = 1, counter = 2 == n = 2 -> remove: nodeToRemove = current = 2, previous->next: current->next = 3 -> move to next node: current = current->next: 3, delete 2 from memory by freeing it, increment removedCount by 1 (i.e., removedCount = 1), list->count-- (i.e., decrease list count), counter = 1 (i.e., reset to 1)
interation #3 current = 3, previous = 1, counter = 1 != n = 2 -> move to next node:  previous = 3, current = 4, counter = 2
iteration #4 current = 4, previous = 3, counter = 2 == n = 2 -> remoe: nodeToremove = current = 2, previous->next: current->next = 5 -> move to next node: current = current->next: 5, delete 4, increment removedCount (i.e., removedCount = 2), list->count--, counter = 1
iteration #5 current = 5, previous = 3, counter = 1 != n = 2 -> move to next node: previous = 5, current = 6, counter = 2

### question 5: image rotation

```c
unsigned char* rotateImage90(unsigned char* original, 
                            unsigned int width, 
                            unsigned int height,
                            unsigned int* newWidth,
                            unsigned int* newHeight) {
    // Validate parameters
    if (original == NULL || newWidth == NULL || newHeight == NULL) {
        return NULL;
    }
    
    if (width == 0 || height == 0) {
        return NULL;
    }
    
    // Calculate new dimensions (90° clockwise rotation)
    *newWidth = height;   // New width = original height
    *newHeight = width;   // New height = original width
    
    // Allocate memory for rotated image
    unsigned char* rotated = malloc(*newWidth * *newHeight * sizeof(unsigned char));
    if (rotated == NULL) {
        return NULL;  // Memory allocation failed
    }
    
    // Perform rotation: pixel at (x,y) goes to (y, height-1-x)
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            // Original pixel position
            unsigned int originalIndex = y * width + x;
            
            // New position after 90° clockwise rotation
            unsigned int newX = y;
            unsigned int newY = (height - 1) - x;
            unsigned int newIndex = newY * (*newWidth) + newX;
            
            // Copy pixel to new position
            rotated[newIndex] = original[originalIndex];
        }
    }
    
    return rotated;
}
```

### question 6: recursive vs iterative
#### iterative binary search

```c
// find the middle
// compare middle with target element
// if middle == target element, return index of middle
// if target element < middle, search on the left side and repeat
// if target element > middle, search on the right side and repeat

binarySearch(array, size, elementCount, target){
    set position to value TARGET_NOT_FOUND
    set targetNotFound to value true
    set first = 0
    set last = elementCount - 1
    
    if array not empty
        while targetNotFound AND have not looked or discarded every element of array
            (first <= last)
            
            middleIndex = floor( (first + last) / 2 )
            
            if array[middleIndex] == target
                set position to middleIndex // position of target in array
                set targetNotFound to false
            else
                if target < array[middleIndex]
                    last = middleIndex – 1 // ignore second half of array
                else
                    first = middleIndex + 1 // ignore first half of array
    
    return position


    

}

const int TARGET_NOT_FOUND = -1;

int binarySearch(int *arr, int size, int elementCount, int target){
    int position = TARGET_NOT_FOUND; 
    bool targetNotFound = true;
    int first = 0; 
    int last = elementCount - 1; 

    if(arr != NULL){
        while(targetNotFound && first <= last){
            int middle = (first + last) / 2;  // floor() not needed for integers
            
            if(arr[middle] == target){
                position = middle; 
                targetNotFound = false;
            } else {
                if(target < arr[middle]) 
                    last = middle - 1;
                else 
                    first = middle + 1; 
            }
        }
    }
    return position;
}

// Wrapper function (same signature as iterative version)
int binarySearch(int *arr, int size, int elementCount, int target) {
    if (arr == NULL) {
        return TARGET_NOT_FOUND;
    }
    return binarySearchRecursive(arr, 0, elementCount - 1, target);
}

// Recursive helper function
int binarySearchRecursive(int *arr, int first, int last, int target) {
    // BASE CASE 1: Search space exhausted
    if (first > last) {
        return TARGET_NOT_FOUND;
    }
    
    // Find middle element
    int middle = (first + last) / 2;
    
    // BASE CASE 2: Target found
    if (arr[middle] == target) {
        return middle;
    }
    
    // RECURSIVE CASES: Search smaller half
    if (target < arr[middle]) {
        // Search left half
        return binarySearchRecursive(arr, first, middle - 1, target);
    } else {
        // Search right half  
        return binarySearchRecursive(arr, middle + 1, last, target);
    }
}
```
##### part a
- iterative: O(1) - uses a few variables
- recursive: O(log n) - each recursive call is a new stack frame
##### part b
- iterative: saves memory space w/ O(1) + no stack overflow
##### part c
- recursive can be problemic with very large arrays 