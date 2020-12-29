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

    HUD->pos = vector_create(566 , -662);
    HUD->vect = vector_create(0, 10);
    game->info->is_win = false;
    for EACH_BLOCK_ON_MAP {
        BLOCK->pos = vector_create((col * 128) + (400 - 128) - INFO->starting_position.x * 128,
                                   (line * 128) + (600 - 128) - INFO->starting_position.y * 128);
        sfSprite_setPosition(BLOCK->sprite, BLOCK->pos);
        sfSprite_setScale(BLOCK->sprite, vector_create(1, 1));
        if (BLOCK->type == BT_SPE_SPEED_DOWN_USED || BLOCK->type == BT_SPE_SPEED_UP_USED)
            BLOCK->type--;
        if (BLOCK->type == BT_SPE_COINS_FOUND)
            BLOCK->type = BT_SPE_COINS;
        if (BLOCK->type == BT_SPE_JUMPER_ORB_USED)
            BLOCK->type = BT_SPE_JUMPER_ORB;
        if (BLOCK->type == BT_SPE_VICTORY)
            sfSprite_setScale(BLOCK->sprite, vector_create(2, 2));
        if (game->info->map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    PLAYER->vect = vector_create(BASIC_PLAYER_X_SPEED, BASIC_PLAYER_Y_SPEED);
    sfSprite_setPosition(BACKGROUND->sprite, vector_create(0, 0));
}

void hud_display(game_t *game)
{
    sfSprite_setOrigin(PLAYER->sprite, vector_create(64, 64));
    if (HUD->pos.y + HUD->vect.y < 0) {
        HUD->pos.y += HUD->vect.y;
        HUD->vect.y *= 1.06;
    }
    PLAYER->vect.y = 0;
    sfSprite_rotate(PLAYER->sprite, -2);
    if (PLAYER->vect.x > 20)
        PLAYER->vect.x = 20;
    else
        PLAYER->vect.x -= 0.3;
    sfSprite_scale(PLAYER->sprite, vector_create(0.8, 0.8));
    sfSprite_setPosition(game->hud->sprite, game->hud->pos);
    sfRenderWindow_drawSprite(RENDER_WINDOW, game->hud->sprite, NULL);
}


void display_level(game_t *game)
{
    while (sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse) {
        if (INPUT->reset->key_state == PRESS || is_player_dead(game))
            reset_map(game);
        input_index(game);
        background_display(game);
        player_display(game);
        map_display(game);
        if (INFO->is_win)
            hud_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
}

static void display_intro_parralax(game_t *game)
{
    for (uint i = 0; i != 4; i++) {
        INTRO->background[i]->pos.x -= (i + 1);
        sfSprite_setPosition(INTRO->background[i]->sprite, INTRO->background[i]->pos);
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->background[i]->sprite, NULL);
    }
}

static void display_intro_player_update(game_t *game)
{
    PLAYER->vect.y += 1;
    if (INPUT->jump->key_state == PRESS && sfSprite_getPosition(PLAYER->sprite).y == BASIC_PLAYER_Y_POSITION)
        PLAYER->vect.y = -20;
    if (sfSprite_getPosition(PLAYER->sprite).y + PLAYER->vect.y >= BASIC_PLAYER_Y_POSITION)
        PLAYER->vect.y = BASIC_PLAYER_Y_POSITION - sfSprite_getPosition(PLAYER->sprite).y;
    sfSprite_move(PLAYER->sprite, PLAYER->vect);
}

void display_intro(game_t *game)
{
    PLAYER->vect = vector_create(0, 0);
    while (!sfKeyboard_isKeyPressed(sfKeyEnter)) {
        input_index(game);
        sfSprite_setColor(INTRO->platform->sprite, color_create(255, 255, 255, (600 - sfSprite_getPosition(PLAYER->sprite).y) * -1 + 220));
        display_intro_parralax(game);
        display_intro_player_update(game);
        player_display(game);
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->platform->sprite, NULL);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
    PLAYER->vect.x = BASIC_PLAYER_X_SPEED;
    sfSprite_setPosition(PLAYER->sprite, vector_create(BASIC_PLAYER_X_POSITION, BASIC_PLAYER_Y_POSITION));
}

int main_loop(char const *path)
{
    game_t *game = game_init(path);

    if (!game)
        return (0);
    INFO->victory_index = 0;
    for EACH_BLOCK_ON_MAP
        if (BLOCK->type == BT_SPE_VICTORY)
            INFO->victory_index = i;
    display_intro(game);
    display_level(game);
    return (1);
}
