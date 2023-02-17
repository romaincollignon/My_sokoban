/*
** EPITECH PROJECT, 2022
** periph.c
** File description:
** full capturing periph
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "struct_all.h"
#include "my.h"

int periph(int getch, char **av, i_g *info_game)
{
    if (getch == KEY_UP)
        return 1;
    if (getch == KEY_RIGHT)
        return 2;
    if (getch == KEY_DOWN)
        return 3;
    if (getch == KEY_LEFT)
        return 4;
    if (getch == 32)
        init_struct(av, info_game);
    return 0;
}
