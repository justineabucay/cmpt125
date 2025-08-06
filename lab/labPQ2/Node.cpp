/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *
 * Modified: July 2025
 * Author: AL
 */

#include <cstddef>   // Needed for nullptr
#include "Node.h"

// Method members - Constructors  
Node::Node() {}

Node::Node( int theData ) {
  data = theData;
}

Node::Node( int theData, Node * theNextNode ) {
  data = theData;
  next = theNextNode;
}
