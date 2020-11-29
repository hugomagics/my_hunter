/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** display.c
*/

#include "my.h"

void display(general_t *general)
{
    sfRenderWindow_clear(general->window, sfBlack);
    for (general->i = 0; general->i < MAX; general->i++) {
        moove_sprite(&general->spawn.spawner[general->i].rect,
        general->spawn.spawner[general->i].offset);
    }
    display_background(general->window, general->background);
    for (general->i = 0; general->i < MAX; general->i++) {
        display_tele(general->window, &general->spawn.spawner[general->i]);
    }
    display_cursor(general->window, general->cursor);
    sfClock_restart(general->clock);
    sfRenderWindow_display(general->window);
}