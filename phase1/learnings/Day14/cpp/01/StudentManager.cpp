#include <iostream>
#include <cstdlib>
#include "Student.h"

using std::cout;
using std::cin;
using std::endl;

void student_read(Student& student) {
	cout << "Enter id:";
	cin >> student.id;
	cout << "Enter name:";
	cin >> student.name;
}

void student_print(Student& student) {
	cout << "Hello " << student.name << " of id " << student.id << "!!!" << endl;
}
