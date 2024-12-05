#include <iostream>
#include <string>
using namespace std;

string username = "Sooraj";
int main() {
    int id = 100;

    return 0;
}
============================================================
// user_mgr.h
void display_username();
============================================================
// user_mgr.cpp
#include <iostream>
#include "user_mgr.h"
using namespace std;

extern string username;
void display_username() {
    cout << "Username: " << username << endl;
}
============================================================