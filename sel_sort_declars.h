#include <stddef.h>

int compare_int(void *a, void *b);
int compare_float(void *a, void *b);
int compare_char(void *a, void *b);
int compare_string(void *a, void *b);
void selection_sort(void *array, int n, size_t size, int (*cmp)(void*, void*));
