#include <stdio.h>
#include <stdbool.h>

#define TAM 10

// ---------- Funções utilitárias ----------

// Limpa o tabuleiro (zera tudo)
void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Imprime o tabuleiro formatado com letras e números
void imprimirTabuleiro(int tabuleiro[TAM][TAM], char lateral[]) {
    printf("   ");
    for (int i = 1; i <= TAM; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c ", lateral[i]);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Aplica uma habilidade no tabuleiro, se possível
void aplicarHabilidade(int habilidade[][5], int linhas, int colunas, int centroX, int centroY, int tabuleiro[TAM][TAM]) {
    int centroHabilidadeX = linhas / 2;
    int centroHabilidadeY = colunas / 2;
    bool dentroDosLimites = true;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int x = centroX - centroHabilidadeX + i;
            int y = centroY - centroHabilidadeY + j;
            if (habilidade[i][j] == 1) {
                if (x < 0 || x >= TAM || y < 0 || y >= TAM) {
                    dentroDosLimites = false;
                }
            }
        }
    }

    if (!dentroDosLimites) {
        printf("⚠️  Erro: habilidade fora dos limites do tabuleiro.\n");
        return;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int x = centroX - centroHabilidadeX + i;
            int y = centroY - centroHabilidadeY + j;
            if (habilidade[i][j] == 1) {
                tabuleiro[x][y] = 1;
            }
        }
    }
}

// Posiciona um navio com direção: 'H' (horizontal), 'V' (vertical), 'D' (diagonal direita), 'E' (diagonal esquerda)
bool posicionarNavio(int tabuleiro[TAM][TAM], char linhaChar, int coluna, char direcao) {
    int linha = linhaChar - 'A';
    coluna--; // ajustar para índice 0

    int dx[3], dy[3];

    if (direcao == 'H') {
        dx[0] = dx[1] = dx[2] = 0;
        dy[0] = -1; dy[1] = 0; dy[2] = 1;
    } else if (direcao == 'V') {
        dy[0] = dy[1] = dy[2] = 0;
        dx[0] = -1; dx[1] = 0; dx[2] = 1;
    } else if (direcao == 'D') {
        dx[0] = -1; dx[1] = 0; dx[2] = 1;
        dy[0] = -1; dy[1] = 0; dy[2] = 1;
    } else if (direcao == 'E') {
        dx[0] = -1; dx[1] = 0; dx[2] = 1;
        dy[0] = 1; dy[1] = 0; dy[2] = -1;
    } else {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        int nx = linha + dx[i];
        int ny = coluna + dy[i];
        if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM || tabuleiro[nx][ny] == 3) {
            return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        int nx = linha + dx[i];
        int ny = coluna + dy[i];
        tabuleiro[nx][ny] = 3;
    }

    return true;
}

// ---------- Função principal ----------

int main() {
    int tabuleiro[TAM][TAM];
    char lateral[TAM] = {'A','B','C','D','E','F','G','H','I','J'};
    limparTabuleiro(tabuleiro);

    // Habilidades pré-definidas
    int habilidadeCone[3][5], habilidadeCruz[5][5], habilidadeOcta[3][5];

    // Preenche Cone
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            habilidadeCone[i][j] = (j >= 2 - i && j <= 2 + i) ? 1 : 0;

    // Preenche Cruz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidadeCruz[i][j] = (i == 2 || j == 2) ? 1 : 0;

    // Preenche Octa
    for (int i = 0; i < 3; i++) {
        int d = (i < 1) ? 1 - i : i - 1;
        for (int j = 0; j < 5; j++)
            habilidadeOcta[i][j] = (j >= 2 - d && j <= 2 + d) ? 1 : 0;
    }

    // Posicionando navios
    printf("Posicione os navios (formato: A1 H para linha A, coluna 1, horizontal)\n");

    char linha;
    int coluna;

    if (!posicionarNavio(tabuleiro, 'A', 2, 'H')) printf("Erro ao posicionar navio 1\n");
    if (!posicionarNavio(tabuleiro, 'D', 4, 'V')) printf("Erro ao posicionar navio 2\n");
    if (!posicionarNavio(tabuleiro, 'F', 7, 'D')) printf("Erro ao posicionar navio 3\n");
    if (!posicionarNavio(tabuleiro, 'I', 2, 'E')) printf("Erro ao posicionar navio 4\n");

    imprimirTabuleiro(tabuleiro, lateral);

    // Menu de habilidades
    int opcao, x, y;
    do {
        printf("\n===== Menu de Habilidades =====\n");
        printf("1. Cone\n2. Cruz\n3. Octa\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("Digite a coordenada X (linha 0-9): ");
        scanf("%d", &x);
        printf("Digite a coordenada Y (coluna 0-9): ");
        scanf("%d", &y);

        switch (opcao) {
            case 1:
                aplicarHabilidade(habilidadeCone, 3, 5, x, y, tabuleiro);
                break;
            case 2:
                aplicarHabilidade(habilidadeCruz, 5, 5, x, y, tabuleiro);
                break;
            case 3:
                aplicarHabilidade(habilidadeOcta, 3, 5, x, y, tabuleiro);
                break;
            default:
                printf("Opção inválida.\n");
        }

        imprimirTabuleiro(tabuleiro, lateral);

    } while (opcao != 0);

    printf("Obrigado por jogar!\n");
    return 0;
}