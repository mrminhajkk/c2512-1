#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_SIZE = 6; 
int giveMeNumber()
{	
	int num = rand() % MAX_SIZE + 1;
	return num;
}

bool isExist(int nums[], int size, int num)
{
    for(int I = 1; I <= size; I++)
    {
        if(nums[I-1] == num){
            return true;
        }
    }
    return false; 
}

void giveMeNumbers(int nums[])
{
    srand(static_cast<unsigned>(time(0)));
    for(int I = 1; I <= MAX_SIZE; I++)
    {
        int num = giveMeNumber();
        while(isExist(nums, I, num))
        {
            num = giveMeNumber();
        }
        nums[I-1] = num;
    }
}

int main()
{
	int numbers[MAX_SIZE];
	giveMeNumbers(numbers);
	for(int I = 1; I <= MAX_SIZE; I++)
    {
        cout << numbers[I-1] << " ";
    }

	return 0;
}

//7 5 6 15 12 15 7 5 5 6 15 4 6 5 7 

//11 8 3 10 14 6 5 15 9 4 1 7 12 2 13