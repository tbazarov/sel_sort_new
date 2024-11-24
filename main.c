#include <stdio.h>
#include <stdlib.h>
#include "ssortdeclars.h"

#define MAX_STRINGS 100
#define MAX_LENGTH 100



int main() 
{
    int n;
    char *strings[MAX_STRINGS];
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    getchar();

    printf("Выберите тип данных:\n");
    printf("1. int\n");
    printf("2. float\n");
    printf("3. char\n");
    printf("4. string\n");

    int type;
    scanf("%d", &type);

    void* arr;
    if (type == 1) 
    {
        arr = malloc(n * sizeof(int));
        printf("Введите элементы массива (int):\n");
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &((int*)arr)[i]);
        }
        selection_sort(arr, n, sizeof(int), compare_int);
    }
    else if (type == 2) 
    {
        arr = malloc(n * sizeof(float));
        printf("Введите элементы массива (float):\n");
        for (int i = 0; i < n; i++) 
        {
            scanf("%f", &((float*)arr)[i]);
        }
        selection_sort(arr, n, sizeof(float), compare_float);
    }
    else if (type == 3) 
    {
        arr = malloc(n * sizeof(char));
        printf("Введите элементы массива (char):\n");
        for (int i = 0; i < n; i++) 
        {
            scanf(" %c", &((char*)arr)[i]);
        }
        selection_sort(arr, n, sizeof(char), compare_char);
    }

    else if (type == 4)
    {

        printf("Введите строки: \n");
        for (int i = 0; i < n; i++) 
        {
            strings[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
            fgets(strings[i], MAX_LENGTH, stdin);

        }
        string_sel_sort(strings, n);

    } 

    printf("Отсортированный массив:\n");

    if (type == 1) 
    {
        for (int i = 0; i < n; i++) 
        {
            printf("%d ", ((int*)arr)[i]);
        }
    } 
    
    else if (type == 2) 
    {
        for (int i = 0; i < n; i++) 
        {
            printf("%f ", ((float*)arr)[i]);
        }
    } 
    
    else if (type == 3) 
    {
        for (int i = 0; i < n; i++) 
        {
            printf("%c ", ((char*)arr)[i]);
        }
    }

    else if (type == 4)
    {
       printf("Отсортированные строки: \n");
        for (int i = 0; i < n; i++) 
        {
            printf("%s", strings[i]);
            free(strings[i]); 
        }
    }

    printf("\n");

    free(arr);
    return 0;
}