/*
** EPITECH PROJECT, 2020
** runner
** File description:
** display player + gravity update
*/

#include "runner.h"

void gravity_update(game_t *game)
{
    PLAYER_Y_SPEED += BASIC_PLAYER_GRAVITY;
    if (PLAYER_Y_SPEED > BASIC_PLAYER_MAX_GRAVITY)
        PLAYER_Y_SPEED = BASIC_PLAYER_MAX_GRAVITY;
}

void player_display(game_t *game)
{
    sfRenderWindow_drawSprite(RENDER_WINDOW, PLAYER->sprite, NULL);
}
