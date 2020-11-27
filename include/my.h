/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** ethrt
*/

#ifndef __MY_H__
#define __MY_H__

#define WIDTH 1920
#define HEIGHT 1080
#define MAX 6

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

typedef struct cursor
{
    sfVector2i pos;
    sfVector2f position;
    sfIntRect rectangle;
    sfSprite *sprite;
    sfTexture *texture;
} cursor_t;

typedef struct background {
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rect;
    sfVector2f pos;
    int offset;
} background_t;

typedef struct tele {
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rect;
    sfVector2f pos;
    int offset;
}tele_t;

typedef struct spawn {
    tele_t spawner [MAX];
}spawn_t;

typedef struct general {
    sfClock* clock;
    sfTime time;
    sfEvent event;
    sfVector2f scale;
    float temp;
    sfRenderWindow* window;
    background_t background;
    spawn_t spawn;
    cursor_t cursor;
    sfMusic *effect1;
    sfMusic *effect2;
    sfMusic *effect3;
    int i;
}general_t;


void tele_changer(general_t *general, sfMouseButtonEvent mouse);
void window_event(sfRenderWindow* window, general_t *general, sfMouseButtonEvent mouse);
void moove_sprite(sfIntRect *rect, int offset);
void moove_items(tele_t *tele);
void tv_spawner();
void put_sound(general_t *general);

void create_cursor(sfRenderWindow *window, general_t *general);
void update_cursor(const sfRenderWindow *window, cursor_t cursor);
void display_cursor(sfRenderWindow *window, cursor_t cursor);
void init_background(general_t *general);
void init_tv(general_t *general);

void display_background(sfRenderWindow *window, background_t background);
void display_tele(sfRenderWindow *window, tele_t *tele);

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);

void moove_sprite(sfIntRect *rect, int offset);
void display(general_t *general);
void destroyer(general_t *general);
void set_textures(general_t *general);

#endif
