#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character 'c' to the standard output (stdout).
 * @c: The character to print
 *
 * Return: On success, returns 1.
 * On error, returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
