/*
* Rectangle.h
*
* Description: This class models a rectangle with a "width" and a "height".
* Class Invariant: The rectangle must have its "width" and "height" > 0.

* Author:
* Modification date: July 2025
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H


// Definition of a rectangle class
class Rectangle {
	
  private: // Everything that follows is private and cannot be "seen" i.e., accessed from outside the class.

  /* Data */
  unsigned int width;   // width of the rectangle
  unsigned int height;  // height of the rectangle
  const unsigned int DEFAULT_VALUE = 10;

  /* Methods - Some classes have private methods, this one doesn't! */

	
  public: // Everything that follows is public and can be "seen" i.e., accessed from outside the class.

  /* Methods - Specific to class */
	
  /* Constructors */
	
  // Default constructor: The default constructor has no parameters.
  // Description: Constructs a rectangle of "width" and "height" = DEFAULT_VALUE.
  Rectangle(); 

  // Parameterized constructor: A constructor with parameters for "width" and "height".
  // Description: Constructs a new Rectangle object with the given values for "width" and "height",
  //              if the given "width" and the given "height" are both > 0
  //              (ensuring the class invariant remains true).
  //              Otherwise, sets the "width" and the "height" to DEFAULT_VALUE.
  Rectangle( unsigned int width, unsigned int height ); 
	
  // Because we only use stack memory for the data of this class, we do not need  
  // to have a destructor. We shall use the destructor provided by the system.
  // ~Rectangle(); 
  
  
  /* Getters: Return information about the rectangle. */
	
  // Note the "const" at the end of the method.
  // This guarantees that the method cannot alter the member variables of "this".
  // "this" is a pointer to the instantiated object.
	
  // Description: Returns the rectangle's "width".
  // PostCondition: Rectangle does not change.
  unsigned int getWidth() const; 
  
  // Description: Returns the rectangle's "height".
  // PostCondition: Rectangle does not change.
  unsigned int getHeight() const;


  /* Setters: Change the values of the data members. */
	
  // Description: Sets the rectangle's "width" to "aWidth" iff "aWidth" > 0. 
  void setWidth( unsigned int aWidth );   
  
  // Description: Sets the rectangle's "height" to "aHeight" iff "aHeight" > 0. 
  void setHeight( unsigned int aHeight ); 


  /* Methods - Specific to Problem Statement */
  // Description: Computes and returns the area of "this" rectangle.
  unsigned int computeArea() const;

  // Description: Computes and returns the perimeter of "this" rectangle.
  unsigned int computePerimeter() const;
  
  // Description: Returns true if the rectangle is also a square.
  bool isRectangleSquare() const;

  // Description: Prints the rectangle's attributes like this:
  // Rectangle with a width of ... and a height of ...
  void printRectangle() const;


}; // Note the ";" - don't forget it!
#endif
