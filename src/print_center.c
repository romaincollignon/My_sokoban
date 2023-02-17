/*
** EPITECH PROJECT, 2022
** print_center.c
** File description:
** print center and verif size window is good
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "struct_all.h"
#include "my.h"

int calc_lenght_d_char(char **map)
{
    int tmp = 0;
    int x = 0;
    for (int y = 0; map[y] != NULL; y++) {
        x = 0;
        for (; map[y][x] != '\0'; x++);
        if (tmp < x)
            tmp = x;
    }
    return tmp;
}

int calc_height_d_char(char **map)
{
    int h = 0;
    while (map[h] != NULL)
        h++;
    return h;
}

void print_center(WINDOW *win, int start_row, char **map)
{
    clear();
    char *txt = "The window is too small !";
    char *len_map = map[0];
    int len_txt = my_strlen(txt);
    int center_col = win->_maxx / 2;
    int half_lenght = my_strlen(len_map) / 2;
    int adjusted_col = center_col - half_lenght;
    int adjusted_col_txt = center_col - (len_txt / 2);
    int adjusted_l_txt = win->_maxy / 2;
    if (calc_height_d_char(map) - 1 > win->_maxy || calc_lenght_d_char(map) >
    win->_maxx){
        mvwprintw(win, adjusted_l_txt, adjusted_col_txt , txt);
        refresh();
        return;
    }
    if (calc_height_d_char(map) <= win->_maxx) {
        for (int i = 0; map[i] != NULL; i++)
            mvwprintw(win, i + start_row, adjusted_col, map[i]);
    }
}
