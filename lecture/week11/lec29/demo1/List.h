/*
 * List.h  ***Using a heap-allocated array***
 * 
 * Class Description: List data collection class (ADT) where elements 
 *                    - are unsorted, but relative order is kept
 *                    - can be duplicated
 *                    List position of elements start at 1 (not 0).
 *
 * Date: July 2025
 */

#ifndef LIST_H
#define LIST_H

class List {

  private:

   /* Data */

   static const int DEFAULT_CAPACITY = 5;     // Default capacity of array
                                              // Set to a small capacity so can test when 
                                              // data collection becomes full.
                                              // Can be changed. 
   int * elements = nullptr;                  // Data structure with capacity of MAX_ELEMENTS
   unsigned int elementCount = 0;             // Current number of elements in List
   unsigned int arraySize = DEFAULT_CAPACITY; // Max number of elements that can be stored in List

   /* Methods */
   
  // Description: Removes all elements from the List.
  // Postconditions: List contains no elements and the element count is 0.
  void clear();

public:
  // Constructor
  List();

  // Destructor
  ~List();

  // Description: Returns the current number of elements in the List.
  // Postcondition: List unchanged.
  // Time Efficicency: O(1)
  unsigned int getElementCount() const;

  // Description: Insert "newElement" at "position" in the List. 
  //              If 1 <= "position" <= getElementCount() + 1 and the insertion
  //              is successful, "newElement" is at "position" in the List,
  //              the other elements, located after "newElement", "have moved" 1 
  //              position up and "true" is returned. Otherwise, "false" is returned.
  // Time Efficicency: O(n)
  bool insert( unsigned int position, int newElement );

  // Description: Removes the element at "position" in the List 
  //              If 1 <= "position" <= getElementCount() and the removal 
  //              is successful, the element at "position" in the List is 
  //              removed, and other elements "have moved" 1 position down, 
  //              and "true" is returned. Otherwise, "false" is returned.  	
  // Time Efficicency: O(n)
  bool remove( unsigned int position );

  // Description: Removes all elements from the List.
  // Description: Returns the element at "position" in the List
  //              in *toBeReturned if 1 <= position <= getElementCount().
  //              If successful, returns "true". Otherwise, returns "false".
  // Postcondition: List unchanged.
  // Time Efficicency: O(1)
  // int retrieve(unsigned int position) const;
  bool getElement( unsigned int position, int * toBeReturned ) const;

  // Description: Replaces the element at "position" in the List by "newElement".
  //              if 1 <= "position" <= getElementCount(). 
  //              If successful, returns "true". Otherwise, returns "false".
  // Time Efficicency: O(1)
  // void modify(unsigned int position, int newElement);
  bool setElement( unsigned int position, int newElement );

  // Description: Prints all elements in the List.
  // Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"	
  // Postcondition: List unchanged.
  // Time Efficicency: O(n)
  void printList() const;	

};
#endif
