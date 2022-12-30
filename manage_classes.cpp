#include "manage_classes.h"

bool Human::logging(string log, string pass)
{
    if(login.compare(log) == 0)
        if(password.compare(pass) == 0)
            return 1;
    return 0;
}
void Human::add_name(string to_add)
{
    name = to_add;
}
void Human::add_surname(string to_add)
{
    surname = to_add;
}
void Human::add_age(uint16_t number)
{
    age = number;
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


