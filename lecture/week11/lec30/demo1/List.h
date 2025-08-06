/*
 * List.h   ***Using a SHSL list ***
 *
 * Class Description: List data collection class (ADT) where elements
 *                    - are unsorted, but relative order is kept
 *                    - can be duplicated
 *                    List position of elements start at 1 (not 0).
 *
 * Last Modification: July 2025
 * Author: AL
 */

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{

private:
  /* Data */
  Node *head = nullptr;          // Pointer to the first node (element) in the List.
  unsigned int elementCount = 0; // Current number of elements in List.

public:
  // Default constructor
  List();

  // Destructor
  // Time Efficicency: O(n)
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
  bool insert(unsigned int position, int newElement);

  // Description: Removes the element at "position" in the List
  //              If 1 <= "position" <= getElementCount() and the removal
  //              is successful, the element at "position" in the List is
  //              removed, and other elements "have moved" 1 position down,
  //              and "true" is returned. Otherwise, "false" is returned.
  // Time Efficicency: O(n)
  bool remove(unsigned int position);

  // Description: Returns the element at "position" in the List
  //              in *toBeReturned if 1 <= position <= getElementCount().
  //              If successful, returns "true". Otherwise, returns "false".
  // Postcondition: List unchanged.
  // Time Efficicency: O(n)
  bool getElement(unsigned int position, int *toBeReturned) const;

  // Description: Replaces the element at "position" in the List by "newElement".
  //              if 1 <= "position" <= getElementCount().
  //              If successful, returns "true". Otherwise, returns "false".
  // Time Efficicency: O(n)
  bool setElement(unsigned int position, int newElement);

  // Description: Prints all elements in the List.
  // Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"
  // Postcondition: List unchanged.
  // Time Efficicency: O(n)
  void printList() const;
};
#endif
