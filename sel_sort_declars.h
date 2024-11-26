#pragma once
#include <stddef.h>

void selection_sort(void *array, int n, size_t size, int (*cmp)(void*, void*));
