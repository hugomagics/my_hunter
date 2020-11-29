/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** my_hunter.c
*/

#include "my.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    general_t general;
    if (info_display(argc, argv) == 1) return (0);
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    general.window = sfRenderWindow_create(mode, "OMTV", sfDefaultStyle, NULL);
    init_all(&general, general.window);
    while (sfRenderWindow_isOpen(general.window)) {
        window_event(general.window, &general, general.event.mouseButton);
        general.time = sfClock_getElapsedTime(general.clock);
        general.temp = general.time.microseconds / 1000000.0;
        update_cursor(general.window, general.cursor);
        if (general.temp > 0.06)
            display(&general);
    }
    destroyer(&general);
    return (0);
}