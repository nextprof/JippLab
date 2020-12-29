#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
    string name;
    string surname;
    string position;
    string id;
    string departamentId;

public:
    Employee(string name, string surname, string id, string departamentId, string position);
    Employee();
    string getName();
    string getSurname();
    string getPosition();
    string getId();
    string getDepartamentId();
};
#endif