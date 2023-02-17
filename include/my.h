/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes and include
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>

    #include "struct_all.h"
    #include "my.h"

    int mini_printf(const char *format, ...);
    char **read_file(char *av[]);
    void print_center(WINDOW *win, int start_row, char **map);
    int my_strlen(char const *str);
    void error(int ac);
    int calc_height(char **map);
    char **my_str_to_word_array(char *b_tab);
    int verif_box(int a, char c);
    char **init_struct(char **av, i_g *info_game);
    int init_box_trou(int a, char **map);
    int init_player(int a, char **map);
    int load_map(i_g *info_game, int tmp);
    int main_sokoban(char **av);
    int periph(int getch, char **av, i_g *info_game);
    void mv_up(i_g *info_game);
    void mv_right(i_g *info_game);
    void mv_down(i_g *info_game);
    void mv_left(i_g *info_game);
    int void_box_up(i_g *info_game);
    void verif_map(i_g *info_game);
    int verif_box_mv(i_g *info_game, int i);
    int box_up(i_g *info_game, int y);
    int box_right(i_g *info_game, int x);
    int box_down(i_g *info_game, int y);
    int box_left(i_g *info_game, int x);
    void print_win_won(i_g *info_game);
    void print_credit(void);
    void verif_won(i_g *info_game);
    void verif_win(i_g *info_game, char **map_cp);
    void main_game_won_win(i_g *info_game, char** cp_map);
    int check_boxs(char fryed, i_g *info_game, int x, int y);
    int verif_won_char(char char_map, i_g *info_game, int x, int y);
    int verif_won_char_box(char char_map, i_g *info_game, int x, int y);

#endif /* !MY_H_ */
