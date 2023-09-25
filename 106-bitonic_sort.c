#include <stdio.h>
#include "sort.h"

/* Function to merge two subarrays in ascending order */
void bitonic_merge(int *array, size_t size, int up) {
    if (size > 1) {
        size_t mid = size / 2;
        for (size_t i = 0; i < mid; i++) {
            if ((array[i] > array[i + mid]) == up) {
                /* Swap elements */
                int temp = array[i];
                array[i] = array[i + mid];
                array[i + mid] = temp;
            }
        }
        bitonic_merge(array, mid, up);
        bitonic_merge(array + mid, mid, up);
    }
}

/* Function to perform bitonic sort */
void bitonic_sort(int *array, size_t size) {
    if (size <= 1) {
        return;
    }

    /* Bitonic sort in ascending order */
    bitonic_sort(array, size / 2);
    bitonic_sort(array + size / 2, size / 2);

    /* Merge the whole sequence in ascending order */
    bitonic_merge(array, size, 1);
}

int main(void) {
    int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bitonic_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
