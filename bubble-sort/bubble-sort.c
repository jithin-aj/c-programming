/**
 * @file bubble-sort.c
 * @author Jithin A
 * @brief File implement a simple bubble sort algorithm in C
 *
 * @version 0.1
 * @date 2023-11-30
 *
 * @copyright Copyright (c) 2023
 *
 */

/* Includes --------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define MIN_ARG_SZ          (5)
#define PARAM_DEBUG_OFFSET  (2)
#define SWAP(x, y)          (x ^= y ^= x ^= y)

int debug = 0;

void
print_help (void)
{
    printf("Invalid arguments size\n");
    printf("Usage: program_name -d <debug> <array_elements>\n");
    printf("Options:\n");
    printf("-d <debug>  Enable or disable debug logs. Use '1' to enable and '0' to disable.\n");
    printf("<array_elements>  One or more array elements. Separate multiple elements with spaces.");
}

/**
 * @brief Allocate/reserve memory for storing elements and processing
 *
 * @param size  - memory size to be allocate
 * @return int* - return allocated memory address
 */
int*
allocate_memory (int size)
{
    return malloc(size * sizeof(size));
}

void
convert_char_to_int (char **argv, int *p_arr, int size)
{
    for (int offset = 0; offset < size; offset++) {
        p_arr[offset] = atoi(argv[offset + 1]);
    }
}

/**
 * @brief Print the give size of list
 *
 * @param p_list - pointer to the list of elements to print
 * @param size   - elements count
 */
void
print_list (int *p_list, int size)
{
    for (int index = 0; index < size; index++) {
        printf("%d ", *p_list);
        p_list++;
    }
    printf("\n");
}

/**
 * @brief Compare key element with the adjacent elements and swap them if found in the wrong order
 *
 * @param p_arr - pointer to the array of elements to be sort
 * @param size  - elements count
 */
void
bubble_sort (int *p_arr, int size)
{
    for (int key = 0; key < size; key++) {
        for (int ele = (key + 1); ele < size; ele++) {
            if (p_arr[key] > p_arr[ele]) {
                SWAP(p_arr[key], p_arr[ele]);
            }
        }
        if (debug) {
            printf("Iteration %d: ", key + 1);
            print_list(p_arr, size);
        }
    }
}

/**
 * @brief Entry point to the algorithm
 *
 * @param argc - elements count
 * @param argv - pointer to the elements
 * @return int
 */
int
main (int argc, char **argv)
{
    if (argc < MIN_ARG_SZ) {
        print_help();
        return 0;
    }

    int size = (argc - 3);    // ignore exe file from the arguments
    printf("Elements count: %d\n", size);

    debug = atoi(argv[PARAM_DEBUG_OFFSET]);

    int *p_arr = allocate_memory(size);
    if (!p_arr) {
        printf("Memory can not be allocated\n");
        return 0;
    }

    convert_char_to_int((argv + PARAM_DEBUG_OFFSET), p_arr, size);

    if (debug) {
        printf("Before sort: ");
        print_list(p_arr, size);
    }

    bubble_sort(p_arr, size);

    printf("After sort: ");
    print_list(p_arr, size);

    free(p_arr);
    return 0;
}
