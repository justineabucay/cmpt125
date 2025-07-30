
#include <iostream> // As we need to print data
#include "Circle.h" // The header file for the class - we need this!

using std::cout;
using std::endl;

// default constructor that creates a circle of radius 10 and centred at coordinates (0, 0)
Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = DEFAULT_RADIUS;
}

// constructor with parameters for x, y and radius
Circle::Circle(double x, double y, double radius){
    this->x = x;
    this->y = y;
    if(radius > 0.0)
        this->radius = radius; 
    else
        this->radius = DEFAULT_RADIUS; 
}

// returns circle's centre x coordinate
double Circle::getX(){
    return x;
}

// returns circle's centre y coordinate
double Circle::getY(){
    return y;
}

// returns circle's radius
double Circle::getRadius(){
    return radius;
}

// moves the circle
void Circle::move(int horiz, int vert){
    x += horiz;
    y += vert;
    return;
}

// changes the circle's radius to r or DEFAULT
void Circle::setRadius(double r){
    if(r > 0.0)
        radius = r; 
    else
        radius = DEFAULT_RADIUS;
    return;
}

// computes and returns the area
double Circle::computeArea(){
    const double PI = 3.1415;
    return PI * radius * radius;
}

// prints data members of Circle
void Circle::printCircle(){
    cout << "This circle has a radius of " << radius << " and its centre is at coordinate (" << x << ", " <<y << ")." << endl;
    return;  
}

// returns true if the object intersects the calling circle
bool Circle::intersect(Circle c){
    // calculate the distance b/w the centres of the two circles
    double distX = x - c.x; 
    double distY = y - c.y;

    double dist = sqrt(distX * distX + distY * distY);

    return dist <= (radius + c.radius);
}

