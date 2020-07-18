#include "vector.h"

//static keyword to prevent following functions from being directly visible to user

static int Vector__size(Vector* this) {
	return this->size_;
}

static int Vector__get(Vector* this, int index) {
	if (index < this->size(this))
		return this->elements[index];
	else {
		printf("Error: index %i is out of bounds in vector of length %i. Returning -1.\n", index, this->size(this));
		return -1;
	}	
}

static void Vector__set(Vector* this, int index, int newVal) {
	if (index < this->size(this))
		this->elements[index] = newVal;
	else {
		printf("Error: index %i is out of bounds in vector of length %i. Not setting element.\n", index, this->size(this));
		return;
	}	
}

static void Vector__push_back(Vector* this, int newVal) {
	this->size_++;
	this->elements = (int*) realloc(this->elements, this->size_*sizeof(int));	
	this->elements[this->size_ - 1] = newVal;
}

static void Vector__pop_back(Vector* this) {
	this->size_--;
	this->elements = (int*) realloc(this->elements, this->size_*sizeof(int));
}

static int* Vector__begin(Vector* this) {

}

static int* Vector__end(Vector* this) {

}

static void Vector__clear(Vector* this) {
	free(this->elements);
	this->elements = NULL;
	this->size_ = 0;
}

static void Vector__insert(Vector* this, int index, int newVal) {
	this->size_++;
	this->elements = (int*) realloc(this->elements, this->size_*sizeof(int));
	int i;
	for (i = this->size_ - 1; i >= index; i--) {
		this->elements[i] = this->elements[i-1];
	}

	this->elements[index] = newVal;
}

static void Vector__erase(Vector* this, int index) {
	this->size_--;
	
	int i;
	for (i = index; i < this->size_; i++) {
		this->elements[i] = this->elements[i+1];
	}

	this->elements = (int*) realloc(this->elements, this->size_*sizeof(int));
}

Vector* new_Vector() {
	Vector* vector = (Vector*) malloc(sizeof(Vector));
	vector->elements = (int*) malloc(sizeof(int) * 0);
	vector->size_ = 0;
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
	free(vector->elements);
	free(vector);
}
