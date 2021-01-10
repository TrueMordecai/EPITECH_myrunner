/*
** EPITECH PROJECT, 2021
** runner
** File description:
** display intro
*/

#include "runner.h"

static void display_intro_change_color(game_t *game)
{
    sfColor color = sfSprite_getColor(PLAYER->sprite);

    if (INPUT->change_color[R]->key_state == ALREADY_PRESS)
        color.r++;
    if (INPUT->change_color[G]->key_state == ALREADY_PRESS)
        color.g++;
    if (INPUT->change_color[B]->key_state == ALREADY_PRESS)
        color.b++;
    sfSprite_setColor(PLAYER->sprite, color);
}

static void display_intro_loop_index(game_t *game)
{
    display_intro_spike(game);
    display_intro_parralax(game);
    display_intro_player_update(game);
    display_intro_text_anim(game);
    display_intro_text_rgb(game);
    player_display(game);
    display_intro_change_color(game);
}

static void display_intro_loop(game_t *game)
{
    sfMusic_play(INFO->mus_intro);
    while (INPUT->skip->key_state != PRESS && INPUT->exit->key_state != 2 &&
    sfRenderWindow_isOpen(RENDER_WINDOW)) {
        if (sfSprite_getPosition(HUD->sprite).y > -800)
            sfSprite_move(HUD->sprite, vector_create(0, -15));
        if (INPUT->skin_change->key_state == PRESS)
            PLAYER->rect.left += 128;
        PLAYER->rect.left >= 128 * 10? PLAYER->rect.left = 0: PLAYER->rect.left;
        input_index(game);
        display_intro_loop_index(game);
        sfSprite_setColor(INTRO->platform->sprite, color_create(255, 255, 255,
        (600 - sfSprite_getPosition(PLAYER->sprite).y) * -1 + 220));
        sfSprite_setPosition(INTRO->platform->sprite, vector_create(80, 728));
        sfRenderWindow_drawSprite(RENDER_WINDOW, HUD->sprite, NULL);
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->platform->sprite, NULL);
        death_effect_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
    sfMusic_stop(INFO->mus_intro);
}

void display_intro(game_t *game)
{
    game->scene = SCENE_INTRO;
    PLAYER->vect = vector_create(0, 0);
    sfSprite_setScale(PLAYER->sprite, vector_create(1, 1));
    sfSprite_setOrigin(PLAYER->sprite, vector_create(64, 64));
    sfSprite_setRotation(PLAYER->sprite, 0);
    sfSprite_setPosition(PLAYER->sprite, vector_create(400, -140));
    INTRO->spike->space = false;
    display_intro_loop(game);
    PLAYER->vect.x = BASIC_PLAYER_X_SPEED;
    sfSprite_setPosition(PLAYER->sprite, vector_create(400, 600));
}
