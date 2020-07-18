#include "vector.h"

//A demo for the C library.
int main() {
	Vector* x = new_Vector();
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
	delete_Vector(x);
	return 0;
}