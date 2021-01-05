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
    enlighten->texture = sfTexture_createFromFile(PATH_LIGHT, sfFalse);
    sfSprite_setTexture(enlighten->sprite, enlighten->texture, sfFalse);
    sfSprite_setColor(enlighten->sprite, color_create(255, 255, 255, 255));
    sfSprite_setOrigin(enlighten->sprite, vector_create(64, 64));
    return (enlighten);
}

static entity_t *map_info_init_portal_1(void)
{
    entity_t *portal1 = malloc(sizeof(entity_t));

    portal1->sprite = sfSprite_create();
    portal1->texture = sfTexture_createFromFile(PATH_PORTAL1, sfFalse);
    sfSprite_setTexture(portal1->sprite, portal1->texture, sfFalse);
    sfSprite_setScale(portal1->sprite, vector_create(2, 2));
    sfSprite_setOrigin(portal1->sprite, vector_create(64, 64));
    return (portal1);
}

static entity_t *map_info_init_portal_2(void)
{
    entity_t *portal2 = malloc(sizeof(entity_t));

    portal2->sprite = sfSprite_create();
    portal2->texture = sfTexture_createFromFile(PATH_EFFECT, sfFalse);
    sfTexture_setRepeated(portal2->texture, sfTrue);
    portal2->rect = rect_create(0, 0, 115, 36);
    sfSprite_setScale(portal2->sprite, vector_create(2, 2));
    sfSprite_setTexture(portal2->sprite, portal2->texture, sfFalse);
    return (portal2);
}

map_info_t *map_info_init(char const *map)
{
    map_info_t *info = malloc(sizeof(map_info_t));

    info->starting_position = map_info_init_get_starting_position(map);
    info->portal1 = map_info_init_portal_1();
    info->portal2 = map_info_init_portal_2();
    info->map = map;
    info->index_under = 0;
    info->enlight_block = map_info_init_set_enlight();
    info->coins_founds = 0;
    info->is_win = false;
    return (info);
}
