/*
filename: List.cpp
*/

#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

// constructor
List::List()
{
    cout << "constructing a list!" << endl;
}

List::~List()
{
    cout << "destricting a list" << endl;
    this->clear();
}

void List::clear()
{
    delete[] elements;
    elements = nullptr;
    elementCount = 0;
    return;
}

unsigned int List::getElementCount() const
{
    return elementCount;
}

bool List::insert(unsigned int position, int newElement)
{

    // validate position: 1) is it within the range of indiced where elements are located in the array?
    //                    2) still space in the array, where the array is not full yet?

    bool ableToInsert = (position >= 1) && (position <= elementCount + 1) && (elementCount < arraySize);

    if (ableToInsert)
    {
        // have we allocated memory for the array yet?
        // lazy memory allocation: allocate only when actually needed, where usually the constructor would allocate the memory immediately
        // in this case, the constructor has not allocated the memory but rather is allocated later when we first insert the first element
        // benefits of using lazy memory allocation: creating a list w/o adding any elements saves memory
        if (elementCount == 0)
        {                                  // first time inserting
            elements = new int[arraySize]; // now, allocating memory on the heap with its address stored in the elements pointer
            if (elements == NULL)
            { // checking if allocation failed
                cout << "new int [arraySize] failed" << endl;
                ableToInsert = false;
                return ableToInsert;
            }
        }
        // otherwise, if elementCount > 0 (i.e., memory was already allocated in a previous insert)
        // shift all elements at pso
        for (unsigned int pos = elementCount; pos >= position; pos--)
            elements[pos] = elements[pos - 1];

        // insert new element
        elements[position - 1] = newElement;
        elementCount++; // increase count of elements

        return ableToInsert;
    }
}

// Description: Removes the element at "position" in the List
//              If 1 <= "position" <= getElementCount() and the removal
//              is successful, the element at "position" in the List is
//              removed, and other elements "have moved" 1 position down,
//              and "true" is returned. Otherwise, "false" is returned.
// Time Efficicency: O(n)
bool List::remove(unsigned int position)
{
    bool ableToRemove = (position >= 1) && (position <= elementCount);
    // remove element by shifting all elements
    // after the one at position toward the beginning of the array,
    // where there is no shift if position == elementCount

    if (ableToRemove)
    {
        for(unsigned int fromIndex = position, toIndex = fromIndex - 1; fromIndex < elementCount; fromIndex++, toIndex++){
            elements[toIndex] = elements[fromIndex]; 
        }
        elementCount--;
    }

    if(elementCount == 0) clear(); 

    return ableToRemove;
}

// Description: Returns the element at "position" in the List
//              in *toBeReturned if 1 <= position <= getElementCount().
//              If successful, returns "true". Otherwise, returns "false".
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getElement(unsigned int position, int *toBeReturned) const{
    bool ableToGet = (position >= 1) && (position <= elementCount);
    if(ableToGet)
        *toBeReturned = elements[position - 1];
    return toBeReturned;
}

bool List::setElement(unsigned int position, int newElement){
    if((position >= 1 ) && (position <= elementCount)){
            elements[position - 1] = newElement;
            return true; 
    }
    return false;
}

void List::printList() const{
    cout << "this list has " << this->elementCount << " elements: {";
    for(unsigned int i = 0; i < this->elementCount; i++)
        cout << " " << this->elements[i];
    cout << " }" << endl;
    return;
}