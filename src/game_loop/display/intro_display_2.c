/*
** EPITECH PROJECT, 2021
** runner
** File description:
** intro display2
*/

#include "runner.h"
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

void display_intro_text_anim_2(game_t *game, int i)
{
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->text->text_info, NULL);
    sfText_setString(INTRO->text->text_info, char_str('m'));
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
    sfText_setString(INTRO->text->text_info, char_str(INTRO->text->str[i]));
    sfText_move(INTRO->text->text_info, vector_create(70, -110));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->text->text_info, NULL);
}

void display_intro_text_anim(game_t *game)
{
    display_intro_text_animate(game);
    for (int i = 0; INTRO->text->str[i] != '\0'; i++) {
        sfText_setPosition(INTRO->text->text_info, INTRO->text->vect[i]);
        sfText_move(INTRO->text->text_info, vector_create(0,
        (((my_compute_power_it((INTRO->text->index_up - 10), 3)) - \
        (INTRO->text->index_up - 10) * 100)) / 20));
        if (INTRO->text->index_up == i)
            sfText_move(INTRO->text->text_info, vector_create(0, -5));
        if (INTRO->text->index_up >= i - 1 && INTRO->text->index_up <= i + 1)
            sfText_move(INTRO->text->text_info, vector_create(0, -5));
        if (INTRO->text->index_up >= i - 2 && INTRO->text->index_up <= i + 2)
            sfText_move(INTRO->text->text_info, vector_create(0, -5));
        sfText_setScale(INTRO->text->text_info, vector_create(1, 1));
        sfText_setColor(INTRO->text->text_info, CC(200, 245, 90, 255));
        sfText_setCharacterSize(INTRO->text->text_info, 50);
        sfText_setOutlineColor(INTRO->text->text_info, sfBlack);
        sfText_setOutlineThickness(INTRO->text->text_info, 3);
        sfText_setString(INTRO->text->text_info, char_str(INTRO->text->str[i]));
        display_intro_text_anim_2(game, i);
    }
}

static void display_intro_text_rgb_2(game_t *game)
{
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1000, 400));
    sfText_setString(INTRO->rgb->text_info, "R : ");
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_move(INTRO->rgb->text_info, vector_create(50, 0));
    sfText_setString(INTRO->rgb->text_info, int_to_str(GC(PLAYER->sprite).r));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1300, 400));
    sfText_setString(INTRO->rgb->text_info, "G : ");
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_move(INTRO->rgb->text_info, vector_create(50, 0));
    sfText_setString(INTRO->rgb->text_info, int_to_str(GC(PLAYER->sprite).g));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1600, 400));
    sfText_setString(INTRO->rgb->text_info, "B : ");
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    sfText_move(INTRO->rgb->text_info, vector_create(50, 0));
    sfText_setString(INTRO->rgb->text_info, int_to_str(GC(PLAYER->sprite).b));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
}

void display_intro_text_rgb(game_t *game)
{
    sfText_setPosition(INTRO->rgb->text_info, vector_create(1130, 200));
    sfText_setCharacterSize(INTRO->rgb->text_info, 50);
    sfText_setString(INTRO->rgb->text_info, "Change skin with S");
    sfText_setColor(INTRO->rgb->text_info, sfWhite);
    sfText_setOutlineThickness(INTRO->rgb->text_info, 5);
    sfText_setOutlineColor(INTRO->rgb->text_info, sfBlack);
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    if (GC(PLAYER->sprite).r +
        GC(PLAYER->sprite).g + GC(PLAYER->sprite).a > 730)
        sfText_setOutlineThickness(INTRO->rgb->text_info, 0);
    else
        sfText_setOutlineThickness(INTRO->rgb->text_info, 2);
    sfText_setString(INTRO->rgb->text_info, INTRO->rgb->str);
    sfText_setPosition(INTRO->rgb->text_info, vector_create(900, 300));
    sfText_setString(INTRO->rgb->text_info, "Press I O P to change color RGB");
    sfText_setOutlineColor(INTRO->rgb->text_info, GC(PLAYER->sprite));
    sfRenderWindow_drawText(RENDER_WINDOW, INTRO->rgb->text_info, NULL);
    display_intro_text_rgb_2(game);
}
