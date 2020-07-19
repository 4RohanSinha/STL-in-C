#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct listNodePrivateMembers;
struct listPrivateMembers;

typedef struct list_node {
	struct listNodePrivateMembers* privateLNM;
	struct list_node (*getNext)(struct list_node* this);
	struct list_node (*getPrev)(struct list_node* this);
	int (*getVal)(struct list_node* this);
}ListNode;

typedef struct list {
	struct listPrivateMembers* privateLM;
	int (*size)(struct list* this);
	int (*getCurrentElement)(struct list* this);

} List;


List* new_List();

void delete_List(List* list);

#endif
