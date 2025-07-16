# structs, linked lists and memory management
## structs
- <mark>**structs**<mark>: data type that allows you to grp mult related items tgt 

        // basic syntax
        struct img_t {
            uint8_t* pixels;    // pointer to pixel array
            unsigned int cols;  // width
            unsigned int rows;  // height
        };

        // using typedef
        typedef struct {
            uint8_t* pixels;
            unsigned int cols;
            unsigned int rows;
        } img_t;  // Creates a new data type called img_t

**why do we use typedef w/ struct**
- basically, when you use the basic syntax you must use the keyword struct every single instance you have to create a variable with the type. on the other hand, with typedef, you do not need to use struct when creating the variables that use this type. 

**to access the struct members**
- **dot operator**: use when working with struct variables

        imt_t img; 
        img.cols = 640;
        img.rows = 480;

- **arrow operator**: use when working with pointers to structs

        img_t* imgptr = malloc(sizeof(img_t));
        imgptr->cols = 640;
        imgptr->rows = 480;

## memory allocation for structs
- **stack**: automatically freed when out of scope
- **heap**: must be freed manually

## shallow vs. deep copy
- **shallow copy**: copies the structs fields byte-for-byte. however, when the structs contains ptrs, both copies pt to the same memory, which creates a ptr allasing (i.e., mult ptrs to the same memory location). when a ptr allasing occurs, it could cause one of ptrs to be invalid after the other copy frees the memory. 
- **deep copy**: on the other hand, deep copy copies the struct AND allocates new memory for any ptr, resulting in each copy having its own memory space. 

        img_t original, duplicate;
        // ... initialize original ...
        duplicate.cols = original.cols;
        duplicate.rows = original.rows;
        duplicate.pixels = malloc(original.cols * original.rows * sizeof(uint8_t));
        memcpy(duplicate.pixels, original.pixels, original.cols * original.rows);

## linked lists
- data structure where nodes are connected through ptrs fotrr flexible file size management

        typedef struct element {
            int val;                    // data
            struct element* next;       // pointer to next node
        } element_t;

### types of linked lists
**SHSL (singly headed singly linked list)**: one head ptr, where each node pts to the next node, and last node pts to NULL

        element_t* head; 
        unsigned int elementCount;

**DHSL (doubly headed singly linked list)**: contains both head + tails ptrs w/ O(1) insertion at both sides. but, it can be complex to maintain

        element_t* head; 
        element_t* tail; 
        unsigned int elementCount;

### common linked list operations
#### insert at front (prepend): O(1)
- O(1): constant time, b/c we always kniw where the front is (i.e., head) and therefore, we do need to traverse through the list

        void prepend(int newVal){
            element_t* newNode = malloc(sizeof(element_t)); // assign the current head pointer to the next field of the new node, making the new node point to the current first node or NULL if list is empty
            if (newNode != NULL){   // check if newNode is NULL
                // assign newNode to head, making the new node the new first node of the list
                newNode->val = newVal;  
                // connect the new node to the existing list
                newNode->next = head; 
                // make new node the new head
                head = newNode; 
                elementCount++; // incremenent elementCount to keep track of how many elements in the list, which has 2 elements in total
            }
        }

#### insert at end (append): O(n) for SHSL, O(1) for DHSL
- O(n): linear time b/c we need to find where the end is and therefore, must traverse the entire

        void append(int newVal) {
            // first, create a new node
            element_t* newNode = malloc(sizeof(element_t));
            if (newNode != NULL) {  // check if empty
                newNode->val = newVal;  
                newNode->next = NULL;  // New node will be the last node
                
                if (head == NULL) {
                    // Case 1: Empty list
                    head = newNode; // new node becomes the first and only node
                } else {
                    // Case 2: Non-empty list - find the end
                    element_t* current = head;  // start at the beginning
                    while (current->next != NULL) { // find the last node or the node whose next ptr is NULL
                        current = current->next;  
                    }
                    current->next = newNode;    // link last node to new node
                }
                elementCount++;
            }
        }

#### remove from front - O(1)

        void removeAtFront() {
            if (head != NULL) {
                element_t* nodeToRemove = head;
                head = head->next;
                free(nodeToRemove);
                elementCount--;
            }
        }

#### traverse the list

        void traverse() {
            element_t* current = head;
            while (current != NULL) {
                printf("%d ", current->val);
                current = current->next;
            }
        }

### programming principles
#### generalization
test your code w/ the following:
- empty list
- single element list
- mult element list

#### order matters

        // CORRECT:
        newNode->next = head;
        head = newNode;

        // WRONG:
        head = newNode;
        newNode->next = head;  // This creates a self-loop!

#### memory management
- always check if malloc() returns NULL
- always free() allocated memory
- set ptrs to NULL after freeing to avoid dangling ptrs

#### when to use each structure
**arrays**
- we need random access to elements
- size is relatively fixed
- memory is a concern 

**linked lists**
- size varies significantly
- freq insertion/deletion operations
- sqn access pattern is acceptable

**structs**
- need to grp related data tgt
- want to pass mult related vals as a single parameter 
- modelling real world entities w/ mult attributes
