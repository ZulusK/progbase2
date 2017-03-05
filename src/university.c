#include <dlList.h>
#include <university.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#define throw(MSG) assert(0&&MSG)

char * findNext(char * str, const char * x, int findChar, int * isQuote) {
	while (*str != '\0') {
		if ((*str == '-' || isalnum(*str) || *str == '+' || isdigit(*str)) && findChar) {
			// printf("alert! %c\n", *str );
			return str;
		}
		for (int i = 0; i < strlen(x); i++) {
			// printf("scan %c and %c\n", *str, x[i] );
			if (*str == x[i]) {
				if (x[i] == '\"') *isQuote = 1;
				return str + 1;
			}
		}
		str++;
	}
	return str;
}
char * getNextLexem(char * str, char ** p ) {
	char * next = NULL;
	int len = 0;
	int isQuote = 0;
	str = findNext(str, "\",", 1, &isQuote);
	if (isQuote)*p = findNext(str, "\"", 0, &isQuote);
	else *p = findNext(str, "\",", 0, &isQuote);

	len =  *p - str;
	if (*p[0] == '\"' || *p[0] == ',') len--;
	next = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++) {
		next[i] = str[i];
	}
	next[len] = '\0';
	return  next;
}

char * getNextLine(char * str, char ** outStr) {
	int length = 1;
	for (; str[length - 1] != '\0' && str[length - 1] != '\n'; length++);
	char *lineCSV = malloc(sizeof(char) * length);
	for (int i = 0; i < length; i++) {
		lineCSV[i] = str[i];
	}
	lineCSV[length - 1] = '\0';
	*outStr = str + length;
	return lineCSV;
}
// Формування списку студентів із CSV строки.
DLList * university_getStudentFromCSV(char * str) {

	DLList * list = DLList_create(STUDENT);
	while (*str != '\0') {
		char * lineCSV = getNextLine(str, &str);
		char * tmp = lineCSV;
		if (strlen(lineCSV) == 0) {
			free(lineCSV);
			break;
		}

		char * name = getNextLexem(lineCSV, &lineCSV);
		char * scoreStr = getNextLexem(lineCSV, &lineCSV);
		char * yearStr = getNextLexem(lineCSV, &lineCSV);
		// printf("%s\n", lineCSV );
		// printf("name:[%s], score[%s], year[%s]\n\n", name, scoreStr, yearStr );
		DLList_addLast(list, STUDENT, Student_create(name, atof(scoreStr), atoi(yearStr)));
		free(tmp);
		free(name);
		free(yearStr);
		free(scoreStr);
	}

	return list;
}

char * university_studentToCSV(Student * stud) {
	if (stud == NULL) throw("NullPointerException");
	int len = strlen(Student_getName(stud))/*name*/ + 2/*"x2*/ + (3 + 2)/*score*/ + 3/*year*/ + 2/*comma x2*/ + 1; /*'/0'*/
	char * str = malloc(sizeof(char) * len);
	sprintf(str, "\"%s\",%3.2lf,%i", Student_getName(stud), Student_getScore(stud), Student_getYear(stud));
	return str;
}
// Формування CSV строки із списку студентів.
char * university_studentListToCSV(DLList * list) {
	if (list == NULL) throw("NullPointerException");
	int count = DLList_getLength(list);
	int csvLen = 0;
	char * studentsStr[count];
	for (int i = 0; i < count; i++) {
		Student * st = DLList_get(list, i);
		// printf("in sttocvs %s\n\n",Student_getName(st));
		studentsStr[i] = university_studentToCSV(st);
		csvLen += strlen(studentsStr[i]) + 1;
	}
	csvLen++;
	char * outStr = malloc(sizeof(char) * csvLen);
	outStr[0] = '\0';
	for (int i = 0; i < count; i++) {
		strcat(outStr, studentsStr[i]);
		strcat(outStr, "\n");
		free(studentsStr[i]);
	}
	return outStr;
}



/*Функція, що приймає викладача і список студентів і в результаті створює новий список,
у який заносяться студенти із вхідного списку, що не прив'язані до даного викладача.*/
DLList*  university_getNotExistingStudents(Lecturer * lec, DLList *list) {
	if (lec == NULL || list == NULL) throw("NullPointerException");
	DLList * outList = DLList_create(STUDENT);
	Student * currStud = NULL;
	int listLen = DLList_getLength(list);

	for (int i = 0; i < listLen; i++) {
		currStud = DLList_get(list, i);
		if (!Lecturer_containsStudent(lec, currStud)) {
			DLList_addFirst(outList, STUDENT, currStud);
		}
	}
	return outList;
}