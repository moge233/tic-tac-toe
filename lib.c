#include "defs.h"


char BOARD[BOARD_SIZE] = ""
"     |     |     \n"
"     |     |     \n"
"_____|_____|_____\n"
"     |     |     \n"
"     |     |     \n"
"_____|_____|_____\n"
"     |     |     \n"
"     |     |     \n"
"     |     |     \n";


/*
 * CHECK_ functions return 1 if a spot is taken, 0 if not
 */

int
CHECK_A(char * board, char c)
{
    return (*(board + A_SPOT) == c);
}


int
CHECK_B(char * board, char c)
{
    return (*(board + B_SPOT) == c);
}


int
CHECK_C(char * board, char c)
{
    return (*(board + C_SPOT) == c);
}


int
CHECK_D(char * board, char c)
{
    return (*(board + D_SPOT) == c);
}


int
CHECK_E(char * board, char c)
{
    return (*(board + E_SPOT) == c);
}


int
CHECK_F(char * board, char c)
{
    return (*(board + F_SPOT) == c);
}


int
CHECK_G(char * board, char c)
{
    return (*(board + G_SPOT) == c);
}


int
CHECK_H(char * board, char c)
{
    return (*(board + H_SPOT) == c);
}


int
CHECK_I(char * board, char c)
{
    return (*(board + I_SPOT) == c);
}


int
CHECK_SPOT(char * board, char c, int spot)
{
    switch(spot)
    {
        case A_SPOT:
            return CHECK_A(board, c);
        case B_SPOT:
            return CHECK_B(board, c);
        case C_SPOT:
            return CHECK_C(board, c);
        case D_SPOT:
            return CHECK_D(board, c);
        case E_SPOT:
            return CHECK_E(board, c);
        case F_SPOT:
            return CHECK_F(board, c);
        case G_SPOT:
            return CHECK_G(board, c);
        case H_SPOT:
            return CHECK_H(board, c);
        case I_SPOT:
            return CHECK_I(board, c);
        default:
            return 0;
    }
}


int
CHECK_WIN(char * board, char c)
{
    if(CHECK_A(board, c))
    {
        if ((CHECK_B(board, c) & CHECK_C(board, c))
            | (CHECK_D(board, c) & CHECK_G(board, c))
            | (CHECK_E(board, c) & CHECK_I(board, c)))
            return 1;
    }
    if(CHECK_B(board, c))
    {
        if (CHECK_E(board, c) & CHECK_H(board, c))
            return 1;
    }
    if(CHECK_C(board, c))
    {
        if ((CHECK_E(board, c) & CHECK_G(board, c))
            | (CHECK_F(board, c) & CHECK_I(board, c)))
            return 1;
    }
    if(CHECK_D(board, c))
    {
        if (CHECK_E(board, c) & CHECK_F(board, c))
            return 1;
    }
    if(CHECK_G(board, c))
    {
        if (CHECK_H(board, c) & CHECK_I(board, c))
            return 1;
    }
    return 0;
}


game_t *
new_game(void)
{
    game_t * game = malloc(sizeof(game_t *));
    game->board = malloc(BOARD_SIZE);
    game->board = BOARD;
    game->player_turn = 0;
    game->moves = 0;
    return game;
}


void
print_player_turn(game_t * game)
{
    if (game->player_turn == 0)
        printf("PLAYER 1: ");
    else
        printf("PLAYER 2: ");
    return;
}


int
get_move(game_t * game)
{
    char c;
    int i;
    c = getchar();
    i = 0;
    while (strrchr("aAbBcCdDeEfFgGhHiImMqQ?", c) == NULL)
    {
        if (i++ > 0)
            printf("\nInvalid character.\n");
        print_player_turn(game);
        c = getchar();
    }
    switch(c)
    {
        case 'a':
        case 'A':
            return A_SPOT;
        case 'b':
        case 'B':
            return B_SPOT;
        case 'c':
        case 'C':
            return C_SPOT;
        case 'd':
        case 'D':
            return D_SPOT;
        case 'e':
        case 'E':
            return E_SPOT;
        case 'f':
        case 'F':
            return F_SPOT;
        case 'g':
        case 'G':
            return G_SPOT;
        case 'h':
        case 'H':
            return H_SPOT;
        case 'i':
        case 'I':
            return I_SPOT;
        case 'm':
        case 'M':
        case '?':
            print_help();
            return 1;
        case 'q':
        case 'Q':
            exit(0);
        default:
            printf("Not a valid spot.\n");
            return 0;
    }
    return 0;
}


void
print_help(void)
{
    printf("%s\n", HELP_BOARD);
    printf("%s\n", HELP_STRING);
    return;
}


void
play(void)
{
    /*
     * Play a game of tic-tac-toe
     */

    game_t * game = new_game();
    int game_over, move;
    game_over = 0;
    move = 0;
    printf("%s\n", game->board);
    print_player_turn(game);
    while (!game_over)
    {
        while (!move)
        {
            move = get_move(game);
            if (CHECK_SPOT(game->board, 'X', move)
                || CHECK_SPOT(game->board, 'O', move))
            {
                printf("Spot's taken.\n");
                move = 0;
            }
        }
        if (!game->player_turn && (move != 1))
        {
            PLACE_X(game->board, move);
            printf("%s\n", game->board);
            game->player_turn = 1;
            if (game->moves >= 4)
                if (CHECK_WIN(game->board, 'X'))
                {
                    printf("Player 1 wins!\n");
                    game_over = 1;
                }
            move = 0;
            ++(game->moves);
        }
        else if (game->player_turn && (move != 1))
        {
            PLACE_O(game->board, move);
            printf("%s\n", game->board);
            game->player_turn = 0;
            if (game->moves >= 4)
                if (CHECK_WIN(game->board, 'O'))
                {
                    printf("Player 2 wins!\n");
                    game_over = 1;
                }
            move = 0;
            ++(game->moves);
        }
        else
            ;
        if (((game->moves) >= 9) && !game_over)
        {
            printf("Draw: Game Over\n");
            game_over = 1;
        }
        if (move == 1)
            move = 0;
    }
    return;
}
