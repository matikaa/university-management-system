#include "functions.h"

bool Human::logging(string log, string pass)
{
    if(login.compare(log) == 0)
        if(password.compare(pass) == 0)
            return 1;
    return 0;
}
void Human::add_name(string Name)
{
    name = Name;
}
void Human::add_surname(string Name)
{
    surname = Name;
}
void Human::add_age(uint16_t Age)
{
    age = Age;
}
void Human::add_ID(uint64_t number)
{
    ID = number;
}
void Human::add_phone_number(uint64_t number)
{
    phone_number = number;
}

void Teacher::add_degree(string to_add)
{
    degree = to_add;
}
void Teacher::add_faculty(string to_add)
{
    faculty = to_add;
}
void Teacher::add_subjects(string to_add)
{
    subjects_to_teach.push_back(to_add);
}
uint32_t Teacher::add_salary(double money)
{
    if(money <= 0)
        return 1;

    salary = money;
    return 0;
}
void Teacher::show_teacher()
{
    cout << "Name and surname: " << name << " " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "ID number: " << ID << endl;
    cout << "Phone number: " << phone_number << endl;
    cout << "Salary: " << salary << endl;
    cout << "Degree: " << degree << endl;
    cout << "Faculty: " << faculty << endl;
    cout << "Teaching subjects:" << endl;
    for(int i = 0; i < subjects_to_teach.size(); ++i)
    {
        cout << "\t" << subjects_to_teach[i] << endl;
    }
    cout << endl;
}

void Employee::add_position(string to_add)
{
    position = to_add;
}
uint32_t Employee::add_salary(double money)
{
    if(money <= 0)
        return 1;

    salary = money;
    return 0;
}
void Employee::show_employee()
{
    cout << "Name and surname: " << name << " " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "ID number: " << ID << endl;
    cout << "Phone number: " << phone_number << endl;
    cout << "Position: " << position << endl;
    cout << "Salary: " << salary << endl;
    cout << endl;
}

uint32_t Student::pay_insurance()
{
    if(valid_insurance() == 1)
        return 1;
    is_insurance_paid = 1;
    return 0;
}
uint32_t Student::valid_insurance()
{
    if(is_insurance_paid == 1)
        return 1;
    return 0;
}
void Student::add_faculty(string to_add)
{
    if(faculty.empty() == 1)
        faculty = to_add;
}
void Student::add_major(string to_add)
{
    if(major.empty() == 1)
        major = to_add;
}
uint32_t Student::add_course(string to_add)
{
    for(size_t i = 0; i < courses.size(); ++i)
    {
        if(courses[i]->course.compare(to_add) == 0)
            return 1;
    }
    Courses *temp = new Courses [1];
    temp->course = to_add;
    courses.push_back(temp);

    return 0;
}
uint32_t Student::add_grade_to_course(string to_add, int grade)
{
    for(size_t i = 0; i < courses.size(); ++i)
    {
        if(courses[i]->course.compare(to_add) == 0)
        {
            if(courses[i]->grades == NULL)
            {
                courses[i]->grades = new int [1];
                if(courses[i]->grades == NULL)
                    throw bad_alloc();

                courses[i]->grades[0] = grade;
                courses[i]->number_of_grades++;
            }
            else
            {
                int *temp = new int [courses[i]->number_of_grades + 1];
                if(temp == NULL)
                    throw bad_alloc();

                for(int j = 0; j < courses[i]->number_of_grades; ++j)
                    temp[j] = courses[i]->grades[j];
                temp[courses[i]->number_of_grades++] = grade;
                free(courses[i]->grades);

                courses[i]->grades = temp;
            }
            return 0;
        }
    }

    return 1;
}
void Student::show_student()
{
    cout << "Name and surname: " << name << " " << surname << endl;
    cout << "Age: " << age << endl;
    cout << "ID number: " << ID << endl;
    cout << "Phone number: " << phone_number << endl;
    cout << "Faculty: " << faculty << endl;
    cout << "Major: " << major << endl;
    cout << "State of insurance: ";
    if(is_insurance_paid == 0)
        cout << "unpaid" << endl;
    else
        cout << "paid" << endl;
    cout << "List of subjects and marks:" << endl;
    for(int i = 0; i < courses.size(); ++i)
    {
        cout << "\tSubject: " << courses[i]->course << endl << "\t    Marks: ";
        for(int j = 0; j < courses[i]->number_of_grades; ++j)
            cout << courses[i]->grades[j] << " ";
        if(courses[i]->number_of_grades == 0)
            cout << "None";
        cout << endl;
    }
    cout << endl;
}

