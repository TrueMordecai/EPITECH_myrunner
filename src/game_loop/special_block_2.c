/*
** EPITECH PROJECT, 2021
** runner
** File description:
** special block 2
*/

#include "runner.h"

static void special_block_apply_coins_animation(entity_t *block)
{
    block->time = sfClock_getElapsedTime(block->clock);
    block->seconds = sfTime_asSeconds(block->time);
    if (float_comparison(block->seconds, 0, 0.3))
        block->rect = rect_create(0, 128 * 0, 128, 128);
    if (float_comparison(block->seconds, 0.3, 0.6))
        block->rect = rect_create(0, 128 * 1, 128, 128);
    if (float_comparison(block->seconds, 0.6, 0.9))
        block->rect = rect_create(0, 128 * 2, 128, 128);
    if (float_comparison(block->seconds, 0.9, 1.2))
        block->rect = rect_create(0, 128 * 3, 128, 128);
    if (block->seconds > 1.2)
        sfClock_restart((block->clock));
    sfSprite_setTextureRect(block->sprite, block->rect);
}

static void special_block_apply_coins(game_t *game, entity_t *block)
{

    if (block->type == BT_SPE_COINS || block->type ==BT_SPE_COINS_FOUND)
        special_block_apply_coins_animation(block);
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_COINS) {
        block->type = BT_SPE_COINS_FOUND;
        sfSprite_setTextureRect(block->sprite, rect_create(0, 128, 128, 128));
        INFO->coins_founds++;
        block->vect = vector_create(0, -45);
    }
    if (block->type == BT_SPE_COINS_FOUND) {
        block->pos.x += block->vect.x;
        block->pos.y += block->vect.y;
        block->vect.y += 3;
    }
}

void special_block_apply_2(game_t *game, entity_t *block)
{
    special_block_apply_coins(game, block);
}
