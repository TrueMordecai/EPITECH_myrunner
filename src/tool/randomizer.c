/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** randomizer
*/

#include "my_hunter.h"

sfVector2f speed_randomizer_particle(void)
{
    float x = (rand() % 40) / 15 + 3;
    float y = (rand() % 40) / 15 + 3;

    if (rand() % 2 == 0)
        x *= -1;
    if (rand() % 2 == 0)
        y *= -1;
    return (vector_create(x, y));
}

sfVector2f position_randomizer_particle(entity_t *entity)
{
    float x = (rand() % entity->rect.width * entity->scale.x) + entity->pos.x;
    float y = (rand() % entity->rect.height * entity->scale.y) + entity->pos.y;

    return (vector_create(x, y));
}

sfVector2f speed_randomizer(void)
{
    float x = (rand() % 4) + 1.5;
    float y = (rand() % 4) + 1.5;

    if (rand() % 2 == 0)
        x *= -1;
    if (rand() % 2 == 0)
        y *= -1;
    return (vector_create(x, y));
}

sfVector2f position_randomizer(entity_t *e)
{
    float x = (rand() % (int)(1920 - e->rect.left * e->scale.x - 600)) + 500;
    float y = (rand() % (int)(1080 - e->rect.height * e->scale.y - 50));

    return (vector_create(x, y));
}
