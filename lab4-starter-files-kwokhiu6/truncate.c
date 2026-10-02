#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    Write a function named truncate() that takes a string s and a
    non-negative integer n. If s has more than n characters (not including the
    null terminator), the function should truncate s at n characters and
    return the number of characters that were removed. If s has n or
    fewer characters, s is unchanged and the function returns 0. For example,
    if s is the string "function" and n is 3, then truncate() changes s to
    the string "fun" and returns 5.
*/

int truncate(char *target, int n){
    int length = 0;
    // get the total length of the string
    while (target[length] != '\0'){
        length++;
    }

    // if the length is less than n, we dont trucate anything
    if (length <= n){
        return 0;
    }

    // we know that the the length is more than n
    // cut off the rest of the world beyond index n of that word
    // so we set the char at idx n as \0
    target[n] = '\0';
    return length-n;

}


int main(int argc, char **argv) {
    /* Do not change the main function */
    if (argc != 3) {
        fprintf(stderr, "Usage: truncate number string\n");
        return 1;
    }
    int amt = strtol(argv[1], NULL, 10);

    char *target = argv[2];

    int soln_val = truncate(target, amt);
    printf("%d %s\n", soln_val, target);

    return 0;
}
