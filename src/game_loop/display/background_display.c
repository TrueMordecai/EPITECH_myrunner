/*
** EPITECH PROJECT, 2020
** runner
** File description:
** backgroud display
*/

#include "runner.h"

void background_display(game_t *game)
{
    sfSprite_move(BACKGROUND->sprite, vector_create(-(PLAYER->vect.x / 4), -(PLAYER->vect.y / 4)));
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->background->sprite, NULL);
}
