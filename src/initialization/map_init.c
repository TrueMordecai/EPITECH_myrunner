/*
** EPITECH PROJECT, 2020
** map_init
** File description:
** init map
*/

#include "runner.h"

char **str_to_array(char *map)
{
    uint new_line_count = 0;
    uint map_size = my_strlen(map);
    char **map_array;
    uint array_index = 1;

    for (uint index = 0; map[index] != '\0'; index++)
        if (map[index] == '\n') new_line_count++;
    for (uint i = 0; i != map_size; i++)
        if (map[i] == '\n') map[i] = '\0';
    map_array = malloc(sizeof(char *) * (new_line_count + 1));
    map_array[new_line_count] = NULL;
    map_array[0] = &map[0];
    for (uint str_index = 0; str_index != map_size - 1; str_index++) {
        if (map[str_index] == '\0') {
            map_array[array_index] = &map[str_index + 1];
            array_index++;
        }
    }
    return (map_array);
}

int array_size_get(char **array)
{
    int size = 0;

    while (array[size] != NULL)
        size++;
    return (size);
}

bool is_a_brick(char **map, int y, int x)
{
    if (x < 0 || y < 0)
        return (false);
    if (x > my_strlen(map[y]) - 1 || y > array_size_get(map) - 1)
        return (false);
    if (map[y][x] != 'o')
        return (false);
    return (true);
}

