/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** cursor.c
*/

#include "my.h"

void create_cursor(sfRenderWindow *window, general_t *general)
{
    general->cursor.rectangle = (sfIntRect){0, 0, 150, 200};
    general->cursor.texture = sfTexture_createFromFile("assets/cursor.png", NULL);
    general->cursor.sprite = sfSprite_create ();
    sfSprite_setTextureRect(general->cursor.sprite, general->cursor.rectangle);
    sfSprite_setTexture(general->cursor.sprite, general->cursor.texture, sfTrue);
    sfSprite_setPosition(general->cursor.sprite, general->cursor.position);
}

void update_cursor(const sfRenderWindow *window, cursor_t cursor)
{
    cursor.pos= sfMouse_getPositionRenderWindow(window);
    cursor.position.x = cursor.pos.x - 50;
    cursor.position.y = cursor.pos.y - 50;
    sfSprite_setTextureRect(cursor.sprite, cursor.rectangle);
    sfSprite_setPosition(cursor.sprite, cursor.position);
}

void display_cursor(sfRenderWindow *window, cursor_t cursor)
{
    sfRenderWindow_drawSprite (window, cursor.sprite, NULL);
}