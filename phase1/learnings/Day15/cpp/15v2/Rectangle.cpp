#include <iostream>

#include "Rectangle.h"

using std::cout;

int Rectangle::findArea() 
{
    return length * breath;
}

Rectangle::Rectangle(int p_length, int p_breath)
{
    length = p_length;
    breath = p_breath;
}

void Rectangle::print()
{
    cout << "[length=" << length << " ft, breath=" << breath << " ft]";
}
    
bool Rectangle::isGreaterThan(Rectangle& other)
{
    int area1 = findArea();
    int area2 = other.findArea();
    return (area1 > area2);
}

bool Rectangle::equals(Rectangle& other)
{
    Rectangle& r1 = (*this);
    Rectangle& r2 = other;
    int area1 = r1.findArea();
    int area2 = r2.findArea();
    return (area1 == area2);
}
