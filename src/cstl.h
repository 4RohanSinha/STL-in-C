//using templates in C: https://stackoverflow.com/questions/10950828/simulation-of-templates-in-c-for-a-queue-data-type
#ifndef CSTL_H
#define CSSTL_H

#include <stdio.h>
#include <stdlib.h>

#define T int
#define TYPE_NAME(x) x##_int
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T long
#define TYPE_NAME(x) x##_long
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T float
#define TYPE_NAME(x) x##_float
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T double
#define TYPE_NAME(x) x##_double
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T char
#define TYPE_NAME(x) x##_char
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T char*
#define TYPE_NAME(x) x##_char_ptr
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#endif
