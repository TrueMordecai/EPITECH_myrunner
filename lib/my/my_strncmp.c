/*
** EPITECH PROJECT, 2020
** strncmp
** File description:
** compare two string
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (0);
    while (str1[i] == str2[i]) {
        if (i == n)
            return (0);
        i++;
    }
    if (str1[i] != str2[i])
        return (str1[i] - str2[i]);
    return (0);
}
