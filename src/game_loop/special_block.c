/*
** EPITECH PROJECT, 2020
** runner
** File description:
** special_block
*/

#include "runner.h"

static void special_block_apply_speed_changer(game_t *game, entity_t *block)
{
    if (block->type == BT_SPE_SPEED_UP || block->type == BT_SPE_SPEED_UP_USED)
        block->rect.left -= 5;
    if (block->type == BT_SPE_SPEED_DOWN || block->type == BT_SPE_SPEED_DOWN)
        block->rect.left += 5;
    if (block->type >= BT_SPE_SPEED_UP && block->type <= BT_SPE_SPEED_DOWN_USED)
        sfSprite_setTextureRect(block->sprite, block->rect);
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_SPEED_UP) {
        PLAYER->vect.x += 10;
        if (PLAYER->vect.x > 60)
            PLAYER->vect.x -= 10;
        block->type = BT_SPE_SPEED_UP_USED;
        return;
    }
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_SPEED_DOWN) {
        PLAYER->vect.x -= 10;
        if (PLAYER->vect.x < 10)
            PLAYER->vect.x += 10;
        block->type = BT_SPE_SPEED_DOWN_USED;
        return;
    }
}

void special_block_apply_jumper_animate(entity_t *block)
{
    block->time = sfClock_getElapsedTime(block->clock);
    block->seconds = sfTime_asSeconds(block->time);
    if (float_comparison(block->seconds, 0, 0.1))
        sfSprite_setScale(block->sprite, vector_create(1.05, 1.1));
    if (float_comparison(block->seconds, 0.1, 0.2))
        sfSprite_setScale(block->sprite, vector_create(1.1, 1.05));
    if (float_comparison(block->seconds, 0.2, 0.3))
        sfSprite_setScale(block->sprite, vector_create(1.2, 0.95));
    if (float_comparison(block->seconds, 0.3, 0.4))
        sfSprite_setScale(block->sprite, vector_create(0.95, 0.9));
    if (block->seconds > 0.4)
        sfClock_restart((block->clock));
    sfSprite_rotate(block->sprite, 1);
}

static void special_block_apply_jumper(game_t *game, entity_t *block)
{
    if (block->type == BT_SPE_JUMPER_ORB) {
        special_block_apply_jumper_animate(block);
    }
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_JUMPER_ORB &&
    (INPUT->jump->key_state == PRESS || INPUT->jump->key_state == 2)) {
        block->type = BT_SPE_JUMPER_ORB_USED;
        sfSprite_scale(block->sprite, vector_create(1.3, 1.3));
        PLAYER->vect.y = BASIC_PLAYER_JUMP_HEIGHT * -1;
    }
}

static void special_block_apply_victory(game_t *game, entity_t *block)
{
    if (block->type != BT_SPE_VICTORY)
        return;
    if (block->pos.x < 1500)
        block->pos.x -= -10;
    if (PLAYER_RIGHT_SIDE - 34 > block->pos.x)
        INFO->is_win = true;
    block->pos.y = PLAYER->pos.y - 128;
}

void special_block_apply(game_t *game, entity_t *block)
{
    special_block_apply_jumper(game, block);
    special_block_apply_speed_changer(game, block);
    special_block_apply_victory(game, block);
    special_block_apply_2(game, block);
}
