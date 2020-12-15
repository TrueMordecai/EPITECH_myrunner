/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** return a reverssed string
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int i = 0;
    int k = my_strlen(str) - 1;
    char swap;

    if (!str)
        return (NULL);

    while (i <= k) {
        swap = str[i];
        str[i] = str[k];
        str[k] = swap;
        i++;
        k--;
    }
    return (str);
}
