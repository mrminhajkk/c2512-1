// user_mgr.cpp
#include <iostream>
#include "user_mgr.h"
using namespace std;

extern string username; //declaration // global.h 
void display_username() {
    cout << "Username: " << username << endl;
}