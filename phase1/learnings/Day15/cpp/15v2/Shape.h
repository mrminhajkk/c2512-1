#pragma once
class Shape
{
    public:    
        // behaviours [member functions]
        virtual float findArea() = 0;
        //
        virtual void print() = 0;
        //
        virtual bool isGreaterThan(Shape& other) = 0;
        virtual bool equals(Shape& other) = 0;
};
