/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** find the first occurences
*/

#include <stdlib.h>

int my_strcmp(char *str, char *str2);

int strcheck(char *str, char *to_find)
{
    int i = 0;

    while (str[i] == to_find[i])
        i++;
    if (to_find[i] == '\0')
        return (1);
    return (0);
}

char *my_strstr(char *str, char *to_find)
{
    int i = 0;

    if (my_strcmp(str, to_find) == 0)
        return (str);
    if (to_find[0] == '\0' || to_find == NULL)
        return (str);
    while (str[i] != '\0') {
        if (strcheck(&str[i], to_find) == 1)
            return (&str[i]);
        i++;
    }
    return (NULL);
}
