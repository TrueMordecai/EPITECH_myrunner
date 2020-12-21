/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "runner.h"
#include <stdio.h>

bool is_in_the_air(game_t *game)
{
    for EACH_BLOCK_ON_MAP { /// THE IF IS TRUE IF PLAYER IS ON A BLOCK
            if (BLOCK->space == false && PLAYER_BOT_SIDE == BLOCK_TOP_SIDE && is_align(PLAYER, BLOCK)) {

            }
        }
}
bool is_align(entity_t *player, entity_t *block)
{
    if (block->space == true)
        return false;
    if (player->pos.x >= block->pos.x && player->pos.x <= block->pos.x + 128)
        return (true);
    return (false);
}


/*
void found_underneath(game_t *game)
{
    INFO->index_under = -1;

    for EACH_BLOCK_ON_MAP
        if (is_align(PLAYER, MAP_ELEMENT) && BOT_PLAYER_SIDE < TOP_BLOCK_SIDE) {
            INFO->index_under = i;
            break;
        }
}

void player_update(game_t *game)
{
    DEBUG(game);
    found_underneath(game);
//    if (!is_in_the_air(game))
    //      PLAYER->vect.y = 0;
    if (is_in_the_air(game) || INPUT->jump_state == PRESS) {
        PLAYER->vect.y += 1;
    } else {
        PLAYER->vect.y = 0;
    }
    map_update(game);
    sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
}



void player_display(game_t *game)
{
    if (INPUT->jump_state == PRESS && is_in_the_air(game) == false)
        PLAYER->vect.y -= 25;
    player_update(game);
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->player->sprite, NULL);
}

void get_input(game_t *game)
{

    if (sfKeyboard_isKeyPressed(INPUT->jump_key) && is_in_the_air(game) == false)
        INPUT->jump_state = PRESS;
    else
        INPUT->jump_state = UNPRESS;
}
*/

void player_display(game_t *game)
{
    sfRenderWindow_drawSprite(RENDER_WINDOW, PLAYER->sprite, NULL);
}

void map_display_update(game_t *game)
{
    for EACH_BLOCK_ON_MAP { /// THE IF IS TRUE IF PLAYER IS ON A BLOCK
            if (BLOCK->space == false && PLAYER_BOT_SIDE == BLOCK_TOP_SIDE && is_align(PLAYER, BLOCK)) {
                PLAYER_Y_SPEED = 0;
                return;
            }
        }
    PLAYER_Y_SPEED += 1;
    for EACH_BLOCK_ON_MAP { /// LOOP IF PLAYER OVEREXTEND IN A BLOCK
            if (BLOCK->space == false && PLAYER_BOT_SIDE + PLAYER_Y_SPEED > BLOCK_TOP_SIDE && PLAYER_BOT_SIDE < BLOCK_BOT_SIDE && is_align(PLAYER, BLOCK)) {
                PLAYER_Y_SPEED = BLOCK_TOP_SIDE - PLAYER_BOT_SIDE;
            }
        }
    for EACH_BLOCK_ON_MAP { /// LOOP APLYING GRAVITY TO BLOCK
            BLOCK->pos.y -= PLAYER_Y_SPEED;
        }
}

void map_display(game_t *game)
{
    map_display_update(game);

    for EACH_BLOCK_ON_MAP {
        game->map[i]->pos.x -= PLAYER_X_SPEED;
        sfSprite_setPosition(game->map[i]->sprite, game->map[i]->pos);
        sfRenderWindow_drawSprite(RENDER_WINDOW, game->map[i]->sprite, NULL);
    }
}


int main_loop(void)
{
    game_t *game = game_init();

    if (!game)
        return (0);

    while (sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse) {
//        get_input(game);
        player_display(game);
        map_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
    return (1);
}
