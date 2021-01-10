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
    sfSprite_setTextureRect(back->sprite, rect_create(LARGE_BG_RECT));
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
    platform->texture = sfTexture_createFromFile(PATH_INTRO_PLATFORM, NULL);
    sfSprite_setTexture(platform->sprite, platform->texture, sfFalse);
    sfSprite_setPosition(platform->sprite, vector_create(80, \
    BASIC_PLAYER_Y_POS + 128));
    sfSprite_setColor(platform->sprite, color_create(255, 255, 255, 255));
    sfSprite_setScale(platform->sprite, vector_create(1, 1));
    sfSprite_setOrigin(platform->sprite, vector_create(64, 64));
    return (platform);
}

static entity_t *intro_init_spike(void)
{
    entity_t *spike = malloc(sizeof(entity_t));

    spike->sprite = sfSprite_create();
    spike->texture = sfTexture_createFromFile(PATH_SPIKE, NULL);
    spike->vect = vector_create(0, -2);
    spike->space = false;
    sfSprite_setTexture(spike->sprite, spike->texture, sfFalse);
    sfSprite_setPosition(spike->sprite, vector_create(-400, -400));
    sfSprite_setColor(spike->sprite, color_create(255, 255, 255, 255));
    sfSprite_setScale(spike->sprite, vector_create(1, 1));
    sfSprite_setOrigin(spike->sprite, vector_create(64, 64));
    return (spike);
}

static text_anim_t *text_anim_init(char *str, char const *font_path, sfColor co)
{
    text_anim_t *text_anim = malloc(sizeof(text_anim_t));

    text_anim->clock = sfClock_create();
    text_anim->str = my_strdup(str);
    text_anim->second = 0;
    text_anim->time = sfClock_getElapsedTime(text_anim->clock);
    text_anim->text_info = sfText_create();
    sfText_setFont(text_anim->text_info, sfFont_createFromFile(font_path));
    sfText_setColor(text_anim->text_info, sfGreen);
    sfText_setCharacterSize(text_anim->text_info, 50);
    sfText_setOutlineColor(text_anim->text_info, co);
    text_anim->index_up = 0;
    sfText_setOutlineThickness(text_anim->text_info, 1);
    text_anim->vect = malloc(sizeof(sfVector2f*) * my_strlen(str));
    for (uint i = 0; str[i]; i++) {
        text_anim->vect[i] = vector_create(1040 + 35 * i, 100);
    }
    return (text_anim);
}

intro_t *intro_init(void)
{
    intro_t *intro = malloc(sizeof(intro_t));

    intro->background = malloc(sizeof(entity_t *) * 4);
    intro->background[0] = intro_init_background(PATH_BG1);
    intro->background[1] = intro_init_background(PATH_BG2);
    intro->background[2] = intro_init_background(PATH_BG3);
    intro->background[3] = intro_init_background(PATH_BG4);
    intro->text = text_anim_init("PRESS ENTER TO PLAY!", \
    "./font/oxy.ttf", sfGreen);
    intro->rgb = text_anim_init("Press S to change skin", \
    "./font/pus.otf", sfBlack);
    intro->platform = intro_init_platform();
    intro->spike = intro_init_spike();
    return (intro);
}
