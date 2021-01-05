/*
** EPITECH PROJECT, 2021
** runner
** File description:
** tool for creation
*/

#include "runner.h"

sfColor color_create(uint r, uint g, uint b, uint a)
{
    sfColor color;

    if (r > 255 || g > 255 || b > 255 || a > 255)
        return (sfBlack);
    color.r = r;
    color.b = b;
    color.g = g;
    color.a = a;
    return (color);
}

sfVector2f vector_create(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfIntRect rect_create(int top, int left, int height, int width)
{
    sfIntRect rect;

    rect.top = top;
    rect.height = height;
    rect.left = left;
    rect.width = width;
    return (rect);
}
