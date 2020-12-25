/*
** EPITECH PROJECT, 2020
** runner
** File description:
** map display related func
*/

#include "runner.h"

static void map_display_update(game_t *game)
{
    if (!is_in_the_air(game)) {
        PLAYER_Y_SPEED = 0;
        sfSprite_setRotation(PLAYER->sprite, 0);
        if ((INPUT->jump->key_state == PRESS ||  INPUT->jump->key_state == ALREADY_PRESS) && !is_in_the_air(game))
            PLAYER_Y_SPEED -= BASIC_PLAYER_JUMP_HEIGHT;
    }
    gravity_update(game);
    for EACH_BLOCK_ON_MAP { /// LOOP IF PLAYER OVEREXTEND IN A BLOCK
            if (BLOCK->space == false && PLAYER_BOT_SIDE + PLAYER_Y_SPEED > BLOCK_TOP_SIDE && PLAYER_BOT_SIDE < BLOCK_BOT_SIDE && is_align(PLAYER, BLOCK))
                PLAYER_Y_SPEED = BLOCK_TOP_SIDE - PLAYER_BOT_SIDE;
        }
    for EACH_BLOCK_ON_MAP /// LOOP APLYING GRAVITY TO BLOCK
        if (BLOCK->type != BT_SPE_COINS_FOUND)
            BLOCK->pos.y -= PLAYER_Y_SPEED;
}

static void map_display_enlighten(game_t *game, entity_t *block)
{
    if (block->type != BT_BASIC)
        return;
    sfSprite_setPosition(INFO->enlight_block->sprite, vector_create(block->pos.x - 2, block->pos.y - 2));
    sfRenderWindow_drawSprite(RENDER_WINDOW, INFO->enlight_block->sprite, NULL);}

static void map_display_disapear_effect(entity_t *block)
{
    if (block->pos.x >= 150 || block->type == BT_SPACE || block->type == BT_SPE_COINS_FOUND)
        return;
    if (block->pos.y < 500)
        block->pos.y -= 20;
    else
        block->pos.y += 20;
    sfSprite_scale(block->sprite, vector_create(0.95, 0.95));
}

void map_display(game_t *game)
{
    map_display_update(game);

    for EACH_BLOCK_ON_MAP {
            if (BLOCK->type != BT_SPE_COINS_FOUND)
                BLOCK->pos.x -= PLAYER_X_SPEED;
            special_block_apply(game, BLOCK);
            map_display_disapear_effect(BLOCK);
            map_display_enlighten(game, BLOCK);
            if (BLOCK->type == BT_SPE_JUMPER_ORB || BLOCK->type == BT_SPE_JUMPER_ORB_USED) {
                sfSprite_setPosition(BLOCK->sprite, vector_create(BLOCK->pos.x + 64, BLOCK->pos.y + 64));
            } else
                sfSprite_setPosition(game->map[i]->sprite, game->map[i]->pos);
            sfRenderWindow_drawSprite(RENDER_WINDOW, game->map[i]->sprite, NULL);
        }
}
