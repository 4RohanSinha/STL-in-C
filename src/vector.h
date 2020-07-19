#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

//private members in a struct: https://stackoverflow.com/questions/3824329/partitioning-struct-into-private-and-public-sections
struct vectorPrivateMembers;

typedef struct vector {
	struct vectorPrivateMembers* privateVM;
	int (*size)(struct vector* this);
	int (*get)(struct vector* this, int index);
	void (*set)(struct vector* this, int index, int newVal);
	void (*push_back)(struct vector* this, int newVal);
	void (*pop_back)(struct vector* this);
	int* (*begin)(struct vector* this);
	int* (*end)(struct vector* this);
	void (*clear)(struct vector* this);
	void (*insert)(struct vector* this, int index, int newVal);
	void (*erase)(struct vector* this, int index);
} Vector;

Vector* new_Vector();

void delete_Vector(Vector* vector);
#endif