static sfIntRect map_init_tileset(char **map, uint x, uint y)
{
    if (!is_a_brick(NORTH) && is_a_brick(EAST) && is_a_brick(SOUTH) && is_a_brick(WEST)) // 1
        return (rect_create(128 * 0, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && !is_a_brick(EAST) && is_a_brick(SOUTH) && is_a_brick(WEST)) // 2
        return (rect_create(128 * 0, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && is_a_brick(EAST) && !is_a_brick(SOUTH) && is_a_brick(WEST)) // 3
        return (rect_create(128 * 0, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && is_a_brick(EAST) && is_a_brick(SOUTH) && !is_a_brick(WEST)) // 4
        return (rect_create(128 * 0, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
    if (!is_a_brick(NORTH) && is_a_brick(EAST) && is_a_brick(SOUTH) && !is_a_brick(WEST)) // 5
        return (rect_create(128 * 1, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (!is_a_brick(NORTH) && !is_a_brick(EAST) && is_a_brick(SOUTH) && is_a_brick(WEST)) // 6
        return (rect_create(128 * 1, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && !is_a_brick(EAST) && !is_a_brick(SOUTH) && is_a_brick(WEST)) // 7
        return (rect_create(128 * 1, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && is_a_brick(EAST) && !is_a_brick(SOUTH) && !is_a_brick(WEST)) // 8
        return (rect_create(128 * 1, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
    if (!is_a_brick(NORTH) && !is_a_brick(EAST) && is_a_brick(SOUTH) && !is_a_brick(WEST)) // 9
        return (rect_create(128 * 2, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (!is_a_brick(NORTH) && !is_a_brick(EAST) && !is_a_brick(SOUTH) && is_a_brick(WEST)) // 10
        return (rect_create(128 * 2, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && !is_a_brick(EAST) && !is_a_brick(SOUTH) && !is_a_brick(WEST)) // 11
        return (rect_create(128 * 2, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    if (!is_a_brick(NORTH) && is_a_brick(EAST) && !is_a_brick(SOUTH) && !is_a_brick(WEST)) // 12
        return (rect_create(128 * 2, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && is_a_brick(EAST) && is_a_brick(SOUTH) && is_a_brick(WEST)) // 13
        return (rect_create(128 * 3, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (!is_a_brick(NORTH) && is_a_brick(EAST) && !is_a_brick(SOUTH) && is_a_brick(WEST)) // 14
        return (rect_create(128 * 3, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (is_a_brick(NORTH) && !is_a_brick(EAST) && is_a_brick(SOUTH) && !is_a_brick(WEST)) // 15
        return (rect_create(128 * 3, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    return (rect_create(128 * 3, 128 * 3, BLOCK_SIZE, BLOCK_SIZE)); // 16
}

char *my_strdup(char *str)
{
    char *nstr = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (uint i = 0; str[i] != '\0'; i++) {
        nstr[i] = str[i];
    }
    nstr[my_strlen(str)] = '\0';
    return (nstr);
}
void map_init_set_element(entity_t *block, sfTexture *texture, sfColor color, block_type_t btype)
{
    sfSprite_setTexture(block->sprite, texture, sfTrue);
    block->type = btype;
    if (btype < BT_DELIMITER)
        block->space = false;
    else
        block->space = true;
    if (btype < BT_DELIMITER_SPE || color.a + color.b + color.g + color.r != 0)
        sfSprite_setColor(block->sprite, color);
    if (btype == BT_SPE_COINS || btype == BT_SPE_JUMPER_ORB) {
        sfSprite_setTextureRect(block->sprite, rect_create(0, 0, 128, 128));
        block->clock = sfClock_create();
        block->seconds = 0;
    }
}

entity_t **map_init(char *map, sfVector2f starting_position)
{
    entity_t **block = malloc(sizeof(entity_t*) * (my_strlen(map) + 1));
    uint col = 1;
    uint line = 1;
    sfTexture *block_texture = sfTexture_createFromFile("image/basic.png", NULL);
    sfTexture *brick0_texture = sfTexture_createFromFile("image/brick0-tileset.png", NULL);
    sfTexture *spike_texture = sfTexture_createFromFile("image/spike.png", NULL);
    sfTexture *wall_texture = sfTexture_createFromFile("image/brickwall.png", NULL);
    sfTexture *speedup_texture = sfTexture_createFromFile("image/speed_up.png", NULL);
    sfTexture *speeddown_texture = sfTexture_createFromFile("image/speed_down.png", NULL);
    sfTexture *jumper_texture = sfTexture_createFromFile("image/jumper_orb.png", NULL);
    sfTexture *coins_texture = sfTexture_createFromFile("image/coins.png", NULL);
    char **map_array = str_to_array(my_strdup(map));

    for (uint i = 0; map[i] != '\0'; i++) {
        block[i] = malloc(sizeof(entity_t));
        block[i]->sprite = sfSprite_create();
        block[i]->space = true;
        block[i]->type = BT_SPACE;
        if (map[i] == '*')
            map_init_set_element(block[i], block_texture, color_create(255, 20, 190, 150), BT_BASIC);
        if (map[i] == 'o') {
            map_init_set_element(block[i], brick0_texture, color_create(255, 20, 190, 245), BT_BRICK);
            sfSprite_setTextureRect(block[i]->sprite, map_init_tileset(map_array, col - 1, line - 1));
        }
        if (map[i] == 'w')
            map_init_set_element(block[i], wall_texture, color_create(255, 150, 255, 100), BT_WALL);
        if (map[i] == 'x')
            map_init_set_element(block[i], spike_texture, color_create(10, 10, 10, 255), BT_SPIKE);
        if (map[i] == '>')
            map_init_set_element(block[i], speedup_texture, color_create(0, 0, 0, 0), BT_SPE_SPEED_UP);
        if (map[i] == '<')
            map_init_set_element(block[i], speeddown_texture, color_create(0, 0, 0, 0), BT_SPE_SPEED_DOWN);
        if (map[i] == 'J') {
            map_init_set_element(block[i], jumper_texture, color_create(0, 0, 0, 0), BT_SPE_JUMPER_ORB);
            sfSprite_setOrigin(block[i]->sprite, vector_create(128 / 2, 128 / 2));
        }
        if (map[i] == 'C')
            map_init_set_element(block[i], coins_texture, color_create(0, 0, 0, 0), BT_SPE_COINS);
        block[i]->pos = vector_create((col * 128) + (400 - 128) - starting_position.x * 128, (line * 128) + (600 - 128) - starting_position.y * 128);
        sfSprite_setPosition(block[i]->sprite, block[i]->pos);
        if (map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    block[my_strlen(map)] = NULL;
    return (block);
}
