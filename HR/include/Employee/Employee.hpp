#include <iostream>

using namespace std;

class Employee
{
public:
    Employee(string, string, string, string);
    ~Employee();
    string id; //identyfikator pracownika
    string name;
    string surname;
    string departmentid; //identyfikator działu w którym pracuje dane osoba
    string position; //stanowisko na którym pracuje dana osoba
};