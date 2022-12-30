#ifndef UNIVERSITY_MANAGEMENT_MANAGE_MENU_H
#define UNIVERSITY_MANAGEMENT_MANAGE_MENU_H
#include "manage_classes.h"

void show_all_students(vector<Student*> &students);
void show_all_teachers(vector<Teacher*> &teachers);
void show_all_employees(vector<Employee*> &employees);

int log_in();
short menu_management();
void submenu();

void students_management(vector<Student*> &students);
void teachers_management(vector<Teacher*> &teachers);
void employees_management(vector<Employee*> &employees);

void students_file_management(vector<Student*> &students);
void teachers_file_management(vector<Teacher*> &teachers);
void employees_file_management(vector<Employee*> &employees);

void free_all(vector<Student*> &students, vector<Teacher*> &teachers, vector<Employee*> &employees);
#endif //UNIVERSITY_MANAGEMENT_MANAGE_MENU_H