void show_all_students(vector<Student*> *students)
{

    for(unsigned long i = 0; i < students[0].size(); ++i)
        students[0][i]->show_student();
}

void show_all_teachers(vector<Teacher*> *teachers)
{
    for(unsigned long i = 0; i < teachers[0].size(); ++i)
        teachers[0][i]->show_teacher();
}

void show_all_employees(vector<Employee*> *employees)
{
    for(unsigned long i = 0; i < employees[0].size(); ++i)
        employees[0][i]->show_employee();
}

short menu_management(vector<Student*> *students, vector<Teacher*> *teachers, vector<Employee*> *employees)
{
    cout << "What do you want to do?" << endl;
    cout << "\t1 - add student\n\t2 - find student by ID\n\t3 - show list of students\n\t4 - delete student\n\t5 - delete list of students\n" << endl;
    cout << "\t6 - add teacher\n\t7 - find teacher by ID\n\t8 - show list of teachers\n\t9 - delete student\n\t10 - delete list of students\n" << endl;
    cout << "\t11 - add employee\n\t12 - find employee by ID\n\t13 - show list of employees\n\t14 - delete student\n\t15 - delete list of students\n" << endl;
    cout << "\t16 - write to file\n\t17 - read from file\n" << endl;
    cout << "\t42 - if you want to quit\n" << endl;

    short choice;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    fflush(stdin);

    string str_to_add;
    uint16_t age;
    uint64_t number;
    int grade;
    bool check = 0;

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

        students->push_back(temp);

    }
    else if(choice == 2)
    {
        cout << "Enter student's ID:" << endl;
        cin >> number;
        for(int i = 0; i < students[0].size(); ++i)
        {
            if(number == students[0][i]->get_ID())
            {
                check = 1;
                cout << "The student you were looking for:" << endl << endl;
                students[0][i]->show_student();
            }
        }
        if(check == 0)
        {
            cout << "There is not that student at our list" << endl;
        }
    }
    else if(choice == 3)
    {
        if(students->size() == 0)
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
        for(int i = 0; i < students->size(); ++i)
        {
            if(students[0][i]->get_ID() == number)
            {
                students[0].erase(students[0].begin() + i);
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
        cout << "Are you sure that you want to delete list of students? 1 - yes, 0 - no" << endl;
        cin >> check;
        if(check == 1)
        {
            students[0].clear();
            cout << "List has been deleted" << endl;
        }
    }
    else if(choice == 6)
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

        teachers->push_back(temp);
    }
    else if(choice == 7)
    {
        cout << "Enter teacher's ID:" << endl;
        cin >> number;
        for(int i = 0; i < teachers[0].size(); ++i)
        {
            if(number == teachers[0][i]->get_ID())
            {
                check = 1;
                cout << "The teacher you were looking for:" << endl << endl;
                teachers[0][i]->show_teacher();
            }
        }
        if(check == 0)
        {
            cout << "There is not that teacher at our list" << endl;
        }
    }
    else if(choice == 8)
    {
        if(teachers->size() == 0)
            cout << "List of teachers is empty" << endl;
        else
        {
            cout << "This is actual list of teachers:" << endl << endl;
            show_all_teachers(teachers);
        }
    }
    else if(choice == 9)
    {
        cout << "Enter teacher's ID who you want to delete: " << endl;
        cin >> number;
        for(int i = 0; i < teachers->size(); ++i)
        {
            if(teachers[0][i]->get_ID() == number)
            {
                teachers[0].erase(teachers[0].begin() + i);
                check = 1;
                cout << "Teacher with ID: " << number << " has been deleted" << endl;
                break;
            }
        }
        if(check == 0)
            cout << "There is no teacher with that ID" << endl;
    }
    else if(choice == 10)
    {
        cout << "Are you sure that you want to delete list of teachers? 1 - yes, 0 - no" << endl;
        cin >> check;
        if(check == 1)
        {
            teachers[0].clear();
            cout << "List has been deleted" << endl;
        }
    }
    else if(choice == 11)
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

        employees[0].push_back(emp);
    }
    else if(choice == 12)
    {
        cout << "Enter employee's ID:" << endl;
        cin >> number;
        for(int i = 0; i < employees[0].size(); ++i)
        {
            if(number == employees[0][i]->get_ID())
            {
                check = 1;
                cout << "The employee you were looking for:" << endl << endl;
                employees[0][i]->show_teacher();
            }
        }
        if(check == 0)
        {
            cout << "There is not that employee at our list" << endl;
        }
    }
    else if(choice == 13)
    {
        if(employees->size() == 0)
            cout << "List of employees is empty" << endl;
        else
        {
            cout << "This is actual list of employees:" << endl << endl;
            show_all_employees(employees);
        }
    }
    else if(choice == 14)
    {
        cout << "Enter employee's ID who you want to delete: " << endl;
        cin >> number;
        for(int i = 0; i < employees->size(); ++i)
        {
            if(employees[0][i]->get_ID() == number)
            {
                employees[0].erase(employees[0].begin() + i);
                check = 1;
                cout << "Employee with ID: " << number << " has been deleted" << endl;
                break;
            }
        }
        if(check == 0)
            cout << "There is no employee with that ID" << endl;
    }
    else if(choice == 15)
    {
        cout << "Are you sure that you want to delete list of employees? 1 - yes, 0 - no" << endl;
        cin >> check;
        if(check == 1)
        {
            employees[0].clear();
            cout << "List has been deleted" << endl;
        }
    }
    else if(choice == 16)
    {
        enum type_t type;

        char array[100];
        int typ = 5;
        cout << "Enter destination (name of file):" << endl;
        cin >> array;

        cout << "Enter type of data (0 - students, 1 - teachers, 2 - employees):" << endl;
        cin >> typ;
        if(typ == 0)
            type = STUDENTS;
        else if(typ == 1)
            type = TEACHERS;
        else if (typ == 2)
            type = EMPLOYEES;
        else
        {
            cout << "INCORRECT TYPE OF DATA" << endl << endl;
            return 99;
        }

        save_to_file(array, students, teachers, employees, type);
    }
    else if(choice == 17)
    {
        enum type_t type;

        char array[100];
        int typ = 5;
        cout << "Enter destination (name of file):" << endl;
        cin >> array;

        cout << "Enter type of data (0 - students, 1 - teachers, 2 - employees):" << endl;
        cin >> typ;
        if(typ == 0)
            type = STUDENTS;
        else if(typ == 1)
            type = TEACHERS;
        else if (typ == 2)
            type = EMPLOYEES;
        else
        {
            cout << "INCORRECT TYPE OF DATA" << endl << endl;
            return 99;
        }

        load_from_file(array, students, teachers, employees, type);
    }

    return choice;
}

