#include <iostream>

using std::cout;
using std::endl;

class Rectangle
{
    private:
        // attributes [member data]
        int length;
        int breath;
    public:    
        // behaviours [member functions]
        int findArea();
        // constrctors 
        Rectangle(int p_length, int p_breath);
        //
        void print();
        //
        bool isGreaterThan(Rectangle& other);
        bool equals(Rectangle& other);
};

int main()
{
    Rectangle plot1(40,30);
    //cout << "Address of plot1 : " << (&plot1) << " and size:" << sizeof(plot1) << endl;
    //cout << "Address of plot1.length : " << (&(plot1.length))  << " and size:" << sizeof(plot1.length) << endl;
    //cout << "Address of plot1.breath : " << (&(plot1.breath)) << " and size:" << sizeof(plot1.breath)  << endl;
    //cout << "after Address of plot1 : " << ((&plot1) + 1) << endl;
    Rectangle plot2(70,20);



    plot1.print(); cout << endl;
    int area1 = plot1.findArea();
    cout << "Area of plot 1 is " << area1  << " sq. ft" << endl;
     
    plot2.print(); cout << endl;
    int area2 = plot2.findArea();
    cout << "Area of plot 2 is " << area2 << " sq. ft" << endl;

    int average = ((area1 + area2) / 2);
    cout << "Average area of two plots is " << average << " sq. ft" << endl;

    if(plot1.equals(plot2))
    {
       plot1.print(); cout << " equals "; plot2.print(); cout << endl;
    }
    else if(plot1.isGreaterThan(plot2))
    {
       plot1.print(); cout << " is greater than "; plot2.print(); cout << endl;
    }
    else
    {
       plot2.print(); cout << " is greater than "; plot1.print(); cout << endl;
    }

    return 0;
}

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
   
