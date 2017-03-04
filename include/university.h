#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <dlList.h>
#define STUDENT_NAME "VASYA"
#define STUDENT 666
#define LECTURER 777
#define LECTURER_NAME "Ruslan The Proger"
typedef struct Student Student;
typedef struct Lecturer Lecturer;

Student * Student_create(char * name,double score, int year,Lecturer * lec);
const char  * Student_getName(Student * stud);
Lecturer * Student_getLecturer(Student * stud);
void Student_setName(Student * stud, const  char * name);
void Student_addLecturer(Student *stud, Lecturer * lec);
void Student_removeLecturer(Student *stud);
void Student_free(Student ** stud);
int Student_compare(void * v1, void *v2);
void Student_setScore(Student * s,double score);
double Student_getScore(Student * s);
void Student_setYear(Student * s, int year);

Lecturer * Lecturer_create(char * name, DLList * list);
const char  * Lecturer_getName(Lecturer * stud);
DLList * Lecturer_getStudentList(Lecturer * stud);
void Lecturer_setName(Lecturer * stud, const  char * name);
void Lecturer_addStudent(Lecturer *stud, Student  * s);
void Lecturer_removeStudent(Lecturer *lec,Student * stud);
void Lecturer_free(Lecturer ** stud);
void Lecturer_addStudentList(Lecturer * lec,DLList * list);
DLList * Lecturer_removeExistingStudentFromList(Lecturer *lec, DLList * list);
#endif