int load_from_file(const char *filename, vector<Student*> *students, vector<Teacher*> *teachers, vector<Employee*> *employees, int type)
{
    if(filename == NULL)
        return 1;

    ifstream file(filename);

    string str_to_add;
    char array[50];
    char to_delete;
    int i = 0, choice = 0, grade = 0;
    uint16_t Age;
    uint64_t number;
    double money;

    if(file.is_open())
    {
        if(type == 0) // students
        {
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

                students->push_back(stu);
            }
        }
        else if(type == 1) // teachers
        {
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

                teachers->push_back(teach);
            }
        }
        else if(type == 2) // employees
        {
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

                employees->push_back(emp);
            }
        }
    }
    else
        cout << "Incorrect destination file" << endl;

    cout << "Your data from file has been loaded successfully" << endl << endl;
    file.close();
    return 0;
}

int save_to_file(const char *filename, vector<Student*> *students, vector<Teacher*> *teachers, vector<Employee*> *employees, enum type_t type)
{
    if(filename == NULL)
        return 1;

    ofstream file;
    file.open(filename);

    if(!file.is_open())
    {
        cout << "Incorrect destination file" << endl;
        return 1;
    }

    if(type == STUDENTS)
    {
        if(students->size() == 0)
        {
            cout << "No data to save to file" << endl;
            return -1;
        }
        for(int i = 0; i < students[0].size(); ++i)
        {
            file << students[0][i]->get_name() << "|" << students[0][i]->get_surname() << "|" << students[0][i]->get_age() << "|";
            file << students[0][i]->get_ID() << "|" << students[0][i]->get_phone() << "|" << students[0][i]->get_insurance() << "|";
            file << students[0][i]->get_faculty() << "|" << students[0][i]->get_major() << "|" << students[0][i]->get_courses().size() << "|";
            for(int j = 0; j < students[0][i]->get_courses().size(); ++j)
            {
                file << students[0][i]->get_courses()[j]->course << "|";
                for(int k = 0; k < students[0][i]->get_courses()[j]->number_of_grades; ++k)
                {
                    file << students[0][i]->get_courses()[j]->grades[k] << "|";
                }
                file << "0";
                if(j + 1 != students[0][i]->get_courses().size())
                    file << "|";
            }
            file << "\n";
        }
    }
    else if(type == TEACHERS)
    {
        if(teachers->size() == 0)
        {
            cout << "No data to save to file" << endl;
            return -1;
        }
        for(int i = 0; i < teachers[0].size(); ++i)
        {
            file << teachers[0][i]->get_name() << "|" << teachers[0][i]->get_surname() << "|" << teachers[0][i]->get_age() << "|";
            file << teachers[0][i]->get_ID() << "|" << teachers[0][i]->get_phone() << "|" << teachers[0][i]->get_salary() << "|";
            file << teachers[0][i]->get_faculty() << "|" << teachers[0][i]->get_degree() << "|" << teachers[0][i]->get_subjects().size();

            for(int j = 0; j < teachers[0][i]->get_subjects().size(); ++j)
            {
                file << "|" << teachers[0][i]->get_subjects()[j];
            }
            file << "\n";
        }
    }
    else if(type == EMPLOYEES)
    {
        if(employees->size() == 0)
        {
            cout << "No data to save to file" << endl;
            return -1;
        }
        for(int i = 0; i < employees[0].size(); ++i)
        {
            file << employees[0][i]->get_name() << "|" << employees[0][i]->get_surname() << "|" << employees[0][i]->get_age() << "|";
            file << employees[0][i]->get_ID() << "|" << employees[0][i]->get_phone() << "|" << employees[0][i]->get_salary() << "|" << employees[0][i]->get_position() << endl;
        }
    }

    cout << "Your data has been saved successfully" << endl << endl;
    file.close();
    return 0;
}

void free_all(vector<Student*> *students, vector<Teacher*> *teachers, vector<Employee*> *employees)
{
    for(int i = 0; i < students[0].size(); ++i)
    {
        for(int j = 0; j < students[0][i]->get_courses().size(); ++j)
            free(students[0][i]->get_courses()[j]->grades);
        students[0][i]->get_courses().clear();
    }
    students[0].clear();

    for(int i = 0; i < teachers[0].size(); ++i)
            teachers[0][i]->get_subjects().clear();
    teachers[0].clear();

    employees[0].clear();

    delete [] students;
    delete [] teachers;
    delete [] employees;
}
