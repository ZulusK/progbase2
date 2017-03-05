#include <dlList.h>
#include <university.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define throw(MSG) assert(0&&MSG)


// int Lecturer_containsStudent(Lecturer * lec,Student * stud);

    // Формування списку студентів із CSV строки.
DLList * university_getStudentFromCSV(char * str);

char * university_studentToCSV(Student * stud){
	if(stud==NULL) throw("NullPointerException");
	int len=strlen(Student_getName(stud))/*name*/+2/*"x2*/+(3+2)/*score*/+3/*year*/ + 2/*comma x2*/+1; /*'/0'*/
	char * str=malloc(sizeof(char)*len);
	sprintf(str,"\"%s\",%3.2lf,%i",Student_getName(stud),Student_getScore(stud),Student_getYear(stud));
	return str;
}
// Формування CSV строки із списку студентів.
char * university_studentListToCSV(DLList * list){
	if(list==NULL) throw("NullPointerException");
	int count=DLList_getLength(list);
	int csvLen=0;
	char * studentsStr[count];
	for(int i=0; i<count;i++){
		Student * st=DLList_get(list,i);
		// printf("in sttocvs %s\n\n",Student_getName(st));
		studentsStr[i]=university_studentToCSV(st);
		csvLen+=strlen(studentsStr[i])+1;
	}
    csvLen++;
    char * outStr=malloc(sizeof(char)*csvLen);
    outStr[0]='\0';
    for(int i=0; i<count;i++){
		strcat(outStr,studentsStr[i]);
		strcat(outStr,"\n");
		free(studentsStr[i]);
	}
	return outStr;
}



/*Функція, що приймає викладача і список студентів і в результаті створює новий список,
у який заносяться студенти із вхідного списку, що не прив'язані до даного викладача.*/
DLList*  university_getNotExistingStudents(Lecturer * lec,DLList *list){
	if(lec==NULL ||list==NULL) throw("NullPointerException");
	DLList * outList=DLList_create(STUDENT);
	Student * currStud=NULL;
	int listLen=DLList_getLength(list);

	for(int i=0; i<listLen;i++){
		currStud=DLList_get(list,i);
		if(!Lecturer_containsStudent(lec,currStud)){
			DLList_addFirst(outList,STUDENT,currStud);
		}
	}
	return outList;
}