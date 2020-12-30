#include "HRMS/HRMS.hpp"

void HRMS::add(Employee& _employee, string _departmentid, double _salary)
{
    if(_salary < 0.0)
        throw -2;
    for(auto& n : dep_id)
    {
    if(n.first == _employee.id)
        throw -1;
    }    
    _employee.departmentid = _departmentid; 
    salary.push_back({ _employee.id, _salary });
    employee.push_back(_employee);      
    dep_id.insert({ _employee.id, _employee.departmentid });
}

void HRMS::printDepartment(string departmentid)
{
    int a = 0;
     for(auto n : dep_id)
    {
    if(n.second == departmentid)
        {++a; break;}
    } 
    if(a == 0)
        throw -3;
    cout << "ID dzialu: " << departmentid << endl;
    cout << " __________________________________________________________";
    cout << "\n|NAME";
    cout.width(10);
    cout << "|" << "SURNAME";
    cout.width(10);
    cout << "|" << "Position";
    cout.width(10);
    cout << "|" << "ID";
    cout.width(8);
    cout << "|" << endl;
    cout.setf(ios::left);

    for(Employee& n : employee)
    {
        if (departmentid == n.departmentid)
        {
            cout << "|=============+================+=================+=========|\n";
            cout << "|";
            cout.width(13);
            cout << n.name << "|";
            cout.width(16);
            cout << n.surname << "|";
            cout.width(17);
            cout << n.position << "|";
            cout.width(9);
            cout << n.id << "|\n";
        }
    }
    cout << "|__________________________________________________________|\n\n\n";
}

void HRMS::changeSalary(string employeeId, double _salary)
{
    if (_salary < 0)
        throw -2;
    int a = 0;
    for(auto n : dep_id)
    {
        if(employeeId == n.first)
            {
                ++a;
                break;
            }
    }
    if(a == 0)
    {
        throw -4;
    }

    auto it = salary.begin();
    cout << "Przed zamiana: " << it->second << "zl\n";
    for (it; it != salary.end(); ++it)
    {
        if (it->first == employeeId) 
        {
            it->second = _salary;
            break;
        }
    }
  
   cout << "Po zamianie: " << it->second << "zl\n\n";

}

void HRMS::printSalaries()
{
    label();
    cout.setf(ios::left);

    for (Employee& n : employee)
    {
      for(auto it = salary.begin(); it != salary.end(); ++it)
        {
              if (n.id == it->first)
              {
                  MapPrint(n, it->second);
                  break;
              }
          }
    }

    endLabel();
}

void HRMS::printSalariesSorted()
{
    label();
    sort(salary.begin(), salary.end(), pairComp);
    for (auto n : salary)
    {
        for (Employee &nn : employee)
        {
            if (nn.id == n.first)
            {
                MapPrint(nn, n.second);
                break;
            }
        }
    }
    endLabel();
}

void MapPrint(Employee& emp, double sal)
{
    cout << "|=============+================+=================+=========+===============+============|\n";
    cout << "|";
    cout.width(13);
    cout << emp.name << "|";
    cout.width(16);
    cout << emp.surname << "|";
    cout.width(17);
    cout << emp.position << "|";
    cout.width(9);
    cout << emp.id << "|";
    cout.width(15);
    cout << emp.departmentid << "|";
    cout.width(10);
    cout << sal << "zl|\n";
}

void label()
{
    cout << " _______________________________________________________________________________________";
    cout << "\n|NAME";
    cout.width(9);
    cout << " " << "|SURNAME";
    cout.width(9);
    cout << " " << "|Position";
    cout.width(9);
    cout << " " << "|ID";
    cout.width(7);
    cout << " " << "|Department ID";
    cout.width(2);
    cout << " " << "|Salary";
    cout << "      " << "|" << endl;
}

void endLabel()
{
    cout << "|_______________________________________________________________________________________|\n\n\n";
}

bool pairComp(const pair<string, double>& e1, const pair<string, double>& e2)
{
    return e1.second > e2.second;
}