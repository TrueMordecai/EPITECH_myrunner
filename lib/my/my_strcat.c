/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates string
*/

char *my_strcpy(char *dest, char const *src);
int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    return (my_strcpy(&dest[my_strlen(dest)], src));
}
