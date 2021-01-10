/*
** EPITECH PROJECT, 2021
** runner
** File description:
** str converter
*/

#include "runner.h"

char *int_to_str(int i)
{
    char *str = malloc(sizeof(char) * 4);

    str[0] = i / 100 % 10 + '0';
    str[1] = i / 10 % 10 + '0';
    str[2] = i % 10 + '0';
    str[3] = '\0';
    return (str);
}

char *char_str(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = '\0';
    return (str);
}

