#include "sel_sort_declars.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

void fill_arr_int(int *arr_int, size_t size); 
void fill_arr_float(int *arr_float, size_t size);
void fill_arr_char(int *arr_char, size_t size);
int is_sorted_int(int *arr_int, size_t size); 
int is_sorted_float(int *arr_float, size_t size);
int is_sorted_char(int *arr_char, size_t size);

int main()
{
    srand(time(NULL));
    int size = rand() % 10000 + 1;
    int *arr_int = malloc(size * sizeof(int));
	int *arr_float = malloc(size * sizeof(float));
	int *arr_char = malloc(size * sizeof(char));

    fill_arr_int(arr_int, size);
	fill_arr_float(arr_float, size);
	fill_arr_char(arr_char, size);
    
	selection_sort(arr_int, size, sizeof(int), compare_int);
	selection_sort(arr_float, size, sizeof(float), compare_float);
	selection_sort(arr_char, size, sizeof(char), compare_char);
    
	printf("%d\n", is_sorted_int(arr_int, size));
	printf("%d\n", is_sorted_float(arr_float, size));
	printf("%c\n", is_sorted_char(arr_char, size));

    free(arr_int);
	free(arr_float);
	free(arr_char);

    return 0;
}

void fill_arr_int(int *arr_int, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        arr_int[i] = rand() % 100;
    }
}

void fill_arr_float(int *arr_float, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		arr_float[i] = rand() % 100;
	}
}

void fill_arr_char(int *arr_char, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		arr_char[i] = rand() % 100;
	}
}

int is_sorted_int(int *arr_int, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (((int*)arr_int)[i] > ((int*)arr_int)[i + 1])
        {
            return 0;  // фигня
        }
    }
    return 1; // чётко
}

int is_sorted_float(int *arr_float, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (((float*)arr_float)[i] > ((float*)arr_float)[i + 1])
        {
            return 0;  // фигня
        }
    }
    return 1; // чётко
}

int is_sorted_char(int *arr_char, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (((char*)arr_char)[i] > ((char*)arr_char)[i + 1])
        {
            return 0;  // фигня
        }
    }
    return 1; // чётко
}

// void run_all_tests(void) 
// {
// 	test_selection_sort_int();
// 	test_selection_sort_float();
// 	test_selection_sort_char();
// 	test_selection_sort_string();
// 	printf("Все тесты были пройдены успешно.");
// }

// void test_selection_sort_int() {

// 	srand(time(NULL));

// 	int random_size = rand() % 10 + 1;
// 	int* arr_int = malloc(sizeof(int) * random_size);

// 	if (arr_int == NULL) {
// 		printf("Память не была выделена для массива целых чисел.\n");
// 		exit(1);
// 	}

// 	for (int i = 0; i < random_size; i++) {
// 		arr_int[i] = rand() % 50;
// 	}
	
// 	size_t len = random_size;

// 	selection_sort(arr_int, len, sizeof(arr_int[0]), compare_int);

// 	for (int i = 0; i < random_size - 1; i++) {
// 		assert(arr_int[i] <= arr_int[i + 1]);
// 	}
	
// 	free(arr_int);
// }

// void test_selection_sort_float() {
// 	int random_size = rand() % 10 + 1;
// 	float* arr_float = malloc(sizeof(float) * random_size);

// 	if (arr_float == NULL) {
// 		printf("Память не была выделена.");
// 		exit(1);
// 	}

// 	for (int i = 0; i < random_size; i++) {
// 		arr_float[i] = (rand() % 50 - 50) / (rand() % 70 - 70);
// 	}

// 	size_t len = random_size;

// 	selection_sort(arr_float, len, sizeof(arr_float[0]), compare_float);

// 	for (int i = 0; i < random_size - 1; i++) {
// 		assert(arr_float[i] <= arr_float[i + 1]);
// 	}

// 	free(arr_float);
// }

// void test_selection_sort_char() {
// 	int random_size = rand() % 50 + 1;
// 	char* arr_char = malloc(sizeof(char) * (random_size + 1));

// 	if (arr_char == NULL) {
// 		printf("Память не была выделена.");
// 		exit(1);
// 	}

// 	for (int i = 0; i < random_size; i++) {
// 		arr_char[i] = 'A' + rand() % 58;
// 	}

// 	arr_char[random_size] = '\0';

// 	size_t len = random_size;

// 	selection_sort(arr_char, len, sizeof(arr_char[0]), compare_char);

// 	for (int i = 0; i < random_size - 1; i++) {
// 		assert(arr_char[i] <= arr_char[i + 1]);
// 	}

// 	free(arr_char);
// }

// void test_selection_sort_string() {

// 	size_t random_lenght = rand() % 50 + 1;
// 	size_t random_size = rand() % 10 + 1;

// 	char** arr_string = malloc(sizeof(char*) * random_size);

// 	if (arr_string == NULL) {
// 		printf("Ошибка выделения памяти");
// 		exit(1);
// 	}

// 	for (int i = 0; i < random_size; i++) {
// 		arr_string[i] = malloc(sizeof(char) * random_lenght);
// 		if (arr_string[i] == NULL) {
// 			printf("Ошибка выделения памяти\n");
// 			exit(1);
// 		}
// 	}


// 	for (int i = 0; i < random_size; ++i) {
// 		for (int j = 0; j < random_lenght  - 1; ++j) {
// 			arr_string[i][j] = 'A' + rand() % 58;
// 		}
// 		arr_string[i][random_lenght - 1] = '\0';
// 	}


// 	selection_sort(arr_string, random_size, sizeof(arr_string[0]), compare_string);

// 	for (int i = 0; i < random_size - 1; i++) {
// 		assert(arr_string[i][0] <= arr_string[i + 1][0]);
// 	}

// 	for (int i = 0; i < random_size; ++i)
// 		free(arr_string[i]);
// 	free(arr_string);
// }




