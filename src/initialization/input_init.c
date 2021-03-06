/*
** EPITECH PROJECT, 2020
** runner
** File description:
** input init
*/

#include "runner.h"

key_input_t *key_input_init(sfKeyCode key_code_value)
{
    key_input_t *key = malloc(sizeof(key_input_t));

    key->key_code = key_code_value;
    if (key_code_value == DEFAULT_SKIP_INTRO)
        key->key_state = ALREADY_PRESS;
    else
        key->key_state = UNPRESS;
    return (key);
}

input_t *input_init(void)
{
    input_t *input = malloc(sizeof(input_t));

    input->jump = key_input_init(DEFAULT_JUMP);
    input->quit = key_input_init(DEFAULT_QUIT_LEVEL);
    input->reset = key_input_init(DEFAULT_RESTART_LEVEL);
    input->skip = key_input_init(DEFAULT_SKIP_INTRO);
    input->exit = key_input_init(DEFAULT_QUIT_GAME);
    input->skin_change = key_input_init(DEFAULT_SKIN_CHANGE);
    input->change_color = malloc(sizeof(key_input_t *) * 3);
    input->change_color[R] = key_input_init(DEFAULT_CHANGE_COLOR_R);
    input->change_color[G] = key_input_init(DEFAULT_CHANGE_COLOR_G);
    input->change_color[B] = key_input_init(DEFAULT_CHANGE_COLOR_B);
    return (input);
}
