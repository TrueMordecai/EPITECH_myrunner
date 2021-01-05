/*
** EPITECH PROJECT, 2020
** runner
** File description:
** error
*/

#include "runner.h"

static bool is_error_map_not_enough_tag(char const *map, char tag, int u)
{
    int count_tag = 0;

    for (uint i = 0; map[i] != '\0'; i++) {
        if (map[i] == tag)
            count_tag++;
    }
    if (count_tag != u)
        return (true);
    return (false);
}

static bool is_error_map_last_line(char const *map)
{
    if (map[my_strlen(map)- 1] != '\n')
        return (true);
    return (false);
}

bool is_error_map(char const *map)
{
    if (is_error_map_not_enough_tag(map, 'C', 3))
        return (true);
    if (is_error_map_not_enough_tag(map, 'V', 1))
        return (true);
    if (is_error_map_not_enough_tag(map, 'P', 1))
        return (true);
    if (is_error_map_last_line(map))
        return (true);
    return (false);
}
