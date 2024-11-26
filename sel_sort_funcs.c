#include "sel_sort_declars.h"
#include "sel_sort_cmps.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void selection_sort(void *array, int n, size_t size, int (*cmp)(void*, void*)) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (cmp((char *)array + j * size, (char *)array + min_idx * size) < 0) 
            {
                min_idx = j;
            }
        }
        if (min_idx != i) 
        {
            swap((char *)array + i * size, (char *)array + min_idx * size, size);
        }
    }
}


void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}


