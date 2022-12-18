#ifndef UNTITLED1_FUNCTIONS_H
#define UNTITLED1_FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Human{
public:
    Human(){};
    virtual ~Human(){};

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

protected:
    string title;
    string faculty;
    string *subjects;
    uint32_t salary;
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
    Courses(){};
    ~Courses(){};

protected:
    string course;
    int *grades;
};

class Student : public Human, public Courses{
public:
    Student(){};
    ~Student(){};

protected:
    string father_name;
    string mother_name;
    string faculty;
    string major;
    vector<Courses*> courses;
};

#endif //UNTITLED1_FUNCTIONS_H
