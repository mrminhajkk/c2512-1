#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	cout << "Hello World" << endl;
	char name[255];
	cout << "Name:";
	cin >> name;
	cout << "Hello " << name << endl;
	return EXIT_SUCCESS;
}
