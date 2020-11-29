/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** tv.c
*/

#include "my.h"

void init_tv(general_t *general)
{
    general->spawn.spawner[general->i].offset = 147;
    general->spawn.spawner[general->i].rect.left = 0;
    general->spawn.spawner[general->i].rect.top = 0;
    general->spawn.spawner[general->i].rect.height = 110;
    general->spawn.spawner[general->i].rect.width = 147;
    general->spawn.spawner[general->i].pos.x = ((rand() % 1700) - 300)*-1;
    general->spawn.spawner[general->i].pos.y = (rand() % 700);
    general->spawn.spawner[general->i].texture =
    sfTexture_createFromFile("assets/tvsprite.png", NULL);
    general->spawn.spawner[general->i].sprite = sfSprite_create();
    sfTexture_setRepeated(general->spawn.spawner[general->i].texture, sfTrue);
}

void display_tele(sfRenderWindow *window, tele_t *tele)
{
    sfSprite_setTexture(tele->sprite, tele->texture, sfTrue);
    moove_items(tele);
    sfSprite_setTextureRect(tele->sprite, tele->rect);
    sfRenderWindow_drawSprite(window, tele->sprite, NULL);
}