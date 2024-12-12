#include<iostream>
#include <stdexcept> // For exception handling
using namespace std;

//typedef float T;    //alias for data type 'float'
using T = float;      //alias for data type 'float'  


class C2512Stack {
    private:
        static const int _size = 3; // Fixed size for the stack
        T arr[_size];           // Array to store stack elements
        int _top;                    // Tracks the current top of the stack

    public:
        // Constructor
        C2512Stack();

        // Stack Operations
        void push(T data);  // Pushes an element onto the stack
        void pop();              // Removes the top element from the stack
        T top() const;      // Returns the top element of the stack

        // Utility Functions
        bool isEmpty() const;    // Checks if the stack is empty
        bool isFull() const;     // Checks if the stack is full
};



int main() {
   
    C2512Stack stack;

    try {
        // Push elements onto the stack
        stack.push(10.0);
        stack.push(12.0);
        stack.push(11.0);
        stack.push(13.0);
    } catch (const overflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }   


    try {    
        // Access and pop elements
        cout << "Top:" << stack.top() << endl; // Output: 11.0
        stack.pop();

        cout << "Top:" << stack.top() << endl; // Output: 12.0
        stack.pop();

        cout << "Top:" << stack.top() << endl; // Output: 10.0
        stack.pop();

        // Attempting to access or pop an element from an empty stack
        cout << "Top:" << stack.top() << endl; // Should throw an exception
        stack.pop();                          // Should throw an exception

    } catch (const underflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

// Constructor: Initialize stack
C2512Stack::C2512Stack() : _top(0) {}

// Push method: Adds an element to the stack
void C2512Stack::push(T data) {
    if (isFull()) {
        throw overflow_error("Stack overflow: Cannot push more elements.");
    }
    arr[_top] = data; // Add data to the stack
    _top++;           // Increment the top
}

// Pop method: Removes the top element from the stack
void C2512Stack::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
    }
    _top--; // Decrement the top
}

// Top method: Returns the element at the top of the stack
T C2512Stack::top() const {
    if (isEmpty()) {
        throw underflow_error("Stack underflow: Cannot access the top of an empty stack.");
    }
    return arr[_top - 1]; // Return the top element
}

// Utility function: Check if the stack is empty
bool C2512Stack::isEmpty() const {
    return _top == 0;
}

// Utility function: Check if the stack is full
bool C2512Stack::isFull() const {
    return _top == _size;
}
