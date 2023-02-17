/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
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

int check_boxs(char fryed, i_g *info_game, int x, int y)
{
    if (verif_won_char_box(fryed, info_game, x, y) == 1 &&
        verif_won_char(fryed, info_game, x, y) == 1)
        return (1);
    return (0);
}

int load_map(i_g *info_game, int tmp)
{
    if (tmp == 1)
        mv_up(info_game);
    if (tmp == 2)
        mv_right(info_game);
    if (tmp == 3)
        mv_down(info_game);
    if (tmp == 4)
        mv_left(info_game);
    return 0;
}

int main_sokoban(char **av)
{
    i_g *info_game = malloc(sizeof(i_g));
    char **map_cp = init_struct(av, info_game);
    initscr();
    keypad(stdscr, TRUE);
    int tmp = 0;
    while (info_game->stop_game == 0){
        refresh();
        print_center(stdscr, 0, info_game->map);
        int info_periph = getch();
        tmp = periph(info_periph, av, info_game);
        tmp = load_map(info_game, tmp);
        main_game_won_win(info_game, map_cp);
    }
    print_center(stdscr, 0, info_game->map);
    endwin();
    print_win_won(info_game);
    return 0;
}
