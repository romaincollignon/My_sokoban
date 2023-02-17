/*
** EPITECH PROJECT, 2022
** win_won.c
** File description:
** verif game win or game won
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

int verif_win_char(char char_map)
{
    if (char_map == 'O') {
        return 1;
    } else {
        return 0;
    }
}

void verif_win(i_g *info_game, char **map_cp)
{
    char **tmp_map = info_game->map;
    int player_x = info_game->player_x;
    int player_y = info_game->player_y;
    int tmp = 0;

    if (map_cp[player_y][player_x] == 'O')
        tmp++;
    for (int y = 0; tmp_map[y] != NULL; y++) {
        for (int x = 0; tmp_map[y][x] != '\0'; x++) {
            tmp += verif_win_char(tmp_map[y][x]);
        }
    }
    if (tmp == 0)
        info_game->stop_game = 1;
}

int verif_won_char_box(char char_map, i_g *info_game, int x, int y)
{
    if (info_game->map[y][x] == info_game->map_cp[y][x]) {
        if (char_map == 'X')
            return (1);
        return (0);
    }
    if (char_map != 'X' && y != 0)
        return (0);
    int tmp = 0;
    if (info_game->map[y][x + 1] == 'X' || info_game->map[y][x + 1] == '#') {
        tmp++;
    }
    if (info_game->map[y + 1][x + 1] == 'X' ||
    info_game->map[y + 1][x + 1] == '#') {
        tmp++;
    }
    if (info_game->map[y + 1][x] == 'X' || info_game->map[y + 1][x] == '#')
        tmp++;
    if (tmp >= 3)
        return (0);
    return (1);
}

int verif_won_char(char char_map, i_g *info_game, int x, int y)
{
    if (char_map != 'X')
        return (0);
    int tmp_y = 0;
    int tmp_x = 0;
    if (info_game->map[y + 1][x] == '#')
        tmp_y++;
    if (info_game->map[y][x + 1] == '#')
        tmp_x++;
    if (info_game->map[y - 1][x] == '#')
        if (tmp_y == 0)
            tmp_y++;
    if (info_game->map[y][x - 1] == '#')
        if (tmp_x == 0)
            tmp_x++;
    if (tmp_x + tmp_y >= 2)
        return (0);
    return (1);
}

void verif_won(i_g *info_game)
{
    char **tmp_map = info_game->map;
    int nb_box = 0;
    for (int y = 0; tmp_map[y] != NULL; y++) {
        for (int x = 0; tmp_map[y][x] != '\0'; x++) {
            nb_box += check_boxs(tmp_map[y][x], info_game, x, y);
        }
    }
    if (nb_box == 0) {
        info_game->stop_game = 2;
    }
}
