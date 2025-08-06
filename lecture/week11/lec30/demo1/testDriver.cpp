/*
 * testDriver.cpp
 *
 * Class Description: Tests the List data collection class.
 *
 * Modified on: July 2025
 * Author: AL
 */

#include <cstddef> // Needed for nullptr
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "List.h"

using std::cout;
using std::endl;

int main()
{

  /* Variables declaration */
  const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
  /* Please, see the note in the method insert(...) in List.cpp about "new(std::nothrow)". */
  List *aList = new (std::nothrow) List();
  if (aList == nullptr)
    return 1;

  List *anotherList = new (std::nothrow) List();
  if (aList == nullptr)
  {
    delete aList;
    aList = NULL;
    return 1;
  }

  /* Populating the list */
  cout << "Populating the List." << endl;
  srand(time(0));
  unsigned int position = 1;
  int element;
  unsigned int limit = MIN_NUMBER_OF_ELEMENTS + rand() % 10;
  // Inserting at the end of the List
  for (unsigned int i = 1; i < limit; i++)
  {
    element = rand() % 100;
    if (!aList->insert(i, element))
      cout << "Could not aList->insert( )." << endl;
    cout << "Inserted " << element << " at position " << i << endl;
  }

  /* Printing the List */
  cout << "Printing the List with " << aList->getElementCount() << " elements." << endl;
  aList->printList();

  /* Remove the element located at position in the List */
  position = 1;
  cout << "Remove the element located at position " << position << " in the List with "
       << aList->getElementCount() << " elements." << endl;
  if (!aList->remove(position))
    cout << "aList->remove( " << position << " ) unsuccessful!" << endl;

  /* Printing the List */
  cout << "Printing the List with " << aList->getElementCount() << " elements." << endl;
  aList->printList();

  /* Remove the element located at position in the List */
  position = 5;
  cout << "Remove the element located at position " << position << " in the List with "
       << aList->getElementCount() << " elements." << endl;
  if (!aList->remove(position))
    cout << "aList->remove( " << position << " ) unsuccessful!" << endl;

  /* Printing the List */
  cout << "Printing the List with " << aList->getElementCount() << " elements." << endl;
  aList->printList();

  /* Remove the element located at position in the List */
  position = 3;
  cout << "Remove the element located at position " << position << " in the List with "
       << aList->getElementCount() << " elements." << endl;
  if (!aList->remove(position))
    cout << "aList->remove( " << position << " ) unsuccessful!" << endl;

  /* Printing the List */
  cout << "Printing the List with " << aList->getElementCount() << " elements." << endl;
  aList->printList();

  /* Remove the element located at position in the List */
  position = 99;
  cout << "Remove the element located at position " << position << " in the List with "
       << aList->getElementCount() << " elements." << endl;
  if (!aList->remove(position))
    cout << "aList->remove( " << position << " ) unsuccessful!" << endl;

  // Inserting at the front of the List
  for (unsigned int i = 1; i < limit; i++)
  {
    element = rand() % 100;
    if (!anotherList->insert(1, element))
      cout << "Could not anotherList->insert( )." << endl;
    cout << "Inserted " << element << " at position " << 1 << endl;
  }

  /* Printing the List */
  cout << "Printing the List with " << anotherList->getElementCount() << " elements." << endl;
  anotherList->printList();

  /* Get the element located at position in the List */
  position = 5;
  int toBeReturned;
  int replaceWith = 99;

  if (!anotherList->getElement(position, &toBeReturned))
    cout << "anotherList->getElement( " << position << " ) unsuccessful!" << endl;
  cout << "Got the element located at position " << position << " in the List with "
       << anotherList->getElementCount() << " elements. It is " << toBeReturned << "." << endl;

  /* Printing the List */
  cout << "Printing the List with " << anotherList->getElementCount() << " elements." << endl;
  anotherList->printList();

  cout << "Set the element located at position " << position << " in the List with "
       << anotherList->getElementCount() << " elements with the value " << replaceWith << "." << endl;
  if (!anotherList->setElement(position, replaceWith))
    cout << "anotherList->setElement( " << position << " ) unsuccessful!" << endl;

  /* Printing the List */
  cout << "Printing the List with " << anotherList->getElementCount() << " elements." << endl;
  anotherList->printList();

  delete aList;
  aList = NULL;

  delete anotherList;
  anotherList = NULL;

  return 0;
}
