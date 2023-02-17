/*
** EPITECH PROJECT, 2022
** moove.c
** File description:
** moove : up, right, down and left
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <my.h>

#include "struct_all.h"
#include "my.h"

int verif_box_mv(i_g *info_game, int i)
{
    int tmp;
    if (info_game->map[info_game->player_y - 1][info_game->player_x]
        == 'X' && i == 1) {
        tmp = box_up(info_game, 0);
        return tmp;
    } if (info_game->map[info_game->player_y][info_game->player_x + 1]
        == 'X' && i == 2) {
        tmp = box_right(info_game, 0);
        return tmp;
    } if (info_game->map[info_game->player_y + 1][info_game->player_x]
        == 'X' && i == 3) {
        tmp = box_down(info_game, 0);
        return tmp;
    } if (info_game->map[info_game->player_y][info_game->player_x - 1]
        == 'X' && i == 4) {
        tmp = box_left(info_game, 0);
        return tmp;
    }
    return 0;
}

int box_up(i_g *info_game, int y)
{
    if (info_game->map[info_game->player_y - 1 - y][info_game->player_x]
    == 'X') {
        if (info_game->map[info_game->player_y - 2 - y][info_game->player_x]
    == '#' || info_game->map[info_game->player_y - 2 - y][info_game->player_x]
    == 'X') {
            return -1;
        }
        if (info_game->map[info_game->player_y - 2 - y][info_game->player_x]
    != '#') {
            info_game->map[info_game->player_y - 2 - y][info_game->player_x]
            = 'X';
            info_game->map[info_game->player_y - 1 - y][info_game->player_x]
            = ' ';
            return 0;
        }
    }
    return 0;
}

int box_right(i_g *info_game, int x)
{
    if (info_game->map[info_game->player_y][info_game->player_x + 1 + x]
    == 'X') {
        if (info_game->map[info_game->player_y][info_game->player_x + 2 + x]
    == '#' || info_game->map[info_game->player_y][info_game->player_x + 2 + x]
    == 'X') {
            return -1;
        }
        if (info_game->map[info_game->player_y][info_game->player_x + 2 + x]
    != '#') {
            info_game->map[info_game->player_y][info_game->player_x + 2 + x]
            = 'X';
            info_game->map[info_game->player_y][info_game->player_x + 1 + x]
            = ' ';
            return 0;
        }
    }
    return 0;
}

int box_down(i_g *info_game, int y)
{
    if (info_game->map[info_game->player_y + 1 + y][info_game->player_x]
    == 'X') {
        if (info_game->map[info_game->player_y + 2 + y][info_game->player_x]
    == '#' || info_game->map[info_game->player_y + 2 + y][info_game->player_x]
    == 'X') {
            return -1;
        }
        if (info_game->map[info_game->player_y + 2 + y][info_game->player_x]
    != '#') {
            info_game->map[info_game->player_y + 2 + y][info_game->player_x]
            = 'X';
            info_game->map[info_game->player_y + 1 + y][info_game->player_x]
            = ' ';
            return 0;
        }
    }
    return 0;
}

int box_left(i_g *info_game, int x)
{
    if (info_game->map[info_game->player_y][info_game->player_x - 1 - x]
    == 'X') {
        if (info_game->map[info_game->player_y][info_game->player_x - 2 - x]
    == '#' || info_game->map[info_game->player_y][info_game->player_x - 2 - x]
    == 'X') {
            return -1;
        }
        if (info_game->map[info_game->player_y][info_game->player_x - 2 - x]
    != '#') {
            info_game->map[info_game->player_y][info_game->player_x - 2 - x]
            = 'X';
            info_game->map[info_game->player_y][info_game->player_x - 1 - x]
            = ' ';
            return 0;
        }
    }
    return 0;
}
