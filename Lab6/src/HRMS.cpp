#include <HRMS.hpp>

void HRMS::add(Employee employee, string departmentId, double salary)
{
    string employeeId = employee.getId();
    if (departmentId != employee.getDepartamentId())
    {
        stringstream errorMsg;
        errorMsg << "Department id of employee does not match to argument's departamentID"
                 << "|| an argument: " << departmentId << " his departamentID: " << employee.getDepartamentId();
        throw invalid_argument(errorMsg.str());
    }
    if (salary < 0)
    {
        stringstream errorMsg;
        errorMsg << "Amount of salary " << employee.getName() << " " << employee.getSurname()
                 << " is = " << salary << " - should be grater or equal 0";
        throw invalid_argument(errorMsg.str());
    }

    list<string>::iterator it;
    for (it = idsEmployees.begin(); it != idsEmployees.end(); it++)
    {
        if (*it == employeeId)
        {
            stringstream errorMsg;
            errorMsg << "This ID: " << employeeId << " already exist in system.";
            throw invalid_argument(errorMsg.str());
        }
    }
    idsEmployees.push_front(employeeId);
    this->allEmloyees[employeeId] = employee;
    this->mapID_departamentID[employeeId] = departmentId;
    this->employeeEarnings[employeeId] = salary;
}

void HRMS::printDepartment(string departmentId)
{
    int counter = 0;
    map<string, string>::iterator it;
    for (it = this->mapID_departamentID.begin(); it != this->mapID_departamentID.end(); ++it)
    {
        if (it->second == departmentId)
        {
            counter++;
            cout << this->allEmloyees[it->first].getName() << " " << this->allEmloyees[it->first].getSurname() << endl;
        }
    }
    if (counter == 0)
    {
        stringstream errorMsg;
        errorMsg << departmentId << " - DepartamentId does not exist in system.";
        throw invalid_argument(errorMsg.str());
    }
}

void HRMS::changeSalary(string employeeId, double salary)
{
    if (salary < 0)
    {
        stringstream errorMsg;
        errorMsg << "Value of salary should be grater or equal 0 "
                 << "employeeId: " << employeeId
                 << " Salary: " << salary
                 << " - should be grater or equal 0";
        throw invalid_argument(errorMsg.str());
    }
    list<string>::iterator it;
    int counter = 0;
    for (it = idsEmployees.begin(); it != idsEmployees.end(); it++)
    {
        if (*it == employeeId)
            counter++;
    }
    if (counter == 0)
    {
        stringstream errorMsg;
        errorMsg << "This ID: " << employeeId << " does not exist in system.";
        throw invalid_argument(errorMsg.str());
    }
    this->employeeEarnings[employeeId] = salary;
}

void HRMS::printSalaries()
{
    map<string, double>::iterator it;
    for (it = this->employeeEarnings.begin(); it != this->employeeEarnings.end(); it++)
    {
        {
            cout << "SALARY: " << it->second << " Position: " << this->allEmloyees[it->first].getPosition() << " "
                 << this->allEmloyees[it->first].getName() << " " << this->allEmloyees[it->first].getSurname()
                 << " ID: " << this->allEmloyees[it->first].getId()
                 << " DepartmentID: " << this->allEmloyees[it->first].getDepartamentId()
                 << endl;
        }
    }
}

void HRMS::printSalariesSorted()
{
    vector<pair<string, double>> vec;
    map<string, double>::iterator it2;
    for (it2 = this->employeeEarnings.begin(); it2 != this->employeeEarnings.end(); it2++)
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    sort(vec.begin(), vec.end(), sortByVal);

    vector<pair<string, double>>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << "SALARY: " << it->second << " Position: " << this->allEmloyees[it->first].getPosition() << " "
             << this->allEmloyees[it->first].getName() << " " << this->allEmloyees[it->first].getSurname()
             << " ID: " << this->allEmloyees[it->first].getId()
             << " DepartmentID: " << this->allEmloyees[it->first].getDepartamentId()
             << endl;
    }
}

bool HRMS::sortByVal(const pair<string, double> &a,
                     const pair<string, double> &b)
{
    return (a.second > b.second);
}