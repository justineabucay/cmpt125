#include "List.h"
#include <iostream>
#include "Node.h"

using namespace std;

// Private helper method to get node at specific position
Node *List::getNodeAt(unsigned int position) const
{
    if (position >= elementCount)
        return nullptr;

    Node *current = head;
    for (unsigned int i = 0; i < position; i++)
    {
        current = current->next;
    }
    return current;
}

// Default constructor
List::List() {}

// Copy constructor
List::List(const List &other)
{
    if (other.head == nullptr)
        return;

    Node *otherCurrent = other.head;
    while (otherCurrent != nullptr)
    {
        append(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
}



// Insertion Methods
bool List::append(int newElement)
{
    bool result = true;
    Node *newNode = new (std::nothrow) Node(newElement);
    if (newNode)
    {
        if (head == nullptr)
            head = newNode;
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        elementCount++;
    }
    else
        result = false;
    return result;
}

bool List::prepend(int newElement)
{
    bool result = true;
    Node *newNode = new (std::nothrow) Node(newElement);
    if (newNode)
    {
        if (tail == nullptr) // empty list
            tail = newNode;
        if (head != nullptr) // non-empty list
            newNode->next = head;
        head = newNode;
        elementCount++;
    }
    else
        result = false;
    return result;
}

bool List::insertAt(unsigned int position, int newElement)
{
    // Handle edge cases
    if (position == 0)
        return prepend(newElement);
    if (position >= elementCount)
        return append(newElement);

    Node *newNode = new (std::nothrow) Node(newElement);
    if (!newNode)
        return false;

    Node *prev = getNodeAt(position - 1);
    if (!prev)
    {
        delete newNode;
        return false;
    }

    newNode->next = prev->next;
    prev->next = newNode;
    elementCount++;
    return true;
}

bool List::insertSorted(int newElement)
{
    if (isEmpty() || newElement <= head->data)
    {
        return prepend(newElement);
    }

    if (newElement >= tail->data)
    {
        return append(newElement);
    }

    Node *current = head;
    unsigned int position = 0;

    while (current->next != nullptr && current->next->data < newElement)
    {
        current = current->next;
        position++;
    }

    return insertAt(position + 1, newElement);
}

// Removal Methods
bool List::removeAtFront()
{
    if (head == nullptr)
        return false;

    Node *toBeRemoved = head;
    head = head->next;

    if (head == nullptr)
    { // List became empty
        tail = nullptr;
    }

    delete toBeRemoved;
    elementCount--;
    return true;
}

bool List::removeAtBack()
{
    if (tail == nullptr)
        return false;

    if (head == tail)
    { // Only one element
        delete head;
        head = tail = nullptr;
        elementCount--;
        return true;
    }

    // Find second to last node
    Node *current = head;
    while (current->next != tail)
    {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
    elementCount--;
    return true;
}

bool List::removeAt(unsigned int position)
{
    if (position >= elementCount)
        return false;
    if (position == 0)
        return removeAtFront();
    if (position == elementCount - 1)
        return removeAtBack();

    Node *prev = getNodeAt(position - 1);
    if (!prev || !prev->next)
        return false;

    Node *toBeRemoved = prev->next;
    prev->next = toBeRemoved->next;
    delete toBeRemoved;
    elementCount--;
    return true;
}

bool List::remove(int element)
{
    if (head == nullptr)
        return false;

    // Check if it's the first element
    if (head->data == element)
    {
        return removeAtFront();
    }

    Node *current = head;
    while (current->next != nullptr && current->next->data != element)
    {
        current = current->next;
    }

    if (current->next == nullptr)
        return false; // Element not found

    Node *toBeRemoved = current->next;
    current->next = toBeRemoved->next;

    if (toBeRemoved == tail)
    { // Removing last element
        tail = current;
    }

    delete toBeRemoved;
    elementCount--;
    return true;
}

bool List::removeAll(int element)
{
    bool removedAny = false;

    // Keep removing from front while it matches
    while (head != nullptr && head->data == element)
    {
        removeAtFront();
        removedAny = true;
    }

    if (head == nullptr)
        return removedAny;

    Node *current = head;
    while (current->next != nullptr)
    {
        if (current->next->data == element)
        {
            Node *toBeRemoved = current->next;
            current->next = toBeRemoved->next;

            if (toBeRemoved == tail)
            {
                tail = current;
            }

            delete toBeRemoved;
            elementCount--;
            removedAny = true;
        }
        else
        {
            current = current->next;
        }
    }

    return removedAny;
}

void List::clear()
{
    while (!isEmpty())
    {
        removeAtFront();
    }
}

// Access/Retrieval Methods
bool List::getFrontElement(int *frontElement) const
{
    if (head == nullptr)
        return false;
    *frontElement = head->data;
    return true;
}

bool List::getBackElement(int *backElement) const
{
    if (tail == nullptr)
        return false;
    *backElement = tail->data;
    return true;
}

bool List::getAt(unsigned int position, int *element) const
{
    Node *node = getNodeAt(position);
    if (!node)
        return false;

    *element = node->data;
    return true;
}

int List::indexOf(int element) const
{
    Node *current = head;
    for (unsigned int i = 0; i < elementCount; i++)
    {
        if (current->data == element)
        {
            return static_cast<int>(i);
        }
        current = current->next;
    }
    return -1; // Not found
}

bool List::contains(int element) const
{
    return indexOf(element) != -1;
}


void List::reverse()
{
    if (elementCount <= 1)
        return;

    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    tail = head; // Old head becomes new tail

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev; // Last node becomes new head
}

List *List::copy() const
{
    List *newList = new (std::nothrow) List();
    if (!newList)
        return nullptr;

    Node *current = head;
    while (current != nullptr)
    {
        if (!newList->append(current->data))
        {
            delete newList;
            return nullptr;
        }
        current = current->next;
    }

    return newList;
}

void List::sort()
{
    if (elementCount <= 1)
        return;

    // Simple bubble sort implementation
    bool swapped;
    do
    {
        swapped = false;
        Node *current = head;

        while (current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

bool List::getMax(int *maxElement) const
{
    if (head == nullptr)
        return false;

    *maxElement = head->data;
    Node *current = head->next;

    while (current != nullptr)
    {
        if (current->data > *maxElement)
        {
            *maxElement = current->data;
        }
        current = current->next;
    }

    return true;
}

bool List::getMin(int *minElement) const
{
    if (head == nullptr)
        return false;

    *minElement = head->data;
    Node *current = head->next;

    while (current != nullptr)
    {
        if (current->data < *minElement)
        {
            *minElement = current->data;
        }
        current = current->next;
    }

    return true;
}

// List Operations
bool List::equals(const List &other) const
{
    if (elementCount != other.elementCount)
        return false;

    Node *thisCurrent = head;
    Node *otherCurrent = other.head;

    while (thisCurrent != nullptr)
    {
        if (thisCurrent->data != otherCurrent->data)
        {
            return false;
        }
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }

    return true;
}

void List::merge(const List &other)
{
    Node *current = other.head;
    while (current != nullptr)
    {
        append(current->data);
        current = current->next;
    }
}

// Display Methods
void List::printList() const
{
    cout << "This list has " << elementCount << " elements: { ";

    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << ", ";
        }
        current = current->next;
    }

    cout << " }" << endl;
}

void List::printReverse() const
{
    cout << "This list in reverse has " << elementCount << " elements: { ";

    if (elementCount == 0)
    {
        cout << " }" << endl;
        return;
    }


    int *elements = new int[elementCount];
    Node *current = head;

    for (unsigned int i = 0; i < elementCount; i++)
    {
        elements[i] = current->data;
        current = current->next;
    }

    for (int i = elementCount - 1; i >= 0; i--)
    {
        cout << elements[i];
        if (i > 0)
        {
            cout << ", ";
        }
    }

    cout << " }" << endl;
    delete[] elements;
}