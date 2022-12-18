#ifndef UNTITLED1_FUNCTIONS_H
#define UNTITLED1_FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;


class Human{
public:
    string login = "qwerty";
    string password = "1234";
    Human(){};
    virtual ~Human(){};

    bool logging(string log, string pass);
    void add_name(string Name);
    void add_surname(string Name);
    void add_sex(string Name);
    void add_age(uint16_t Age);
    void add_ID(string Name);
    void add_phone_number(uint64_t number);
    virtual void show_student(){};
    virtual void show_teacher(){};

protected:
    string name;
    string surname;
    string sex;
    uint16_t age;
    string ID;
    uint64_t phone_number;
};

class Teacher : public Human{
public:
    Teacher(){};
    ~Teacher(){};
    void add_degree(string to_add);
    void add_faculty(string to_add);
    void add_subjects(string to_add);
    uint32_t add_salary(double money);
    void show_teacher() override;

protected:
    string degree;
    string faculty;
    vector<string> subjects_to_teach;
    double salary;
};

class Employee : public Human{
public:
    Employee(){};
    ~Employee(){};

protected:
    string position;
    string salary;
};

class Courses{
public:
    Courses(){grades = NULL; number_of_grades = 0;};
    ~Courses(){};
    string course;
    int *grades;
    int number_of_grades;
};

class Student : public Human, public Courses{
public:
    Student(){is_insuacre_paid = 0;};
    ~Student(){};

    void add_father_name(string to_add);
    void add_mother_name(string to_add);
    uint32_t pay_insurance();
    uint32_t valid_insurance();
    void add_faculty(string to_add);
    void add_major(string to_add);
    uint32_t add_course(string to_add);
    uint32_t add_grade_to_course(string to_add, int grade);
    void show_student() override;

protected:
    string father_name;
    string mother_name;
    bool is_insuacre_paid;
    string faculty;
    string major;
    vector<Courses*> courses;
};

void show_all_students(class Human **to_print);
void show_all_teachers(class Human **to_print);

#endif //UNTITLED1_FUNCTIONS_H
