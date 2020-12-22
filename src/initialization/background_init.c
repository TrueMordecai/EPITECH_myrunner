/*
** EPITECH PROJECT, 2020
** runner
** File description:
** background init
*/

#include "runner.h"

entity_t *background_init(void)
{
    entity_t *background = malloc(sizeof(entity_t));

    background->sprite = sfSprite_create();
    background->texture = sfTexture_createFromFile("image/backgrounds/bg1hd.png", NULL);
    sfTexture_setRepeated(background->texture, sfTrue);
    sfSprite_setColor(background->sprite, color_create(255, 150, 150, 255));
    sfSprite_setScale(background->sprite, vector_create(BACKGROUND_SCALE));
    sfSprite_setPosition(background->sprite, vector_create(BACKGROUND_STARTING_POS));
    sfSprite_setTextureRect(background->sprite, rect_create(LARGE_BACKGROUND_RECT));
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    return (background);
}
