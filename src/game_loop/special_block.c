/*
** EPITECH PROJECT, 2020
** runner 
** File description:
** special_block
*/

#include "runner.h"

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

void special_block_apply(game_t *game, entity_t *block)
{
    special_block_apply_speed_changer(game, block);
}
