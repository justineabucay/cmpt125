/*
 * Filename: get_name.c
 *
 * Description: Function get_name() gets the
 *              name of the user.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

char *get_name(void)
{

    // Should be enough space for a name
    const unsigned int SIZE = 1024;
    char line[SIZE];

    // Prompt the user for their name
    printf("Please enter your name: ");

    // Reads at most SIZE-1 chars from stdin,
    // up to first newline, EOF or error.
    // We ALWAYS check for I/O errors.
    if (fgets(line, SIZE, stdin) == NULL)
    {
        perror("failed to read a name");
        line[0] = '\0';
    }

    return line;
}

int main(void)
{

    // Initialize the pointer using the
    // function's return value
    char *name = get_name();

    // Echo user's name
    printf("Your name is %s\n", name);

    return 0;
}
