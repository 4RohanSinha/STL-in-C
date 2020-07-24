#ifdef T

//private members in a struct: https://stackoverflow.com/questions/3824329/partitioning-struct-into-private-and-public-sections
struct TYPE_NAME(vectorPrivateMembers);

typedef struct TYPE_NAME(c_vector) {
	struct TYPE_NAME(vectorPrivateMembers)* privateVM;
	int (*size)(struct TYPE_NAME(c_vector)* this);
	T (*get)(struct TYPE_NAME(c_vector)* this, int index);
	void (*set)(struct TYPE_NAME(c_vector)* this, int index, T newVal);
	void (*push_back)(struct TYPE_NAME(c_vector)* this, T newVal);
	void (*pop_back)(struct TYPE_NAME(c_vector)* this);
	T* (*begin)(struct TYPE_NAME(c_vector)* this);
	T* (*end)(struct TYPE_NAME(c_vector)* this);
	void (*clear)(struct TYPE_NAME(c_vector)* this);
	void (*insert)(struct TYPE_NAME(c_vector)* this, int index, T newVal);
	void (*erase)(struct TYPE_NAME(c_vector)* this, int index);
	void (*assign)(struct TYPE_NAME(c_vector)* this, T* data);
	T* (*data)(struct TYPE_NAME(c_vector)* this);
} TYPE_NAME(vector);

TYPE_NAME(vector)* TYPE_NAME(new_vector)();

void TYPE_NAME(delete_vector) (TYPE_NAME(vector)* vector);
#endif
