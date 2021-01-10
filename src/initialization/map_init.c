/*
** EPITECH PROJECT, 2020
** map_init
** File description:
** init map
*/

#include "runner.h"

sfTexture **map_init_load_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture*) * 9);

    texture[0] = sfTexture_createFromFile(PATH_BASIC, NULL);
    texture[1] = sfTexture_createFromFile(PATH_BRICK, NULL);
    texture[2] = sfTexture_createFromFile(PATH_SPIKE, NULL);
    texture[3] = sfTexture_createFromFile(PATH_WALL, NULL);
    texture[4] = sfTexture_createFromFile(PATH_SPEEDU, NULL);
    texture[5] = sfTexture_createFromFile(PATH_SPEEDD, NULL);
    texture[6] = sfTexture_createFromFile(PATH_JUMPERO, NULL);
    texture[7] = sfTexture_createFromFile(PATH_COIN, NULL);
    texture[8] = sfTexture_createFromFile(PATH_PORTAL, NULL);
    return (texture);
}

char_tex ctc(sfTexture **tex, char c)
{
    char_tex chtex;

    chtex.c = c;
    chtex.tex = tex;
    return (chtex);
}

void map_init2(char_tex ctex, \
sfVector2f pos, char **mtab, entity_t *b)
{
    b->space = true;
    b->type = BT_SPACE;
    if (ctex.c == '*') MISE(b, ctex.tex[0], CC(255, 20, 190, 150), BT_BASIC);
    if (ctex.c == 'o') {
        MISE(b, ctex.tex[1], CC(255, 20, 190, 245), BT_BRICK);
        sfSprite_setTextureRect(b->sprite, MIT(mtab, pos.x - 1, pos.y - 1));
    }
    if (ctex.c == 'w') MISE(b, ctex.tex[3], CC(255, 150, 255, 100), BT_WALL);
    if (ctex.c == 'x') MISE(b, ctex.tex[2], CC(10, 10, 10, 255), BT_SPIKE);
    if (ctex.c == '>') MISE(b, ctex.tex[4], CC(0, 0, 0, 0), BT_SPE_SPEED_UP);
    if (ctex.c == '<') MISE(b, ctex.tex[5], CC(0, 0, 0, 0), BT_SPE_SPEED_DOWN);
    if (ctex.c == 'J') {
        MISE(b, ctex.tex[6], CC(0, 0, 0, 0), BT_SPE_JUMPER_ORB);
        sfSprite_setOrigin(b->sprite, vector_create(64, 64));
    }
    if (ctex.c == 'V') {
        MISE(b, ctex.tex[8], CC(0, 0, 0, 0), BT_SPE_VICTORY);
        sfSprite_setScale(b->sprite, vector_create(2, 2));
    }
    if (ctex.c == 'C') MISE(b, ctex.tex[7], CC(0, 0, 0, 0), BT_SPE_COINS);
}

entity_t **map_init(char *map, sfVector2f starting_position)
{
    entity_t **block = malloc(sizeof(entity_t*) * (my_strlen(map) + 1));
    uint h = 1;
    uint v = 1;
    sfTexture **at = map_init_load_texture();
    char **mtab = str_to_array(my_strdup(map));

    for (uint i = 0; map[i] != '\0'; i++) {
        block[i] = malloc(sizeof(entity_t));
        block[i]->sprite = sfSprite_create();
        map_init2(ctc(at, map[i]), vector_create(h, v), mtab, block[i]);
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
