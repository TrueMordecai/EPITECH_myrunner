/*
** EPITECH PROJECT, 2021
** runner
** File description:
** display intro 3
*/

#include "runner.h"

void display_intro_parralax(game_t *game)
{
    for (uint i = 0; i != 4; i++) {
        INTRO->background[i]->pos.x -= (i + 1);
        sfSprite_setPosition(INTRO->background[i]->sprite,
        INTRO->background[i]->pos);
        sfRenderWindow_drawSprite(RENDER_WINDOW,
        INTRO->background[i]->sprite, NULL);
    }
}

void display_intro_player_update(game_t *game)
{
    sfVector2f pps = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f sps = sfSprite_getPosition(INTRO->spike->sprite);

    if (pps.x + 128 >= sps.x && pps.x + 128 <= sps.x + 128 && pps.y > 472) {
        sfSprite_setPosition(DEATH->sprite, pps);
        sfSprite_setPosition(PLAYER->sprite, vector_create(400, -140));
        DEATH->space = true;
        death_effect_display(game);
        return;
    }
    PLAYER->vect.y += 1;
    if (INPUT->jump->key_state == PRESS &&
        sfSprite_getPosition(PLAYER->sprite).y == BASIC_PLAYER_Y_POS)
        PLAYER->vect.y = -20;
    if (sfSprite_getPosition(PLAYER->sprite).y + PLAYER->vect.y >= 600)
        PLAYER->vect.y = 600 - sfSprite_getPosition(PLAYER->sprite).y;
    sfSprite_move(PLAYER->sprite, PLAYER->vect);
}

void display_intro_spike(game_t *game)
{
    if (rand() % 100 == 0 && INTRO->spike->space == false) {
        sfSprite_setPosition(INTRO->spike->sprite, vector_create(2500, 600));
        INTRO->spike->space = true;
    }
    if (INTRO->spike->space == true) {
        sfSprite_move(INTRO->spike->sprite, vector_create(-20, 0));
        sfSprite_setColor(INTRO->platform->sprite,
        color_create(100, 100, 100, 255));
        sfSprite_setPosition(INTRO->platform->sprite,
        vector_create(sfSprite_getPosition(INTRO->spike->sprite).x - 400, 728));
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->platform->sprite, NULL);
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->spike->sprite, NULL);
    }
    if (sfSprite_getPosition(INTRO->spike->sprite).x <= -500) {
        INTRO->spike->space = false;
    }
}
