/*
** EPITECH PROJECT, 2021
** runner
** File description:
** map init 2
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

sfIntRect map_init_tileset2(char **map, uint x, uint y)
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

sfIntRect map_init_tileset(char **map, uint x, uint y)
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
