#include "manage_menu.h"

void show_all_students(vector<Student*> &students)
{
    for(unsigned long i = 0; i < students.size(); ++i)
        students[i]->show_student();
}

void show_all_teachers(vector<Teacher*> &teachers)
{
    for(unsigned long i = 0; i < teachers.size(); ++i)
        teachers[i]->show_teacher();
}

void show_all_employees(vector<Employee*> &employees)
{
    for(unsigned long i = 0; i < employees.size(); ++i)
        employees[i]->show_employee();
}

int log_in()
{
    Human to_log;

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
            return 1;
        }

        cout << "Enter login:" << endl;
        getline(cin, login);
        fflush(stdin);

        cout << "Enter password:" << endl;
        getline(cin, password);
        fflush(stdin);
    }

    return 0;
}
short menu_management()
{
    cout << "What do you want to do?" << endl;
    cout << "\t1 - manage student\n\t2 - manage teacher\n\t3 - manage employee\n\t4 - manage files\n" << endl;
    cout << "\t10 - if you want to quit\n" << endl;

    short choice;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    fflush(stdin);
    return choice;
}
void submenu()
{
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Employee*> employees;

    while(1)
    {
        int choice = menu_management();
        if(choice == 1)
            students_management(students);
        else if(choice == 2)
            teachers_management(teachers);
        else if(choice == 3)
            employees_management(employees);
        else if(choice == 4)
        {
            short number;
            cout << "Enter who you want to manage (1 - students, 2 - teachers, 3 - employees)" << endl;
            cin >> number;
            if(number == 1)
                students_file_management(students);
            else if(number == 2)
                teachers_file_management(teachers);
            else if(number == 3)
                employees_file_management(employees);
        }
        else if(choice == 10)
            break;
    }
    cout << "End of program" << endl;
    free_all(students, teachers, employees);
}

