#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HELP_BOARD  "     |     |     \n"\
                    "  A  |  B  |  C  \n"\
                    "_____|_____|_____\n"\
                    "     |     |     \n"\
                    "  D  |  E  |  F  \n"\
                    "_____|_____|_____\n"\
                    "     |     |     \n"\
                    "  G  |  H  |  I  \n"\
                    "     |     |     \n"\


#define HELP_STRING "Enter the letter corresponding character to\n"\
                    "the spot you'd like to take.\n"\
                    "Valid spot characters:\n"\
                    "a, A, b, B, c, C, d, D, e, E, f, F, g, G, h, H, i, I"\
                    "\n"\
                    "m, M, and ? display this message.\n"\
                    "q and Q quits the game.\n"


#define BOARD_SIZE 162


typedef struct
{
    char * board;
    int help, moves, player_turn;
} game_t;


#define A_SPOT 20
#define B_SPOT 26
#define C_SPOT 32
#define D_SPOT 74
#define E_SPOT 80
#define F_SPOT 86
#define G_SPOT 128
#define H_SPOT 134
#define I_SPOT 140


#define PLACE_X(board, spot) { \
    *(board + spot) = 'X'; \
}


#define PLACE_O(board, spot) { \
    *(board + spot) = 'O'; \
}


int
CHECK_A(char * board, char c);


int
CHECK_B(char * board, char c);


int
CHECK_C(char * board, char c);


int
CHECK_D(char * board, char c);


int
CHECK_E(char * board, char c);


int
CHECK_F(char * board, char c);


int
CHECK_G(char * board, char c);


int
CHECK_H(char * board, char c);


int
CHECK_I(char * board, char c);


int
CHECK_SPOT(char * board, char c, int spot);

int
CHECK_WIN(char * board, char c);


game_t *
new_game(void);


void
print_player_turn(game_t * game);


int
get_move(game_t * game);


void
print_help(void);


void
play(void);


#endif
