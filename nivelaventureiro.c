#include <stdio.h>

#define SIZE 10 // Tamanho do tabuleiro
#define SHIP_SIZE 3 // Tamanho dos navios

void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int placeShip(int board[SIZE][SIZE], int row, int col, int length, char orientation) {
    if (orientation == 'H') { // Horizontal
        if (col + length > SIZE) return 0; // Excede os limites
        for (int i = 0; i < length; i++) {
            if (board[row][col + i] != 0) return 0; // Sobreposição
        }
        for (int i = 0; i < length; i++) {
            board[row][col + i] = 3; // Colocando o navio
        }
    } else if (orientation == 'V') { // Vertical
        if (row + length > SIZE) return 0; // Excede os limites
        for (int i = 0; i < length; i++) {
            if (board[row + i][col] != 0) return 0; // Sobreposição
        }
        for (int i = 0; i < length; i++) {
            board[row + i][col] = 3; // Colocando o navio
        }
    } else if (orientation == 'D') { // Diagonal
        if (row + length > SIZE || col + length > SIZE) return 0; // Excede os limites
        for (int i = 0; i < length; i++) {
            if (board[row + i][col + i] != 0) return 0; // Sobreposição
        }
        for (int i = 0; i < length; i++) {
            board[row + i][col + i] = 3; // Colocando o navio
        }
    }
    return 1; // Sucesso
}

int main() {
    int board[SIZE][SIZE] = {0}; // Inicializa o tabuleiro com água (0)

    // Posicionar navios
    if (placeShip(board, 1, 1, SHIP_SIZE, 'H')) {
        printf("Navio horizontal posicionado com sucesso.\n");
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    if (placeShip(board, 4, 4, SHIP_SIZE, 'V')) {
        printf("Navio vertical posicionado com sucesso.\n");
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    if (placeShip(board, 0, 0, SHIP_SIZE, 'D')) {
        printf("Navio diagonal posicionado com sucesso.\n");
    } else {
        printf("Erro ao posicionar navio diagonal.\n");
    }

    // Exibir o tabuleiro
    printBoard(board);
    return 0;
}
