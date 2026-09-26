#include <stdio.h>
#include <stdlib.h>

/* Return a pointer to an array of two dynamically allocated arrays of ints.
   The first array contains the elements of the input array s that are
   at even indices.  The second array contains the elements of the input
   array s that are at odd indices.

   Do not allocate any more memory than necessary. You are not permitted
   to include math.h.  You can do the math with modulo arithmetic and integer
   division.
*/
int **split_array(const int *s, int length) {
    // approach:
    // use a for loop to loop through s, if the index is even, add it to the first array, if odd, add it to the second array
    // since int length is passed in, we can use that to determine the size of the two arrays
    int even_count = (length + 1) / 2; // if length is odd, the first array will have one more element than the second array
    int odd_count = length / 2; // if length is even, the second array will have the same number of
    int *odd_array = malloc(sizeof(int) * odd_count); // allocate memory for the first arrays
    int *even_array = malloc(sizeof(int) * even_count); // allocate memory for the second array

    for (int i = 0; i < length; i++) {
        // if the index is even, add it to the first array, if odd, add it to the second array
        if (i % 2 == 0) { // if the index is even, so 
            even_array[i / 2] = s[i]; // eg. i = 4, so add to index 
        } else { // if the index is odd
            odd_array[i / 2] = s[i]; // eg. i = 3, 
        }
    }

    // want to return: a pointer to an array of two dynamically allocated arrays of ints
    // so result is a pointer to a list of pointers, where each pointer points to an array of ints
    int **result = malloc(sizeof(int *) * 2); // allocate memory for the array of pointers
    result[0] = even_array; // set the first pointer to point to the first array
    result[1] = odd_array; // set the second pointer to point to the second array
    return result;
}

/* Return a pointer to an array of ints with size elements.
   - strs is an array of strings where each element is the string
     representation of an integer.
   - size is the size of the array
 */

int *build_array(char **strs, int size) {
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = strtol(strs[i], NULL, 10);
    }
    return arr;

}


int main(int argc, char **argv) {
    /* Replace the comments in the next two lines with the appropriate
       arguments.  Do not add any additional lines of code to the main
       function or make other changes.
     */
     // argv looks like ["./split_array", "1", "2", "3", "4", "5"
     // so **argv is a pointer to a pointer to a char, which is the first element of the array of strings

    // argv is the first input string. eg "10"
    // &argv[1] points to the first command-line number
    // use &argv coz buildarray takes **strs, which you want to loop through the array of pointers to each string
    int *full_array = build_array(&argv[1], argc - 1);
    int **result = split_array(full_array, argc - 1);

    printf("Original array:\n");
    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", full_array[i]);
    }
    printf("\n");

    printf("result[0]:\n");
    for (int i = 0; i < argc / 2; i++) {
        printf("%d ", result[0][i]);
    }
    printf("\n");

    printf("result[1]:\n");
    for (int i = 0; i < (argc - 1) / 2; i++) {
        printf("%d ", result[1][i]);
    }
    printf("\n");
    free(full_array);
    free(result[0]);
    free(result[1]);
    free(result);
    return 0;
}
