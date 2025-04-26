#include <stdio.h>

int main() { 
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Array de caracteres para as linhas do tabuleiro
    int i, j;
    int tabuleiro [10][10] = {

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}    
    };
    
        // Exibindo o tabuleiro
        printf("TABULEIRO BATALHA NAVAL:\n");
        printf("   1  2  3  4  5  6  7  8  9  10\n"); // Imprime o cabeçalho do tabuleiro
        for (i = 0; i < 10; i++) {
            printf("%c ", linha[i]); // Imprime as linhas do tabuleiro
            for (j = 0; j < 10; j++) {
                printf(" %d ", tabuleiro[i][j]); // Imprime o valor do tabuleiro
            }
            printf("\n");
        }
    // Preenchendo o tabuleiro com valores de exemplo (3 representa um navio, 0 representa água)

    //posicionando o primeiro navio
    printf("Posicionando o primeiro navio...(HORIZONTAL)\n");
    printf("Cada navio ocupa 3 posições, selecione a posiçao do centro do navio (casa do meio)\n");
    printf("Digite a linha e a coluna para posicionar o primeiro navio (ex: A1): ");
    
    char linhaNavio1;
    int colunaNavio1;

    scanf(" %c%d", &linhaNavio1, &colunaNavio1);
    if (linhaNavio1 < 'A' || linhaNavio1 > 'J' || colunaNavio1 < 1 || colunaNavio1 > 10) {
        printf("Posição inválida! Tente novamente.\n");
        return 1;
    }
    else if (tabuleiro[linhaNavio1 - 'A'][colunaNavio1 - 1] == 3 ||
        tabuleiro[linhaNavio1 - 'A'][colunaNavio1] == 3 ||
        tabuleiro[linhaNavio1 - 'A'][colunaNavio1 + 1] == 3) 
        {
        printf("Não é possível posicionar o navio aqui!\n");

        return 1;
    } else {
        tabuleiro[linhaNavio1 - 'A'][colunaNavio1 - 1] = 3;
        tabuleiro[linhaNavio1 - 'A'][colunaNavio1] = 3;
        tabuleiro[linhaNavio1 - 'A'][colunaNavio1 + 1] = 3;
    }

    //posicionando o segundo navio
    printf("Posicionando o segundo navio...(VERTICAL)\n");
    printf("Digite a linha e a coluna do segundo navio (ex: D4): ");

    char linhaNavio2;
    int colunaNavio2;

    scanf(" %c%d", &linhaNavio2, &colunaNavio2);
    if (linhaNavio2 < 'A' || linhaNavio2 > 'J' || colunaNavio2 < 1 || colunaNavio2 > 10) {
        printf("Posição inválida! Tente novamente.\n");
        return 1; // Retorna 1 para indicar erro
    }
    else if (tabuleiro[linhaNavio2 - 'A'][colunaNavio2 - 1] == 3 || 
        tabuleiro[linhaNavio2 - 'A'][colunaNavio2] == 3 || 
        tabuleiro[linhaNavio2 - 'A'][colunaNavio2 + 1] == 3) {
        printf("Não é possível posicionar o navio aqui!\n");
        return 1; // Retorna 1 para indicar erro
    } 
    else if (tabuleiro[linhaNavio2 - 'A'][colunaNavio2 - 1] == 3 || 
            tabuleiro[linhaNavio2 - 'A'][colunaNavio2] == 3 || 
            tabuleiro[linhaNavio2 - 'A'][colunaNavio2 + 1] == 3) {
        printf("Não é possível posicionar o navio aqui!\n");
    }
     else {
        tabuleiro[linhaNavio2 - 'A' - 1][colunaNavio2] = 3;
        tabuleiro[linhaNavio2 - 'A'][colunaNavio2] = 3;
        tabuleiro[linhaNavio2 - 'A' + 1][colunaNavio2] = 3;
    }

    // Exibindo o tabuleiro
    printf("TABULEIRO BATALHA NAVAL:\n");
        printf("   1  2  3  4  5  6  7  8  9  10\n"); // Imprime o cabeçalho do tabuleiro
        for (i = 0; i < 10; i++) {
            printf("%c ", linha[i]); // Imprime as linhas do tabuleiro
            for (j = 0; j < 10; j++) {
                printf(" %d ", tabuleiro[i][j]); // Imprime o valor do tabuleiro
            }
        printf("\n");
    }
    printf("Navios Posicionados com sucesso!\n");
    return 0;
}