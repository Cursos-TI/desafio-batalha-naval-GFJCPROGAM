#include <stdio.h>

#define SIZE 10
#define SHIP 3
#define WATER 0
#define ATTACK 5 // Dano do ataque em área

void initializeBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = WATER;
        }
    }
}

void printBoard(int board[SIZE][SIZE]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void attackArea(int board[SIZE][SIZE], int row, int col) {
    // ataque em toda a coluna
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][col] == SHIP) {
            board[i][col] = WATER; // Destrói o navio
            printf("Navio destruído na coluna %d, linha %d!\n", col, i);
        }
    }
}

int main() {
    int board[SIZE][SIZE];
    initializeBoard(board);
    
    // Coloque navios (exemplo)
    board[1][2] = SHIP;
    board[3][2] = SHIP;

    printBoard(board);
    
    // Executar ataque em área
    attackArea(board, 0, 2); // Ataque na coluna 2
    
    printBoard(board);
    
    return 0;
}    
