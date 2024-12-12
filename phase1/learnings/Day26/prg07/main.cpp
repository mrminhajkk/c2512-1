#include<iostream>
#include<string>
using namespace std;

#ifndef C2512STACK_H
#define C2512STACK_H
    #include <stdexcept> // For exception handling
    template<class T>
    class C2512Stack {
    private:
        static const int _size = 3; // Fixed size for the stack
        T arr[_size];           // Array to store stack elements
        int _top;               // Tracks the current top of the stack

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
#endif // C2512STACK_H


int main() {
   
    C2512Stack<double> stack;

    try {
        // Push elements onto the stack
        stack.push(10.0);
        stack.push(12.0);
        stack.push(11.0);
        stack.push(12.0);
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

    cout << endl << endl;
    cout << "---------------------------String stack-----------------" << endl;
    C2512Stack<string> names;

    try {
        // Push elements onto the stack
        names.push("Athira");
        names.push("Abel");
        names.push("Minhaj");
        names.push("Raj");
    } catch (const overflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }   

    
    try {    
        // Access and pop elements
        cout << "Top:" << names.top() << endl; // Output: 11.0
        names.pop();

        cout << "Top:" << names.top() << endl; // Output: 12.0
        names.pop();

        cout << "Top:" << names.top() << endl; // Output: 10.0
        names.pop();

        // Attempting to access or pop an element from an empty stack
        cout << "Top:" << names.top() << endl; // Should throw an exception
        names.pop();                          // Should throw an exception

    } catch (const underflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

// Constructor: Initialize stack
template<class T>
C2512Stack<T>::C2512Stack() : _top(0) {}

// Push method: Adds an element to the stack
template<class T>
void C2512Stack<T>::push(T data) {
    if (_top >= _size) {
        throw overflow_error("Stack overflow: Cannot push more elements.");
    }
    arr[_top] = data; // Add data to the stack
    _top++;           // Increment the top
}

// Pop method: Removes the top element from the stack
template<class T>
void C2512Stack<T>::pop() {
    if (_top <= 0) {
        throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
    }
    _top--; // Decrement the top
}

// Top method: Returns the element at the top of the stack
template<class T>
T C2512Stack<T>::top() const {
    if (_top <= 0) {
        throw underflow_error("Stack underflow: Cannot access the top of an empty stack.");
    }
    return arr[_top - 1]; // Return the top element
}

// Utility function: Check if the stack is empty
template<class T>
bool C2512Stack<T>::isEmpty() const {
    return _top == 0;
}

// Utility function: Check if the stack is full
template<class T>
bool C2512Stack<T>::isFull() const {
    return _top == _size;
}
