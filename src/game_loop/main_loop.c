/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** main loop of my hunter
*/

#include "runner.h"
#include <stdio.h>

void map_update(game_t *game)
{
//    if (INFO->index_under != -1 && game->map[INFO->index_under]->pos.y < BOT_PLAYER_SIDE + PLAYER->vect.y)
//        PLAYER->vect.y = game->map[INFO->index_under]->pos.y - BOT_PLAYER_SIDE;
//    my_put_nbr(PLAYER->vect.y);
    for EACH_BLOCK_ON_MAP {
            MAP_ELEMENT->pos.y -= PLAYER->vect.y;
            sfSprite_setPosition(MAP_ELEMENT->sprite, MAP_ELEMENT->pos);
        }
}

bool is_in_the_air(game_t *game)
{
    if (INFO->index_under == -1)
        return (true);
    if (BOT_PLAYER_SIDE <= game->map[INFO->index_under]->pos.y - 10)
        return (true);
    return (false);
}

bool is_align(entity_t *player, entity_t *block)
{
    if (block->space == true)
        return false;
    if (player->pos.x >= block->pos.x && player->pos.x <= block->pos.x + 128 * 0.4) {
        return (true);
    }
    if (player->pos.x + player->rect.width * player->scale.x >= block->pos.x && player->pos.x + player->rect.width * player->scale.x <= block->pos.x + 128 * 0.4) {
        return (true);
    }
    return (false);
}

int found_underneath(game_t *game)
{
    INFO->index_under = -1;
    for EACH_BLOCK_ON_MAP
        if (is_align(PLAYER, MAP_ELEMENT)) {
            INFO->index_under = i;
            break;
        }
    if (INFO->index_under == 0)
        return (-1);
    for EACH_BLOCK_ON_MAP
        if (is_align(PLAYER, MAP_ELEMENT) && game->map[INFO->index_under]->pos.y >= MAP_ELEMENT->pos.y) {
            INFO->index_under = i;
        }
    if (INFO->index_under == 0)
        return (-1);
    return (INFO->index_under);
}

void player_update(game_t *game)
{
    found_underneath(game);

    if (is_in_the_air(game) || INPUT->jump_state == PRESS)
        PLAYER->vect.y += 1;
    else
        PLAYER->vect.y = 0;
    map_update(game);
    sfSprite_setPosition(PLAYER->sprite, PLAYER->pos);
}

void player_display(game_t *game)
{
    if (INPUT->jump_state == PRESS && is_in_the_air(game) == false)
        PLAYER->vect.y -= 20;
    player_update(game);
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->player->sprite, NULL);
}

void get_input(game_t *game)
{

    if (sfKeyboard_isKeyPressed(INPUT->jump_key) && is_in_the_air(game) == false)
        INPUT->jump_state = PRESS;
    else
        INPUT->jump_state = UNPRESS;
/*    if (INPUT->jump_state == PRESS && sfKeyboard_isKeyPressed(INPUT->jump_key))
        INPUT->jump_state = ALREADY_PRESS;
    if (sfKeyboard_isKeyPressed(INPUT->jump_key) && INPUT->jump_state != ALREADY_PRESS)
        INPUT->jump_state = PRESS;
    if (sfKeyboard_isKeyPressed(INPUT->jump_key) == sfFalse)
        INPUT->jump_state = UNPRESS;*/
}

void map_display(game_t *game)
{
    for (int i = 0; game->map[i] != 0; i++) {
        game->map[i]->pos.x -= SPEED;
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
        get_input(game);
        player_display(game);
        map_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
    return (1);
}
