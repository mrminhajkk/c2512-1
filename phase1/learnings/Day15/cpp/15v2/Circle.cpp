#include <iostream>

#include "Circle.h"

using std::cout;

float Circle::findArea() 
{
    return 3.14 * radius * radius;
}

Circle::Circle(int p_radius)
{
    radius = p_radius;
}

void Circle::print()
{
    cout << "[radius=" << radius << " ft]";
}
    
bool Circle::isGreaterThan(Circle& other)
{
    float area1 = findArea();
    float area2 = other.findArea();
    return (area1 > area2);
}

bool Circle::equals(Circle& other)
{
    Circle& r1 = (*this);
    Circle& r2 = other;
    float area1 = r1.findArea();
    float area2 = r2.findArea();
    return (area1 == area2);
}
