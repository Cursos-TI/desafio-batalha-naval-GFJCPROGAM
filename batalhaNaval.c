#include <stdio.h>

#define SIZE 10 // Tamanho do tabuleiro
#define SHIP_SIZE 3 // Tamanho dos navios

int main() {
    int board[SIZE][SIZE]; // Matriz que representa o tabuleiro
    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int h_ship_row = 2;
    int h_ship_col = 3;

    // Colocar navio horizontal na matriz
    for (int j = 0; j < SHIP_SIZE; j++) {
        board[h_ship_row][h_ship_col + j] = 3; // Representa o navio com 3
    }

    // Coordenadas iniciais do navio vertical
    int v_ship_row = 5;
    int v_ship_col = 5;

    // Colocar navio vertical na matriz
    for (int i = 0; i < SHIP_SIZE; i++) {
        board[v_ship_row + i][v_ship_col] = 3; // Representa o navio com 3
    }

    // Exibir o tabuleiro
    printf("Tabuleiro do Batalha Naval:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]); // Imprime 0 para água e 3 para o navio
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    return 0;
}
