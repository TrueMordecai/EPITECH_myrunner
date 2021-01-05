/*
** EPITECH PROJECT, 2020
** runner
** File description:
** player init
*/

#include "runner.h"

entity_t *player_init(void)
{
    entity_t *player = malloc(sizeof(entity_t));

    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile(PLAYER_TEXTURE_PATH, NULL);
    player->pos = vector_create(BASIC_PLAYER_X_POS, BASIC_PLAYER_Y_POS);
    player->vect = vector_create(BASIC_PLAYER_X_SPEED, BASIC_PLAYER_Y_SPEED);
    player->rect = rect_create(0, 0, 128, 128);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, vector_create(64, 64));
    return (player);
}
