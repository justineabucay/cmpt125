/*
 * List.cpp   ***Using a SHSL list ***
 * 
 * Class Description: List data collection class (ADT) where elements 
 *                    - are unsorted, but relative order is kept
 *                    - can be duplicated
 *                    List position of elements start at 1 (not 0). 
 *
 * Date : uly 2025
 * Author: Justine
 */
#include "List.h"
#include <iostream>

using namespace std;

// Default constructor
List::List() {
    head = nullptr;
    elementCount = 0;
}

// Destructor
// Time Efficiency: O(n)
List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    elementCount = 0;
}

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficiency: O(1)
unsigned int List::getElementCount() const {
    return elementCount;
}

// Description: Insert "newElement" at "position" in the List. 
//              If 1 <= "position" <= getElementCount() + 1 and the insertion
//              is successful, "newElement" is at "position" in the List,
//              the other elements, located after "newElement", "have moved" 1 
//              position up and "true" is returned. Otherwise, "false" is returned.
// Time Efficiency: O(n)
bool List::insert(unsigned int position, int newElement) {
    // check if valid
    if (position < 1 || position > elementCount + 1) {
        return false;
    }
    
    // create new node
    Node* newNode = new Node;
    newNode->data = newElement;
    newNode->next = nullptr;
    
    // insert at the beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        // find the node
        Node* current = head;
        for (unsigned int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        
        // insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }
    
    elementCount++;
    return true;
}

// Description: Removes the element at "position" in the List 
//              If 1 <= "position" <= getElementCount() and the removal 
//              is successful, the element at "position" in the List is 
//              removed, and other elements "have moved" 1 position down, 
//              and "true" is returned. Otherwise, "false" is returned.  	
// Time Efficiency: O(n)
bool List::remove(unsigned int position) {
    // check if valid
    if (position < 1 || position > elementCount) {
        return false;
    }
    
    Node* nodeToDelete = nullptr;
    
    // remove from the beginning
    if (position == 1) {
        nodeToDelete = head;
        head = head->next;
    } else {
        // find the node
        Node* current = head;
        for (unsigned int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        
        // remove the node
        nodeToDelete = current->next;
        current->next = nodeToDelete->next;
    }
    
    delete nodeToDelete;
    elementCount--;
    return true;
}

// Description: Returns the element at "position" in the List
//              in *toBeReturned if 1 <= position <= getElementCount().
//              If successful, returns "true". Otherwise, returns "false".
// Postcondition: List unchanged.
// Time Efficiency: O(n)
bool List::getElement(unsigned int position, int* toBeReturned) const {
    // check if valid
    if (position < 1 || position > elementCount || toBeReturned == nullptr) {
        return false;
    }
    
    // transverse to position
    Node* current = head;
    for (unsigned int i = 1; i < position; i++) {
        current = current->next;
    }
    
    *toBeReturned = current->data;
    return true;
}

// Description: Replaces the element at "position" in the List by "newElement".
//              if 1 <= "position" <= getElementCount(). 
//              If successful, returns "true". Otherwise, returns "false".
// Time Efficiency: O(n)
bool List::setElement(unsigned int position, int newElement) {
    // check if valid
    if (position < 1 || position > elementCount) {
        return false;
    }
    
    // traverse to position
    Node* current = head;
    for (unsigned int i = 1; i < position; i++) {
        current = current->next;
    }
    
    current->data = newElement;
    return true;
}

// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"	
// Postcondition: List unchanged.
// Time Efficiency: O(n)
void List::printList() const {
    cout << "This List has " << elementCount << " elements: { ";
    
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    
    cout << " }" << endl;
}