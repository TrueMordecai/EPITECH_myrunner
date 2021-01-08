/*
** EPITECH PROJECT, 2021
** runner
** File description:
** display intro
*/

#include "runner.h"

void display_intro_parralax(game_t *game)
{
    for (uint i = 0; i != 4; i++) {
        INTRO->background[i]->pos.x -= (i + 1);
        sfSprite_setPosition(INTRO->background[i]->sprite,
        INTRO->background[i]->pos);
        sfRenderWindow_drawSprite(RENDER_WINDOW,
        INTRO->background[i]->sprite, NULL);
    }
}

static void display_intro_player_update(game_t *game)
{
    sfVector2f pps = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f sps = sfSprite_getPosition(INTRO->spike->sprite);

    if (pps.x + 128 >= sps.x && pps.x + 128 <= sps.x + 128 && pps.y > 472) {
        sfSprite_setPosition(DEATH->sprite, pps);
        sfSprite_setPosition(PLAYER->sprite, vector_create(400, -140));
        DEATH->space = true;
        death_effect_display(game);
        return;
    }
    PLAYER->vect.y += 1;
    if (INPUT->jump->key_state == PRESS &&
        sfSprite_getPosition(PLAYER->sprite).y == BASIC_PLAYER_Y_POS)
        PLAYER->vect.y = -20;
    if (sfSprite_getPosition(PLAYER->sprite).y + PLAYER->vect.y >= 600)
        PLAYER->vect.y = 600 - sfSprite_getPosition(PLAYER->sprite).y;
    sfSprite_move(PLAYER->sprite, PLAYER->vect);
}

static void display_intro_spike(game_t *game)
{
    if (rand() % 100 == 0 && INTRO->spike->space == false) {
        sfSprite_setPosition(INTRO->spike->sprite, vector_create(2500, 600));
        INTRO->spike->space = true;
    }
    if (INTRO->spike->space == true) {
        sfSprite_move(INTRO->spike->sprite, vector_create(-20, 0));
        sfSprite_setColor(INTRO->platform->sprite,
        color_create(100, 100, 100, 255));
        sfSprite_setPosition(INTRO->platform->sprite,
        vector_create(sfSprite_getPosition(INTRO->spike->sprite).x - 400, 728));
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->platform->sprite, NULL);
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->spike->sprite, NULL);
    }
    if (sfSprite_getPosition(INTRO->spike->sprite).x <= -500) {
        INTRO->spike->space = false;
    }
}

char *char_to_str(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = '\0';
    return(str);
}


static void display_intro_text_animate(game_t *game)
{
    INTRO->text->time = sfClock_getElapsedTime(INTRO->text->clock);
    INTRO->text->second = sfTime_asSeconds(INTRO->text->time);
    if (INTRO->text->second > 0.04) {
        INTRO->text->index_up++;
        sfClock_restart((INTRO->text->clock));
    }
    if (INTRO->text->index_up >= my_strlen(INTRO->text->str))
        INTRO->text->index_up = 0;
}

void display_intro_text_anim(game_t *game)
{
    display_intro_text_animate(game);
    for (int i = 0; INTRO->text->str[i] != '\0'; i++) {
        sfText_setPosition(INTRO->text->text_info, INTRO->text->vect[i]);
        sfText_move(INTRO->text->text_info, vector_create(0,
        (((my_compute_power_it((INTRO->text->index_up - 10), 3)) - (INTRO->text->index_up - 10) * 100)) / 20));
        if (INTRO->text->index_up == i)
            sfText_move(INTRO->text->text_info, vector_create(0, -5));
        if (INTRO->text->index_up >= i - 1 && INTRO->text->index_up <= i + 1)
            sfText_move(INTRO->text->text_info, vector_create(0, -5));
        if (INTRO->text->index_up >= i - 2 && INTRO->text->index_up <= i + 2)
            sfText_move(INTRO->text->text_info, vector_create(0, -5));
        sfText_setScale(INTRO->text->text_info, vector_create(1, 1));
        sfText_setColor(INTRO->text->text_info, color_create(200, 245, 90, 255));
        sfText_setCharacterSize(INTRO->text->text_info, 50);
        sfText_setOutlineColor(INTRO->text->text_info, sfBlack);
        sfText_setOutlineThickness(INTRO->text->text_info, 3);
        sfText_setString(INTRO->text->text_info, char_to_str(INTRO->text->str[i]));
        sfRenderWindow_drawText(RENDER_WINDOW, INTRO->text->text_info, NULL);
        sfText_setString(INTRO->text->text_info, char_to_str('m'));
        sfText_setCharacterSize(INTRO->text->text_info, 30);
        sfText_setScale(INTRO->text->text_info, vector_create(5, -2.3));
        sfText_setColor(INTRO->text->text_info, color_create(0, 0, 0, 40));
        sfText_setOutlineThickness(INTRO->text->text_info, 0);
        sfText_move(INTRO->text->text_info, vector_create(-70, 110));
        sfRenderWindow_drawText(RENDER_WINDOW, INTRO->text->text_info, NULL);
        sfText_setScale(INTRO->text->text_info, vector_create(1, 1));
        sfText_setColor(INTRO->text->text_info, color_create(200, 245, 90, 0));
        sfText_setCharacterSize(INTRO->text->text_info, 50);
        sfText_setOutlineColor(INTRO->text->text_info, sfWhite);
        sfText_setOutlineThickness(INTRO->text->text_info, 1);
        sfText_setString(INTRO->text->text_info, char_to_str(INTRO->text->str[i]));
        sfText_move(INTRO->text->text_info, vector_create(70, -110));
        sfRenderWindow_drawText(RENDER_WINDOW, INTRO->text->text_info, NULL);
    }
}

