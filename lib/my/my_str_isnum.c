/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** check if all character are alpha
*/

int char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    if (!str)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (char_is_num(str[i]) == 0)
            return (0);
    return (1);
}
