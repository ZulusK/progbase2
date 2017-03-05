#include <university.h>
#include <dlList.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define throw(MSG) assert(0&&MSG)

struct Lecturer {
	char * name;
	DLList * list;
};
Lecturer * Lecturer_create(char * name, DLList  * list) {
	Lecturer * lec = malloc(sizeof(Lecturer));
	if (lec == NULL) return NULL;
	lec->name = NULL;
	lec->list = DLList_create(STUDENT);

	if (name != NULL && name[0] != '\0')
		Lecturer_setName(lec, name);
	else Lecturer_setName(lec, LECTURER_NAME);

	if (list != NULL)
		Lecturer_addStudentList(lec,list);

	if (lec->list == NULL) {
		free(lec);
		return NULL;
	}
	return lec;
}
const char * Lecturer_getName(Lecturer * lec){
	if(lec==NULL) throw("NullPointerException");
	return lec->name;
}
void Lecturer_setName(Lecturer * lec,const char * name){
	if (name != NULL && name[0] != '\0') {
		if (lec->name != NULL) {
			free(lec->name);
		}
		lec->name = malloc(sizeof(char) * (strlen(name) + 1));
		if (lec->name != NULL)
			strcpy(lec->name, name);
	}
}

DLList * Lecturer_getStudentList(Lecturer * lec) {
	if (lec == NULL) throw("NullPointerException");
	return lec->list;
}

void Lecturer_addStudent(Lecturer *lec, Student  * s) {
	if (lec == NULL || s == NULL) throw("NullPointerException");
	DLList_addFirst(lec->list, STUDENT, s);
}

void Lecturer_addStudentList(Lecturer * lec, DLList * list) {
	if (lec == NULL || list == NULL) throw("NullPointerException");
	int len = DLList_getLength(list);
	for (int i = 0; i < len; i++) {
		Student * s = DLList_get(list, i);
		if (!Lecturer_containsStudent(lec, s))
			Lecturer_addStudent(lec, s);
	}
}

void Lecturer_removeStudent(Lecturer *lec, Student * stud) {
	if (lec == NULL || stud == NULL) throw("NullPointerException");
	DLList_removeData(lec->list,stud,Student_compare);
}

int Lecturer_containsStudent(Lecturer * lec,Student * stud){
	return DLList_contains(lec->list,STUDENT,stud,Student_compare);
}

void Lecturer_free(Lecturer ** lec) {
	if (lec == NULL)throw("NullPointerException");
	if ((*lec)->list != NULL)
		DLList_free(&(*lec)->list, NULL);
	if ((*lec)->name != NULL) free((*lec)->name);
	free(*lec);
	*lec = NULL;
}