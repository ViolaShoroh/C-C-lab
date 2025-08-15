#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 25

typedef struct {
  int day;
  int month;
  int year;
} Data;

typedef struct {
  char full_name[N];
  Data date;
  char group[N];
} Student;

void print_student(Student stud) {
  printf("Студент: %s; Дата рождения: %d.%d.%d; группа: %s;\n", stud.full_name, stud.date.day, stud.date.month,
         stud.date.year, stud.group);
}

Student input_student() {
  Student res;
  char tmp[N][3];
  printf("Введите имя студента\n");
  scanf("%s", res.full_name);
  printf("Введите дату рождения(ч/з пробел)\n");
  scanf("%s.%s.%s", tmp[0], tmp[1], tmp[2]);
  res.date.day = atoi(tmp[0]);
  res.date.month = atoi(tmp[1]);
  res.date.year = atoi(tmp[2]);
  printf("Введите группу студента\n");
  scanf("%s", res.group);
  return res;
}

void sort_students(Student *students, int len) {
  Student tmp;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      int res = strcmp(students[j - 1].full_name, students[j].full_name);
      if (res > 0) {
        tmp = students[j - 1];
        students[j - 1] = students[j];
        students[j] = tmp;
      }
    }
  }
}

void stud_to_file(FILE *f, Student stud) {
  fwrite(&stud, sizeof(Student), 1, f);
}

void stud_from_file(FILE *f, Student stud) {
  fread(&stud, sizeof(Student), 1, f);
}

int main() 
{
    system("chcp 1251");
    system("cls");
    int len = 5;
    Student studList[len];
  FILE *fw;
  fw = fopen("lab3.txt", "wt");
  for (int i = 0; i < len; i++) {
    studList[i] = input_student();
  }
  sort_students(studList, len);
  for (int i = 0; i < len; i++) {
    stud_to_file(fw, studList[i]);
  }
  fclose(fw);
  FILE *fr;
  fr = fopen("lab3.txt", "rt");
  for (int i = 0; i < len; i++) {
    stud_from_file(fr, studList[i]);
  }
  fclose(fr);
  for (int i = 0; i < len; i++) {
    print_student(studList[i]);
  }
  return 0;
}