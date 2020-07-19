#include "vector.h"

//private members in a struct adapted from: https://stackoverflow.com/questions/3824329/partitioning-struct-into-private-and-public-sections
struct vectorPrivateMembers {
	int* elements;
	int size_;
};
//static keyword to prevent following functions from being directly visible to user

static int Vector__size(Vector* this) {
	return this->privateVM->size_;
}

static int Vector__get(Vector* this, int index) {
	if (index < this->size(this))
		return this->privateVM->elements[index];
	else {
		printf("Error: index %i is out of bounds in vector of length %i. Returning -1.\n", index, this->size(this));
		return -1;
	}	
}

static void Vector__set(Vector* this, int index, int newVal) {
	if (index < this->size(this))
		this->privateVM->elements[index] = newVal;
	else {
		printf("Error: index %i is out of bounds in vector of length %i. Not setting element.\n", index, this->size(this));
		return;
	}	
}

static void Vector__push_back(Vector* this, int newVal) {
	this->privateVM->size_++;
	this->privateVM->elements = (int*) realloc(this->privateVM->elements, this->privateVM->size_*sizeof(int));	
	this->privateVM->elements[this->privateVM->size_ - 1] = newVal;
}

static void Vector__pop_back(Vector* this) {
	this->privateVM->size_--;
	this->privateVM->elements = (int*) realloc(this->privateVM->elements, this->privateVM->size_*sizeof(int));
}

static int* Vector__begin(Vector* this) {

}

static int* Vector__end(Vector* this) {

}

static void Vector__clear(Vector* this) {
	free(this->privateVM->elements);
	this->privateVM->elements = NULL;
	this->privateVM->size_ = 0;
}

static void Vector__insert(Vector* this, int index, int newVal) {
	this->privateVM->size_++;
	this->privateVM->elements = (int*) realloc(this->privateVM->elements, this->privateVM->size_*sizeof(int));
	int i;
	for (i = this->privateVM->size_ - 1; i >= index; i--) {
		this->privateVM->elements[i] = this->privateVM->elements[i-1];
	}

	this->privateVM->elements[index] = newVal;
}

static void Vector__erase(Vector* this, int index) {
	this->privateVM->size_--;
	
	int i;
	for (i = index; i < this->privateVM->size_; i++) {
		this->privateVM->elements[i] = this->privateVM->elements[i+1];
	}

	this->privateVM->elements = (int*) realloc(this->privateVM->elements, this->privateVM->size_*sizeof(int));
}

Vector* new_Vector() {
	Vector* vector = (Vector*) malloc(sizeof(Vector));
	vector->privateVM = (struct vectorPrivateMembers*) malloc(sizeof(struct vectorPrivateMembers));
	vector->privateVM->elements = (int*) malloc(sizeof(int) * 0);
	vector->privateVM->size_ = 0;
	vector->size = Vector__size;
	vector->get = Vector__get;
	vector->set = Vector__set;
	vector->push_back = Vector__push_back;
	vector->pop_back = Vector__pop_back;
	vector->begin = Vector__begin;
	vector->end = Vector__end;
	vector->clear = Vector__clear;
	vector->insert = Vector__insert;
	vector->erase = Vector__erase;
}

void delete_Vector(Vector* vector) {
	if (vector->privateVM->elements != NULL)
		free(vector->privateVM->elements);
	
	if (vector->privateVM != NULL)
		free(vector->privateVM);

	if (vector != NULL)
		free(vector);
}
