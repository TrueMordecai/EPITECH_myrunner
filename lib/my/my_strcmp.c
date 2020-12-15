/*
** EPITECH PROJECT, 2020
** strcmp
** File description:
** compare two string
*/

#include <stdio.h>

int my_strlen(char const *str);

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (0);
    while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != 0) {
        i++;
    }
    if (str1[i] > str2[i])
        return (1);
    if (str1[i] < str2[i])
        return (-1);
    return (0);
}
