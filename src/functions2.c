/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** functions2.c
*/

#include "my.h"

int info_display(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1] = "-h") {
            my_putstr("*=================================*\n");
            my_putstr("|    My hunter made by   @magics  |\n");
            my_putstr("| mohammed henni content included |\n");
            my_putstr("|          ~  USAGE  ~            |\n");
            my_putstr("| (./my_hunter) to enter the game |\n");
            my_putstr("|        sounds are played        |\n");
            my_putstr("|    randomly when tv explose     |\n");
            my_putstr("*=================================*\n");
            return (1);
        }
    }
    return (0);
}

void init_all(general_t *general, sfRenderWindow *window)
{
    create_cursor(general->window, general);
    general->clock = sfClock_create();
    init_background(general);
    for (general->i = 0; general->i < MAX; general->i++)
        init_tv(general);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
}

void destroyer(general_t *general)
{
    int i = 0;
    sfRenderWindow_destroy(general->window);
    sfSprite_destroy(general->background.sprite);
    sfTexture_destroy(general->background.texture);
    sfClock_destroy(general->clock);
    sfTexture_destroy(general->cursor.texture);
    sfSprite_destroy (general->cursor.sprite);
}