/*
** EPITECH PROJECT, 2020
** str upcase
** File description:
** to up from lower char
*/

#include <stdio.h>

char *my_strlowcase(char *str);

int char_is_up(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int char_is_low(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int char_is_alphanum(char c)
{
    if (c > '0' && c < 'z')
        if (c <= '9' || (c >= 'A' && c <= 'Z') || c >= 'a')
            return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    if (!str)
        return (NULL);
    my_strlowcase(&str[0]);
    if (char_is_low(str[0]) == 1)
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (char_is_low(str[i]) == 1 && char_is_alphanum(str[i - 1]) == 0)
            str[i] -= 32;
    }
    return (str);
}
