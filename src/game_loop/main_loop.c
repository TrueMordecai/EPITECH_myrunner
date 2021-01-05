/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "runner.h"
#include <stdio.h>

void hud_display(game_t *game)
{
    sfSprite_setOrigin(PLAYER->sprite, vector_create(64, 64));
    if (HUD->pos.y + HUD->vect.y < 0) {
        HUD->pos.y += HUD->vect.y;
        HUD->vect.y *= 1.06;
    }
    PLAYER->vect.y = 0;
    sfSprite_rotate(PLAYER->sprite, -2);
    if (PLAYER->vect.x > 20)
        PLAYER->vect.x = 20;
    else
        PLAYER->vect.x -= 0.3;
    sfSprite_scale(PLAYER->sprite, vector_create(0.8, 0.8));
    sfSprite_setPosition(game->hud->sprite, game->hud->pos);
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->hud->sprite, NULL);
}

void display_level(game_t *game)
{
    while (INPUT->quit->key_state != PRESS && INPUT->exit->key_state != 2) {
        if (INPUT->reset->key_state == PRESS || is_player_dead(game))
            reset_map(game);
        input_index(game);
        background_display(game);
        player_display(game);
        map_display(game);
        if (INFO->is_win)
            hud_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
}

bool portal_position_found_and_valid(game_t *game)
{
    INFO->victory_index = 0;
    for (EACH_BLOCK_ON_MAP)
        if (BLOCK->type == BT_SPE_VICTORY)
            INFO->victory_index = i;
    for (EACH_BLOCK_ON_MAP)
        if (BLOCK_LEFT_SIDE > game->map[INFO->victory_index]->pos.x &&
        BLOCK->space == false) {
            my_put_nbr(i);
            my_putstr("The portal isn't well placed, check -h\n");
            return (false);
        }
    return (true);
}

int main_loop(char const *path)
{
    game_t *game = game_init(path);

    if (!game)
        return (0);
    if (!portal_position_found_and_valid(game))
        return (0);
    while (!sfKeyboard_isKeyPressed(sfKeyEscape)) {
        display_intro(game);
        reset_map(game);
        display_level(game);
    }
    return (1);
}
