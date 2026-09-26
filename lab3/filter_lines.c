#include <stdio.h>
#include <stdlib.h>

// Do not include any additional header files

#define MAX_LINE 256

/*
 * Read lines one at a time from in using fgets, and write to out only
 * the lines that contain the character target. A line "contains" target
 * if target appears anywhere in the line, including in the newline
 * character itself (so target == '\n' matches every line).
 *
 * Returns the number of lines written to out.
 * Assume no line is longer than MAX_LINE - 1 characters. (What could go wrong
 * if a line was longer?)
 *
 * Note the buffer below is declared with MAX_LINE elements and fgets is
 * called with MAX_LINE as the size argument: fgets will read at most
 * MAX_LINE - 1 characters and always null-terminates what it reads, so
 * the buffer needs room for the terminator as well as the characters.
 */
int filter_lines(FILE *in, FILE *out, char target) {
    char buffer[MAX_LINE];

    int count = 0;
    // TODO: Complete this function
    // file is already open, so we can just read from it
    // approach: use fgets to read a line from the file, then check if the line contains the target character.
    // If it does, write it to the output file.
    // Keep track of how many lines are written and return that count at the end.

    // Read at most MAX_LINE - 1 characters from in and store the line in buffer.
    while (fgets(buffer, MAX_LINE, in) != NULL) {
        // check if the line contains the target character
        for (int i = 0; buffer[i] != '\0'; i++) { // check each char in the line
            if (buffer[i] == target) {
                fputs(buffer, out); // match, we put the entire line into out
                count++; // keep track!
                break; // no need to check the rest of the line
            }
        }
        // check the next line in the file
    }

    return count;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s infile outfile target_char\n", argv[0]);
        exit(1);
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Could not open %s for reading\n", argv[1]);
        exit(1);
    }

    FILE *out = fopen(argv[2], "w");
    if (out == NULL) {
        fprintf(stderr, "Could not open %s for writing\n", argv[2]);
        fclose(in);
        exit(1);
    }

    char target = argv[3][0];
    int count = filter_lines(in, out, target);
    printf("Wrote %d matching line(s) to %s\n", count, argv[2]);

    fclose(in);
    fclose(out);
    return 0;
}
