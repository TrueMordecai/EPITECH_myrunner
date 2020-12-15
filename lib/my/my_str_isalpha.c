/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** check if all character are alpha
*/
int char_is_up(char c);
int char_is_low(char c);


int my_str_isalpha(char const *str)
{
    if (!str)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (char_is_low(str[i]) == 0 && char_is_up(str[i]) == 0)
            return (0);
    return (1);
}
