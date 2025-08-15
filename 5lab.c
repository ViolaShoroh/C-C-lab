#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 25

typedef struct 
{
    int day;
    int month;
    int year;
} Data;

typedef struct 
{
    char full_name[N];
    Data date;
    char group[N];
} Student;

void print_student(Student stud) 
{
    printf("Студент: %s; Дата рождения: %d.%d.%d; группа: %s;\n", stud.full_name, stud.date.day, stud.date.month,
         stud.date.year, stud.group);
}

Student input_student() 
{
    Student res;
    int tmp[3];
    printf("Введите имя студента\n");
    scanf("%s", res.full_name);
    printf("Введите дату рождения(ч/з пробел)\n");
    scanf("%d %d %d", &res.date.day, &res.date.month, &res.date.year);
    printf("Введите группу студента\n");
    scanf("%s", res.group);
    return res;
}

void sort_students(Student *students, int len)
{
    Student tmp;
    for (int i = 0; i < len - 1; i++) 
    {
        for (int j = len - 1; j > i; j--) 
        {
            int res = strcmp(students[j - 1].full_name, students[j].full_name);
            if (res > 0) 
            {
                tmp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = tmp;
            }
        }
    }
}

int main() 
{
    system("chcp 1251");
    system("cls");
    int len = 5;
    Student spisok[len];
    for (int i = 0; i < len; i++) 
    {
        spisok[i] = input_student();
    }
    sort_students(spisok, len);
    for (int i = 0; i < len; i++) 
    {
        print_student(spisok[i]);
    }
    return 0;
}