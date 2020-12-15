/*
** EPITECH PROJECT, 2020
** runner
** File description:
** player init
*/

#include "runner.h"

entity_t *player_init()
{
    entity_t *player = malloc(sizeof(entity_t));

    player->sprite = sfSprite_create();
    player->scale = vector_create(0.5, 0.5);
    player->rect = rect_create(0, 0, 121, 121);
    player->texture = sfTexture_createFromFile("image/cube.png", NULL);
    player->pos = vector_create(300, 700);
    player->vect = vector_create(SPEED, 2);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, player->scale);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    return (player);
}
