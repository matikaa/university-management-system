#include "functions.h"

int main()
{   Human to_log;

    string login;
    string password;
    string temporary;

    cout << "Enter login:" << endl;
    getline(cin, login);
    fflush(stdin);

    cout << "Enter password:" << endl;
    getline(cin, password);
    fflush(stdin);

    while(1)
    {
        if(to_log.logging(login, password) == 1)
        {
            cout << "Correct. You are logged now." << endl << endl;
            break;
        }

        cout << "Wrong login or password. If you want to break, enter YES or whatever else if you want to try again" << endl;
        getline(cin, temporary);
        fflush(stdin);

        if(temporary.compare("yes") == 0 || temporary.compare("YES") == 0)
        {
            cout << "End of program" << endl;
            return 0;
        }

        cout << "Enter login:" << endl;
        getline(cin, login);
        fflush(stdin);

        cout << "Enter password:" << endl;
        getline(cin, password);
        fflush(stdin);
    }

    vector<Student*> *students = new vector<Student*> [1];
    vector<Teacher*> *teachers = new vector<Teacher*> [1];
    vector<Employee*> *employees = new vector<Employee*> [1];

    while(menu_management(students, teachers, employees) != 42);

    free_all(students, teachers, employees);
    return 0;
}
