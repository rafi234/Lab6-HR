
#include <iostream>
#include "Employee/Employee.hpp"
#include <list>
#include <map>
#include<vector>
#include <algorithm>

using namespace std;

class HRMS {
private:
    list<Employee> employee;
    map<string, string> dep_id;
    vector <pair<string, double>> salary;

public:
    void add(Employee&, string, double);
    void printDepartment(string);
    void changeSalary(string, double);
    void printSalaries();
    void printSalariesSorted();
};

bool pairComp(const pair<string, double>&, const pair<string, double>&);
void label();
void MapPrint(Employee&, double);
void endLabel();