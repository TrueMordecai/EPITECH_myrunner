/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** check if all character are alpha
*/

int char_is_printable(char c)
{
    if (c <= 31 || c > 126)
        return (0);
    return (1);
}

int my_str_isprintable(char const *str)
{
    if (!str)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (char_is_printable(str[i]) == 0)
            return (0);
    return (1);
}
