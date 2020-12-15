/*
** EPITECH PROJECT, 2020
** runner
** File description:
** map_info_init
*/

#include "runner.h"

map_info_t *map_info_init(void)
{
    map_info_t *info = malloc(sizeof(map_info_t));

    info->index_under = 0;
    return (info);
}
