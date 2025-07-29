/* 
 * dataStructure.h
 *
 * Provides a data structure made of a doubly-headed singly-linked list 
 * (DHSL) of unsorted elements, in which duplicated elements are allowed.
 * 
 * A DHSL list is comprised of a single variable of data type list_t
 * and zero or more elements, where each element is stored in a node variable of
 * data type element_t. The struct list_t contains a pointer (called "head") to 
 * the first element (node in the list) in the list and a pointer (called "tail") to 
 * the last element (node) of the list. It also keeps track of the number of elements  
 * (nodes) in the list. If the list is empty, both "head" and "tail" pointers are 
 * set to NULL and "elementCount" is set to 0.
 * The first element (node in the list) contains a pointer to the "next" element,
 * and so on. The last element in the list (last node) has its "next" pointer set 
 * to NULL.
 * 
 * The interface of this data structure includes several utility 
 * functions that operate on this data structure.
 *
 * Precondition: Functions that operate on such data structure
 *               require a valid pointer to it as their first argument.
 *
 * Do not change this dataStructure.h file.
 *
 * Your name:
 * Modified Date: July 2025
*/


/*** Data structure ***/

/* List element (node): our DHSL list is a chain of these nodes. */
typedef struct element {
  int val;
  struct element * next;
} element_t;

/* List header: keeps track of the first and last list elements 
   as well as the number of elements stored in our data structure. */
typedef struct list {
  element_t * head;
  element_t * tail;
  unsigned int elementCount;
} list_t;


/*** Data structure interface ***/

/* A type for returning status codes */
typedef enum {
  LIST_OK,
  LIST_ERROR,
  LIST_NULL_PARAM
} listResult_t;


/* 
 * Description: Creates a new empty data structure of list_t type and 
 *              if successful, returns a pointer to it. 
 *              If unsuccessful, returns a NULL pointer.
 * Time Efficiency: O(1)
 */
list_t * list_create( void );

/*
 * Description: Frees all memory used by the data structure pointed to by "list". 
 *              Returns LIST_OK on success, otherwise returns LIST_ERROR.
 * Time Efficiency: O(n)
 */ 
listResult_t list_destroy( list_t * list );

/* 
 * Description: Returns a pointer to a new element i.e., a node  
 *              containing "newElement" and its "next" pointer set to NULL, 
 *              or NULL if memory allocation fails.
 * Time Efficiency: O(1)
 */
element_t * element_create( int newElement );

/* Description: Appends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns LIST_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_append( list_t * list, int newElement );

/* Description: Prepends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns LIST_OK. 
 *              If "newElement" cannot be prepended, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_prepend( list_t * list, int newElement );

/* Description: Removes the front (first) element (node) from the data 
 *              structure pointed to by "list" and returns LIST_OK. 
 *              If no elements (no nodes) can be removed, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_removeFront( list_t * list );

/* Description: Returns a pointer to the element (node) at "position" 
 *              in the data structure pointed to by "list". 
 *              To determine the proper "position" in the list,
 *              know that the first element (node) in the list is 
 *              at "position" 1, the second element (node) is at 
 *              "position" 2, etc. Returns NULL if "position" is 
 *              out of range. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */
element_t * list_get( list_t * list, unsigned int position );
							
/* Description: Returns a pointer to the element (i.e., to the node) that 
 *              contains the first occurrence of "targetElement" in the data 
 *              structure pointed to by "list". Returns NULL if "targetElement"
 *              is not found. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t * list_find( list_t * list, int targetElement );

/* Description: Prints the content of the data structure pointed to by "list",
 *              printing the list in human-readable form from the first element
 *              (in the first node) to the last element (in the last node), 
 *              between curly braces, then returns LIST_OK. 
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 *              This function does not modify the data structure.
 * Time Efficiency: O(n)
 */
listResult_t list_print( list_t * list );
