/*
** EPITECH PROJECT, 2020
** runner
** File description:
** map_info_init
*/

#include "runner.h"

static sfVector2f starting_position_get(char const *map)
{
    sfVector2f starting_position = {0, 0};

    for (int i = 0; map[i] != 'P'; i++) {
        starting_position.x++;
        if (map[i] == '\n') {
            starting_position.y++;
            starting_position.x = 0;
        }
    }
    return (starting_position);
}

map_info_t *map_info_init(char const *map)
{
    map_info_t *info = malloc(sizeof(map_info_t));

    info->starting_position = starting_position_get(map);
    info->map = map;
    info->index_under = 0;
    return (info);
}
