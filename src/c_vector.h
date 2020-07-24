#ifndef C_VECTOR_H
#define C_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define T int
#define TYPE_NAME(x) int_##x
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T long
#define TYPE_NAME(x) long_##x
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T float
#define TYPE_NAME(x) float_##x
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T double
#define TYPE_NAME(x) double_##x
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T char
#define TYPE_NAME(x) char_##x
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME

#define T char*
#define TYPE_NAME(x) string_##x
#include "vector.h"
#include "vector.c"
#undef T
#undef TYPE_NAME
#endif
