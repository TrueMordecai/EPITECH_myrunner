/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "runner.h"
#include <stdio.h>

void reset_map(game_t *game)
{
    uint line = 1;
    uint col = 1;
    for EACH_BLOCK_ON_MAP {
        BLOCK->pos = vector_create((col * 128) + (300 - 128) - INFO->starting_position.x * 128,
                                   (line * 128) + (700 - 128) - INFO->starting_position.y * 128);
        sfSprite_setPosition(BLOCK->sprite, BLOCK->pos);
        if (game->info->map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    PLAYER->vect = vector_create(BASIC_PLAYER_X_SPEED, BASIC_PLAYER_Y_SPEED);
    sfSprite_setPosition(BACKGROUND->sprite, vector_create(0, 0));
}

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
            if ((PLAYER_LEFT_SIDE  >= BLOCK_LEFT_SIDE && PLAYER_LEFT_SIDE <= BLOCK_RIGHT_SIDE))
                if (PLAYER_TOP_SIDE < BLOCK_BOT_SIDE && PLAYER_TOP_SIDE >= BLOCK_TOP_SIDE)
                    if (BLOCK->space == false)
                        return (true);
            if ((PLAYER_RIGHT_SIDE  >= BLOCK_LEFT_SIDE && PLAYER_RIGHT_SIDE <= BLOCK_RIGHT_SIDE))
                if (PLAYER_TOP_SIDE < BLOCK_BOT_SIDE && PLAYER_TOP_SIDE >= BLOCK_TOP_SIDE)
                    if (BLOCK->space == false)
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

void get_input(game_t *game)
{

    if (sfKeyboard_isKeyPressed(INPUT->jump_key) && is_in_the_air(game) == false)
        INPUT->jump_state = PRESS;
    else
        INPUT->jump_state = UNPRESS;
}

void player_display(game_t *game)
{
    sfRenderWindow_drawSprite(RENDER_WINDOW, PLAYER->sprite, NULL);
}

void gravity_update(game_t *game)
{
    PLAYER_Y_SPEED += BASIC_PLAYER_GRAVITY;
    if (PLAYER_Y_SPEED > BASIC_PLAYER_MAX_GRAVITY)
        PLAYER_Y_SPEED = BASIC_PLAYER_MAX_GRAVITY;
}

void map_display_update(game_t *game)
{
    if (!is_in_the_air(game)) {
        PLAYER_Y_SPEED = 0;
        sfSprite_setRotation(PLAYER->sprite, 0);
        if (INPUT->jump_state == PRESS)
            PLAYER_Y_SPEED -= BASIC_PLAYER_JUMP_HEIGHT;
    }
    gravity_update(game);
    for EACH_BLOCK_ON_MAP { /// LOOP IF PLAYER OVEREXTEND IN A BLOCK
            if (BLOCK->space == false && PLAYER_BOT_SIDE + PLAYER_Y_SPEED > BLOCK_TOP_SIDE && PLAYER_BOT_SIDE < BLOCK_BOT_SIDE && is_align(PLAYER, BLOCK))
                PLAYER_Y_SPEED = BLOCK_TOP_SIDE - PLAYER_BOT_SIDE;
        }
    for EACH_BLOCK_ON_MAP /// LOOP APLYING GRAVITY TO BLOCK
        BLOCK->pos.y -= PLAYER_Y_SPEED;
}

void map_display_enlighten(game_t *game, entity_t *block)
{
    if (block->type != BT_BASIC)
        return;
    sfSprite_setPosition(INFO->enlight_block->sprite, vector_create(block->pos.x - 2, block->pos.y - 2));
    sfRenderWindow_drawSprite(RENDER_WINDOW, INFO->enlight_block->sprite, NULL);
}

void map_display(game_t *game)
{
    map_display_update(game);

    for EACH_BLOCK_ON_MAP {
            game->map[i]->pos.x -= PLAYER_X_SPEED;
            map_display_enlighten(game, BLOCK);
            sfSprite_setPosition(game->map[i]->sprite, game->map[i]->pos);
            sfRenderWindow_drawSprite(RENDER_WINDOW, game->map[i]->sprite, NULL);
        }
}

void background_display(game_t *game)
{
    sfSprite_move(BACKGROUND->sprite, vector_create(-(PLAYER->vect.x / 4), -(PLAYER->vect.y / 4)));
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->background->sprite, NULL);
}

int main_loop(void)
{
    game_t *game = game_init();

    if (!game)
        return (0);

    while (sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse) {
        if (sfKeyboard_isKeyPressed(sfKeyB) || is_player_dead(game))
            reset_map(game);
        get_input(game);
        background_display(game);
        player_display(game);
        map_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
    return (1);
}
