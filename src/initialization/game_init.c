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
    char *map = file_read("./map");

    game->core = core_init();
    game->player = player_init();
    game->info = map_info_init(map);
    game->map = map_init(map, INFO->starting_position);
    game->input = input_init();
    game->background = background_init();
    return (game);
}
