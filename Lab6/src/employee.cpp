#include <employee.hpp>

Employee::Employee(string name, string surname, string id, string departamentId, string position)
{
    this->name = name;
    this->surname = surname;
    this->id = id;
    this->departamentId = departamentId;
    this->position = position;
}
Employee::Employee() { ; }
string Employee::getName() { return this->name; }
string Employee::getSurname() { return this->surname; }
string Employee::getPosition() { return this->position; }
string Employee::getId() { return this->id; }
string Employee::getDepartamentId() { return this->departamentId; }