/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H
    typedef struct info_game {
        char** map;
        char** map_cp;
        int nbr_box;
        int nbr_trou;
        int player_x;
        int player_y;
        int stop_game;
        int box_x;
        int box_y;
    } i_g;

#endif /* !STRUCT_MENU_H */
