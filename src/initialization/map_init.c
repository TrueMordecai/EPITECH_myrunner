/*
** EPITECH PROJECT, 2020
** map_init
** File description:
** init map
*/

#include "runner.h"

entity_t **map_init(char const *map, sfVector2f starting_position)
{
    entity_t **block = malloc(sizeof(entity_t*) * (my_strlen(map) + 1));
    int col = 1;
    int line = 1;
    sfTexture *texture_temp = sfTexture_createFromFile("image/basic.png", NULL);

    for (uint i = 0; map[i] != '\0'; i++) {
        block[i] = malloc(sizeof(entity_t));
        block[i]->sprite = sfSprite_create();
        block[i]->space = true;
        if (map[i] == '*') {
            sfSprite_setTexture(block[i]->sprite, texture_temp, sfTrue);
            block[i]->space = false;
        }
        block[i]->pos = vector_create((col * 128) + (300 - 128) - starting_position.x * 128,
                                      (line * 128) + (700 - 128) - starting_position.y * 128);
        sfSprite_setPosition(block[i]->sprite, block[i]->pos);
        if (map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    block[my_strlen(map)] = NULL;
    return (block);
}
