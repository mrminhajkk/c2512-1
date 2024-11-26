#include <iostream>

#include "Rectangle.h"
#include "Circle.h"

using std::cout;
using std::endl;

int main()
{
    Rectangle plot1(40,30);
    Rectangle plot2(70,20);
    Circle plot3(30);


    plot1.print(); cout << endl;
    int area1 = plot1.findArea();
    cout << "Area of plot 1 is " << area1  << " sq. ft" << endl;
     
    plot2.print(); cout << endl;
    int area2 = plot2.findArea();
    cout << "Area of plot 2 is " << area2 << " sq. ft" << endl;

    plot3.print(); cout << endl;
    int area3 = plot3.findArea();
    cout << "Area of plot 3 is " << area3 << " sq. ft" << endl;


    return 0;
}
