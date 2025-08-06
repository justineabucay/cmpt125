/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *
 * Modified: July 2025
 * Author: AL
 */

#ifndef NODE_H
#define NODE_H


class Node {
	
public:

  // Data members
  int data;                 // The data in the node
  Node * next =  nullptr;   // Pointer to next node
	
  // Method members - Constructors
  Node();
  Node( int theData );
  Node( int theData, Node * theNextNode );

}; 
#endif