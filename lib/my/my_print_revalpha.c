/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** print alphabet
*/

#include <unistd.h>

int my_print_revalpha(void)
{
    int i = 'z';

    while (i != 'a' - 1) {
        write(1, &i, 1);
        i--;
    }
    return (1);
}
