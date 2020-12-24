/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "runner.h"
#include <stdio.h>

void reset_map(game_t *game)
{
    uint line = 1;
    uint col = 1;
    for EACH_BLOCK_ON_MAP {
        BLOCK->pos = vector_create((col * 128) + (400 - 128) - INFO->starting_position.x * 128,
                                   (line * 128) + (600 - 128) - INFO->starting_position.y * 128);
        sfSprite_setPosition(BLOCK->sprite, BLOCK->pos);
        sfSprite_setScale(BLOCK->sprite, vector_create(1, 1));
        if (BLOCK->type == BT_SPE_SPEED_DOWN_USED || BLOCK->type == BT_SPE_SPEED_UP_USED)
            BLOCK->type--;
        if (game->info->map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    PLAYER->vect = vector_create(BASIC_PLAYER_X_SPEED, BASIC_PLAYER_Y_SPEED);
    sfSprite_setPosition(BACKGROUND->sprite, vector_create(0, 0));
}

int main_loop(char const *path)
{
    game_t *game = game_init(path);

    if (!game)
        return (0);

    while (sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse) {
        if (INPUT->reset->key_state == PRESS || is_player_dead(game))
            reset_map(game);
        input_index(game);
        background_display(game);
        player_display(game);
        map_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
    return (1);
}
