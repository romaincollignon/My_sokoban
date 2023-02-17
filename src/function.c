/*
** EPITECH PROJECT, 2022
** function.c
** File description:
** function
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "struct_all.h"
#include "my.h"

char **read_file(char *av[])
{
    struct stat st;
    stat(av[1], &st);
    if (st.st_size == 0)
        exit (84);
    char *file = malloc(sizeof(char) * (st.st_size + 1));
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit (84);
    read(fd, file, st.st_size);
    file[st.st_size] = '\0';
    close(fd);
    char **B_file = my_str_to_word_array(file);
    free(file);
    return (B_file);
}

void error(int ac)
{
    if (ac == 1) {
        write(2, "Enter argument\n", my_strlen("Enter argument\n"));
        exit (84);
    }
    if (ac != 2) {
        write(2, "Error argument\n", my_strlen("Error argument\n"));
        exit (84);
    }
}

void print_win_won(i_g *info_game)
{
    if (info_game->stop_game == 1) {
        exit (0);
    }
    if (info_game->stop_game == 2) {
        exit (1);
    }
}

void print_credit(void)
{
    mini_printf("USAGE\n");
    mini_printf("     ./my_sokoban map\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("     map file representing the warehouse map, containing ’#’ \
for walls,\n         ’P’ for the player, ’X’ for boxes and ’O’ for \
storage locations.\n");
}
