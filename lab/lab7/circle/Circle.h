/*
* Circle.h
*
* Description: This class models a circle ...
* Class Invariant: The circle's radius must be greater than 0.0

* Author:
* Creation date:
*/

#ifndef CIRCLE_H
#define CIRCLE_H

// Definition of a circle class
class Circle {

  private: //everything that follows is private and cannot be "seen" from outside the class

  // Put your code here
    double const DEFAULT_RADIUS = 10.0; 
    double radius; 
    double x;
    double y; 

  public: //everything that follows is public

  // Put your code here
    // default constructor that creates a circle of radius 10 and centred at coordinates (0, 0)
    Circle(); 

    // constructor with parameters fo x, y and radius
    Circle(double x, double y, double radius);   

    // returns circle's centre x coordinate
    double getX();

    // returns the circle's centre y coordinate
    double getY(); 

    // returns circle's radius
    double getRadius();

    // moves the circle the given horizontal and vertical distanes
    void move(int horiz, int vert); 

    // changes the circle's radius to r or to 10.0 if r is invalid
    void setRadius(double r);

    // computes and returns the circle's area 
    double computeArea();

    // prints circle's data members
    void printCircle(); 

    // returns true if the Circle object intersects the calling circle
    bool intersect(Circle c); 

}; // Note the ";" - don't forget it!
// End of Circle.h

#endif