#include <cstddef> 
#include <iostream> 
#include "List.h"

using namespace std; 

int main(){
    /* Variables declaration */
    const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
    /* Please, see the note in the method insert(...) in List.cpp about "new(std::nothrow)". */
    List *aList = new (std::nothrow) List();
    if (aList == nullptr)
        return 1;

    int theFrontElement = 0;
    int newElement;

    /* Populating the List appending and prepending */
    cout << "Populating the List." << endl;
    srand(time(0));
    unsigned int limit = MIN_NUMBER_OF_ELEMENTS + rand() % 10;
    for (unsigned int i = 0; i < limit; i++)
    {
        newElement = rand() % 10;
        cout << "aList->append( " << newElement << " )" << endl;
        if (!aList->append(newElement))
            cout << "Could not aList->append( )." << endl;
        /* Printing the List */
        cout << "Print the List with " << aList->getElementCount() << " elements." << endl;
        aList->printList();
        newElement = rand() % 10;
        cout << "aList->prepend( " << newElement << " )" << endl;
        if (!aList->prepend(newElement))
            cout << "Could not aList->prepend( )." << endl;
        /* Printing the List */
        cout << "Print the List with " << aList->getElementCount() << " elements." << endl;
        aList->printList();
    }

    /* Printing the List */
    cout << "Print the List with " << aList->getElementCount() << " elements." << endl;
    aList->printList();

    /* Getting the element at the front of the List */
    if (!aList->getFrontElement(&theFrontElement))
        cout << "Could not aList->getFrontElement( )." << endl;
    cout << "Getting the element at the front of the List: " << theFrontElement << endl;

    /* Removing the element at the front of the List */
    cout << "Removing the element at the front of the List." << endl;
    if (!aList->removeAtFront())
        cout << "Could not aList->removeAtFront( )." << endl;

    /* Printing the List */
    cout << "Print the modified List with " << aList->getElementCount() << " elements." << endl;
    aList->printList();

    /* Getting the element at the front of the List */
    if (!aList->getFrontElement(&theFrontElement))
        cout << "Could not aList->getFrontElement( )." << endl;
    cout << "Getting the element at the front of the List: " << theFrontElement << endl;

    delete aList;
    aList = NULL;

    return 0;
}