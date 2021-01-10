/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** tool_functiuns, i should implemnt them in a library
*/

#include "runner.h"

bool float_comparison(float to_compare, float tag_1, float tag_2)
{
    if (to_compare > tag_1 && to_compare < tag_2)
        return (true);
    return (false);
}

char *file_read(char const *path)
{
    int fd = open(path, O_RDONLY);
    char *map = NULL;
    struct stat buf;

    if (fd == -1)
        return (NULL);
    stat(path, &buf);
    map = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, map, buf.st_size);
    map[buf.st_size] = '\0';
    return (map);
}

sfVector2f vector2i_to_vector2f(sfVector2i vect)
{
    sfVector2f nvect;

    nvect.x = (float)vect.x;
    nvect.y = (float)vect.y;
    return (nvect);
}

char *my_strdup(char *str)
{
    char *nstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (uint i = 0; str[i] != '\0'; i++) {
        nstr[i] = str[i];
    }
    nstr[my_strlen(str)] = '\0';
    return (nstr);
}

int array_size_get(char **array)
{
    int size = 0;

    while (array[size] != NULL)
        size++;
    return (size);
}