static void display_intro_change_color(game_t *game)
{
    sfColor color = sfSprite_getColor(PLAYER->sprite);

    if (INPUT->change_color[R]->key_state == ALREADY_PRESS)
        color.r++;
    if (INPUT->change_color[G]->key_state == ALREADY_PRESS)
        color.g++;
    if (INPUT->change_color[B]->key_state == ALREADY_PRESS)
        color.b++;
    sfSprite_setColor(PLAYER->sprite, color);
}

char *int_to_str(int i)
{
    char *str = malloc(sizeof(char) * 4);

    str[0] = i / 100 % 10 + '0';
    str[1] = i / 10 % 10 + '0';
    str[2] = i % 10 + '0';
    str[3] = '\0';
    return (str);
}

static void display_intro_text_rgb(game_t *game)
{
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1130, 200));
    sfText_setCharacterSize(INTRO->rgb->text_info, 50);
    sfText_setString(INTRO->rgb->text_info, "Change skin with S");
    sfText_setColor(INTRO->rgb->text_info, sfWhite);
    sfText_setColor(INTRO->rgb->text_info, sfWhite);
    sfText_setOutlineThickness(INTRO->rgb->text_info, 5);
    sfText_setOutlineColor(INTRO->rgb->text_info, sfBlack);
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    if (sfSprite_getColor(PLAYER->sprite).r + sfSprite_getColor(PLAYER->sprite).g + sfSprite_getColor(PLAYER->sprite).a > 760)
        sfText_setOutlineThickness(INTRO->rgb->text_info, 0);
    else
        sfText_setOutlineThickness(INTRO->rgb->text_info, 2);
     sfText_setString(INTRO->rgb->text_info, INTRO->rgb->str);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(900, 300));
    sfText_setString(INTRO->rgb->text_info, "Press I O P to change color R G B");
    sfText_setOutlineColor(INTRO->rgb->text_info, sfSprite_getColor(PLAYER->sprite));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1000, 400));
    sfText_setString(INTRO->rgb->text_info, "R : ");
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_move(INTRO->rgb->text_info, vector_create(50, 0));
    sfText_setString(INTRO->rgb->text_info, int_to_str(sfSprite_getColor(PLAYER->sprite).r));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1300, 400));
    sfText_setString(INTRO->rgb->text_info, "G : ");
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_move(INTRO->rgb->text_info, vector_create(50, 0));
    sfText_setString(INTRO->rgb->text_info, int_to_str(sfSprite_getColor(PLAYER->sprite).g));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1600, 400));
    sfText_setString(INTRO->rgb->text_info, "B : ");
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_move(INTRO->rgb->text_info, vector_create(50, 0));
    sfText_setString(INTRO->rgb->text_info, int_to_str(sfSprite_getColor(PLAYER->sprite).b));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
}

static void display_intro_loop(game_t *game)
{
    while (INPUT->skip->key_state != PRESS && INPUT->exit->key_state != 2) {
        if (sfSprite_getPosition(HUD->sprite).y > -800)
            sfSprite_move(HUD->sprite, vector_create(0, -15));
        if (INPUT->skin_change->key_state == PRESS)
            PLAYER->rect.left += 128;
        PLAYER->rect.left >= 128 * 10? PLAYER->rect.left = 0: PLAYER->rect.left;
        input_index(game);
        display_intro_spike(game);
        display_intro_parralax(game);
        display_intro_player_update(game);
        display_intro_text_anim(game);
        display_intro_text_rgb(game);
        player_display(game);
        display_intro_change_color(game);
        sfSprite_setColor(INTRO->platform->sprite, color_create(255, 255, 255,
        (600 - sfSprite_getPosition(PLAYER->sprite).y) * -1 + 220));
        sfSprite_setPosition(INTRO->platform->sprite, vector_create(80, 728));
        sfRenderWindow_drawSprite(RENDER_WINDOW, HUD->sprite, NULL);
        sfRenderWindow_drawSprite(RENDER_WINDOW, INTRO->platform->sprite, NULL);
        death_effect_display(game);
        sfRenderWindow_display(RENDER_WINDOW);
        sfRenderWindow_clear(RENDER_WINDOW, sfBlack);
    }
}

void display_intro(game_t *game)
{
    game->scene = SCENE_INTRO;
    PLAYER->vect = vector_create(0, 0);
    sfSprite_setScale(PLAYER->sprite, vector_create(1, 1));
    sfSprite_setOrigin(PLAYER->sprite, vector_create(64, 64));
    sfSprite_setRotation(PLAYER->sprite, 0);
    sfSprite_setPosition(PLAYER->sprite, vector_create(400, -140));
    INTRO->spike->space = false;
    display_intro_loop(game);
    PLAYER->vect.x = BASIC_PLAYER_X_SPEED;
    sfSprite_setPosition(PLAYER->sprite, vector_create(400, 600));
}
