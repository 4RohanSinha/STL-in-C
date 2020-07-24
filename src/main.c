#include <stdio.h>
#include <string.h>
#include "cstl.h"

//A demo for the C library.
int main() {
	vector_int* x = new_vector_int();
	x->push_back(x, 5);
	x->push_back(x, 4);

	printf("the size of vector x is: %i\n\n", x->size(x));
	printf("the value of the vector x at index 0 is %i\n\n", x->get(x, 0));
	printf("the value of the vector x at index 1 is %i\n\n", x->get(x, 1));

	x->insert(x, 1, 6);
	printf("INSERTED: the size of vector x is: %i\n\n", x->size(x));
	printf("the value of the vector x at index 1 is %i\n\n", x->get(x, 1));
	printf("the value of the vector x at index 2 is %i\n\n", x->get(x, 2));
	
	x->pop_back(x);
	printf("the size of vector x is now: %i\n\n", x->size(x));
	printf("the value of the vector x at index 0 is %i\n\n", x->get(x, 0));
	printf("the value of the vector x at index 1 is %i\n\n", x->get(x, 1));
	delete_vector_int(x);

	//TODO: fix valgrind error
	//work on fixing vector of chars
	vector_char_ptr* y = new_vector_char_ptr();
	vector_char* z = new_vector_char();
	strcpy(z->data(z), "Test");
	y->push_back(y, z->data(z));
	printf("%s\n", y->get(y, 0));
	delete_vector_char(z);
	delete_vector_char_ptr(y);
	return 0;
}
