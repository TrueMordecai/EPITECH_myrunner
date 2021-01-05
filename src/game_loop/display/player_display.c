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

static void player_display_rotation_set(game_t *game)
{
    float r = (int)sfSprite_getRotation(PLAYER->sprite) % 90;
    float true_r = (int)sfSprite_getRotation(PLAYER->sprite);

    if (is_in_the_air(game)) {
        sfSprite_rotate(PLAYER->sprite, 6);
        return;
    }
    if (r <= 85 && r != 0 && r >= 45) {
        sfSprite_rotate(PLAYER->sprite, 5);
        return;
    }
    if (r > 5 && r < 45) {
        sfSprite_rotate(PLAYER->sprite, -5);
        return;
    }
    if (float_comparison(true_r, -5, 5) || float_comparison(true_r, 355, 365)) {
        sfSprite_setRotation(PLAYER->sprite, 0);
    }
    if (float_comparison(true_r, 84, 96))
        sfSprite_setRotation(PLAYER->sprite, 90);
    if (float_comparison(true_r, 174, 186))
        sfSprite_setRotation(PLAYER->sprite, 180);
    if (float_comparison(true_r, 264, 276))
        sfSprite_setRotation(PLAYER->sprite, 270);
}

void player_display(game_t *game)
{
    player_display_rotation_set(game);
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
    sfRenderWindow_drawSprite(RENDER_WINDOW, PLAYER->sprite, NULL);
}
