/*
** EPITECH PROJECT, 2020
** str upcase
** File description:
** to up from lower char
*/

#include <stdio.h>

char *my_strupcase(char *str)
{
    if (!str)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}