void students_management(vector<Student*> &students)
{
    string str_to_add;
    uint16_t age;
    uint64_t number;
    int grade;
    bool check = 0;

    cout << "\t1 - add student\n\t2 - find student by ID\n\t3 - show list of students\n\t4 - delete student\n\t5 - delete list of students\n" << endl;

    short choice;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    fflush(stdin);

    if(choice == 1)
    {
        Student *temp = new Student [1];
        if(temp == NULL)
            throw bad_alloc();

        cout << "Student's name:" << endl;
        getline(cin, str_to_add);
        temp->add_name(str_to_add);

        cout << "Student's surname:" << endl;
        fflush(stdin);
        getline(cin, str_to_add);
        temp->add_surname(str_to_add);

        cout << "Student's age:" << endl;
        cin >> age;
        temp->add_age(age);

        cout << "Student's ID:" << endl;
        cin >> number;
        temp->add_ID(number);

        cout << "Student's phone number:" << endl;
        cin >> number;
        temp->add_phone_number(number);

        cout << "Insurance paid? 1 - yes, 2 - no" << endl;
        cin >> number;
        if(number == 1)
            temp->pay_insurance();

        fflush(stdin);
        cout << "Student's faculty:" << endl;
        getline(cin, str_to_add);
        temp->add_faculty(str_to_add);

        fflush(stdin);
        cout << "Student's major:" << endl;
        getline(cin, str_to_add);
        temp->add_major(str_to_add);

        cout << "Add courses and write 'end' to finish:" << endl;
        while(1)
        {
            cout << "Course:";
            fflush(stdin);
            getline(cin, str_to_add);
            if(str_to_add.compare("end") == 0)
                break;

            temp->add_course(str_to_add);

            cout << "Add grades and write '0' to finish:" << endl;
            while(1)
            {
                cin >> grade;
                if(grade == 0)
                    break;
                temp->add_grade_to_course(str_to_add, grade);
            }
        }

        students.push_back(temp);

    }
    else if(choice == 2)
    {
        cout << "Enter student's ID:" << endl;
        cin >> number;
        for(int i = 0; i < students.size(); ++i)
        {
            if(number == students[i]->get_ID())
            {
                check = 1;
                cout << "The student you were looking for:" << endl << endl;
                students[i]->show_student();
            }
        }
        if(check == 0)
        {
            cout << "There is not that student at our list" << endl;
        }
    }
    else if(choice == 3)
    {
        if(students.size() == 0)
            cout << "List of students is empty" << endl;
        else
        {
            cout << "This is actual list of students:" << endl << endl;
            show_all_students(students);
        }
    }
    else if(choice == 4)
    {
        cout << "Enter student's ID who you want to delete: " << endl;
        cin >> number;
        for(int i = 0; i < students.size(); ++i)
        {
            if(students[i]->get_ID() == number)
            {
                students.erase(students.begin() + i);
                check = 1;
                cout << "Student with ID: " << number << " has been deleted" << endl;
                break;
            }
        }
        if(check == 0)
            cout << "There is no student with that ID" << endl;
    }
    else if(choice == 5)
    {
        cout << "Are you sure that you want to delete list of students? 1 - yes, 2 - no" << endl;
        cin >> check;
        if(check == 1)
        {
            students.clear();
            cout << "List has been deleted" << endl;
        }
    }
}
void teachers_management(vector<Teacher*> &teachers)
{
    string str_to_add;
    uint16_t age;
    uint64_t number;
    int grade;
    bool check = 0;

    cout << "\t1 - add teacher\n\t2 - find teacher by ID\n\t3 - show list of teachers\n\t4 - delete teacher\n\t5 - delete list of teachers\n" << endl;

    short choice;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    fflush(stdin);

    if(choice == 1)
    {
        double money;

        Teacher *temp = new Teacher [1];
        if(temp == NULL)
            throw bad_alloc();

        cout << "Teacher's name:" << endl;
        getline(cin, str_to_add);
        temp->add_name(str_to_add);

        cout << "Teacher's surname:" << endl;
        fflush(stdin);
        getline(cin, str_to_add);
        temp->add_surname(str_to_add);

        cout << "Teacher's age:" << endl;
        cin >> age;
        temp->add_age(age);

        cout << "Teacher's ID:" << endl;
        cin >> number;
        temp->add_ID(number);

        cout << "Teacher's phone number:" << endl;
        cin >> number;
        temp->add_phone_number(number);

        cout << "Teacher's degree:" << endl;
        fflush(stdin);
        getline(cin, str_to_add);
        temp->add_degree(str_to_add);

        cout << "Teacher's faculty:" << endl;
        fflush(stdin);
        getline(cin, str_to_add);
        temp->add_faculty(str_to_add);

        cout << "Teacher's salary:" << endl;
        cin >> money;
        temp->add_salary(money);

        cout << "Add subjects which teacher takes care and write 'end' to finish:" << endl;
        while(1)
        {
            cout << "Subject:";
            fflush(stdin);
            getline(cin, str_to_add);
            if(str_to_add.compare("end") == 0)
                break;

            temp->add_subjects(str_to_add);
        }

        teachers.push_back(temp);
    }
    else if(choice == 2)
    {
        cout << "Enter teacher's ID:" << endl;
        cin >> number;
        for(int i = 0; i < teachers.size(); ++i)
        {
            if(number == teachers[i]->get_ID())
            {
                check = 1;
                cout << "The teacher you were looking for:" << endl << endl;
                teachers[i]->show_teacher();
            }
        }
        if(check == 0)
        {
            cout << "There is not that teacher at our list" << endl;
        }
    }
    else if(choice == 3)
    {
        if(teachers.size() == 0)
            cout << "List of teachers is empty" << endl;
        else
        {
            cout << "This is actual list of teachers:" << endl << endl;
            show_all_teachers(teachers);
        }
    }
    else if(choice == 4)
    {
        cout << "Enter teacher's ID who you want to delete: " << endl;
        cin >> number;
        for(int i = 0; i < teachers.size(); ++i)
        {
            if(teachers[i]->get_ID() == number)
            {
                teachers.erase(teachers.begin() + i);
                check = 1;
                cout << "Teacher with ID: " << number << " has been deleted" << endl;
                break;
            }
        }
        if(check == 0)
            cout << "There is no teacher with that ID" << endl;
    }
    else if(choice == 5)
    {
        cout << "Are you sure that you want to delete list of teachers? 1 - yes, 2 - no" << endl;
        cin >> check;
        if(check == 1)
        {
            teachers.clear();
            cout << "List has been deleted" << endl;
        }
    }
}
void employees_management(vector<Employee*> &employees)
{
    string str_to_add;
    uint16_t age;
    uint64_t number;
    bool check = 0;

    cout << "\t1 - add employee\n\t2 - find employee by ID\n\t3 - show list of employees\n\t4 - delete employee\n\t5 - delete list of employees\n" << endl;

    short choice;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    fflush(stdin);

    if(choice == 1)
    {
        Employee *emp = new Employee [1];
        if(emp == NULL)
            throw bad_alloc();

        double money;

        cout << "Employee's name:" << endl;
        getline(cin, str_to_add);
        emp->add_name(str_to_add);

        cout << "Employee's surname:" << endl;
        fflush(stdin);
        getline(cin, str_to_add);
        emp->add_surname(str_to_add);

        cout << "Employee's age:" << endl;
        cin >> age;
        emp->add_age(age);

        cout << "Employee's ID:" << endl;
        cin >> number;
        emp->add_ID(number);

        cout << "Employee's phone number:" << endl;
        cin >> number;
        emp->add_phone_number(number);

        cout << "Employee's position:" << endl;
        fflush(stdin);
        getline(cin, str_to_add);
        emp->add_position(str_to_add);

        cout << "Employee's salary:" << endl;
        cin >> money;
        emp->add_salary(money);

        employees.push_back(emp);
    }
    else if(choice == 2)
    {
        cout << "Enter employee's ID:" << endl;
        cin >> number;
        for(int i = 0; i < employees.size(); ++i)
        {
            if(number == employees[i]->get_ID())
            {
                check = 1;
                cout << "The employee you were looking for:" << endl << endl;
                employees[i]->show_teacher();
            }
        }
        if(check == 0)
        {
            cout << "There is not that employee at our list" << endl;
        }
    }
    else if(choice == 3)
    {
        if(employees.size() == 0)
            cout << "List of employees is empty" << endl;
        else
        {
            cout << "This is actual list of employees:" << endl << endl;
            show_all_employees(employees);
        }
    }
    else if(choice == 4)
    {
        cout << "Enter employee's ID who you want to delete: " << endl;
        cin >> number;
        for(int i = 0; i < employees.size(); ++i)
        {
            if(employees[i]->get_ID() == number)
            {
                employees.erase(employees.begin() + i);
                check = 1;
                cout << "Employee with ID: " << number << " has been deleted" << endl;
                break;
            }
        }
        if(check == 0)
            cout << "There is no employee with that ID" << endl;
    }
    else if(choice == 5)
    {
        cout << "Are you sure that you want to delete list of employees? 1 - yes, 2 - no" << endl;
        cin >> check;
        if(check == 1)
        {
            employees.clear();
            cout << "List has been deleted" << endl;
        }
    }
}

