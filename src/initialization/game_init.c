/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** init game
*/

#include "runner.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

game_t *game_init(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->core = core_init();
    game->player = player_init();
    game->map = map_init();
    game->info = map_info_init();
    game->input = input_init();
    return (game);
}
