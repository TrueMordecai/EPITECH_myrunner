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
        if ((INPUT->jump->key_state == PRESS || \
            INPUT->jump->key_state == ALREADY_PRESS) && !is_in_the_air(game))
            PLAYER_Y_SPEED -= BASIC_PLAYER_JUMP_HEIGHT;
    }
    gravity_update(game);
    for (EACH_BLOCK_ON_MAP) {
        if (!BLOCK->space && PLAYER_BOT_SIDE + PLAYER_Y_SPEED > BLOCK_TOP_SIDE\
            && PLAYER_BOT_SIDE < BLOCK_BOT_SIDE && is_align(PLAYER, BLOCK))
            PLAYER_Y_SPEED = BLOCK_TOP_SIDE - PLAYER_BOT_SIDE;
    }
    for (EACH_BLOCK_ON_MAP)
        if (BLOCK->type != BT_SPE_COINS_FOUND)
            BLOCK->pos.y -= PLAYER_Y_SPEED;
}

static void map_display_enlighten(game_t *game, entity_t *block)
{
    if (block->type != BT_BASIC)
        return;
    sfSprite_setPosition(INFO->enlight_block->sprite, \
    vector_create(block->pos.x - 2, block->pos.y - 2));
    sfSprite_setOrigin(INFO->enlight_block->sprite, vector_create(64, 64));
    sfRenderWindow_drawSprite(RENDER_WINDOW,    \
    INFO->enlight_block->sprite, NULL);}

static void map_display_disapear_effect(entity_t *block)
{
    if (block->pos.x >= 150 || block->type == BT_SPACE ||   \
        block->type == BT_SPE_COINS_FOUND)
        return;
    if (block->pos.y < 500)
        block->pos.y -= 20;
    else
        block->pos.y += 20;
    sfSprite_scale(block->sprite, vector_create(0.95, 0.95));
}

static void map_display_portal(game_t *game, entity_t *block)
{
    sfSprite_setPosition(INFO->portal1->sprite, block->pos);
    sfSprite_setPosition(INFO->portal2->sprite, block->pos);
    sfSprite_move(INFO->portal2->sprite, vector_create(-113, -93));
    sfRenderWindow_drawSprite(RENDER_WINDOW, INFO->portal2->sprite, 0);
    sfRenderWindow_drawSprite(RENDER_WINDOW, INFO->portal1->sprite, 0);
}

void map_display(game_t *game)
{
    map_display_update(game);
    for (EACH_BLOCK_ON_MAP) {
        if (BLOCK->type != BT_SPE_COINS_FOUND) BLOCK->pos.x -= PLAYER_X_SPEED;
        special_block_apply(game, BLOCK);
        map_display_disapear_effect(BLOCK);
        map_display_enlighten(game, BLOCK);
        sfSprite_setPosition(BLOCK->sprite, BLOCK->pos);
        if (BLOCK->type == BT_SPE_VICTORY)
            map_display_portal(game, BLOCK);
        sfRenderWindow_drawSprite(RENDER_WINDOW, game->map[i]->sprite, 0);
    }
}
