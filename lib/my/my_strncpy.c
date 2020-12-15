/*
** EPITECH PROJECT, 2020
** my strcpy
** File description:
** copy character in a string
*/


#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int size)
{
    int i = 0;

    for (i = 0; i < size && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < size; i++)
        dest[i] = '\0';
    return (dest);
}
