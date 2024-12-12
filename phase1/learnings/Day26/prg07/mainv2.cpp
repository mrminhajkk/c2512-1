#include<iostream>
#include <stdexcept> // For exception handling
using namespace std;

template<class T>
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

class DoubleStack : public C2512Stack<double> {
    public:
        //my additional behaviours 
};


int main() {
   
    DoubleStack stack;

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



    return 0;
}




// Constructor: Initialize stack
template<class T>
C2512Stack<T>::C2512Stack() : _top(0) {}

// Push method: Adds an element to the stack
template<class T>
void C2512Stack<T>::push(T data) {
    if (isFull()) {
        throw overflow_error("Stack overflow: Cannot push more elements.");
    }
    arr[_top] = data; // Add data to the stack
    _top++;           // Increment the top
}

// Pop method: Removes the top element from the stack
template<class T>
void C2512Stack<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack underflow: Cannot pop from an empty stack.");
    }
    _top--; // Decrement the top
}

// Top method: Returns the element at the top of the stack
template<class T>
T C2512Stack<T>::top() const {
    if (isEmpty()) {
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
