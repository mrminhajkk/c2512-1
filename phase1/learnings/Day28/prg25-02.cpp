// program to demonstrate circular reference problem and 
// its solution using weak_ptr

// what is circular reference problem?
//      Circular reference problem occurs 
//      when two or more objects refer to each other,
//      creating a cycle of references. 
//
//      This can lead to memory leaks because the objects
//      will never be destroyed due to the circular references.
// is weak_ptr then not the smart_ptr?
//      weak_ptr is a smart pointer 
//      that holds a non-owning ("weak") reference to an object 
//      that is managed by shared_ptr.
#include <iostream>
#include <memory>

struct Child;
struct Parent {
    std::shared_ptr<Child> child;
    ~Parent() { std::cout << "Parent destroyed\n"; }
};

struct Child {
    std::weak_ptr<Parent> parent; // Use weak_ptr to avoid circular reference
    ~Child() { std::cout << "Child destroyed\n"; }
};

int main() {
    std::shared_ptr<Parent> p = std::make_shared<Parent>();
    std::shared_ptr<Child> c = std::make_shared<Child>();

    p->child = c;
    c->parent = p; // Circular reference resolved with weak_ptr

    return 0; // Both Parent and Child are destroyed correctly
}