#include <iostream>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main() {
	char name[255];

    do {
        cout << "Enter name:";
        cin >> name;
        cout << "Hello " << name << "!!!" << endl;
    } while(strcmp(name,"end") != 0);

	return EXIT_SUCCESS;
}
