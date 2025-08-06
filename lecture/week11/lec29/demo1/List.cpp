/*
 * List.cpp  ***Using a heap-allocated array***
 * 
 * Class Description: List data collection class (ADT) where elements 
 *                    - are unsorted, but relative order is kept
 *                    - can be duplicated
 *                    List position of elements start at 1 (not 0).
 *
 * Date: July 2025
 */

#include <iostream>
#include "List.h"  // Header file

using std::cout;
using std::endl;

// Constructor
List::List() {
   cout << "Constructing a List!" << endl;   // For testing purposes ... and curiosity
} 

// Destructor
List::~List() {
	cout << "Destructing a List!" << endl;   // For testing purposes ... and curiosity
   this->clear();
}

// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
void List::clear() {

   delete [] elements;
	elements = nullptr;   // a habit to get into
   elementCount = 0;
   return;
} 

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
unsigned int List::getElementCount() const {
   return elementCount;
} 

// Description: Insert "newElement" at "position" in the List. 
//              If 1 <= "position" <= getElementCount() + 1 and the insertion
//              is successful, "newElement" is at "position" in the List,
//              the other elements, located after "newElement", "have moved" 1 
//              position up and "true" is returned. Otherwise, "false" is returned.
// Time Efficicency: O(n)
bool List::insert( unsigned int position, int newElement ) {

   // Validate position: 1) Is it within the range of indices where elements 
   //                          are located in the array?
   //                       2) Still space in the array (array not full yet)?
   bool ableToInsert = ( position >= 1 ) && ( position <= elementCount + 1 ) &&             
                       ( elementCount < arraySize );

   if ( ableToInsert ) {   
      // Have we allocated memory for the array yet?
      if ( elementCount == 0 ) {
         elements = new int[arraySize];
         if (elements == NULL) {
      		// For debug purposes
		      cout << "new int[arraySize] failed!" << endl;
            ableToInsert = false;
            return ableToInsert;
         }            		
      }
      // Make room for new Element by shifting all elements at
      // positions >= position toward the end of the array
      // (no shift if position == elementCount + 1)
      for ( unsigned int pos = elementCount; pos >= position; pos-- )
         elements[pos] = elements[pos - 1];
         
      // Insert new Element
      elements[position - 1] = newElement;
      elementCount++;  // Increase count of elements
   } 

   return ableToInsert;
}  


// Description: Removes the element at "position" in the List 
//              If 1 <= "position" <= getElementCount() and the removal 
//              is successful, the element at "position" in the List is 
//              removed, and other elements "have moved" 1 position down, 
//              and "true" is returned. Otherwise, "false" is returned.
// Time Efficicency: O(n)  
bool List::remove( unsigned int position ) {

   bool ableToRemove = ( position >= 1 ) && ( position <= elementCount );
   if ( ableToRemove ) {
      // Remove Element by shifting all elements after the one at
      // position toward the beginning of the array
      // (no shift if position == elementCount)
      for ( unsigned int fromIndex = position, toIndex = fromIndex - 1; fromIndex < elementCount;
	        fromIndex++, toIndex++ )
         elements[toIndex] = elements[fromIndex];
         
      elementCount--;  // Decrease count of elements
   } 
   if ( elementCount == 0 ) clear( );

   return ableToRemove;
}

   
// Description: Returns the element at "position" in the List
//              in *toBeReturned if 1 <= position <= getElementCount().
//              If successful, returns "true". Otherwise, returns "false".
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getElement( unsigned int position, int * toBeReturned ) const {

   // Enforce precondition
   bool ableToGet = ( position >= 1 ) && ( position <= elementCount );
   if ( ableToGet )
      *toBeReturned = elements[position - 1];

   return toBeReturned;
} 

   
// Description: Replaces the element at "position" in the List by "newElement".
//              if 1 <= "position" <= getElementCount(). 
//              If successful, returns "true". Otherwise, returns "false".
// Time Efficicency: O(1)
bool List::setElement( unsigned int position, int newElement ) {
   // Enforce precondition
   bool ableToSet = ( position >= 1 ) && ( position <= elementCount );
   if ( ableToSet )
      elements[position - 1] = newElement;

   return ableToSet;
} 
   
// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"	
// Postcondition: List unchanged.
// Time Efficicency: O(n)
void List::printList() const {

  cout << "This List has " << this->elementCount << " elements: {";
  for ( unsigned int index = 0; index < this->elementCount; index++ )
      cout << " " << this->elements[index];
  cout << " }" << endl;
  return;
} 

//  End of implementation file
