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
void Human::add_sex(string Name)
{
    sex = Name;
}
void Human::add_age(uint16_t Age)
{
    age = Age;
}
void Human::add_ID(string Name)
{
    ID = Name;
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
    cout << "Imie i nazwisko: " << name << " " << surname << endl;
    cout << "Plec: " << sex << endl;
    cout << "Identyfikator: " << ID << endl;
    cout << "Numer telefonu: " << phone_number << endl;
    cout << "Tytul: " << degree << endl;
    cout << "Wydzial: " << faculty << endl;
    cout << "Przedmioty wykladane:" << endl;
    for(int i = 0; i < subjects_to_teach.size(); i++)
    {
        cout << "    " << subjects_to_teach[i] << endl;
    }
    cout << endl;
}

void Student::add_father_name(string to_add)
{
    if(father_name.empty() == 1)
        father_name = to_add;
};
void Student::add_mother_name(string to_add)
{
    if(mother_name.empty() == 1)
        mother_name = to_add;
}
uint32_t Student::pay_insurance()
{
    if(valid_insurance() == 1)
        return 1;
    is_insuacre_paid = 1;
    return 0;
}
uint32_t Student::valid_insurance()
{
    if(is_insuacre_paid == 1)
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

                for(int j = 0; j < courses[i]->number_of_grades; j++)
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
    cout << "Imie i nazwisko: " << name << " " << surname << endl;
    cout << "Plec: " << sex << endl;
    cout << "Imie matki: " << mother_name << endl << "Imie ojca: " << father_name << endl;
    cout << "Identyfikator: " << ID << endl;
    cout << "Numer telefonu: " << phone_number << endl;
    cout << "Wydzial: " << faculty << endl;
    cout << "Kierunek: " << major << endl;
    cout << "Status ubezpieczenia: ";
    if(is_insuacre_paid == 0)
        cout << "nieoplacone" << endl;
    else
        cout << "oplacone" << endl;
    cout << "Karta ocen:" << endl;
    for(int i = 0; i < courses.size(); i++)
    {
        cout << "\tPrzedmiot: " << courses[i]->course << endl << "\t    Oceny: ";
        for(int j = 0; j < courses[i]->number_of_grades; j++)
            cout << courses[i]->grades[j] << " ";
        if(courses[i]->number_of_grades == 0)
            cout << "Brak";
        cout << endl;
    }
    cout << endl;
}

void show_all_students(class Human **to_print)
{

    for(int i = 0; i < 2; i++)
        (*(to_print+i))->show_student();
}

void show_all_teachers(class Human **to_print)
{
    for(int i = 0; i < 1; i++)
        (*(to_print+i))->show_teacher();
}

