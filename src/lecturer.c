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
void Lecturer_clearList(void * p1) {
	Student_removeLecturer(p1);
}
Lecturer * Lecturer_create(char * name, DLList  * list) {
	Lecturer * lec = malloc(sizeof(Lecturer));
	if (lec == NULL) return NULL;
	lec->name = NULL;
	lec->list = NULL;

	if (name != NULL && name[0] != '\0')
		Lecturer_setName(lec, name);
	else Lecturer_setName(lec, LECTURER_NAME);

	if (list != NULL)
		lec->list = list;
	else lec->list = DLList_create(STUDENT);

	if (lec->list == NULL) {
		free(lec);
		return NULL;
	}
	return lec;
}
const char  * Lecturer_getName(Lecturer * lec) {
	if (lec == NULL) throw("NullPointerException");
	return lec->name;
}
void Lecturer_setName(Lecturer * lec, const  char * name) {
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
	Student_addLecturer(s, lec);
}
void Lecturer_addStudentList(Lecturer * lec, DLList * list) {
	if (lec == NULL || list == NULL) throw("NullPointerException");
	DLList_clear(lec->list, Lecturer_clearList);
	int len = DLList_getLength(list);
	for (int i = 0; i < len; i++) {
		// DLList_addLast(lec->list, STUDENT, DLList_get(list, i));
		Lecturer_addStudent(lec, DLList_get(list, i));
	}
}
void Lecturer_removeStudent(Lecturer *lec, Student * stud) {
	if (lec == NULL || stud == NULL) throw("NullPointerException");
	if (Student_getLecturer(stud) == lec)
		Student_removeLecturer(stud);
}

void Lecturer_free(Lecturer ** lec) {
	if (lec == NULL)throw("NullPointerException");
	if ((*lec)->list != NULL)
		DLList_free(&(*lec)->list, Lecturer_clearList);
	if ((*lec)->name != NULL) free((*lec)->name);
	free(*lec);
	*lec = NULL;
}

DLList * Lecturer_removeExistingStudentFromList(Lecturer *lec, DLList * list) {
	if (lec == NULL || list == NULL)throw("NullPointerException");
	int studListLen = DLList_getLength(list);
	DLList * outList = DLList_create(STUDENT);
	for (int i = 0; i < studListLen; i++) {
		if (lec != Student_getLecturer(DLList_get(list, i))) {
			DLList_addFirst(outList, STUDENT, DLList_get(list, i));
		}
	}
	return outList;
}