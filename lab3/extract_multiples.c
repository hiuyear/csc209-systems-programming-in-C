#include <stdio.h>
#include <stdlib.h>

/*
 * Scan arr (length n) for elements that are evenly divisible by divisor.
 * Out will point to an array of the elements of arr that are evenly 
 * divisible by divisor, * in the same order that they appear in arr.
 * Return the number of elements in the array pointed to by out.
 *
 * Do not allocate any more memory than necessary.
 */
int extract_multiples(int *arr, int n, int divisor, int **out) {
   // TODO: complete this function
   // first count how many elements are venely divisible by divisor
   // then create a malloc of that size
   // loop through each item in arr
   // if it is evenly divisible then we add it to the malloc list
    int count = 0;
    for (int i = 0; i < n; i ++){
        // arr is a pointer to the start of an array
        if (arr[i] % divisor == 0){
            count ++;
        }
    }

    // out is a pointer to a pointer that points to multiples
    // deference once, to change what OUT points to (rn it points to another pointer, the start of an array)
    *out = malloc(sizeof(int) * count);

    // now go thorugh arr again and add the multiples to the new array
    // we need a second index to keep track of where we are in the new array.
    // we only advance to the next index in the new array when we find a multiple, so j++ only at the end of each succeful append to the new array
    for (int i = 0, j = 0; i < n; i ++){
        if (arr[i] % divisor == 0){
            (*out)[j] = arr[i]; 
            // deref out once, to get to the start of the array,
            // then use [i] to jump to the right index, 
            // then add the new item to the array
            j++;
        }
    }
    return count;
}

/* Build a dynamically allocated array of ints from an array of strings,
   as in split_array.c's build_array. */
int *build_array(char **strs, int size) {
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = strtol(strs[i], NULL, 10);
    }
    return arr;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s divisor num1 [num2 ...]\n", argv[0]);
        exit(1);
    }

    int divisor = strtol(argv[1], NULL, 10);
    int n = argc - 2;
    int *full_array = build_array(&argv[2], n);

    int *multiples; // multiples is a pointer to an undefined array
    int count = extract_multiples(full_array, n, divisor, &multiples);
    // &multiples: the address of the pointer so that extract_multiples can modify it to point to the new array

    printf("Multiples of %d:\n", divisor);
    for (int i = 0; i < count; i++) {
        printf("%d ", multiples[i]);
    }
    printf("\n");

    free(full_array);
    free(multiples);
    return 0;
}
