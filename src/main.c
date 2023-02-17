/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> sokoban
*/


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "struct_all.h"
#include "my.h"


void main_game_won_win(i_g *info_game, char** cp_map)
{
    verif_win(info_game, cp_map);
    verif_won(info_game);
}

int main(int ac, char **av, char **env)
{
    if (!env || !env[0])
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        print_credit();
        return 0;
    }
    error(ac);
    main_sokoban(av);
    return 0;
}
