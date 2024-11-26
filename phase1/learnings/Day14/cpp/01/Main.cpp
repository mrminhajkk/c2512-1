#include <iostream>
#include <cstdlib>
#include "Student.h"
#include "StudentManager.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	int N;
	cout << "Number of Students:"; cin >> N;


	Student students[N] {};

	for(int I = 0; I < N; I++) {
		cout << "Enter " << (I+1) << " th student details." << endl;  student_read(students[I]);
	}
	
	for(int I = 0; I < N; I++) {
		student_print(students[I]); 
	}

	return EXIT_SUCCESS;
}
