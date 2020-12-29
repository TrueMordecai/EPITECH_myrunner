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
    hud->texture = sfTexture_createFromFile("image/end_menu.png", NULL);
    hud->vect = vector_create(0, 10);
    sfSprite_setTexture(hud->sprite, hud->texture, sfTrue);
    hud->pos = vector_create(566, -682);
    sfSprite_setPosition(hud->sprite, hud->pos);
    return (hud);
}
