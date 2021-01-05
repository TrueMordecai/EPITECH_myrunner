/*
** EPITECH PROJECT, 2021
** runner
** File description:
** reset map and player
*/

#include "runner.h"

static void reset_map_2(game_t *game)
{
    game->scene = SCENE_GAME;
    HUD->pos = vector_create(566, -662);
    HUD->vect = vector_create(0, 10);
    game->info->is_win = false;
    input_index(game);
    sfSprite_setScale(PLAYER->sprite, vector_create(1, 1));
    sfSprite_setOrigin(PLAYER->sprite, vector_create(0, 0));
    sfSprite_setRotation(PLAYER->sprite, 0);
    PLAYER->vect = vector_create(BASIC_PLAYER_X_SPEED, BASIC_PLAYER_Y_SPEED);
}

void reset_map(game_t *game)
{
    uint line = 1;
    uint col = 1;

    reset_map_2(game);
    for (EACH_BLOCK_ON_MAP) {
        BLOCK->pos = vector_create(col * 128 + 272 - INFO->starting_position.x *
        128, line * 128 + 472 - INFO->starting_position.y * 128);
        sfSprite_setPosition(BLOCK->sprite, BLOCK->pos);
        sfSprite_setScale(BLOCK->sprite, vector_create(1, 1));
        if (BLOCK->type == 8 || BLOCK->type == 10) BLOCK->type--;
        if (BLOCK->type == BT_SPE_COINS_FOUND) BLOCK->type = BT_SPE_COINS;
        if (BLOCK->type == 12) BLOCK->type = BT_SPE_JUMPER_ORB;
        if (BLOCK->type == BT_SPE_VICTORY)
            sfSprite_setScale(BLOCK->sprite, vector_create(2, 2));
        if (game->info->map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    sfSprite_setPosition(BACKGROUND->sprite, vector_create(BG_STARTING_POS));
    sfSprite_setOrigin(PLAYER->sprite, vector_create(64, 64));
}

