/*
** EPITECH PROJECT, 2020
** runner
** File description:
** backgroud display
*/

#include "runner.h"

static void background_display_portal_effect(game_t *game)
{
    INFO->portal2->rect.left -= 1;
    sfSprite_setTextureRect(INFO->portal2->sprite, INFO->portal2->rect);
}

void background_display(game_t *game)
{
    sfSprite_move(BACKGROUND->sprite, vector_create(-(PLAYER->vect.x / 4), -(PLAYER->vect.y / 4)));
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->background->sprite, NULL);
    background_display_portal_effect(game);
}
