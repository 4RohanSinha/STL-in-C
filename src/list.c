#include "list.h"

struct listNodePrivateMembers {
	struct list_node* next;
	struct list_node* prev;
	int val;
};

struct listPrivateMembers {
	ListNode* head_;
	ListNode* tail_;
	ListNode* currentNode_;
	int size_;
};
List* new_List() {
	return NULL;
}

void delete_List(List* list) {

}
