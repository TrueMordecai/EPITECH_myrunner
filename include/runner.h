/*
** EPITECH PROJECT, 2020
** my_hunter include
** File description:
** all information for the my _hunter
*/

#ifndef _RUNNER_H_
#define _RUNNER_H_
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <SFML/Graphics/Rect.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

///  Quality Of Life Macro
#define CORE game->core
#define RENDER_WINDOW game->core->window
#define PLAYER game->player
#define MAP_ELEMENT game->map[i]
#define INFO game->info

/// Core Information Macro
#define RESOLUTION_X 1920
#define RESOLUTION_Y 1080
#define FRAME_RATE 60

/// Basic Information Macro
#define MAP_SCALE 0.4

/// Side Player Macro (QoL)
#define LEFT_PLAYER_SIDE game->player->pos.x
#define RIGHT_PLAYER_SIDE game->player->pos.x + (game->player->scale.x * game->player->rect.width)
#define TOP_PLAYER_SIDE game->player->pos.y
#define BOT_PLAYER_SIDE game->player->pos.y + (game->player->scale.y * game->player->rect.height)

/// Side Block Macro (QoL)
#define LEFT_BLOCK_SIDE game->map[i]->pos.x
#define RIGHT_BLOCK_SIDE game->map[i]->pos.x + (game->map[i]->scale.x * 128)
#define TOP_BLOCK_SIDE game->map[i]->pos.y
#define BOT_X_BLOCK_SIDE game->map[i]->pos.y + (game->map[i]->scale.y * 128)

/// Other QoL Macro
#define EACH_BLOCK_ON_MAP (uint i = 0; game->map[i] != 0; i++)

/// In Game Information
#define SPEED 4


typedef struct core_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
} core_t;

typedef struct map_info_s {
    int index_under;
} map_info_t;

typedef struct entity_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f vect;
    sfTime time;
    sfClock *clock;
    float seconds;
    bool space;
} entity_t;

typedef struct game_s {
    core_t *core;
    entity_t **map;
    entity_t *player;
    map_info_t *info;
} game_t;

core_t *core_init(void);
game_t *game_init(void);
entity_t *player_init();
entity_t **map_init(void);
map_info_t *map_info_init(void);

sfVector2f vector2i_to_vector2f(sfVector2i vect);
sfColor color_create(uint r, uint g, uint b, uint a);
sfVector2f vector_create(float x, float y);
sfIntRect rect_create(int top, int left, int height, int width);

int main_loop(void);
void game_destroy(game_t *game);

#endif
