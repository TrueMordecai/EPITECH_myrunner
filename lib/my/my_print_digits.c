/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** print alphabet
*/

#include <unistd.h>

int my_print_digits(void)
{
    int i = '0';

    while (i != '9' + 1) {
        write(1, &i, 1);
        i++;
    }
    return (1);
}
