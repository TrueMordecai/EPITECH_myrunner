/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates string
*/

char *my_strncpy(char *dest, char const *src, int nb);
int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    return (my_strncpy(&dest[my_strlen(dest)], src, nb));
}
