/*
** EPITECH PROJECT, 2020
** runner
** File description:
** collections of functiuns that check the of the game
*/

#include "runner.h"

bool is_align(entity_t *p, entity_t *b)
{
    if (b->space == true)
        return false;
    if (p->pos.x >= b->pos.x && p->pos.x <= b->pos.x + 128)
        return (true);
    if (p->pos.x + 128 >= b->pos.x && p->pos.x + 128 <= b->pos.x + 128)
        return (true);

    return (false);
}

bool is_player_in_block(entity_t *p, entity_t *b)
{
    if (p->pos.x > b->pos.x && p->pos.x + 128 < b->pos.x)
        if (p->pos.y >= b->pos.y && p->pos.y < b->pos.y + 128)
            return (true);
    if (p->pos.x + 128 >= b->pos.x && p->pos.x + 128 <= b->pos.x + 128)
        if (p->pos.y >= b->pos.y && p->pos.y < b->pos.y + 128)
            return (true);
    if (p->pos.x > b->pos.x && p->pos.x + 128 < b->pos.x)
        if (p->pos.y + 128 >= b->pos.y && p->pos.y + 128 <= b->pos.y + 128)
            return (true);
    if (p->pos.x + 128 >= b->pos.x && p->pos.x + 128 <= b->pos.x + 128)
        if (p->pos.y + 128 >= b->pos.y && p->pos.y + 128 <= b->pos.y + 128)
            return (true);
    return (false);
}

static bool is_player_dead2(game_t *game, uint i)
{
    if ((PLAYER_BOT_SIDE + PLAYER_Y_SPEED >= BLOCK_TOP_SIDE) &&\
        (PLAYER_BOT_SIDE + PLAYER_Y_SPEED <= BLOCK_BOT_SIDE) &&\
        BLOCK->type == BT_SPIKE)
        if (PLAYER_RIGHT_SIDE >= BLOCK_LEFT_SIDE &&\
            PLAYER_RIGHT_SIDE <= BLOCK_RIGHT_SIDE)
            return (true);
    if ((PLAYER_LEFT_SIDE >= BLOCK_LEFT_SIDE &&\
        PLAYER_LEFT_SIDE <= BLOCK_RIGHT_SIDE) &&\
        (BLOCK->type == false || BLOCK->type == BT_SPIKE))
        if (PLAYER_TOP_SIDE < BLOCK_BOT_SIDE &&\
            PLAYER_TOP_SIDE >= BLOCK_TOP_SIDE)
            return (true);
    if ((PLAYER_RIGHT_SIDE >= BLOCK_LEFT_SIDE &&\
        PLAYER_RIGHT_SIDE <= BLOCK_RIGHT_SIDE))
        if (PLAYER_TOP_SIDE < BLOCK_BOT_SIDE &&\
            PLAYER_TOP_SIDE >= BLOCK_TOP_SIDE &&\
            (BLOCK->type == false || BLOCK->type == BT_SPIKE))
            return (true);
    return (false);
}

bool is_player_dead(game_t *game)
{
    for (EACH_BLOCK_ON_MAP) {
        if (is_player_dead2(game, i)) {
            return (true);
        }
    }
    return (false);
}

bool is_in_the_air(game_t *game)
{
    for (EACH_BLOCK_ON_MAP) {
        if (BLOCK->space == false && PLAYER_BOT_SIDE == BLOCK_TOP_SIDE &&\
        is_align(PLAYER, BLOCK)) {
            return (false);
        }
    }
    return (true);
}
