/*
** EPITECH PROJECT, 2020
** my strcpy
** File description:
** copy character in a string
*/

#include <stdlib.h>

char *my_strcpy_custom(char *dest, char const *src, char c)
{
    int i = 0;

    while (src[i] != c) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL)
        return (NULL);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
