/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** functions.c
*/

#include "my.h"

void tele_changer(general_t *general, sfMouseButtonEvent mouse)
{
    int i = 0;
    for (i = 0; i < MAX; i++) {
        if ((mouse.x >= general->spawn.spawner[i].pos.x)
        && (mouse.x <= general->spawn.spawner[i].pos.x + 147)) {
            if ((mouse.y >= general->spawn.spawner[i].pos.y)
            && (mouse.y <= general->spawn.spawner[i].pos.y + 110)) {
                general->spawn.spawner[i].rect.top = 110;
                put_sound(general);
            }
        }
    }
}

void window_event(sfRenderWindow* window,
general_t *general, sfMouseButtonEvent mouse)
{
    while (sfRenderWindow_pollEvent(window, &general->event)) {
        if ((general->event.type == sfEvtKeyPressed)
        && (general->event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (general->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (mouse.type == sfEvtMouseButtonPressed)
            if (mouse.button == sfMouseLeft)
                tele_changer(general, mouse);
    }
}

void moove_sprite(sfIntRect *rect, int offset)
{
    rect->left += offset;
}

void moove_items(tele_t *tele)
{
    sfSprite_setPosition(tele->sprite, tele->pos);
    tele->pos.x += 15;
    if (tele->pos.x > 1920) {
        tele->pos.x = -300;
        tele->pos.y = (rand() % -800);
        tele->rect.top = 0;
    }
}

void put_sound(general_t *general)
{
    int nb = (rand() % 3);
    general->effect1 = sfMusic_createFromFile("./assets/effect1.ogg");
    general->effect2 = sfMusic_createFromFile("./assets/effect2.ogg");
    general->effect3 = sfMusic_createFromFile("./assets/effect3.ogg");
    if (nb == 0) {
        sfMusic_play(general->effect1);
        sfMusic_setVolume(general->effect1, 10);
    }
    if (nb == 1) {
        sfMusic_play(general->effect2);
        sfMusic_setVolume(general->effect2, 10);
    }
    if (nb == 2) {
        sfMusic_play(general->effect3);
        sfMusic_setVolume(general->effect3, 10);
    }
}