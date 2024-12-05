#include <iostream>
#include <string>
#include "user_mgr.h"
using namespace std;

int main() {
    int id = 100;
    display_username();
    cout << "id=" << id << endl;
    return 0;
}
string username; //definition without initialization
//string username = "Minhaj"; //definition and initialization