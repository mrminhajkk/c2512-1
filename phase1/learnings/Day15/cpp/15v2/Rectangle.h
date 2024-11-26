#pragma once
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
