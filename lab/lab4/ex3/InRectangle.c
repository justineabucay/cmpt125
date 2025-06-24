#include <math.h>
#include <stdio.h>
#include "InRectangle.h"

int InRectangle(float pt[POINTS], float rect[CORNERS])
{
    float pointX = pt[0];
    float pointY = pt[1];

    float corner1X = rect[0];
    float corner1Y= rect[1];
    float corner2X = rect[2];
    float corner2Y = rect[3];

    // finding the min/max of the two coordinates
    float leftX = min(corner1X, corner2X);
    float rightX = max(corner1X, corner2X);
    float topY = max(corner1Y, corner2Y);
    float bottomY = min(corner1Y, corner2Y);

    // boundary checking: check if point is within the rectangle borders
    if(pointX >= leftX && pointX <= rightX && pointY >= bottomY && pointY <= topY)
        return 1; // point is found inside or on the border
    else 
        return 0; // // point is found outside the border
}

float min(float val1, float val2)
{
    if(val1 <= val2) 
        return val1;
    else 
        return val2;
}

float max(float val1, float val2)
{
        if(val1 >= val2) 
        return val1;
    else 
        return val2;
}