/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** my_hunter.c
*/

#include "my.h"

int main(void)
{
    srand(time(NULL));
    general_t general;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    general.window = sfRenderWindow_create(mode, "OMTV", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(general.window, 60);
    sfRenderWindow_setMouseCursorVisible(general.window, sfFalse);
    general.clock = sfClock_create();
    init_background(&general);
    create_cursor(general.window, &general);
    for(general.i = 0; general.i < MAX; general.i++) {
        init_tv(&general);
    }
    while (sfRenderWindow_isOpen(general.window)) {
        window_event(general.window, &general, general.event.mouseButton);
        general.time = sfClock_getElapsedTime(general.clock);
        general.temp = general.time.microseconds / 1000000.0;
        update_cursor(general.window, general.cursor);
        if (general.temp > 0.07) {
            display(&general);
        }
    }
    destroyer(&general);
    return (0);
}