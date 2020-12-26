/*
** EPITECH PROJECT, 2020
** runner
** File description:
** hud init
*/

#include "runner.h"

entity_t *hud_init(void)
{
    entity_t *hud = malloc(sizeof(entity_t));

    hud->sprite = sfSprite_create();
    hud->texture = sfTexture_createFromFile("image/menu.png", NULL);
    sfSprite_setTexture(hud->sprite, hud->texture, sfTrue);
    sfSprite_setPosition(hud->sprite, vector_create(0, -1000));
    return (hud);
}
