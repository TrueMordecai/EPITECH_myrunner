/*
** EPITECH PROJECT, 2020
** runner
** File description:
** collections of functiuns that check the of the game
*/

#include "runner.h"

bool is_align(entity_t *player, entity_t *block)
{
    if (block->space == true)
        return false;
    if (player->pos.x >= block->pos.x && player->pos.x <= block->pos.x + 128)
        return (true);
    if (player->pos.x + 128 >= block->pos.x && player->pos.x + 128 <= block->pos.x + 128)
        return (true);

    return (false);
}

bool is_player_dead(game_t *game)
{
    for EACH_BLOCK_ON_MAP {
            if ((PLAYER_BOT_SIDE + PLAYER_Y_SPEED >= BLOCK_TOP_SIDE) && (PLAYER_BOT_SIDE + PLAYER_Y_SPEED <= BLOCK_BOT_SIDE))
                if (PLAYER_RIGHT_SIDE >= BLOCK_LEFT_SIDE && PLAYER_RIGHT_SIDE <= BLOCK_RIGHT_SIDE)
                    if (BLOCK->type == BT_SPIKE)
                        return (true);
            if ((PLAYER_LEFT_SIDE  >= BLOCK_LEFT_SIDE && PLAYER_LEFT_SIDE <= BLOCK_RIGHT_SIDE))
                if (PLAYER_TOP_SIDE < BLOCK_BOT_SIDE && PLAYER_TOP_SIDE >= BLOCK_TOP_SIDE)
                    if (BLOCK->space == false || BLOCK->type == BT_SPIKE)
                        return (true);
            if ((PLAYER_RIGHT_SIDE  >= BLOCK_LEFT_SIDE && PLAYER_RIGHT_SIDE <= BLOCK_RIGHT_SIDE))
                if (PLAYER_TOP_SIDE < BLOCK_BOT_SIDE && PLAYER_TOP_SIDE >= BLOCK_TOP_SIDE)
                    if (BLOCK->space == false || BLOCK->type == BT_SPIKE)
                        return (true);
        }
    return (false);
}

bool is_in_the_air(game_t *game)
{
    for EACH_BLOCK_ON_MAP { /// THE IF IS TRUE IF PLAYER IS ON A BLOCK
            if (BLOCK->space == false && PLAYER_BOT_SIDE == BLOCK_TOP_SIDE && is_align(PLAYER, BLOCK)) {
                return (false);
            }
        }
    return (true);
}
