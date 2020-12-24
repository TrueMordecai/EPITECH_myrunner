/*
** EPITECH PROJECT, 2020
** runner
** File description:
** special_block
*/

#include "runner.h"

static void special_block_apply_coins(game_t *game, entity_t *block)
{
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_COINS) {
        block->type = BT_SPE_COINS_FOUND;
    }
    if (block->type == BT_SPE_COINS_FOUND) {
        block->pos.x = 0 + block->pos.x / 1.1;
        block->pos.y = 0 + block->pos.y / 1.1;
    }
}

static void special_block_apply_speed_changer(game_t *game, entity_t *block)
{
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_SPEED_UP) {
        PLAYER->vect.x += 10;
        if (PLAYER->vect.x > 60)
            PLAYER->vect.x -= 10;
        block->type = BT_SPE_SPEED_UP_USED;
    }
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_SPEED_DOWN) {
        PLAYER->vect.x -= 10;
        if (PLAYER->vect.x < 10)
            PLAYER->vect.x += 10;
        block->type = BT_SPE_SPEED_DOWN_USED;
    }
}

static void special_block_apply_jumper(game_t *game, entity_t *block)
{
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_JUMPER_ORB && INPUT->jump->key_state == PRESS) {
        sfSprite_scale(block->sprite, vector_create(1.5, 1.5));
        PLAYER->vect.y = BASIC_PLAYER_JUMP_HEIGHT * -1;
    }
}

void special_block_apply(game_t *game, entity_t *block)
{
    special_block_apply_jumper(game, block);
    special_block_apply_speed_changer(game, block);
    special_block_apply_coins(game, block);
}
