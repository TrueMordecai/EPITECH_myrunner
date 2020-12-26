/*
** EPITECH PROJECT, 2020
** runner
** File description:
** special_block
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
        sfSprite_setTextureRect(block->sprite, rect_create(0, 128 * 1, 128, 128));
        INFO->coins_founds++;
        block->vect = vector_create(0, -45);
    }
    if (block->type == BT_SPE_COINS_FOUND) {
        block->pos.x += block->vect.x;
        block->pos.y += block->vect.y;
        block->vect.y += 3;
    }
}

static void special_block_apply_speed_changer(game_t *game, entity_t *block)
{
    if (block->type == BT_SPE_SPEED_UP)
        block->rect.left -= 5;
    if (block->type == BT_SPE_SPEED_DOWN)
        block->rect.left += 5;
    if (block->type >= BT_SPE_SPEED_UP && block->type <= BT_SPE_SPEED_DOWN_USED)
        sfSprite_setTextureRect(block->sprite, block->rect);
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
    if (is_player_in_block(PLAYER, block) && block->type == BT_SPE_JUMPER_ORB && (INPUT->jump->key_state == PRESS || INPUT->jump->key_state == ALREADY_PRESS)) {
        block->type = BT_SPE_JUMPER_ORB_USED;
        sfSprite_scale(block->sprite, vector_create(1.3, 1.3));
        PLAYER->vect.y = BASIC_PLAYER_JUMP_HEIGHT * -1;
    }
}

static void special_block_apply_victory(game_t *game, entity_t *block)
{
    if (block->type != BT_SPE_VICTORY)
        return;
    block->pos.y = PLAYER->pos.y - 64;

    if (block->pos.x < 1500)
        block->pos.x -= -10;
    if (is_player_in_block(PLAYER, block))
        INFO->is_win = true;
}

void special_block_apply(game_t *game, entity_t *block)
{
    special_block_apply_jumper(game, block);
    special_block_apply_speed_changer(game, block);
    special_block_apply_coins(game, block);
    special_block_apply_victory(game, block);
}
