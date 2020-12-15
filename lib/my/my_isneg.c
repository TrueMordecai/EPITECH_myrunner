/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** print N or P if negative/positive
*/

#include <unistd.h>

int my_putchar(char c);

int my_isneg(int n)
{
    n < 0 ? my_putchar('N') : my_putchar('P');
    return (0);
}
