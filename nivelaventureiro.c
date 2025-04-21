#include <stdio.h>

#define TAM 10
#define NAVIO 3 

void inicializaTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionaNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna <= TAM - NAVIO) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linha][coluna + j] = NAVIO; 
        }
    }
}

void posicionaNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha <= TAM - NAVIO) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linha + j][coluna] = NAVIO; 
        }
    }
}

void posicionaNavioDiagonalDir(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha <= TAM - NAVIO && coluna <= TAM - NAVIO) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linha + j][coluna + j] = NAVIO;  
        }
    }
}

void posicionaNavioDiagonalEsq(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha <= TAM - NAVIO && coluna >= NAVIO - 1) {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linha + j][coluna - j] = NAVIO;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializaTabuleiro(tabuleiro);
    
    // Posicionando navios
    posicionaNavioHorizontal(tabuleiro, 1, 2);
    posicionaNavioVertical(tabuleiro, 3, 5);
    posicionaNavioDiagonalDir(tabuleiro, 0, 0); 
    posicionaNavioDiagonalEsq(tabuleiro, 2, 7); 

    // Exibição do tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
