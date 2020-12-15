/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** return string length
*/

int my_strlen_custom(char const *str, char c)
{
    int i = 0;

    while (str[i] != c)
        i++;
    return (i);
}

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
