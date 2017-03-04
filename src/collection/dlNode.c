#include <dlList.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#define throw(MSG) assert(0 && MSG)

struct DLNode {
	int dataType;
	DLNode * next;
	DLNode *prev;
	void * data;
};
void DLNode_clearLinks(DLNode * node);
int DLNode_dataType(DLNode * node) {
	if (node == NULL) throw("NullPointerException");
	return node->dataType;
}
/**
	@brief alloc memory for a new DLNode
	@param dataType type of data, that will be containeds in node
	@param data pointer to data, that will be contained isn node
	@return poiter to created nodes
 */
DLNode * DLNode_create(int dataType, void * data) {
	DLNode * node = malloc(sizeof(DLNode));
	if (node == NULL) {
		return NULL;
	}
	node->dataType = dataType;
	node->data = data;
	DLNode_clearLinks(node);
	return node;
}
/**
	@brief clear pointer to next and prev node in list
	@param node pointer to node
 */
void DLNode_clearLinks(DLNode *node) {
	node->next = NULL;
	node->prev = NULL;
}
/**
	@brief free memory, that had alloced for a node
	@param node pointer to node
	@param data_free pointer to function, which free node->data
 */
void DLNode_free(DLNode** node, void (*data_free)(void *)) {
	if (node == NULL) {
		throw ("NullPointerException");
	}
	if ((*node)->data != NULL && data_free != NULL) {
		data_free((*node)->data);
	}
	free(*node);
	*node = NULL;
}
/**
	@brief return pointer to data, which are stored in node
	@param node pointer to node
	@return pointer to data in node (void *)
 */
void *   DLNode_getData(DLNode * node) {
	if (node == NULL) {
		throw ("NullPointerException");
	}
	else return node->data;
}
/**
	@brief return pointer next node
	@param node pointer to node
	@return pointer to next node
 */
DLNode * DLNode_getNext(DLNode * node) {
	if (node == NULL) {
		throw ("NullPointerException");
	}
	else return node->next;
}
/**
	@brief return pointer prev node
	@param node pointer to node
	@return pointer to prev node
 */
DLNode * DLNode_getPrev(DLNode * node) {
	if (node == NULL) {
		throw ("NullPointerException");
	}
	else return node->prev;
}
/**
	@brief return data type
	@param node pointer to node
	@return type of data in node
 */
int 	 DLNode_getDataType(DLNode * node) {
	if (node == NULL) {
		throw ("NullPointerException");
	} else {
		return node->dataType;
	}
}
/**
	@brief add new node after current
	@param node pointer to pointer to node
	@param newNode pointer to new node
	@param dataType type of data, which are contained in node
	@return pointer to node
 */
DLNode * DLNode_addAfter(DLNode * node, DLNode * newNode, int dataType) {
	if (newNode == NULL) {
		throw ("NullPointerException");
		return NULL;
	}
	if (newNode->dataType != dataType || (node != NULL && node->dataType != dataType)) {
		throw ("DataTypeException");
		return NULL;
	}
	if (node == NULL) {
		return newNode;
	} else {
		DLNode * next = node->next;
		if (next != NULL) {
			next->prev = newNode;
			newNode->next = next;
		}
		node->next = newNode;
		newNode->prev = node;
		return node;
	}
}
/**
	@brief add new node before current
	@param node pointer to pointer to node
	@param newNode pointer to new node
	@param dataType type of data, which are contained in node
	@return pointer to node, that will be have low index in list
 */
DLNode * DLNode_addBefore(DLNode * node, DLNode * newNode, int dataType) {
	if (newNode == NULL) {
		throw ("NullPointerException");
		return NULL;
	}
	if (newNode->dataType != dataType || (node != NULL && node->dataType != dataType)) {
		throw ("DataTypeException");
		return NULL;
	}
	if (node == NULL) {
		return  newNode;
	} else {
		DLNode * prev = node->prev;
		if (prev != NULL) {
			prev->next = newNode;
			newNode->prev = prev;
		}
		node->prev = newNode;
		newNode->next = node;
		return newNode;
	}
}
/**
 *  add new node before current
 *	@param node pointer to pointer to node
 *	@param newNode pointer to new node
 *	@param dataType type of data, which are contained in node
 *	@return pointer to node, that will be have low index in list
 */
DLNode * DLNode_insertToSorted(DLNode * head, DLNode * newNode, int (*compare)(void * , void *)) {
	if (newNode == NULL) {
		throw ("NullPointerException");
	}
		DLNode_clearLinks(newNode);
	if (head == NULL || compare(head->data, newNode->data) == -1) {
		head=DLNode_addBefore(head,newNode, newNode->dataType);
	} else {
		DLNode * node = head;
		while (node->next != NULL && compare(node->next->data, newNode->data) != -1) {
			node = node->next;
		}
		DLNode_addAfter(node, newNode, node->dataType);
	}
	return head;
}
/**
 * remove rmNode from DLNode-list
 * @param  head   head of DLNode-list
 * @param  rmNode node
 * @return        new head of DLNode-list
 */
DLNode *  DLNode_remove(DLNode * head, DLNode * rmNode) {
	if (rmNode == NULL || head == NULL) {
		throw ("NullPointerException");
	}
	if (rmNode->dataType != head->dataType) {
		throw ("DataTypeException");
	}
	if (head == rmNode) {
		head = head->next;;
		if (head != NULL) {
			head->prev = NULL;
		}
		DLNode_clearLinks(rmNode);
	} else {
		DLNode * tmp = head;
		while (tmp != NULL && tmp->data != rmNode->data) {
			tmp = tmp->next;
		}
		if (tmp != NULL) {
			DLNode * next = rmNode->next;
			DLNode * prev = rmNode->prev;
			if (next != NULL) {
				next->prev = prev;
			}
			if (prev != NULL) {
				prev->next = next;
			}
			DLNode_clearLinks(rmNode);
		}
	}
	return head;
}
/**
 * return countof nodes in list
 * @param  head head of DLNode-list
 * @return      count of node in list
 */
int DLNode_getLength(DLNode * head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}
/**
 * returns node  at some position in list
 * @param  head  pointer to head of list
 * @param  index position of nodes in list(start from 0)
 * @return       node[index]
 */
DLNode * DLNode_getNodeAt(DLNode * head, int index) {
	if (head == NULL) throw("NullPointerException");
	if (index < 0 || index >= DLNode_getLength(head)) {
		return NULL;
	}
	while (head != NULL && index > 0) {
		head = head->next;
		index--;
	}
	return head;
}
DLNode * DLNode_removeAt(DLNode * head, int index) {
	DLNode * rmNode = DLNode_getNodeAt(head, index);
	return DLNode_remove(head, rmNode);
}

DLNode * DLNode_sortList(DLNode * head, int (*compare)(void *, void *)) {
	DLNode * sortNode = NULL;
	while (head != NULL) {
		DLNode * tmp = head;
		head=DLNode_remove(head, head);
		sortNode = DLNode_insertToSorted(sortNode, tmp, compare);
	}
	return sortNode;
}