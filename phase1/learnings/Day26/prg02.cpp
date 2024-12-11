#include <iostream>
#include <vector>    // For vector 
#include <algorithm>
using namespace std;
struct Employee
{
    public:
        string name;
        float salary;
        Employee(string name, float salary)
        {
            this->name = name;
            this->salary = salary;
        }
        friend ostream& operator<<(ostream& os, const Employee& employee)
        {
            os << "[" << employee.name << " " << employee.salary << "]";
            return os;
        }
};
int main()
{
    vector<float> temperatures {88.0f, 79.0f, 90.0f, 93.0f, 83.0f};
    vector<double> salaries {10000.0, 20000.0, 30000.0, 40000.0, 50000.0};
    vector<string> departments {"HR", "Finance", "Admin", "IT", "Sales"};
    vector<Employee> employees {Employee("John", 10000.0), Employee("Jane", 20000.0), 
                                Employee("Jim", 30000.0), Employee("Jack", 40000.0), 
                                Employee("Jill", 50000.0)};

    cout << "Temperatures:"; 
    for_each(temperatures.begin(), temperatures.end(), [](float temperature){cout << temperature << " ";}); 
    cout << endl;

    cout << "Salaries:"; 
    for_each(salaries.begin(), salaries.end(), [](float salary){cout << salary << " ";}); 
    cout << endl;

    cout << "Departments:";
    for_each(departments.begin(), departments.end(), [](string department){cout << department << " ";});
    cout << endl;

    cout << "Employees:";
    for_each(employees.begin(), employees.end(), [](Employee employee){cout << employee << " ";});
    cout << endl;
    return 0;
}