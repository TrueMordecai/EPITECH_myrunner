/*
** EPITECH PROJECT, 2020
** print comb n
** File description:
** print_combn
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int my_putchar(char c);

int compute_square(int x, int y)
{
    int i = 0;
    int res = 1;

    while (i != y) {
        res *= x;
        i++;
    }
    return (res);
}

int check_validity(int size, int nb)
{
    int i = 1;

    while (i < nb) {
        if (size % 10 <= ((size/10) % 10))
            return (1);
        size /= 10;
        i++;
    }
    return (0);
}

int edge_ca(int nb, int original_i)
{
    if (nb == 9 && original_i == 1)
        return (0);
    if (nb == 89 && original_i == 2)
        return (0);
    if (nb == 789 && original_i == 3)
        return (0);
    if (nb == 6789 && original_i == 4)
        return (0);
    if (nb == 56789 && original_i == 5)
        return (0);
    if (nb == 456789 && original_i == 6)
        return (0);
    if (nb == 3456789 && original_i == 7)
        return (0);
    if (nb == 23456789 && original_i == 8)
        return (0);
    if (nb == 123456789 && original_i == 9)
        return (0);
    return (1);
}

void print_comb_n(int nb, int size, int original_i)
{
    size = compute_square(10, size) / 10;
    while (size != 0) {
        my_putchar('0' + (nb / size) % 10);
        size /= 10;
    }
    if (edge_ca(nb, original_i) == 1) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_combn(int i)
{
    int k = 0;
    while (compute_square(10, i) != k) {
        if (check_validity(k, i) == 0)
            print_comb_n(k, i, i);
        k++;
    }
    return (0);
}
