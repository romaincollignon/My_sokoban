/*
** EPITECH PROJECT, 2022
** init_struct.c
** File description:
** full initalisation struct
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "struct_all.h"
#include "my.h"


int verif_player(int a, char **map, int y, int x)
{
    if (a == 0 && map[y][x] == 'P')
        return y;
    if (a == 1 && map[y][x] == 'P')
        return x;
    return 0;
}

int init_player(int a, char **map)
{
    int result = 0;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            result += verif_player(a, map, y, x);
        }
        if (result != 0)
            return result;
    }
    return result;
}

int verif_box(int a, char c)
{
    if (c == 'O' && a == 0)
        return 1;
    if (c == 'X' && a == 1)
        return 1;
    return 0;
}

int init_box_trou(int a, char **map)
{
    int result = 0;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            result += verif_box(a, map[y][x]);
        }
    }
    return result;
}

char **init_struct(char **av, i_g *info_game)
{
    info_game->map = read_file(av);
    info_game->map_cp = read_file(av);
    info_game->nbr_box = init_box_trou(0, info_game->map);
    info_game->nbr_trou = init_box_trou(1, info_game->map);
    info_game->player_y = init_player(0, info_game->map);
    info_game->player_x = init_player(1, info_game->map);
    info_game->stop_game = 0;
    return read_file(av);
}
