#include<iostream>
#include<queue>
using namespace std;


int main() 
{
    queue<double> salaries;
    salaries.push(10000.0);
    salaries.push(30000.0);
    salaries.push(20000.0);

    cout << "size:" << salaries.size() << endl;
    cout << "empty:" << salaries.empty() << endl;

    cout << endl;
    cout << "top:" << salaries.front() << endl; salaries.pop();
    cout << "top:" << salaries.front() << endl; salaries.pop();
    cout << "top:" << salaries.front() << endl; salaries.pop();
    cout << "top:" << salaries.front() << endl; salaries.pop();

    return 0;
}