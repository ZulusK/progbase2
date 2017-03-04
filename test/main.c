#include <check.h>
#include <dlList.h>
#include <university.h>
#include <stdio.h>

int main(void){
	DLList * list=DLList_create(0);
	int p=99;
	DLList_addFirst(list,0,&p);
	printf("%i\n",*(int*)DLList_get(list,0));
}
