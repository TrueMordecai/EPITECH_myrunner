/*
** EPITECH PROJECT, 2020
** runner
** File description:
** map_info_init
*/

#include "runner.h"

static sfVector2f map_info_init_get_starting_position(char const *map)
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

static entity_t *map_info_init_set_enlight(void)
{
    entity_t *enlighten = malloc(sizeof(entity_t));

    enlighten->sprite = sfSprite_create();
    enlighten->texture =  sfTexture_createFromFile("image/enlighten.png", sfFalse);
    sfSprite_setTexture(enlighten->sprite, enlighten->texture, sfFalse);
    sfSprite_setColor(enlighten->sprite, color_create(255, 255, 255, 255));
    return(enlighten);
}

map_info_t *map_info_init(char const *map)
{
    map_info_t *info = malloc(sizeof(map_info_t));

    info->starting_position = map_info_init_get_starting_position(map);
    info->map = map;
    info->index_under = 0;
    info->enlight_block = map_info_init_set_enlight();
    info->coins_founds = 0;
    return (info);
}
