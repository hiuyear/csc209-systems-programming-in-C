#include <stdio.h>
#include <string.h>


/*
    This program has two arguments: the first is a greeting message, and the
    second is a name.

    The message is an impersonal greeting, such as "Hi" or "Good morning".
    name is set to refer to a string holding a friend's name, such as
    "Emmanuel" or "Xiao".

    First copy the first argument to the array greeting. (Make sure it is
    properly null-terminated.)

    Write code to personalize the greeting string by appending a space and
    then the string pointed to by name.
    So, in the first example, greeting should be set to "Hi Emmanuel", and
    in the second it should be "Good morning Xiao".

    If there is not enough space in greeting, the resulting greeting should be
    truncated, but still needs to hold a proper string with a null terminator.
    For example, "Good morning" and "Emmanuel" should result in greeting
    having the value "Good morning Emmanu" and "Top of the morning to you" and
    "Patrick" should result in greeting having the value "Top of the morning ".

    Do not make changes to the code we have provided other than to add your
    code where indicated.
*/

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: greeting message name\n");
        return 1;
    }
    char greeting[20];
    char *name = argv[2];

    // Your code goes here
    // 1. copy the greeting into arr greeting, then add \0 to the end of greeting (even if there is a lot of empty space between greeting and end of greeting)
    strncpy(greeting, argv[1], sizeof(greeting) - 1);
    greeting[sizeof(greeting)-1] = '\0';

    // cat an empty space between greeting and name. 
    // only cat the space if there is space left (ie. taking into consideration the last \0 in greetings AND the length of the greeting itself)
    if (strlen(greeting) < sizeof(greeting) - 1){
        strncat(greeting, " ", sizeof(greeting) - 1 - strlen(greeting));
    }

    // cat the name with however much space left we have (squeeze in as much of the name as possible BETWEEN the greeting, " ". and the \0 at the end)
    strncat(greeting, name, sizeof(greeting) - 1 - strlen(greeting));
    printf("%s\n", greeting);
    return 0;
}


