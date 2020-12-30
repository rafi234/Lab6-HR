#include "Employee/Employee.hpp"

Employee::Employee(string _id, string _name, string _surname, string _position)
{
    this->id =_id;
    this->name = _name;
    this->surname = _surname; 
    this->position = _position;
    cout << "Utworzono uzytkowinka: " << name << " " << surname << endl;  
}

Employee::~Employee()
{
    cout << "Usunieto uzytkownika: " << this->name << " " << this->surname << endl;
}
