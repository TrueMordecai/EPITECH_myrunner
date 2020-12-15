/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** core_init
*/

#include "runner.h"

core_t *core_init(void)
{
    core_t *core = malloc(sizeof(core_t));

    core->video_mode.width = RESOLUTION_X;
    core->video_mode.height = RESOLUTION_Y;
    core->video_mode.bitsPerPixel = 32;
    core->window = sfRenderWindow_create(core->video_mode, "my_runner",
    sfClose | sfResize, NULL);
    sfRenderWindow_setMouseCursorVisible(core->window, sfFalse);
    sfRenderWindow_setFramerateLimit(core->window, FRAME_RATE);
    return (core);
}
