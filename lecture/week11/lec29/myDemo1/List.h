/*
Filename: List.h
Description:    List data collection where elements
                - are unsorted, but relative order is kept
                - can be duplicated
                List postion of elements start at 1 (not 0)
Date: July 2025
*/

#ifndef LIST_H
#define LIST_H

class List
{
private:
    /* this is where we will be declaring our fields (and defining their datatype) */
    static const int DEFAULT_CAPACITY = 5; // default capacity of array. we are setting it to a small capacity, so that when the data collections becomes full, we can change it.

    int *elements = nullptr;       // initializing pointer to point to nothing (i.e., to NULL)
                                   // but we will eventually use to access a heap-allocated array to save memory
    unsigned int elementCount = 0; // current number of elements in List
    unsigned int arraySize = DEFAULT_CAPACITY;

    // declare all methods

    // description: removes all elements from the List
    // postconditions: List contains no elements and the elemtn count is 0
    void clear();

public:
    // constructor
    List();

    // destructor
    ~List();

    // description: returns the current number of elements in the List
    // postcondition: list unchanged
    unsigned int getElementCount() const;

    // Description: Insert "newElement" at "position" in the List.
    //              If 1 <= "position" <= getElementCount() + 1 and the insertion
    //              is successful, "newElement" is at "position" in the List,
    //              the other elements, located after "newElement", "have moved" 1
    //              position up and "true" is returned. Otherwise, "false" is returned.
    bool insert(unsigned int position, int newElement);

    // Description: Removes the element at "position" in the List
    //              If 1 <= "position" <= getElementCount() and the removal
    //              is successful, the element at "position" in the List is
    //              removed, and other elements "have moved" 1 position down,
    //              and "true" is returned. Otherwise, "false" is returned.
    // Time Efficicency: O(n)
    bool remove(unsigned int postion);

    // Description: Returns the element at "position" in the List
    //              in *toBeReturned if 1 <= position <= getElementCount().
    //              If successful, returns "true". Otherwise, returns "false".
    // Postcondition: List unchanged.
    // Time Efficicency: O(1)
    bool getElement(unsigned int position, int * toBeReturned) const;

    // Description: Replaces the element at "position" in the List by "newElement".
    //              if 1 <= "position" <= getElementCount().
    //              If successful, returns "true". Otherwise, returns "false".
    // Time Efficicency: O(1)
    // void modify(unsigned int position, int newElement);
    bool setElement(unsigned int position, int newElement);

    // Description: Prints all elements in the List.
    // Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"
    // Postcondition: List unchanged.
    // Time Efficicency: O(n)
    void printList() const;

}; // do not forget about the semicolon //

#endif