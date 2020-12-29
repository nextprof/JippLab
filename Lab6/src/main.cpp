#include <HRMS.hpp>

using namespace std;

void testExceptions()
{
    HRMS systemTest;

    try
    {
        cout << endl;
        cout << "Trying add an Employee to system with other departmentID he is " << endl;
        Employee test0("nameTest0", "surnameTest0", "IdTEST0", "DepIdTest0", "occupationTest0");
        systemTest.add(test0, "DepIdTestOps", 4100);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        cout << endl;
        cout << "Trying to add an Employee to salary less than 0" << endl;
        Employee test1("nameTest", "surnameTest", "IdTEST", "DepIdTest", "occupationTest");
        systemTest.add(test1, "DepIdTest", -4100);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        cout << endl;
        cout << "Trying to change an Employee salary to less than 0" << endl;
        Employee test2("nameTest2", "surnameTest2", "IdTEST2", "DepIdTest2", "occupationTest2");
        systemTest.add(test2, "DepIdTest2", 4100);
        systemTest.changeSalary("IdTEST2", -100);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        cout << endl;
        cout << "Trying to create an Employee with non-unique ID" << endl;
        Employee test3("nameTest3", "surnameTest3", "IdTEST3", "DepIdTest3", "occupationTest3");
        Employee test4("nameTest4", "surnameTest4", "IdTEST3", "DepIdTest4", "occupationTest4");
        systemTest.add(test3, "DepIdTest3", 4100);
        systemTest.add(test4, "DepIdTest4", 5100);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        cout << endl;
        cout << "Trying to print non-existing Department ID members" << endl;
        systemTest.printDepartment("FakeDepartmentID");
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    try
    {
        cout << endl;
        cout << "Trying to change salary id that not exist in system. " << endl;
        systemTest.changeSalary("FakeID", 2500);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}
void test()
{
    HRMS system;

    Employee first("Artur", "Ciesielczyk", "ID1", "DEPID1", "Marketingowiec");
    Employee second("Artem", "Buhera", "ID2", "DEPID2", "InspektorGlowny");
    Employee third("Patryk", "Dudek", "ID3", "DEPID2", "Prezes");
    Employee fourth("Dawid", "Banach", "ID4", "DEPID2", "Kierownik");
    Employee fifth("Jan", "Bartula", "ID5", "DEPID3", "Dyrektor");
    Employee sixth("Filip", "Bulinski", "ID6", "DEPID3", "Recepcjonista");
    Employee seventh("Oskar", "Sliwinski", "ID7", "DEPID3", "Kucharz");
    Employee eigth("Szczepan", "Dolega", "ID8", "DEPID3", "Prokurator");
    Employee ninth("Adrian", "Dochnal", "ID9", "DEPID4", "Adwokat");
    Employee tenth("Mateusz", "Ciepal", "ID10", "DEPID4", "Kierowca");
    try
    {
        system.add(first, "DEPID1", 4100);
        system.add(second, "DEPID2", 6300);
        system.add(third, "DEPID2", 8550);
        system.add(fourth, "DEPID2", 5800);
        system.add(fifth, "DEPID3", 6250);
        system.add(sixth, "DEPID3", 3550);
        system.add(seventh, "DEPID3", 5050);
        system.add(eigth, "DEPID3", 7500);
        system.add(ninth, "DEPID4", 6200);
        system.add(tenth, "DEPID4", 3200);

        system.printSalaries();

        system.changeSalary("ID2", 7300);
        system.changeSalary("ID3", 9550);
        system.changeSalary("ID4", 6800);
    }
    catch (invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    cout << endl
         << "After raise members of DepartamentId 2 (+1000)"
         << endl;

    system.printSalaries();

    cout << endl
         << "Printing departments: ID1"
         << endl;
    system.printDepartment("DEPID1");

    cout << endl
         << "Printing departments: ID2"
         << endl;
    system.printDepartment("DEPID2");

    cout << endl
         << "Printing departments: ID3"
         << endl;
    system.printDepartment("DEPID3");

    cout << endl
         << "Printing departments: ID4"
         << endl;
    system.printDepartment("DEPID4");

    cout << endl
         << "Printing sorted salaries"
         << endl;

    system.printSalariesSorted();
}
int main()
{
    test();
    testExceptions();
}
