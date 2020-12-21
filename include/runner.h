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

/// -------- /!\ QoL : Access principals structure. USE ONLY WITH PARAMETER GAME
#define CORE game->core
#define RENDER_WINDOW game->core->window
#define PLAYER game->player
#define INFO game->info
#define INPUT game->input
/// ------------------------------------

/// -------- /!\ QoL : Access player informations. USE ONLY WITH PARAMETER GAME
#define PLAYER_X_SPEED (game->player->vect.x)
#define PLAYER_Y_SPEED (game->player->vect.y)
#define PLAYER_LEFT_SIDE (game->player->pos.x)
#define PLAYER_RIGHT_SIDE (game->player->pos.x + 128)
#define PLAYER_TOP_SIDE (game->player->pos.y)
#define PLAYER_BOT_SIDE (game->player->pos.y + 128)
/// ------------------------------------

/// -------- /!\ QoL : Access block informations. USE ONLY WITH PARAMETER GAME
#define EACH_BLOCK_ON_MAP (uint i = 0; game->map[i] != NULL; i++)
/// Use the macro below in a "for" loop pair with the macor above
#define BLOCK game->map[i]
#define BLOCK_LEFT_SIDE (game->map[i]->pos.x)
#define BLOCK_RIGHT_SIDE (game->map[i]->pos.x + 128)
#define BLOCK_TOP_SIDE (game->map[i]->pos.y)
#define BLOCK_BOT_SIDE (game->map[i]->pos.y + 128)
#define BLOCK_IS_NOT_SPACE game->map[i]->space == false
#define BLOCK_IS_SPACE game->map[i]->space == true
/// ------------------------------------


/// -------- /!\ Information for initialization
#define BASIC_PLAYER_X_SPEED 8
#define BASIC_PLAYER_Y_SPEED 5
#define BASIC_PLAYER_X_POSITION 300
#define BASIC_PLAYER_Y_POSITION 700
#define PLAYER_TEXTURE_PATH "image/cube.png"
/// ------------------------------------


/// -------- /!\ Default key
#define DEFAULT_JUMP sfKeySpace
/// ------------------------------------

/// -------- /!\ Core Information Macro
#define RESOLUTION_X 1920
#define RESOLUTION_Y 1080
#define FRAME_RATE 60
/// ------------------------------------

/// Enum for state of the button, PRESS is only for one loop.
typedef enum {
    UNPRESS = 0,
    PRESS,
    ALREADY_PRESS,
    END_BUTTON_STATE_T,
} button_state_t;

typedef struct input_s {
    button_state_t jump_state;
    sfKeyCode jump_key;
} input_t;

typedef struct core_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
} core_t;

typedef struct map_info_s {
    int index_under;
    sfVector2f starting_position;
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
    input_t *input;
} game_t;

core_t *core_init(void);
game_t *game_init(void);
entity_t *player_init(void);
entity_t **map_init(char const *map, sfVector2f starting_position);
input_t *input_init(void);
map_info_t *map_info_init(char const *map);

char *file_read(char const *path);
sfVector2f vector2i_to_vector2f(sfVector2i vect);
sfColor color_create(uint r, uint g, uint b, uint a);
sfVector2f vector_create(float x, float y);
sfIntRect rect_create(int top, int left, int height, int width);

int main_loop(void);
void game_destroy(game_t *game);

#endif
