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

void verif_map(i_g *info_game)
{
    if (info_game->map_cp[info_game->player_y][info_game->player_x] == 'O')
        info_game->map[info_game->player_y][info_game->player_x] = 'O';
    else
        info_game->map[info_game->player_y][info_game->player_x] = ' ';
}

void mv_up(i_g *info_game)
{
    if (info_game->player_y - 1 < 0)
        return;
    if (info_game->map[info_game->player_y - 1][info_game->player_x] != '#') {
        if (verif_box_mv(info_game, 1) == -1) {
            return;
        }
        info_game->map[info_game->player_y - 1][info_game->player_x] = 'P';
        verif_map(info_game);
        info_game->player_y -= 1;
    }
}

void mv_right(i_g *info_game)
{
    if (info_game->map[info_game->player_y + 1][info_game->player_x] == '0')
        return;
    if (info_game->map[info_game->player_y][info_game->player_x + 1] != '#') {
        if (verif_box_mv(info_game, 2) == -1) {
            return;
        }
        info_game->map[info_game->player_y][info_game->player_x + 1] = 'P';
        verif_map(info_game);
        info_game->player_x += 1;
    }
}

void mv_down(i_g *info_game)
{
    if (info_game->map[info_game->player_y + 1] == NULL)
        return;
    if (info_game->map[info_game->player_y + 1][info_game->player_x] != '#') {
        if (verif_box_mv(info_game, 3) == -1) {
            return;
        }
        info_game->map[info_game->player_y + 1][info_game->player_x] = 'P';
        verif_map(info_game);
        info_game->player_y += 1;
    }
}

void mv_left(i_g *info_game)
{
    if (info_game->player_x - 1 < 0)
        return;
    if (info_game->map[info_game->player_y][info_game->player_x - 1] != '#') {
        if (verif_box_mv(info_game, 4) == -1) {
            return;
        }
        info_game->map[info_game->player_y][info_game->player_x - 1] = 'P';
        verif_map(info_game);
        info_game->player_x -= 1;
    }
}
