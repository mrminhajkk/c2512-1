#pragma once
class Circle
{
    private:
        // attributes [member data]
        int radius;
    public:    
        // behaviours [member functions]
        float findArea();
        // constrctors 
        Circle(int p_radius);
        //
        void print();
        //
        bool isGreaterThan(Circle& other);
        bool equals(Circle& other);
};
