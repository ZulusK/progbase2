#include <university.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define throw(MSG) assert(0&&MSG)
struct Student {
	char * name;
	double score;
	int year;
};

Student * Student_create(char * name, double score, int year) {
	Student * s = malloc(sizeof(Student));
	if(s==NULL) return NULL;
	s->name = NULL;
	s->score = 0;
	s->year = 0;
	if (name != NULL) {
		Student_setName(s, name);
	}
	else {
		Student_setName(s, STUDENT_NAME);
	}
	Student_setYear(s, year);
	Student_setScore(s, score);
	return s;
}

void Student_setScore(Student * s, double score) {
	if (score >= 0 && score <= 100) s->score = score;
}

double Student_getScore(Student * s) {
	if (s == NULL) throw("NullPointerException");
	return s->score;
}

int Student_compare(void * v1, void *v2) {
	Student * s1 = v1;
	Student * s2 = v2;
	if (strcmp(s1->name, s2->name) == 0 && s1->year == s2->year && fabs(s1->score - s2->score) < 0.001) {
		return 0;
	} else {
		return 1;
	}
}

void Student_setYear(Student * s, int year) {
	if (s == NULL) throw("NullPointerException");
	if (year <= 100 || year >= 0) s->year = year;
}
int Student_getYear(Student * s) {
	if (s == NULL) throw("NullPointerException");
	return s->year;
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
		// printf("%s\n",stud->name );
	}
}

void Student_free(void  * p) {
	Student * stud = (Student *)p;
	if (stud == NULL)throw("NullPointerException");
	if (stud->name != NULL) {
		free(stud->name);
	}
	free(stud);
}