/*
** EPITECH PROJECT, 2020
** runner
** File description:
** death_effect
*/

#include "runner.h"

entity_t *death_effect_init(void)
{
    entity_t *death_effect = malloc(sizeof(entity_t));

    death_effect->sprite = sfSprite_create();
    death_effect->texture = sfTexture_createFromFile(PATH_DEATH, NULL);
    death_effect->clock = sfClock_create();
    death_effect->seconds = 0;
    death_effect->rect = rect_create(0, 0, 43, 52);
    death_effect->space = false;
    sfSprite_setScale(death_effect->sprite, vector_create(3, 3));
    sfSprite_setTexture(death_effect->sprite, death_effect->texture, sfFalse);
    return (death_effect);
}
