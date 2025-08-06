/*
* Circle.h
*
* Description: This class models a circle with a radius.
* Class Invariant: the radius must always be > 0.

* Author: Justine
* Modification date: July 2025
*/

#ifndef CIRCLEE_H
#define CIRCLE_H

class Circle{
    private:
        double radius; 
        const double DEFAULT_RADIUS = 5.0;
    public:
        // default constructor: creates a circle with DEFAULT_RADIUS
        Circle();

        // parameterized constructor: creates a circle with given radius
        Circle(double radius);

        // getter method: returns the radius
        double getRadius();

        // setter method: sets radius if > 0, otherwise sets to DEFAULT_RADIUS
        void setRadius(double newRadius);

        // calculation methods
        // returns the area
        double computeArea();

        double computeCircumference();

        double computeDiameter(); 

        // utility methods: 
        // returns true if radius equals 1.0
        bool isCircleUnit();

        // prints values
        void printCircle();

};

#endif