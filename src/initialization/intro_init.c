/*
** EPITECH PROJECT, 2020
** runner.h
** File description:
** intro init
*/

#include "runner.h"

static entity_t *intro_init_background(char const *path)
{
    entity_t *back = malloc(sizeof(entity_t));

    back->sprite = sfSprite_create();
    back->texture = sfTexture_createFromFile(path, NULL);
    sfTexture_setRepeated(back->texture, sfTrue);
    sfSprite_setTextureRect(back->sprite, rect_create(LARGE_BACKGROUND_RECT));
    back->pos = vector_create(0, 0);
    sfSprite_setTexture(back->sprite, back->texture, sfFalse);
    sfSprite_setPosition(back->sprite, back->pos);
    sfSprite_setScale(back->sprite, vector_create(5, 5));
    return (back);
}

static entity_t *intro_init_platform(void)
{
    entity_t *platform = malloc(sizeof(entity_t));

    platform->sprite = sfSprite_create();
    platform->texture = sfTexture_createFromFile("image/intro_platform.png", NULL);
    sfSprite_setTexture(platform->sprite, platform->texture, sfFalse);
    sfSprite_setPosition(platform->sprite, vector_create(80, BASIC_PLAYER_Y_POSITION + 128));
    sfSprite_setColor(platform->sprite, color_create(255, 255, 255, 255));
    sfSprite_setScale(platform->sprite, vector_create(1, 1));
    return (platform);
}

static entity_t *intro_init_spike(void)
{
    entity_t *spike = malloc(sizeof(entity_t));

    spike->sprite = sfSprite_create();
    spike->texture = sfTexture_createFromFile("image/spike.png", NULL);
    spike->vect = vector_create(0, -2);
    spike->space = false;
    sfSprite_setTexture(spike->sprite, spike->texture, sfFalse);
    sfSprite_setPosition(spike->sprite, vector_create(-400, -400));
    sfSprite_setColor(spike->sprite, color_create(255, 255, 255, 255));
    sfSprite_setScale(spike->sprite, vector_create(1, 1));
    return (spike);
}

intro_t *intro_init(void) {
    intro_t *intro = malloc(sizeof(intro_t));

    intro->background = malloc(sizeof(entity_t *) * 4);
    intro->background[0] = intro_init_background("image/intro/background_1.png");
    intro->background[1] = intro_init_background("image/intro/background_2.png");
    intro->background[2] = intro_init_background("image/intro/background_3.png");
    intro->background[3] = intro_init_background("image/intro/background_4.png");
    intro->platform = intro_init_platform();
    intro->spike = intro_init_spike();
    return (intro);
}
