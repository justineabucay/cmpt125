/*
* Rectangle.cpp
*
* Description: This class models a rectangle with a width and a height.
* Class Invariant: The rectangle must have its width and height > 0.

* Author: 
* Modification date: July 2025
*/

#include <iostream> // As we need to print data
#include "Rectangle.h" // The header file for the class - we need this!

using std::cout;
using std::endl;


/* Method implementations */

// Now, read each of the method implementations. 
// The Rectangle:: preceding each method indicates that the method belongs to the Rectangle class. 
// If it is omitted, the compiler will attempt to create a separate function 
// (not belonging to the class). This is not what we want.


// Default constructor: The default constructor has no parameters.
// Description: Constructs a rectangle of width and height = DEFAULT_VALUE.
Rectangle::Rectangle() : width( DEFAULT_VALUE ), height( DEFAULT_VALUE ) {
  // This output statement let's us know when a constructor is implicitly called (optional).
	cout << "Calling default constructor." << endl;
}  
// Note: This part of the constructor's header " : width( DEFAULT_VALUE ), height( DEFAULT_VALUE )"
// is called the "initialiation list". 

// Parameterized constructor: A constructor with parameters for width and height.
// Description: Constructs a new Rectangle object with the given values for width and height
//              if the given width and the given height are both > 0
//              ensuring the class invariant remains true.
//              Otherwise, sets the width and the height to DEFAULT_VALUE;
Rectangle::Rectangle( unsigned int aWidth, unsigned int aHeight ) { 
  cout << "Calling parameterized constructor with width " << aWidth << " and a height " << aHeight << endl;
  /* I can implement this method this way: */
  if ( aWidth > 0) width = aWidth;
  else width = DEFAULT_VALUE;
  if ( aHeight > 0) height = aHeight;
  else height = DEFAULT_VALUE;
  /* But I am repeating the code of setWidth(...) and setHeight(...) methods.
     Why not call these methods instead? This way, we are not repeating code! */
  this->setWidth( aWidth );
  this->setHeight( aHeight );
}

// Because we only use stack memory for the data of this class, we do not need  
// to have a destructor. We shall use the destructor provided by the system.

     
/* Getters: Return information about the rectangle. */

// Note the "const" at the end of the method.
// This guarantees that the method cannot alter the member variables
	
// Description: Returns the rectangle's width.
unsigned int Rectangle::getWidth() const {
	return width;
}

// Description: Returns the rectangle's height.
unsigned int Rectangle::getHeight() const {
	return height;
}

/* Setters: change the values of the attributes. */

// Description: Sets the rectangle's width to aWidth iff aWidth > 0. 
void Rectangle::setWidth( unsigned int aWidth ) {
	// Ensures the class invariant is satisfied!
	if ( aWidth > 0) width = aWidth;
	else width = DEFAULT_VALUE;
	return;
}
	
// Description: Sets the rectangle's height to aHeight iff aHeight > 0. 
void Rectangle::setHeight( unsigned int aHeight ){
	// Ensures the class invariant is satisfied!
	if ( aHeight > 0) height = aHeight;
	else height = DEFAULT_VALUE;
	return;
}	 

/* Methods - Specific to Problem Statement */ 

// Description: Computes and returns the area of "this" rectangle.
unsigned int Rectangle::computeArea() const {
	return width * height;
}

// Description: Returns true if the rectangle is also a square.
bool Rectangle::isRectangleSquare() const {
	return width == height;
}
	
// Description: Prints the rectangle's attributes using this format:
//              Rectangle with a width of ... and a height of ... .
void Rectangle::printRectangle() const {
	cout << "Rectangle with a width of " << getWidth();
	cout << " and a height of " << getHeight();
  cout << "." << endl;
	return;
}
      
// End of the implementation file
