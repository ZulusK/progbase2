#ifndef DLLIST_H
#define DLLIST_H

typedef struct DLList DLList;
DLList * DLList_create(int dataType);//
void  	 DLList_free(DLList ** node, void (*data_free)(void *));
DLList * DLList_addLast(DLList * list, int dataType, void * data  );//
DLList * DLList_addFirst(DLList * list, int dataType, void * data  );//
DLList * DLList_clear(DLList * list, void (*data_free)(void *));
DLList * DLList_insert(DLList * list,int dataType, void * data,  int index);//
DLList * DLList_insertToSortedList(DLList * list,  int dataType, void * data, int (*compare)(void *, void*));
DLList * DLList_sort(DLList * list,  int (*compare)(void *, void*));
void *   DLList_get(DLList * list, int index);//
void *   DLList_removeFirst(DLList * list);//
void *   DLList_removeLast(DLList * list);//
void * 	 DLList_removeData(DLList * list, void * key, int (*compare)(void *, void*));
void *   DLList_removeAt(DLList * list, int index);
int  	 DLList_find(DLList * list, void * key, int (*compare)(void *, void*));
int 	 DLList_getLength(DLList * list );
int      DLList_indexOf(DLList * list, int dataType, void * data, int (*compare)(void *, void*) );
int  	 DLList_isEmpty(DLList * list);
int 	 DLList_contains(DLList * list, int dataType, void * data, int (*compare)(void *, void*)) ;

typedef struct DLNode DLNode;

DLNode * DLNode_create(int dataType, void * data);
void 	 DLNode_free(DLNode** node, void (*data_free)(void *));
void * 	 DLNode_getData(DLNode * node);
DLNode * DLNode_getNext(DLNode * node);
DLNode * DLNode_getPrev(DLNode * node);
int 	 DLNode_dataType(DLNode * node);
DLNode * DLNode_addAfter(DLNode * node,DLNode * newNode, int dataType);
DLNode * DLNode_addBefore(DLNode * node,DLNode * newNode, int dataType);
DLNode * DLNode_remove(DLNode * head,DLNode * rmNode);
DLNode * DLNode_removeAt(DLNode * head, int index);
DLNode * DLNode_insertToSorted(DLNode * head,DLNode * newNode,int(*compare)(void *,void*));
DLNode * DLNode_getNodeAt(DLNode * head, int index);
DLNode * DLNode_sortList(DLNode * head,int (*compare)(void *, void*));
int 	 DLNode_getLength(DLNode * list );

int DLNode_getLength(DLNode * list );
#endif