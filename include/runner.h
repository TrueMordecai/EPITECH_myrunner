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
#define CORE game->core
#define RENDER_WINDOW game->core->window
#define PLAYER game->player
#define INFO game->info
#define INPUT game->input
#define BACKGROUND game->background
#define HUD game->hud
#define INTRO game->intro
#define DEATH game->death_effect
#define PLAYER_X_SPEED (game->player->vect.x)
#define PLAYER_Y_SPEED (game->player->vect.y)
#define PLAYER_LEFT_SIDE (game->player->pos.x)
#define PLAYER_RIGHT_SIDE (game->player->pos.x + 128)
#define PLAYER_TOP_SIDE (game->player->pos.y)
#define PLAYER_BOT_SIDE (game->player->pos.y + 128)
#define NORTH map, y - 1, x
#define EAST map, y, x + 1
#define SOUTH map, y + 1, x
#define WEST map, y, x - 1
#define EACH_BLOCK_ON_MAP uint i = 0; game->map[i] != NULL; i++
#define BLOCK game->map[i]
#define BLOCK_LEFT_SIDE (game->map[i]->pos.x)
#define BLOCK_RIGHT_SIDE (game->map[i]->pos.x + 128)
#define BLOCK_TOP_SIDE (game->map[i]->pos.y)
#define BLOCK_BOT_SIDE (game->map[i]->pos.y + 128)
#define BLOCK_IS_NOT_SPACE game->map[i]->space == false
#define BLOCK_IS_SPACE game->map[i]->space == true
#define BASIC_PLAYER_X_SPEED 20
#define BASIC_PLAYER_Y_SPEED 0
#define BASIC_PLAYER_JUMP_HEIGHT 27
#define BASIC_PLAYER_GRAVITY 1.5
#define BASIC_PLAYER_MAX_GRAVITY 30
#define BASIC_PLAYER_X_POS 400
#define BASIC_PLAYER_Y_POS 600
#define BG_SCALE 2, 2
#define LARGE_BG_RECT 0, 0, 1000000, 10000
#define BG_STARTING_POS 0, -1000
#define BLOCK_SIZE 128
#define PLAYER_SIZE 128
#define PLAYER_TEXTURE_PATH "image/cube.png"
#define DEFAULT_JUMP sfKeySpace
#define DEFAULT_RESTART_LEVEL sfKeyR
#define DEFAULT_QUIT_LEVEL sfKeyQ
#define DEFAULT_SKIP_INTRO sfKeyEnter
#define DEFAULT_QUIT_GAME sfKeyEscape
#define DEFAULT_SKIN_CHANGE sfKeyS
#define DEFAULT_CHANGE_COLOR_R sfKeyI
#define DEFAULT_CHANGE_COLOR_G sfKeyO
#define DEFAULT_CHANGE_COLOR_B sfKeyP
#define RESOLUTION_X 1920
#define RESOLUTION_Y 1080
#define FRAME_RATE 60
#define PATH_INTRO_PLATFORM "image/intro_platform.png"
#define PATH_SPIKE "image/spike.png"
#define PATH_BG1 "image/intro/background_1.png"
#define PATH_BG2 "image/intro/background_2.png"
#define PATH_BG3 "image/intro/background_3.png"
#define PATH_BG4 "image/intro/background_4.png"
#define PATH_BASIC "image/basic.png"
#define PATH_BRICK "image/brick0-tileset.png"
#define PATH_WALL "image/brickwall.png"
#define PATH_SPEEDU "image/speed_up.png"
#define PATH_SPEEDD "image/speed_down.png"
#define PATH_JUMPERO "image/jumper_orb.png"
#define PATH_COIN "image/coins.png"
#define PATH_PORTAL "image/win_portal.png"
#define PATH_LIGHT "image/enlighten.png"
#define PATH_PORTAL1 "image/portal1.png"
#define PATH_EFFECT "image/portal_effect.png"
#define PATH_BG "image/bg.png"
#define PATH_DEATH "image/death_effect.png"
#define MISE map_init_set_element
#define MIT map_init_tileset
#define CC color_create
#define GC sfSprite_getColor
#define X_BLOCK_START_POS (h * 128) + (400 - 128) - starting_position.x * 128
#define Y_BLOCK_START_POS (v * 128) + (600 - 128) - starting_position.y * 128
typedef struct {
    sfTexture **tex;
    char c;
} char_tex;
typedef enum {
    UNPRESS = 0,
    PRESS,
    ALREADY_PRESS,
    END_BUTTON_STATE_T,
} button_state_t;
typedef enum {
    SCENE_INTRO = 0,
    SCENE_GAME
} scene_t;
typedef enum {
    R = 0,
    G,
    B
} RGB_MACROS;
typedef enum {
    BT_BASIC = 0,
    BT_BRICK,
    BT_DELIMITER,
    BT_SPIKE,
    BT_WALL,
    BT_SPACE,
    BT_DELIMITER_SPE,
    BT_SPE_SPEED_UP,
    BT_SPE_SPEED_UP_USED,
    BT_SPE_SPEED_DOWN,
    BT_SPE_SPEED_DOWN_USED,
    BT_SPE_JUMPER_ORB,
    BT_SPE_JUMPER_ORB_USED,
    BT_SPE_COINS,
    BT_SPE_COINS_FOUND,
    BT_SPE_VICTORY,
} block_type_t;
typedef struct key_input_s {
    button_state_t key_state;
    sfKeyCode key_code;
} key_input_t;
typedef struct core_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
} core_t;
typedef struct entity_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f vect;
    block_type_t type;
    sfTime time;
    sfClock *clock;
    float seconds;
    bool space;
} entity_t;
typedef struct map_info_s {
    char const *map;
    entity_t *death_effect;
    int index_under;
    sfVector2f starting_position;
    entity_t *enlight_block;
    unsigned short coins_founds;
    bool is_win;
    uint victory_index;
    entity_t *portal1;
    entity_t *portal2;
    sfVector2f true_vect;
    sfMusic *mus_intro;
    sfMusic *mus_map;
    sfMusic **mus_coin;
} map_info_t;
typedef struct input_s {
    key_input_t *jump;
    key_input_t *reset;
    key_input_t *quit;
    key_input_t *skip;
    key_input_t *exit;
    key_input_t *skin_change;
    key_input_t **change_color;
} input_t;
typedef struct text_anim_s {
    char *str;
    sfText *text_info;
    sfVector2f *vect;
    sfTime time;
    sfClock *clock;
    float second;
    int index_up;
} text_anim_t;
typedef struct intro_s {
    entity_t **background;
    entity_t *platform;
    entity_t *spike;
    text_anim_t *text;
    text_anim_t *rgb;
} intro_t;
typedef struct game_s {
    core_t *core;
    entity_t *background;
    entity_t *hud;
    entity_t **map;
    entity_t *player;
    entity_t *death_effect;
    intro_t *intro;
    map_info_t *info;
    input_t *input;
    scene_t scene;
} game_t;
core_t *core_init(void);
game_t *game_init(char const *path);
entity_t *player_init(void);
entity_t **map_init(char *map, sfVector2f starting_position);
input_t *input_init(void);
map_info_t *map_info_init(char const *map);
entity_t *background_init(void);
entity_t *hud_init(void);
intro_t *intro_init(void);
entity_t *death_effect_init(void);
bool is_error_map(char const *map);
char *file_read(char const *path);
sfVector2f vector2i_to_vector2f(sfVector2i vect);
sfColor color_create(uint r, uint g, uint b, uint a);
sfVector2f vector_create(float x, float y);
sfIntRect rect_create(int top, int left, int height, int width);
void map_display(game_t *game);
void display_intro(game_t *game);
void display_intro_parralax(game_t *game);
void background_display(game_t *game);
void player_display(game_t *game);
void gravity_update(game_t *game);
void death_effect_display(game_t *game);
void input_index(game_t *game);
bool is_align(entity_t *player, entity_t *block);
bool is_player_dead(game_t *game);
bool is_in_the_air(game_t *game);
bool is_player_in_block(entity_t *player, entity_t *block);
bool float_comparison(float to_compare, float tag_1, float tag_2);
void reset_map(game_t *game);
int array_size_get(char **array);
char *my_strdup(char *str);
int main_loop(char const *path);
void special_block_apply(game_t *game, entity_t *block);
void special_block_apply_2(game_t *game, entity_t *block);
void game_destroy(game_t *game);
void window_event(game_t *game);
void display_intro_parralax(game_t *game);
void display_intro_player_update(game_t *game);
void display_intro_spike(game_t *game);
void display_intro(game_t *game);
char *int_to_str(int i);
char *char_str(char c);
void display_intro_text_anim(game_t *game);
void display_intro_text_rgb(game_t *game);
char **str_to_array(char *map);
bool isbrick(char **map, int y, int x);
sfIntRect map_init_tileset2(char **map, uint x, uint y);
sfIntRect map_init_tileset(char **map, uint x, uint y);
void map_init_set_element(entity_t *b, sfTexture *t, sfColor c, block_type_t k);
#endif
