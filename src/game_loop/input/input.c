/*
** EPITECH PROJECT, 2020
** runner
** File description:
** input related functiuns
*/

#include "runner.h"

void get_input(key_input_t *key)
{
    if (sfKeyboard_isKeyPressed(key->key_code) == sfTrue && (key->key_state == PRESS || key->key_state == ALREADY_PRESS)) {
        key->key_state = ALREADY_PRESS;
        return;
    }
    if (sfKeyboard_isKeyPressed(key->key_code) == sfTrue) {
        key->key_state = PRESS;
    } else {
        key->key_state = UNPRESS;
    }
}

void input_index(game_t *game)
{
    get_input(INPUT->jump);
    get_input(INPUT->quit);
    get_input(INPUT->reset);
    get_input(INPUT->skip);
    get_input(INPUT->exit);
}
