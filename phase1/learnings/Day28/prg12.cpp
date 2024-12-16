#include<iostream>
#include<string>
using namespace std;

/*
auto sayHello(string name) -> void {
    cout << "Hello " << name << endl;
}*/

int main() 
{
    auto sayHello = [](string name) -> void {
        cout << "Hello " << name << endl;
    };
    
    sayHello("Nayana");
    sayHello("Nimisha");
        
    return 0;
}
