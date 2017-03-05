#include <dlList.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define throw(MSG) assert(0&& MSG)
struct DLList {
	DLNode * item;
	int dataType;
};

/**
 * returns last node of list
 * @param  list pointer to list
 * @return      to last node of list
 */
DLNode * DLList_getTail(DLList * list) {
	if (list == NULL) throw("NullPointerException");
	if (list->item == NULL) return NULL;
	DLNode *node = list->item;
	while (DLNode_getNext(node) != NULL) {
		node = DLNode_getNext(node);
	}
	return node;
}

/**
 *  returns count of nodes in list
 * @param  list list pointer to list
 * @return      count of nodes in list
 */
int DLList_getLength(DLList * list) {
	if (list == NULL) throw("NullPointerException");
	return DLNode_getLength(list->item);
}

/**
 * returns data from node at some position in list
 * @param  list pointer to list
 * @param  index position of nodes in list(start from 0)
 * @return       data of node[index]
 */
void * DLList_get(DLList * list, int index) {
	return DLNode_getData(DLNode_getNodeAt(list->item, index));
}
/**
 * alloc memory for a new list
 * @param  dataType type of data, that is stored in list
 * @return          pointer to a new list
 */
DLList * DLList_create(int dataType) {
	DLList * list = malloc(sizeof(DLList));
	if (list == NULL) return NULL;
	list->dataType = dataType;
	list->item = NULL;
	return list;
}
/**
 * free memory, that contains list
 * @param list pointer to list
 * @param data_free pointer to function, that free stored data
 */
void  DLList_free(DLList ** list, void (*data_free)(void *)) {
	if (list == NULL) throw("NullPointerException");
	if ((*list)->item != NULL) {
		DLList_clear(*list, data_free);
	}
	free(*list);
	*list = NULL;
}
/**
 * add new node at tail of list
 * @param  list     pointer to list
 * @param  data     data, for a new node
 * @param  dataType type of data for a new Node
 * @return          pointer to list
 */
DLList * DLList_addLast(DLList * list, int dataType, void * data) {
	if (list == NULL) throw("NullPointerException");
	if (list->dataType != dataType) {
		throw ("DataTypeException");
	}
	if (list->item == NULL) {
		list->item = DLNode_create(dataType, data);
	} else {
		DLNode * tail = DLList_getTail(list);
		DLNode_addAfter(tail, DLNode_create(dataType, data), dataType);
	}
	return list;
}
/**
 * add new node at head of list
 * @param  list     pointer to list
 * @param  dataType type of data for a new Node
 * @param  data     data, for a new node
 * @return          pointer to list
 */
DLList * DLList_addFirst(DLList *list, int dataType, void * data  ) {
	if (list == NULL) throw("NullPointerException");
	if (list->dataType != dataType) {
		throw ("DataTypeException");
	}
	list->item = DLNode_addBefore(list->item, DLNode_create(dataType, data), dataType);
	return list;
}

/**
 * add new node at position of list
 * @param  list    pointer to list
 * @param  data     data, for a new node
 * @param  dataType type of data for a new Node
 * @param  index    position of node at list
 * @return          pointer to list
 */
DLList * DLList_insert(DLList * list, int dataType, void * data, int index) {
	if (list == NULL) throw("NullPointerException");
	if (index < 0 || index > DLList_getLength(list)) {
		throw ("IndexOutOfBoundException");
	}
	if (dataType != list->dataType) throw("DataTypeException");
	if (index == 0)
	{
		DLList_addFirst(list, dataType, data);
	} else {
		DLNode * node = list->item;
		index--;
		while (DLNode_getNext(node) != NULL && index > 0) {
			node = DLNode_getNext(node);
			index--;
		}
		DLNode_addAfter(node, DLNode_create(dataType, data), dataType);
	}
	return list;
}

/**
 * remove head of list
 * @param  list pointer to list
 * @return      data from removed node
 */
void *DLList_removeFirst(DLList * list) {
	return DLList_removeAt(list, 0);
}
/**
 * remove tail of list
 * @param  list pointer to list
 * @return      data from removed node
 */
void * DLList_removeLast(DLList * list) {
	return DLList_removeAt(list, DLList_getLength(list) - 1);
}
void *  DLList_remove(DLList * list, DLNode * node) {
	if (list == NULL || node == NULL) throw("NullPointerException");
	if (list->dataType != DLNode_dataType(node)) throw("DataTypeException");
	void * data = DLNode_getData(node);
	list->item = DLNode_remove(list->item, node);
	DLNode_free(&node, NULL);
	return data;
}
/**
 * remove element, that contains data, that is quals key
 * @param list 		pointer to list
 * @param key 		key for search
 * @param compare 	pointer to function ot compare data
 * @return 			data from removed node;
 */
