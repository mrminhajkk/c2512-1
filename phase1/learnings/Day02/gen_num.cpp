#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_SIZE = 5; 
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
/*
//ME:1 2 3 4 5   [venkatesh, sooraj, nimisha, vishak, josh->ge]  
    SOLID:  4 1 3 2 5
    SOLID: 10 6 7 8 9
    CP   :  3 4 1 5 2           [FM=1, AF=2, B=3, P=4, S=5]
    SP   :  4 1 6 2 3           [5] [7]   [A=1, B=2, C=3, D=4, FA=5, FW=6, P=7]

                                [CoR=1, Cmd=2, I=3, MED=4, Meme=5, 
                                 O=6,   Sta=7, Str=8, TM=9, V=10  ]
    BP   : 1 4 5  2 3
    BP   : 7 8 9 10 6 
//GE:1 2 3 4 5  [ayisha, athira, dhaheen, nayana, abel]
    SOLID: 1 5 2  4 3 
    SOLID: 9 7 8 10 6
    CP: 5 4 2 3 1          
    SP: 2 5 3 1 7               [4] [6] 
    BP:  1 5 4 3 2              
    BP: 10 6 8 9 7
//AU:1 2 3 4  [minhaj, vinayak, sana, pitchumani]
    SOLID: 4  5 1 2                 [3] ME
    SOLID: 7 10 8 9                 [6] GE 
    CP: 3 4 5 2                     [1]
    SP: 6 3 5 4                     [7] [2] [1] 
    BP:  4 5 1 3                    [2]
    BP: 10 9 7 6                    [8]


//SOLIC:1 2 3 4 5 
     6 7 8 9 10
//CP:1 2 3 4 5
//SP:1 2 3 4 5 6 7
//BP:1 2 3 4 5 
//BP:6 7 8 9 10
*/