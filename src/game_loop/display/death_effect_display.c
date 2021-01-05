/*
** EPITECH PROJECT, 2020
** runner
** File description:
** death_effect_display
*/

#include "runner.h"

void death_effect_display_2(game_t *game)
{
    if (float_comparison(DEATH->seconds, 0.4, 0.5)) {
        sfSprite_setColor(PLAYER->sprite, color_create(255, 255, 255, 100));
        DEATH->rect = rect_create(0, 52 * 4, 43, 52);
    }
    if (float_comparison(DEATH->seconds, 0.5, 0.6))
        DEATH->rect = rect_create(0, 52 * 5, 43, 52);
    if (float_comparison(DEATH->seconds, 0.6, 0.7)) {
        sfSprite_setColor(PLAYER->sprite, color_create(255, 255, 255, 255));
        DEATH->rect = rect_create(0, 52 * 6, 43, 52);
    }
    if (DEATH->seconds > 0.7) {
        DEATH->space = false;
        sfClock_restart((DEATH->clock));
    }
    sfSprite_setTextureRect(DEATH->sprite, DEATH->rect);
    sfRenderWindow_drawSprite(RENDER_WINDOW, DEATH->sprite, NULL);

}

void death_effect_display(game_t *game)
{
    if (DEATH->space == false) {
        sfClock_restart(DEATH->clock);
        return;
    }
    DEATH->time = sfClock_getElapsedTime(DEATH->clock);
    DEATH->seconds = sfTime_asSeconds(DEATH->time);
    sfSprite_move(DEATH->sprite, vector_create(-15, 0));
    if (float_comparison(DEATH->seconds, 0, 0.1)) {
        sfSprite_setColor(PLAYER->sprite, color_create(255, 255, 255, 100));
        DEATH->rect = rect_create(0, 52 * 0, 43, 52);
    }
    if (float_comparison(DEATH->seconds, 0.1, 0.2))
        DEATH->rect = rect_create(0, 52 * 1, 43, 52);
    if (float_comparison(DEATH->seconds, 0.2, 0.3)) {
        sfSprite_setColor(PLAYER->sprite, color_create(255, 255, 255, 255));
        DEATH->rect = rect_create(0, 52 * 2, 43, 52);
    }
    if (float_comparison(DEATH->seconds, 0.3, 0.4))
        DEATH->rect = rect_create(0, 52 * 3, 43, 52);
    death_effect_display_2(game);
}
