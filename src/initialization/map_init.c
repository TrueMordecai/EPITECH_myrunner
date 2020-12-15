/*
** EPITECH PROJECT, 2020
** map_init
** File description:
** init map
*/

#include "runner.h"

char *file_read(char *path)
{
    int fd = open(path, O_RDONLY);
    char *map = NULL;
    struct stat buf;
    stat(path, &buf);
    map = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, map, buf.st_size);
    map[buf.st_size] = '\0';
    return (map);
}

entity_t **map_init(void)
{
    char *map = file_read("./map");
    entity_t **block = malloc(sizeof(entity_t*) * (my_strlen(map) + 1));
    int col = 1;
    int line = 1;
    sfTexture *texture_temp = sfTexture_createFromFile("image/basic.png", NULL);

    for (uint i = 0; map[i] != '\0'; i++) {
        block[i] = malloc(sizeof(entity_t));
        block[i]->sprite = sfSprite_create();
        block[i]->scale = vector_create(MAP_SCALE, MAP_SCALE);
        block[i]->space = true;
        if (map[i] == '*') {
            sfSprite_setTexture(block[i]->sprite, texture_temp, sfTrue);
            block[i]->space = false;
        }
        block[i]->pos = vector_create(col * 128 * MAP_SCALE, line * 128 * MAP_SCALE);
        sfSprite_setPosition(block[i]->sprite, block[i]->pos);
        sfSprite_setScale(block[i]->sprite, block[i]->scale);
        if (map[i] == '\n') {
            line++;
            col = 0;
        }
        col++;
    }
    block[my_strlen(map)] = NULL;
    return (block);
}
