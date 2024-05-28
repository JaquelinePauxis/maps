#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo os macros do código
#define TAMANHO_MAPA 20
#define TAMANHO_MAPA2 20
#define JOGAR 1
#define TUTORIAL 2
#define SAIR 3
#define ENCERRAMENTO 4
#define ESPACO ' '
#define JOGADOR '&'
#define CHAVE '@'
#define PORTA_FECHADA 'D'
#define PORTA_ABERTA '='
#define BOTAO 'O'
#define ESPINHO '#'
#define TELETRANSPORTE '>'
#define MONSTRO1 'X'
#define MONSTRO2 'V'
#define PAREDE '*'

// Declaração das funções
void limparTela();
void exibirMapa(char mapa[TAMANHO_MAPA][TAMANHO_MAPA], int posX, int posY, int posX_monstro, int posY_monstro);
void moverMonstroAleatoriamente(int *posX_monstro, int *posY_monstro);
void iniciarFase2();

int main() {
    int escolha;
    char movimento;
    int posX_monstro, posY_monstro;

    // Inicialização do gerador de números aleatórios
    srand(time(NULL));

    do {
        // Exibindo tela inicial e menu do jogo
        printf("The Green Project\n");
        printf("======= MENU =======\n");
        printf("%d. Jogar\n", JOGAR);
        printf("%d. Tutorial\n", TUTORIAL);
        printf("%d. Sair\n", SAIR);
        printf("%d. ENCERRAMENTO\n", ENCERRAMENTO);
        printf("====================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        // Executando a ação de acordo com o que o usuário digitou
        switch (escolha) {
            case JOGAR:
                printf("Iniciando o jogo...\n");
                // Mapa 10x10
                char mapa[TAMANHO_MAPA][TAMANHO_MAPA] = {
                    {PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE},
                    {PAREDE, ESPACO, ESPACO, ESPACO, ESPACO, ESPACO, ESPACO, ESPACO, ESPACO, PAREDE},
                    // Adicione o resto do mapa aqui
                };

                int posX = 1;
                int posY = 1;

                // Loop do jogo
                do {
                    moverMonstroAleatoriamente(&posX_monstro, &posY_monstro);
                    exibirMapa(mapa, posX, posY, posX_monstro, posY_monstro);
                    printf("Digite W (cima), A (esquerda), S (baixo) ou D (direita): ");
                    scanf(" %c", &movimento);

                    // Implemente a lógica de movimento do jogador aqui

                } while (movimento != 'Q' && movimento != 'q'); // Digite Q para sair
                break;

            case TUTORIAL:
                // Implemente o tutorial aqui
                break;

            case ENCERRAMENTO:
                // Implemente os créditos aqui
                break;

            case SAIR:
                printf("Encerrando o programa. Até logo!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != SAIR);

    return 0;
}

// Função para limpar a tela
void limparTela() {
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
}

// Função para exibir o mapa
void exibirMapa(char mapa[TAMANHO_MAPA][TAMANHO_MAPA], int posX, int posY, int posX_monstro, int posY_monstro) {
    limparTela();
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            if (i == posX && j == posY) {
                printf("%c ", JOGADOR);
            } else if (i == posX_monstro && j == posY_monstro) {
                printf("%c ", MONSTRO1); // Troque pelo símbolo correto
            } else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para mover o monstro aleatoriamente
void moverMonstroAleatoriamente(int *posX_monstro, int *posY_monstro) {
    int direcao = rand() % 4; // 0: cima, 1: baixo, 2: esquerda, 3: direita

    switch (direcao) {
        case 0: // Cima
            if (*posX_monstro > 0) {
                (*posX_monstro)--;
            }
            break;
        case 1: // Baixo
            if (*posX_monstro < TAMANHO_MAPA - 1) {
                (*posX_monstro)++;
            }
            break;
        case 2: // Esquerda
            if (*posY_monstro > 0) {
                (*posY_monstro)--;
            }
            break;
        case 3: // Direita
            if (*posY_monstro < TAMANHO_MAPA - 1) {
                (*posY_monstro)++;
            }
            break;
    }
}

// Função para iniciar a segunda fase
void iniciarFase2() {
    // Implemente a lógica para a segunda fase aqui
}
