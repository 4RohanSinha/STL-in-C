#ifdef T

//private members in a struct adapted from: https://stackoverflow.com/questions/3824329/partitioning-struct-into-private-and-public-sections
struct TYPE_NAME(vectorPrivateMembers) {
	T* elements;
	int size_;
};
//static keyword to prevent following functions from being directly visible to user

static int TYPE_NAME(Vector__size) (TYPE_NAME(vector)* this) {
	return this->privateVM->size_;
}

static T TYPE_NAME(Vector__get) (TYPE_NAME(vector)* this, int index) {
	if (index < this->size(this))
		return this->privateVM->elements[index];
	else {
		//TODO: define functions for each type to return errors
		printf("Error: index %i is out of bounds in vector of length %i. Returning -1.\n", index, this->size(this));
		return -1;
	}	
}

static void TYPE_NAME(Vector__set) (TYPE_NAME(vector)* this, int index, T newVal) {
	if (index < this->size(this))
		this->privateVM->elements[index] = newVal;
	else {
		printf("Error: index %i is out of bounds in vector of length %i. Not setting element.\n", index, this->size(this));
		return;
	}	
}

static void TYPE_NAME(Vector__push_back)(TYPE_NAME(vector)* this, T newVal) {
	this->privateVM->size_++;
	this->privateVM->elements = realloc(this->privateVM->elements, this->privateVM->size_*sizeof(T));	
	this->privateVM->elements[this->privateVM->size_ - 1] = newVal;
}

static void TYPE_NAME(Vector__pop_back) (TYPE_NAME(vector)* this) {
	this->privateVM->size_--;
	this->privateVM->elements = realloc(this->privateVM->elements, this->privateVM->size_*sizeof(T));
}

static T* TYPE_NAME(Vector__begin) (TYPE_NAME(vector)* this) {

}

static T* TYPE_NAME(Vector__end) (TYPE_NAME(vector)* this) {

}

static void TYPE_NAME(Vector__clear) (TYPE_NAME(vector)* this) {
	free(this->privateVM->elements);
	this->privateVM->elements = NULL;
	this->privateVM->size_ = 0;
}

static void TYPE_NAME(Vector__insert) (TYPE_NAME(vector)* this, int index, T newVal) {
	this->privateVM->size_++;
	this->privateVM->elements = realloc(this->privateVM->elements, this->privateVM->size_*sizeof(T));
	int i;
	for (i = this->privateVM->size_ - 1; i >= index; i--) {
		this->privateVM->elements[i] = this->privateVM->elements[i-1];
	}

	this->privateVM->elements[index] = newVal;
}

static void TYPE_NAME(Vector__erase) (TYPE_NAME(vector)* this, int index) {
	this->privateVM->size_--;
	
	int i;
	for (i = index; i < this->privateVM->size_; i++) {
		this->privateVM->elements[i] = this->privateVM->elements[i+1];
	}

	this->privateVM->elements = realloc(this->privateVM->elements, this->privateVM->size_*sizeof(T));
}

static void TYPE_NAME(Vector__assign) (TYPE_NAME(vector)* this, T* data) {
	if (this->privateVM->elements != NULL)
		free(this->privateVM->elements);
	this->privateVM->elements = data;
}

static T* TYPE_NAME(Vector__data) (TYPE_NAME(vector)* this) {
	return this->privateVM->elements;
}

TYPE_NAME(vector)* TYPE_NAME(new_vector) () {
	TYPE_NAME(vector)* vectorRes = malloc(sizeof(TYPE_NAME(vector)));
	vectorRes->privateVM = malloc(sizeof(struct TYPE_NAME(vectorPrivateMembers)));
	vectorRes->privateVM->elements = malloc(sizeof(T) * 1);
	vectorRes->privateVM->size_ = 0;
	vectorRes->size = TYPE_NAME(Vector__size);
	vectorRes->get = TYPE_NAME(Vector__get);
	vectorRes->set = TYPE_NAME(Vector__set);
	vectorRes->push_back = TYPE_NAME(Vector__push_back);
	vectorRes->pop_back = TYPE_NAME(Vector__pop_back);
	vectorRes->begin = TYPE_NAME(Vector__begin);
	vectorRes->end = TYPE_NAME(Vector__end);
	vectorRes->clear = TYPE_NAME(Vector__clear);
	vectorRes->insert = TYPE_NAME(Vector__insert);
	vectorRes->erase = TYPE_NAME(Vector__erase);
	vectorRes->assign = TYPE_NAME(Vector__assign);
	vectorRes->data = TYPE_NAME(Vector__data);
}

void TYPE_NAME(delete_vector) (TYPE_NAME(vector)* vector) {
	
	if (vector->privateVM->elements != NULL)
		free(vector->privateVM->elements);
	
	if (vector->privateVM != NULL)
		free(vector->privateVM);

	if (vector != NULL)
		free(vector);
}

#endif