void * 	 DLList_removeData(DLList * list, void * key, int (*compare)(void *, void*)) {
	if (list->item == NULL) return NULL;
	int index = DLList_find(list, key, compare);
	if (index == -1) {
		return NULL;
	}
	DLNode * rmnode = DLNode_getNodeAt(list->item, index);
	return DLList_remove(list, rmnode);
}
/**
 * remove node from list at some position
 * @param  list  pointer to list
 * @param  index position of node in list
 * @return       data from removed node
 */
void *  DLList_removeAt(DLList * list, int index) {
	if (list->item == NULL) return NULL;
	DLNode * node = DLNode_getNodeAt(list->item, index);
	return DLList_remove(list, node);
}
/**
 * search data in list
 * @param  list   		pointer to list
 * @param  dataType  	type of data in list
 * @param  data 		data for search
 * @param  compar    	pointer to fucntion to compare data
 * @return       		index of node with datain list, or -1
 */
int DLList_indexOf(DLList * list, int dataType, void * data, int (*compare)(void *, void*) ) {
	if (list != NULL || data != NULL || compare != NULL) {
		int index = 0;
		DLNode * node = list->item;
		while (node != NULL && compare(DLNode_getData(node), data) != 0) {
			node = DLNode_getNext(node);
			index++;
		}
		if (node != NULL) {
			return index;
		}
	}
	return -1;
}

/**
 * look,is list contains data
 * @param list 		pointer to list
 * @param data 		data for search
 * @param compare   pointer to function, which compare to data
 * @return 			1 if list contains data, else 0
 */
int DLList_contains(DLList * list, int dataType, void * data, int (*compare)(void *, void*)) {
	if (dataType != list->dataType) throw("DataTypeException");
	if (compare == NULL || list == NULL || data == NULL) {
		throw ("NullPointerException");
	}
	DLNode * node = list->item;
	while (node != NULL) {
		if (compare(DLNode_getData(node), data) == 0) {
			return 1;
		}
		node = DLNode_getNext(node);
	}
	return 0;
}
/**
 * look, is list contains any element
 * @param  list pointer to list
 * @return      1, if list is empty,elese - 0
 */
int  DLList_isEmpty(DLList * list) {
	if (list == NULL) {
		throw ("NullPointerException");
	}
	if (list->item == NULL) return 1;
	else return 0;
}
/**
 * free all node of list
 * @param list 		pointer to list
 * @param data_free pointer to functin for free node's data
 * return list ,whith cleared data
 */
DLList * DLList_clear(DLList * list, void (*data_free)(void *)) {
	if (list == NULL) throw("NullPointerException");
	if (list->item != NULL) {
		DLNode  * node = list->item;
		while (node != NULL) {
			list->item = DLNode_getNext(node);
			DLNode_free(&node, data_free);
			node = list->item;
		}
	}
	list->item = NULL;
	return list;
}
/**
 * insert node to sorted list
 * @param list 		pointer to list
 * @param dataType  type of data in list
 * @param data 		data to insert in list
 * @param compare	pointer to function, for compare data in list
 * return sorted list
 */
DLList * DLList_insertToSortedList(DLList * list,  int dataType, void * data, int (*compare)(void *, void*)) {
	list->item = DLNode_insertToSorted(list->item, DLNode_create(dataType, data), compare);

	return list;
}
/**
 * sort DLList
 * @param 	list 	pointer to list
 * @param	compare pointer to function, which compare elements
 * return 	sorted list
 */
DLList * DLList_sort(DLList * list, int (*compare)(void *, void*)) {
	if (list == NULL) {
		throw ("NullPointerException");
	}

	list->item = DLNode_sortList(list->item, compare);
	return list;
}
/**
 * search
 * @param  list 	pointer to list
 * @param  compare  pointer to functio, that compared data
 * @param  key 		ky for search
 * @return 			index of node, that is equal key
 */
int DLList_find(DLList * list, void * key, int (*compare)(void *, void*)) {
	if (list == NULL || key == NULL || compare == NULL) throw ("NullPointerException");
	DLNode * node = list->item;
	int index = 0;
	while (node != NULL && compare(DLNode_getData(node), key) != 0) {
		node = DLNode_getNext(node);
		index++;
	}
	if (node != NULL) {
		return index;
	}
	else return -1;
}