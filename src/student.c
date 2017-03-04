#include <university.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define throw(MSG) assert(0&&MSG)
struct Student {
	char * name;
	Lecturer * lecturer;
	double score;
	int year;
};

Student * Student_create(char * name, double score, int year, Lecturer * lec) {
	Student * s = malloc(sizeof(Student));
	s->name = NULL;
	s->score = 0;
	s->year = 0;
	s->lecturer = NULL;
	if (name != NULL) {
		Student_setName(s, name);
	}
	else {
		Student_setName(s, STUDENT_NAME);
	}
	if (s == NULL) {
		Student_setYear(s, year);
	}
	if (lec != NULL) {
		Student_addLecturer(s, lec);
	}
	Student_setScore(s, score);
	return s;
}
void Student_setScore(Student * s, double score) {
	if(score>=0 && score<=100) s->score=score;
}
double Student_getScore(Student * s) {
	if (s == NULL) throw("NullPointerException");
	return s->score;
}
Lecturer * Student_getLecturer(Student * stud) {
	if (stud == NULL) throw("NullPointerException");
	return stud->lecturer;
}

int Student_compare(void * v1, void *v2) {
	Student * s1 = v1;
	Student * s2 = v2;
	if (strcmp(s1->name, s2->name) == 0 && s1->year == s2->year && fabs((s1->score - s2->score)) < 0.001) {
		return 0;
	} else {
		return 1;
	}
}
void Student_setYear(Student * s, int year){
	if (s== NULL) throw("NullPointerException");
	if(year<=100 || year>=0) s->year=year; 
}
const char  * Student_getName(Student * stud) {
	if (stud == NULL) throw("NullPointerException");
	return stud->name;
}
void Student_setName(Student * stud, const  char * name) {
	if (name != NULL && name[0] != '\0') {
		if (stud->name != NULL) {
			free(stud->name);
		}
		stud->name = malloc(sizeof(char) * (strlen(name) + 1));
		if (stud->name != NULL)
			strcpy(stud->name, name);
	}
}
void Student_addLecturer(Student *stud, Lecturer * lec) {
	if (stud == NULL || lec == NULL)throw("NullPointerException");
	if (stud->lecturer != NULL) {
		Lecturer_removeStudent(lec, stud);
	}
	DLList * list = Lecturer_getStudentList(lec);
	DLList_addFirst(list, STUDENT, stud);
	stud->lecturer = lec;
}
void Student_removeLecturer(Student *stud) {
	if (stud == NULL) throw("NullPointerException");
	if (stud->lecturer != NULL) {
		DLList * list = Lecturer_getStudentList(stud->lecturer);
		DLList_removeData(list, stud, Student_compare);
	}
	stud->lecturer = NULL;
}
void Student_free(Student ** stud) {
	if (stud == NULL)throw("NullPointerException");
	Student_removeLecturer(*stud);
	if ((*stud)->name != NULL) {
		free((*stud)->name);
	}
	free(*stud);
	*stud = NULL;
}
