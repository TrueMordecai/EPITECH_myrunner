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
bool isbrick(char **map, int y, int x)
{
    if (x < 0 || y < 0)
        return (false);
    if (x > my_strlen(map[y]) - 1 || y > array_size_get(map) - 1)
        return (false);
    if (map[y][x] != 'o')
        return (false);
    return (true);
}

static sfIntRect map_init_tileset2(char **map, uint x, uint y)
{
    if (!isbrick(NORTH) && !isbrick(EAST) && isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 2, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (!isbrick(NORTH) && !isbrick(EAST) && !isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 2, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && !isbrick(EAST) && !isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 2, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    if (!isbrick(NORTH) && isbrick(EAST) && !isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 2, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && isbrick(EAST) && isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 3, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (!isbrick(NORTH) && isbrick(EAST) && !isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 3, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && !isbrick(EAST) && isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 3, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    return (rect_create(128 * 3, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
}

static sfIntRect map_init_tileset(char **map, uint x, uint y)
{
    if (!isbrick(NORTH) && isbrick(EAST) && isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 0, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && !isbrick(EAST) && isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 0, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && isbrick(EAST) && !isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 0, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && isbrick(EAST) && isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 0, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
    if (!isbrick(NORTH) && isbrick(EAST) && isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 1, 128 * 0, BLOCK_SIZE, BLOCK_SIZE));
    if (!isbrick(NORTH) && !isbrick(EAST) && isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 1, 128 * 1, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && !isbrick(EAST) && !isbrick(SOUTH) && isbrick(WEST))
        return (rect_create(128 * 1, 128 * 2, BLOCK_SIZE, BLOCK_SIZE));
    if (isbrick(NORTH) && isbrick(EAST) && !isbrick(SOUTH) && !isbrick(WEST))
        return (rect_create(128 * 1, 128 * 3, BLOCK_SIZE, BLOCK_SIZE));
    return (map_init_tileset2(map, x, y));
}

void map_init_set_element(entity_t *block, sfTexture *texture,
sfColor color, block_type_t btype)
{
    if (btype == BT_SPE_SPEED_UP || btype == BT_SPE_SPEED_DOWN) {
        sfTexture_setRepeated(texture, sfTrue);
        block->rect = rect_create(0, 0, 128, 128);
    }
    sfSprite_setTexture(block->sprite, texture, sfTrue);
    block->type = btype;
    if (btype < BT_DELIMITER)
        block->space = false;
    else
        block->space = true;
    if (btype < BT_DELIMITER_SPE || color.a + color.b + color.g + color.r != 0)
        sfSprite_setColor(block->sprite, color);
    if (btype == BT_SPE_COINS || btype == BT_SPE_JUMPER_ORB) {
        block->rect = rect_create(0, 0, 128, 128);
        block->clock = sfClock_create();
        block->seconds = 0;
    }
}

entity_t **map_init(char *map, sfVector2f starting_position)
{
    entity_t **block = malloc(sizeof(entity_t*) * (my_strlen(map) + 1));
    uint h = 1;
    uint v = 1;
    sfTexture *block_texture = sfTexture_createFromFile(PATH_BASIC, NULL);
    sfTexture *brick0_texture = sfTexture_createFromFile(PATH_BRICK, NULL);
    sfTexture *spike_texture = sfTexture_createFromFile(PATH_SPIKE, NULL);
    sfTexture *wall_texture = sfTexture_createFromFile(PATH_WALL, NULL);
    sfTexture *speedu_texture = sfTexture_createFromFile(PATH_SPEEDU, NULL);
    sfTexture *speedd_texture = sfTexture_createFromFile(PATH_SPEEDD, NULL);
    sfTexture *jumper_texture = sfTexture_createFromFile(PATH_JUMPERO, NULL);
    sfTexture *coins_texture = sfTexture_createFromFile(PATH_COIN, NULL);
    sfTexture *win_portal_texture = sfTexture_createFromFile(PATH_PORTAL, NULL);
    char **mtab = str_to_array(my_strdup(map));

    for (uint i = 0; map[i] != '\0'; i++) {
        block[i] = malloc(sizeof(entity_t));
        block[i]->sprite = sfSprite_create();
        block[i]->space = true;
        block[i]->type = BT_SPACE;
        if (map[i] == '*')
            MISE(block[i], block_texture, CC(255, 20, 190, 150), BT_BASIC);
        if (map[i] == 'o') {
            MISE(block[i], brick0_texture, CC(255, 20, 190, 245), BT_BRICK);
            sfSprite_setTextureRect(block[i]->sprite, MIT(mtab, h - 1, v - 1));
        }
        if (map[i] == 'w')
            MISE(block[i], wall_texture, CC(255, 150, 255, 100), BT_WALL);
        if (map[i] == 'x')
            MISE(block[i], spike_texture, CC(10, 10, 10, 255), BT_SPIKE);
        if (map[i] == '>')
            MISE(block[i], speedu_texture, CC(0, 0, 0, 0), BT_SPE_SPEED_UP);
        if (map[i] == '<')
            MISE(block[i], speedd_texture, CC(0, 0, 0, 0), BT_SPE_SPEED_DOWN);
        if (map[i] == 'J') {
            MISE(block[i], jumper_texture, CC(0, 0, 0, 0), BT_SPE_JUMPER_ORB);
            sfSprite_setOrigin(block[i]->sprite, vector_create(64, 64));
        }
        if (map[i] == 'V') {
            MISE(block[i], win_portal_texture, CC(0, 0, 0, 0), BT_SPE_VICTORY);
            sfSprite_setScale(block[i]->sprite, vector_create(2, 2));
        }
        if (map[i] == 'C')
            MISE(block[i], coins_texture, CC(0, 0, 0, 0), BT_SPE_COINS);
        block[i]->pos = vector_create(X_BLOCK_START_POS, Y_BLOCK_START_POS);
        sfSprite_setPosition(block[i]->sprite, block[i]->pos);
        sfSprite_setOrigin(block[i]->sprite, vector_create(64, 64));
        if (map[i] == '\n') {
            v++;
            h = 0;
        }
        h++;
    }
    block[my_strlen(map)] = NULL;
    return (block);
}