void students_file_management(vector<Student*> &students)
{
    short read_load = 0;
    cout << "Do you want to read from file (1) or save to file (2)?" << endl;
    cin >> read_load;
    fflush(stdin);

    string filename;
    cout << "Enter name of file:" << endl;
    getline(cin, filename);
    fflush(stdin);

    if(read_load == 1)
    {
        ifstream file(filename);

        string str_to_add;
        char array[50];
        char to_delete;
        int i = 0, choice = 0, grade = 0;
        uint16_t Age;
        uint64_t number;
        double money;

        if(!file.is_open())
        {
            cout << "Incorrect destination file" << endl;
            return;
        }

        while(file)
        {
            Student *stu = new Student[1];
            if(stu == NULL)
                throw bad_alloc();

            while(file)
            {
                *(array + i) = file.get();
                if(*array == '\n')
                    continue;
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }

            }
            if(file.good() == 0)
            {
                delete[] stu;
                break;
            }
            i = 0;
            str_to_add = array;
            stu->add_name(str_to_add);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }

            i = 0;
            str_to_add = array;
            stu->add_surname(str_to_add);

            file >> Age;
            file >> to_delete;
            stu->add_age(Age);

            file >> number;
            file >> to_delete;
            stu->add_ID(number);

            file >> number;
            file >> to_delete;
            stu->add_phone_number(number);

            file >> number;
            file >> to_delete;
            if(number == 1)
                stu->pay_insurance();

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }
            i = 0;
            str_to_add = array;
            stu->add_faculty(str_to_add);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }
            i = 0;
            str_to_add = array;
            stu->add_major(str_to_add);

            file >> choice;
            file >> to_delete;

            for(int j = 0; j < choice; ++j)
            {
                while(file)
                {
                    *(array + i) = file.get();
                    if(*(array + (i++)) == '|')
                    {
                        *(array + i - 1) = '\0';
                        break;
                    }
                }
                i = 0;
                str_to_add = array;
                stu->add_course(str_to_add);

                while(1)
                {
                    file >> grade;
                    if(j < choice - 1)
                        file >> to_delete;
                    else if(grade != 0)
                        file >> to_delete;

                    if(grade == 0)
                        break;

                    stu->add_grade_to_course(str_to_add, grade);
                }
            }

            students.push_back(stu);
        }

        file.close();
    }
    else if(read_load == 2)
    {
        if(students.size() == 0)
        {
            cout << "No data to save to file" << endl;
            return;
        }

        ofstream file;
        file.open(filename);

        if(!file.is_open())
        {
            cout << "Incorrect destination file" << endl;
            return;
        }
        for(int i = 0; i < students.size(); ++i)
        {
            file << students[i]->get_name() << "|" << students[i]->get_surname() << "|" << students[i]->get_age() << "|";
            file << students[i]->get_ID() << "|" << students[i]->get_phone() << "|" << students[i]->get_insurance() << "|";
            file << students[i]->get_faculty() << "|" << students[i]->get_major() << "|" << students[i]->get_courses().size() << "|";
            for(int j = 0; j < students[i]->get_courses().size(); ++j)
            {
                file << students[i]->get_courses()[j]->course << "|";
                for(int k = 0; k < students[i]->get_courses()[j]->number_of_grades; ++k)
                {
                    file << students[i]->get_courses()[j]->grades[k] << "|";
                }
                file << "0";
                if(j + 1 != students[i]->get_courses().size())
                    file << "|";
            }
            file << "\n";
        }

        file.close();
    }
    else
    {
        cout << "Incorrect input" << endl << endl;
        return;
    }

    cout << "Your data has been saved successfully" << endl << endl;
    return;
}
void teachers_file_management(vector<Teacher*> &teachers)
{
    short read_load = 0;
    cout << "Do you want to read from file (1) or save to file (2)?" << endl;
    cin >> read_load;
    fflush(stdin);

    string filename;
    cout << "Enter name of file:" << endl;
    getline(cin, filename);
    fflush(stdin);

    if(read_load == 1)
    {
        ifstream file(filename);

        string str_to_add;
        char array[50];
        char to_delete;
        int i = 0, choice = 0;
        uint16_t Age;
        uint64_t number;
        double money;

        while(file)
        {
            Teacher *teach = new Teacher[1];
            if(teach == NULL)
                throw bad_alloc();

            while(file)
            {
                *(array + i) = file.get();
                if(*array == '\n')
                    continue;
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }

            }
            if(file.good() == 0)
            {
                delete[] teach;
                break;
            }
            i = 0;
            str_to_add = array;
            teach->add_name(str_to_add);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }

            i = 0;
            str_to_add = array;
            teach->add_surname(str_to_add);

            file >> Age;
            file >> to_delete;
            teach->add_age(Age);

            file >> number;
            file >> to_delete;
            teach->add_ID(number);

            file >> number;
            file >> to_delete;
            teach->add_phone_number(number);

            file >> money;
            file >> to_delete;
            teach->add_salary(money);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }
            i = 0;
            str_to_add = array;
            teach->add_faculty(str_to_add);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }
            i = 0;
            str_to_add = array;
            teach->add_degree(str_to_add);

            file >> choice; // how many subjects
            file >> to_delete;

            for(int j = 0; j < choice; ++j)
            {
                while(file)
                {
                    *(array + i) = file.get();
                    if(*(array + (i++)) == '|' || *(array +i-1) == '\n')
                    {
                        *(array + i - 1) = '\0';
                        break;
                    }
                }
                i = 0;
                str_to_add = array;
                teach->add_subjects(str_to_add);

            }

            teachers.push_back(teach);

        }

        file.close();
    }
    else if(read_load == 2)
    {
        if(teachers.size() == 0)
        {
            cout << "No data to save to file" << endl;
            return;
        }

        ofstream file;
        file.open(filename);

        if(!file.is_open())
        {
            cout << "Incorrect destination file" << endl;
            return;
        }

        for(int i = 0; i < teachers.size(); ++i)
        {
            file << teachers[i]->get_name() << "|" << teachers[i]->get_surname() << "|" << teachers[i]->get_age() << "|";
            file << teachers[i]->get_ID() << "|" << teachers[i]->get_phone() << "|" << teachers[i]->get_salary() << "|";
            file << teachers[i]->get_faculty() << "|" << teachers[i]->get_degree() << "|" << teachers[i]->get_subjects().size();

            for(int j = 0; j < teachers[i]->get_subjects().size(); ++j)
            {
                file << "|" << teachers[i]->get_subjects()[j];
            }
            file << "\n";
        }

        file.close();
    }
    else
    {
        cout << "Incorrect input" << endl << endl;
        return;
    }

    cout << "Your data has been saved successfully" << endl << endl;
    return;
}
void employees_file_management(vector<Employee*> &employees)
{
    short read_load = 0;
    cout << "Do you want to read from file (1) or save to file (2)?" << endl;
    cin >> read_load;
    fflush(stdin);

    string filename;
    cout << "Enter name of file:" << endl;
    getline(cin, filename);
    fflush(stdin);

    if(read_load == 1)
    {
        ifstream file(filename);

        if(!file.is_open())
        {
            cout << "Incorrect destination file" << endl;
            return;
        }

        string str_to_add;
        char array[50];
        char to_delete;
        int i = 0, choice = 0, grade = 0;
        uint16_t Age;
        uint64_t number;
        double money;

        while(file)
        {
            Employee *emp = new Employee[1];
            if(emp == NULL)
                throw bad_alloc();

            while(file)
            {
                *(array + i) = file.get();
                if(*array == '\n')
                    continue;
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }

            }
            if(file.good() == 0)
            {
                delete[] emp;
                break;
            }
            i = 0;
            str_to_add = array;
            emp->add_name(str_to_add);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }

            i = 0;
            str_to_add = array;
            emp->add_surname(str_to_add);

            file >> Age;
            file >> to_delete;
            emp->add_age(Age);

            file >> number;
            file >> to_delete;
            emp->add_ID(number);

            file >> number;
            file >> to_delete;
            emp->add_phone_number(number);

            file >> money;
            file >> to_delete;
            emp->add_salary(money);

            while(file)
            {
                *(array + i) = file.get();
                if(*(array + (i++)) == '|' || *(array +i-1) == '\n')
                {
                    *(array + i - 1) = '\0';
                    break;
                }
            }
            i = 0;
            str_to_add = array;
            emp->add_position(str_to_add);

            employees.push_back(emp);

        }
        file.close();
    }
    else if(read_load == 2)
    {
        if(employees.size() == 0)
        {
            cout << "No data to save to file" << endl;
            return;
        }

        ofstream file;
        file.open(filename);

        if(!file.is_open())
        {
            cout << "Incorrect destination file" << endl;
            return;
        }

        for(int i = 0; i < employees.size(); ++i)
        {
            file << employees[i]->get_name() << "|" << employees[i]->get_surname() << "|" << employees[i]->get_age() << "|";
            file << employees[i]->get_ID() << "|" << employees[i]->get_phone() << "|" << employees[i]->get_salary() << "|" << employees[i]->get_position() << endl;
        }

        file.close();
    }
    else
    {
        cout << "Incorrect input" << endl << endl;
        return;
    }

    cout << "Your data has been saved successfully" << endl << endl;
    return;
}

void free_all(vector<Student*> &students, vector<Teacher*> &teachers, vector<Employee*> &employees)
{
    for(int i = 0; i < students.size(); ++i)
    {
        for(int j = 0; j < students[i]->get_courses().size(); ++j)
            free(students[i]->get_courses()[j]->grades);
        students[i]->get_courses().clear();
    }

    for(int i = 0; i < teachers.size(); ++i)
        teachers[i]->get_subjects().clear();

    students.clear();
    teachers.clear();
    employees.clear();
}