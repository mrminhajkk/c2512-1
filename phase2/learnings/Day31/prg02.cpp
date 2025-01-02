#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void sayHi() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Hi World!!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Hi Abel!!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Hi Nimisha!!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Hi Venkatesh!!" << endl;
}
void sayGoodAfternoon() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Good Afternoon World!!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Good Afternoon Vinayak!!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Good Afternoon Dhaheen!!" << endl;
}
int main()
{
    
    thread thrSayHi(sayHi);
    thread thrSayGoodAfternoon(sayGoodAfternoon);
    thrSayHi.join();
    thrSayGoodAfternoon.join();
    
    cout<<"Hello World" << endl;

    return 0;
}