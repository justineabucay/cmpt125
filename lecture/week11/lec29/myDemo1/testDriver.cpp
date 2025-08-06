/*
filename: testDriver.cpp

*/
#include <cstddef> 
#include <iostream>
#include "List.h"

using std::cout; 
using std::endl;

int main()
{

    /* Variables declaration */
    const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
    List *aList = new List();

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
    // Inserting at the front of the List
    // for ( unsigned int i = 1; i < limit; i++ ) {
    //   element = rand( ) % 100;
    //   if ( ! aList->insert( 1, element ) )
    //     cout << "Could not aList->insert( )." << endl;
    //   cout << "Inserted " << element << " at position " << 1 << endl;
    // }

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

    delete aList;
    aList = NULL;

    return 0;
}