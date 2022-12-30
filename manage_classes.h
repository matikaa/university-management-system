#ifndef UNIVERSITY_MANAGEMENT_MANAGE_CLASSES_H
#define UNIVERSITY_MANAGEMENT_MANAGE_CLASSES_H
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

enum type_t
{
    STUDENTS,
    TEACHERS,
    EMPLOYEES
};

class Human{
protected:
    string name;
    string surname;
    uint16_t age;
    uint64_t ID;
    uint64_t phone_number;
public:
    string login = "qwerty";
    string password = "1234";
    Human(){};
    virtual ~Human(){};

    bool logging(string log, string pass);
    void add_name(string to_add);
    void add_surname(string to_add);
    void add_age(uint16_t number);
    void add_ID(uint64_t number);
    void add_phone_number(uint64_t number);

    string get_name(){return name;};
    string get_surname(){return surname;};
    uint16_t get_age(){return age;};
    uint64_t get_ID(){return ID;};
    uint64_t get_phone(){return phone_number;};

    virtual void show_student(){};
    virtual void show_teacher(){};
    virtual void show_employee(){};
};

class Teacher : public Human{
private:
    string degree;
    string faculty;
    vector<string> subjects_to_teach;
    double salary;
public:
    Teacher(){};
    ~Teacher(){};
    void add_degree(string to_add);
    void add_faculty(string to_add);
    void add_subjects(string to_add);
    uint32_t add_salary(double money);

    string get_degree(){return degree;};
    string get_faculty(){return faculty;};
    vector<string> get_subjects(){return subjects_to_teach;};
    double get_salary(){return salary;};

    void show_teacher() override;
};

class Employee : public Human{
private:
    string position;
    double salary;
public:
    Employee(){};
    ~Employee(){};
    void add_position(string to_add);
    uint32_t add_salary(double money);

    string get_position(){return position;};
    double get_salary(){return salary;};

    void show_employee() override;
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
private:
    bool is_insurance_paid;
    string faculty;
    string major;
    vector<Courses*> courses;
public:
    Student(){is_insurance_paid = 0;};
    ~Student(){};

    uint32_t pay_insurance();
    uint32_t valid_insurance();
    void add_faculty(string to_add);
    void add_major(string to_add);
    uint32_t add_course(string to_add);
    uint32_t add_grade_to_course(string to_add, int grade);

    bool get_insurance(){return is_insurance_paid;};
    string get_faculty(){return faculty;};
    string get_major(){return major;};
    vector<Courses*> get_courses(){return courses;};

    void show_student() override;
};


#endif //UNIVERSITY_MANAGEMENT_MANAGE_CLASSES_H
