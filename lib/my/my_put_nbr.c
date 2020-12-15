/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** display number on screen
*/

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int my_put_nbr(int nb);
int my_putchar(char c);

int edge_case(int nb)
{
    if (nb == INT_MIN) {
        my_put_nbr(-214748364);
        my_put_nbr(8);
        return (1);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    long i = 1;

    if (edge_case(nb) == 1)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while (i * 10 <= nb)
        i *= 10;
    while (i != 1) {
        my_putchar(nb / i + '0');
        nb = nb % i;
        i /= 10;
    }
    my_putchar(nb + '0');
    return (1);
}
