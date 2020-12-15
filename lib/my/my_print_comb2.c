/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** print number differently
*/

#include <unistd.h>
#include <stdio.h>

int my_putchar(char c);

void print_comb2(int t1, int u1, int t2, int u2)
{
    if (!(t1 == '9' && u1 == '8' && t2 == '9' && u2 == '9')) {
        my_putchar(t1);
        my_putchar(u1);
        my_putchar(' ');
        my_putchar(t2);
        my_putchar(u2);
        my_putchar(',');
        my_putchar(' ');
    } else {
        my_putchar(t1);
        my_putchar(u1);
        my_putchar(' ');
        my_putchar(t2);
        my_putchar(u2);
    }
}

void my_print_comb2_alg(char t1, char u1, char t2, char u2)
{
    while (t1 != '9' || u1 != '9' || t2 != '9' || u2 != '9') {
        if ((t1 * 10 + u1) < (t2 * 10 + u2))
            print_comb2(t1, u1, t2, u2);
        u2++;
        if (u2 == '9' + 1) {
            u2 = '0';
            t2++;
        }
        if (t2 == '9' + 1) {
            t2 = '0';
            u1++;
        }
        if (u1 == '9' + 1) {
            u1 = '0';
            t1++;
        }
    }
}

int my_print_comb2(void)
{
    char t1 = '0';
    char u1 = '0';
    char t2 = '0';
    char u2 = '0';

    my_print_comb2_alg(t1, u1, t2, u2);
    return (1);
}
