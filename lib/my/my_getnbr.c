/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** return a int from a char*
*/

#include <stdbool.h>
#include <limits.h>

bool char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    else
        return (false);
}

int my_getnbr(char *str)
{
    long res = 0;
    int i = 0;
    int neg = 1;

    if (!str)
        return (0);
    while (char_is_num(str[i]) == false)
        i++;
    if (str[i] == '\0')
        return (0);
    if (i > 0 && str[i - 1] == '-')
        neg = -1;
    while (char_is_num(str[i]) == true) {
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    if (res >= INT_MAX || res <= INT_MIN)
        return (0);
    return (res * neg);
}
