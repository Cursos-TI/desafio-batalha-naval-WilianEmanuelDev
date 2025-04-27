#include <stdio.h>

#define linhas 10 // Define o número de linhas do tabuleiro
#define coluna 10 // Define o número de colunas do tabuleiro
// Define o tamanho do tabuleiro como 10x10
int main() 
{ 

    // Declaração de variáveis
    char lateralTab[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Array de caracteres para as linhas do tabuleiro
    int i, j, k;
    int tabuleiro[linhas][coluna] = {0}; // Inicializa o tabuleiro com 0 (água)
    char linhaNavio1, linhaNavio2, linhaNavio3, linhaNavio4; // Variáveis para armazenar a linha dos navios
    int colunaNavio1, colunaNavio2, colunaNavio3, colunaNavio4; // Variáveis para armazenar a coluna dos navios

    // Inicializa o tabuleiro com 0 (água)
    printf("TABULEIRO BATALHA NAVAL:\n");
    printf("  1  2  3  4  5  6  7  8  9  10\n"); // Imprime o cabeçalho do tabuleiro
        for (i = 0; i < linhas; i++) {
        printf("%c", lateralTab[i]); // Imprime as linhas do tabuleiro
            for (j = 0; j < coluna; j++) {
            printf(" %d ", tabuleiro[i][j]); // Imprime o valor do tabuleiro
        }
        printf("\n");
    }
    
    //posicionando o primeiro navio
    printf("Posicionando o primeiro navio...(HORIZONTAL)\n");
    printf("Cada navio ocupa 3 posições, selecione a posiçao do centro do navio (casa do meio)\n");
    printf("Digite a linha e a coluna para posicionar o primeiro navio (ex: A1): ");

    scanf(" %c%d", &linhaNavio1, &colunaNavio1);
    if (linhaNavio1 < 'A' || linhaNavio1 > 'J' || colunaNavio1 < 1 || colunaNavio1 > 10) {
        printf("Posição inválida! Tente novamente.\n");
        return 1;
    }
        else
        for (k = 0; k < 3; k++) {
            if (tabuleiro[linhaNavio1 - 'A'][colunaNavio1 - 1] == 3) {
                printf("Não é possível posicionar o navio aqui!\n"); // Verifica se a posição já está ocupada
                return 1; // Retorna 1 para indicar erro
            }
        }    
        for (k = 0; k < 3; k++) {
            tabuleiro[linhaNavio1 - 'A'][colunaNavio1 - 1 + k] = 3;
    }

    //posicionando o segundo navio
    printf("Posicionando o segundo navio...(VERTICAL)\n");
    printf("Digite a linha e a coluna do segundo navio (ex: D4): ");

    scanf(" %c%d", &linhaNavio2, &colunaNavio2);
    if (linhaNavio2 < 'A' || linhaNavio2 > 'J' || colunaNavio2 < 1 || colunaNavio2 > 10) {
        printf("Posição inválida! Tente novamente.\n");
        return 1; // Retorna 1 para indicar erro
    }
    else
        for (k = 0; k < 3; k++) {
            if (tabuleiro[linhaNavio2 - 'A' - 1 + k][colunaNavio2 - 1] == 3) {
                printf("Não é possível posicionar o navio aqui!\n"); // Verifica se a posição já está ocupada
                return 1; // Retorna 1 para indicar erro
            }
        }    
        for (k = 0; k < 3; k++) {
            tabuleiro[linhaNavio2 - 'A' + k][colunaNavio2 - 1] = 3;
    }

    //posicionando o terceiro navio
    printf("Posicionando o terceiro navio...(DIAGONAL)\n");
    printf("Digite a linha e a coluna para posicionar o terceiro navio (ex: F7): ");
    
  
    scanf(" %c%d", &linhaNavio3, &colunaNavio3);
    
    if (linhaNavio3 < 'A' || linhaNavio3 > 'J' || colunaNavio3 < 1 || colunaNavio3 > 10) {
        printf("Posição inválida! Tente novamente.\n");
        return 1;
    }
    else {
        for (k = 0; k < 3; k++) {
            if (tabuleiro[linhaNavio3 - 'A' - 1 + k][colunaNavio3 - k] == 3) {
                printf("Não é possível posicionar o navio aqui!\n");
                return 1;
            }
        }
        for (k = 0; k < 3; k++) {
            tabuleiro[linhaNavio3 - 'A' - 1 + k][colunaNavio3 - k] = 3;
        }
        
    }
    //posicionando o quarto navio
        printf("Digite a linha e a coluna para posicionar o quarto navio (ex: I2): ");
        scanf(" %c%d", &linhaNavio4, &colunaNavio4);
        
        if (linhaNavio4 < 'A' || linhaNavio4 > 'J' || colunaNavio4 < 1 || colunaNavio4 > 10) {
            printf("Posição inválida! Tente novamente.\n");
            return 1;
        } else
            for (k = 0; k < 3; k++) {
                if (tabuleiro[linhaNavio4 - 'A' - k][colunaNavio4 - 1 + k] == 3) {
                    printf("Não é possível posicionar o navio aqui!\n");
                    return 1;
                }
            }
            for (k = 0; k < 3; k++) {
                tabuleiro[linhaNavio4 - 'A' - k][colunaNavio4 - 1 + k] = 3;
            }

        /*tabuleiro[linhaNavio3 - 'A'][colunaNavio3] = 3; // Marca a posição do navio no tabuleiro
        tabuleiro[linhaNavio3 - 'A' + 1][colunaNavio3 + 1] = 3; // Marca a posição do navio no tabuleiro
        tabuleiro[linhaNavio3 - 'A' + 2][colunaNavio3 + 2] = 3; // Marca a posição do navio no tabuleiro*/
    
    // Exibindo o tabuleiro
    printf("TABULEIRO BATALHA NAVAL:\n");
        printf("   1  2  3  4  5  6  7  8  9  10\n"); // Imprime o cabeçalho do tabuleiro
        for (i = 0; i < linhas; i++) {
            printf("%c ", lateralTab[i]); // Imprime as linhas do tabuleiro
            for (j = 0; j < coluna; j++) {
                printf(" %d ", tabuleiro[i][j]); // Imprime o valor do tabuleiro
            }
        printf("\n");
    }
        
    printf("Navios Posicionados com sucesso!\n");

        printf("Obrigado por jogar!\n");
        return 0;
    
}