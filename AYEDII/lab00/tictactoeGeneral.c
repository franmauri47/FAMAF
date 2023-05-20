#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define N 5 //Constante que define el tamaño del tablero
#define CELL_MAX (N * N - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[N][N])
{
    int cell = 0;

    print_sep(N);
    for (int row = 0; row < N; ++row) {
        for (int column = 0; column < N; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(N);
    }
}

char get_winner(char board[N][N])
{    
    char winner = '-';    
    char initial;
    for(int row = 0; row < N; row++){
        initial = board[row][0];
        for(int column = 1; column < N; column++){
            if(board[row][column] == initial){
                winner = initial;
            } else {
                winner = '-';
                break;
            }
        }
        if (winner == initial){
            break;
        }
    }

    if(winner == '-'){
        for (int column = 0; column < N; column++){
            initial = board[0][column];
            for(int row=1; row < N; row++){
                if(board[row][column] == initial){
                    winner = initial;
                } else {
                    winner = '-';
                    break;
                }
            }
            if (winner == initial){
            break;
            }
        }
    }

    if(winner == '-'){
        initial = board[0][0];
        for (int pos = 0; pos < N; pos++){
            if (board[pos][pos] == initial){
                winner = initial;
            } else{
                winner = '-';
                break;
            }
        }
    }

    if(winner == '-'){        
        int posh = (N-1);
        int posv = 0;
        initial = board[posh][posv];
        while (posh >= 0){
            if (board[posh][posv] == initial){
                winner = initial;
            } else{
                winner = '-';
                break;
            }
            posh = (posh - 1);
            posv = (posv + 1);
        }        
    }
    return winner;
}

bool has_free_cell(char board[N][N])
{
    bool free_cell=false;
    for (int row=0; row < N; row++){
        for (int column=0; column < N; column++){
            if(board[row][column] == '-'){
                free_cell=true;
            }
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[N][N];
    for (int row = 0; row < N; row++) {
      for (int column = 0; column < N; column++) {
         board[row][column] = '-';
      }
   }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / N;
            int colum = cell % N;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
