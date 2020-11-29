/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** background.c
*/

#include "my.h"

void init_background(general_t *general)
{
    general->background.offset = 0;
    general->background.rect.left = 0;
    general->background.rect.top = 0;
    general->background.rect.height = 1000;
    general->background.rect.width = 1920;
    general->background.texture =
    sfTexture_createFromFile("assets/room.png", NULL);
    general->background.sprite = sfSprite_create();
    sfTexture_setRepeated(general->background.texture, sfTrue);
}

void display_background(sfRenderWindow *window, background_t background)
{
    sfSprite_setTexture(background.sprite, background.texture, sfTrue);
    sfSprite_setTextureRect(background.sprite, background.rect);
    sfRenderWindow_drawSprite(window, background.sprite, NULL);
}