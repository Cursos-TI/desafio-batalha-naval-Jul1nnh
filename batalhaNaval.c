#include <stdio.h>

#define TAMANHO 10
#define NAVIO 7

int matriz[TAMANHO][TAMANHO] = {0};

int valida_posicao(int linha, int coluna, int tamanho, int direcao){
    for(int i = 0; i < tamanho; i++) {
        int l = linha, c = coluna;

        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l -= i, c += i; }
        else if (direcao == 'd') { l += i, c += i; }

        //verifica limites
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO)
            return 0;

        //verifica se ja tem navio
        if (matriz[l][c] != 0)
            return 0;
    }
    return 1;
}

void posiciona_navio(int linha, int coluna, int tamanho, int direcao){
    for (int i = 0; i < tamanho; i++){
        int l = linha, c = coluna;

        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l -= i, c += i; }
        else if (direcao == 'd') { l += i, c += i; }

        matriz [l][c] = NAVIO;
    }
}

void triangulo(int linha_ancora, int coluna_ancora) {
    int habilidade[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5}
    };

    int linha_base = linha_ancora - 0;
    int coluna_base = coluna_ancora - 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 5) {
                int l = linha_base + i;
                int c = coluna_base + j;

                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                    if (matriz[l][c] == NAVIO) {
                        matriz[l][c] = 1; // navio atingido
                    } else {
                        matriz[l][c] = 5; // marca da habilidade
                    }
                }
            }
        }
    }
}

void cruz(int linha_ancora, int coluna_ancora) {
    int habilidade[3][3] = {
        {0, 5, 0},
        {5, 5, 5},
        {0, 5, 0}
    };

    int linha_base = linha_ancora - 1;
    int coluna_base = coluna_ancora - 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (habilidade[i][j] == 5) {
                int l = linha_base + i;
                int c = coluna_base + j;

                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                    if (matriz[l][c] == NAVIO) {
                        matriz[l][c] = 1;
                    } else {
                        matriz[l][c] = 5;
                    }
                }
            }
        }
    }
}

void cruz_maior(int linha_ancora, int coluna_ancora) {
    int habilidade[3][5] = {
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0}
    };

    int linha_base = linha_ancora - 1;
    int coluna_base = coluna_ancora - 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 5) {
                int l = linha_base + i;
                int c = coluna_base + j;

                if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO) {
                    if (matriz[l][c] == NAVIO) {
                        matriz[l][c] = 1;
                    } else {
                        matriz[l][c] = 5;
                    }
                }
            }
        }
    }
}

int main(){
    int linha1 = 3, coluna1 = 2; // navio horizontal
    if (valida_posicao(linha1, coluna1, 3, 'H')) {
         posiciona_navio(linha1, coluna1, 3, 'H'); 
    } else {
        printf("NAVIO HORIZONTAL INVALIDO!\n"); 
    }

    int linha2 = 5, coluna2 = 7; // navio vertical
    if (valida_posicao(linha2, coluna2, 3, 'V')) {
         posiciona_navio(linha2, coluna2, 3, 'V'); 
    } else {
        printf("NAVIO VERTICAL INVALIDO!\n"); 
    }

    int linha3 = 9, coluna3 = 0; // navio diagonal(cima-direita)
    if (valida_posicao(linha3, coluna3, 3, 'D')) {
         posiciona_navio(linha3, coluna3, 3, 'D'); 
    } else {
        printf("NAVIO DIAGONAL INVALIDO!\n"); 
    }

    int linha4 = 0, coluna4 = 7; // navio diagonal(baixo-direita)
    if (valida_posicao(linha4, coluna4, 3, 'd')) {
         posiciona_navio(linha4, coluna4, 3, 'd'); 
    } else {
        printf("NAVIO DIAGONAL INVALIDO!\n"); 
    }

    triangulo(2, 3);
    cruz(7, 3);
    cruz_maior(1, 7);

    //imprimir matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
