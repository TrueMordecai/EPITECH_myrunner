/*
** EPITECH PROJECT, 2020
** print comb
** File description:
** print come number
*/

#include <unistd.h>

int my_putchar(char c);

void print_comb(char h, char t, char u)
{
    my_putchar(h);
    my_putchar(t);
    my_putchar(u);
    if (h != '7' || t != '8' || u != '9') {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb(void)
{
    char h = '0';
    char t = '0';
    char u = '0';

    while (h != '9') {
        if (u > t && t > h)
            print_comb(h, t, u);
        u++;
        if (u == '9' + 1) {
            u = '0';
            t++;
        }
        if (t == '9' + 1) {
            t = '0';
            h++;
        }
    }
    return (1);
}
