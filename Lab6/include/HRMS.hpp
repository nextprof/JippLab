#include <employee.hpp>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

#ifndef HRMS_H
#define HRMS_H

class HRMS
{
    list<string> idsEmployees;

    map<string, Employee> allEmloyees;
    map<string, string> mapID_departamentID;
    map<string, double> employeeEarnings;

    static bool sortByVal(const pair<string, double> &a,
                          const pair<string, double> &b);

public:
    void add(Employee employee, string departmentId, double salary);
    void printDepartment(string departmentId);
    void changeSalary(string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted();
};
#endif