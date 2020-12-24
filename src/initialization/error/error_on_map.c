/*
** EPITECH PROJECT, 2020
** runner
** File description:
** error
*/

#include "runner.h"

static bool is_error_map_player_spawn(char const *map)
{
    int count_spawn = 0;

    for (uint i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            count_spawn++;
    }
    if (count_spawn != 1) {
        return (true);
    }
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
    if (is_error_map_player_spawn(map))
        return (true);
    if (is_error_map_last_line(map))
        return (true);
    return (false);
}
