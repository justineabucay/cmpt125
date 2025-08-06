/*
 * List.cpp  ***Using a SHSL list ***
 *
 * Class Description: List data collection class (ADT) where elements
 *                    - are unsorted, but relative order is kept
 *                    - can be duplicated
 *                    List position of elements start at 1 (not 0).
 *
 * Last Modification: July 2025
 */

#include <cstddef> // Needed for nullptr
#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

// Constructor
List::List()
{
  cout << "Constructing a List!" << endl; // For testing purposes ... and curiosity
}

// Destructor
// Time Efficicency: O(n)
List::~List()
{
  cout << "Destructing a List!" << endl; // For testing purposes ... and curiosity
  while (getElementCount() > 0)
    remove(1); // Here, we could check the return value of the remove(...) method,
               // but, considering that we are destroying the List object at this point,
               // there may not be much we could do if remove(...) is unsuccessful,
               // i.e., if remove(...) is returning "false".
}

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
unsigned int List::getElementCount() const
{
  return elementCount;
}

// Description: Insert "newElement" at "position" in the List.
//              If 1 <= "position" <= getElementCount() + 1 and the insertion
//              is successful, "newElement" is at "position" in the List,
//              the other elements, located after "newElement", "have moved" 1
//              position up and "true" is returned. Otherwise, "false" is returned.
// Time Efficicency: O(n)
bool List::insert(unsigned int position, int newElement)
{

  // Validate position: Is position within the List?
  // Will work for the test case when the List is empty (elementCount is 0)
  // and we are inserting at position 1, which is the only position at which
  // we can insert when the List is empty.
  bool ableToInsert = (position >= 1) && (position <= getElementCount() + 1);

  if (ableToInsert)
  {

    /* Explanation from our TA Sam: When the default new operator is used as follows:
                        Node * newNode = new Node( newElement );
       but the required memory cannot not be allocated, the new operator, used as illustrated above,
       will throw a bad_alloc exception and halts the execution (unless the exception is handled).
       This is called the "default behaviour" of the new operator.

       Note from Anne: Since we have not introduced C++ Exceptions in this course
                       (I believe this topic will be discussed in CMPT 225),
                       we shall make use of the following new operator, introduced below by Sam.

       Back to Sam's explanation: This default behaviour of the new operator can be modified by
       invoking the new operator using "nothrow" as follows:
                        Node* newNode = new(std::nothrow) Node( newElement );
       In such a case, the returned pointer "newNode" needs to be tested for "nullptr" value.
    */
    Node *newNode = new (std::nothrow) Node(newElement);
    if (newNode)
    { // Same as "if ( newNode != nullptr )"
      if (position == 1)
      {
        newNode->next = head;
        head = newNode;
      }
      else
      { // Insert at position
        Node *current = head;
        Node *prev = nullptr;
        for (unsigned int index = 1; index < position; index++)
        {
          prev = current;
          current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
      }
      elementCount++; // One more element in the list

      // Note: Since a SHSL list is used as the data structure of this List class,
      //       we do not have to actually move the nodes. This part of this method's
      //       description 'the other elements, located after "newElement", "have moved" 1
      //       position up' happens automatically.
    }
    else
      ableToInsert = false;
  }

  return ableToInsert;
}

// Description: Removes the element at "position" in the List
//              If 1 <= "position" <= getElementCount() and the removal
//              is successful, the element at "position" in the List is
//              removed, and other elements "have moved" 1 position down,
//              and "true" is returned. Otherwise, "false" is returned.
// Time Efficicency: O(n)
bool List::remove(unsigned int position)
{

  // Validate the requirements described in this method's description
  bool ableToRemove = (position >= 1) && (position <= getElementCount());
  if (ableToRemove)
  {
    if (head)
    { // Same as "if ( head != nullptr )"
      Node *tobeRemoved = head;

      if (position == 1)
        head = head->next;
      else
      {
        Node *current = head;
        Node *prev = nullptr;
        for (unsigned int index = 1; index < position; index++)
        {
          prev = current;
          current = current->next;
        }
        prev->next = current->next;
        tobeRemoved = current;
      }

      tobeRemoved->next = nullptr;
      delete tobeRemoved;
      tobeRemoved = nullptr;

      elementCount--; // One less element in the list

      // Note: Since a SHSL list is used as the data structure of this List class, we do
      //       not have to actually move the nodes. This part of this method's description
      //       'other elements "have moved" 1 position down' happens automatically.
    }
  }

  return ableToRemove;
}

// Description: Returns the element at "position" in the List
//              in *toBeReturned if 1 <= position <= getElementCount().
//              If successful, returns "true". Otherwise, returns "false".
// Postcondition: List unchanged.
// Time Efficicency: O(n)
bool List::getElement(unsigned int position, int *toBeReturned) const
{

  // Validate the requirements described in this method's description
  bool ableToGet = (position >= 1) && (position <= getElementCount());
  if (ableToGet)
  {
    if (position == 1)
      *toBeReturned = head->data;
    else
    {
      Node *current = head;
      for (unsigned int index = 1; index < position; index++)
      {
        current = current->next;
      }
      *toBeReturned = current->data;
    }
  }

  return ableToGet;
}

// Description: Replaces the element at "position" in the List by "newElement".
//              if 1 <= "position" <= getElementCount().
//              If successful, returns "true". Otherwise, returns "false".
// Time Efficicency: O(n)
bool List::setElement(unsigned int position, int newElement)
{

  // Validate the requirements described in this method's description
  bool ableToSet = (position >= 1) && (position <= getElementCount());
  if (ableToSet)
  {
    if (position == 1)
      head->data = newElement;
    else
    {
      Node *current = head;
      for (unsigned int index = 1; index < position; index++)
      {
        current = current->next;
      }
      current->data = newElement;
    }
  }
  return ableToSet;
}

// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n> }"
// Postcondition: List unchanged.
// Time Efficicency: O(n)
void List::printList() const
{

  cout << "This List has " << getElementCount() << " elements: {";
  if (head)
  { // Same as "if ( head != nullptr )"
    Node *current = head;
    for (unsigned int i = 1; i <= getElementCount(); i++)
    {
      cout << " " << current->data;
      current = current->next;
    }
  }
  cout << " }" << endl;
  return;
}
