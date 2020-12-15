/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display string
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);
int my_strlen(char const *str);

int my_putstr(char const *str)
{
    if (str == NULL)
        return (1);
    write(1, &str[0], my_strlen(str));
    return (0);
}
