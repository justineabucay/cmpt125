#include "List.h"
#include <iostream> 
#include "Node.h"
#include "List.h"

using namespace std;

// Default constructor
List::List(){}

// Destructor
List::~List(){
    while(getElementCount() > 0){
        removeAtFront(); 
    }
}

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
unsigned int List::getElementCount() const{
    return elementCount;
}

// Description: Inserts "newElement" at the back of the List
//              and returns "true" if successful, "false" otherwise.
// Time Efficicency: O(1)
bool List::append(int newElement){
    bool result = true; 
    Node * newNode = new(std::nothrow) Node(newElement);
    if(newNode){
        if(head == nullptr)
            head = newNode;
        if(tail != nullptr) 
            tail->next = newNode;
        tail = newNode; 
        elementCount++; 
    } else
        result = false; 
    return result;
}

// Description: Inserts "newElement" at the front of the List
//              and returns "true" if successful, "false" otherwise.
// Time Efficicency: O(1)
bool List::prepend(int newElement){
    bool result = true; 
    Node * newNode = new(std::nothrow) Node(newElement);
    if(newNode){
        if(tail == nullptr) // empty list
            tail = newNode;
        if(head != nullptr) // non-empty list
            newNode->next = head;
        head = newNode; 
        elementCount++;        
    } else
        result = false; 
    return result;
}

// Description: Removes the element from the front of the List
//              and returns "true" if successful, "false" otherwise.
// Precondition: List is not empty.
// Time Efficicency: O(1)
bool List::removeAtFront(){
    bool result = true; 
    
    if(head != nullptr){
        Node * toBeRemoved = head; 
        head = head->next; 

        toBeRemoved->next = nullptr; 
        delete toBeRemoved;
        toBeRemoved = nullptr; 
    } else
        result = false; 
    
    return result; 
}

// Description: Returns via the parameter "frontElement" the element
//              at the front of the List and returns "true" if
//              successful, "false" otherwise.
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getFrontElement(int *frontElement) const{
    bool result = true; 
    if(head != nullptr){
        *frontElement = head->data; 
    } else
        result = false; 
    return result; 
}

// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n> }"
// Postcondition: List unchanged.
// Time Efficicency: O(n)
void List::printList() const{
    cout << "This list has <" << elementCount << "> elements: { "; 
    if(head != nullptr){
        Node * current = head; 
        for (unsigned int i = 1; i <= elementCount; i++)
        {
            cout << " " << current->data;
            current = current->next; 
        }
        cout << " }" << endl;
        return;
    }

}