#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo os macros do código
#define TAMANHO_MAPA 10
#define JOGAR 1
#define SAIR 2
#define ENCERRAMENTO 3
#define ESPACO ' '
#define JOGADOR '&'
#define CHAVE '@'
#define PORTA_FECHADA 'D'
#define PORTA_ABERTA '='
#define BOTAO 'O'
#define ESPINHO '#'
#define MONSTRO2 'V'
#define PAREDE '*'

int posX, posY; // Posição inicial do jogador
int posX_monstro2, posY_monstro2; // Posição inicial do monstro nível 2
int num_reiniciamentos = 0; // Contador de reiniciamentos da fase
int temChave = 0; // 0: não tem a chave, 1: tem a chave

char mapa[TAMANHO_MAPA][TAMANHO_MAPA]; // Mapa 1
char mapa2[TAMANHO_MAPA][TAMANHO_MAPA]; // Mapa 2

// Função para limpar a tela
void limparTela() {
    system("clear"); // Para sistemas Unix-like
    //system("cls"); // Para sistemas Windows
}

// Função para reiniciar a fase
void reiniciarFase() {
    posX = 1;
    posY = 1;
    posX_monstro2 = 8;
    posY_monstro2 = 8;
    num_reiniciamentos++;
    if (num_reiniciamentos >= 3) {
        // Reiniciar o jogo
    }
}

// Função para exibir o mapa
void exibirMapa(char mapa[][TAMANHO_MAPA]) {
    limparTela();
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            if (i == posX && j == posY) {
                printf("%c ", JOGADOR);
            } else if (i == posX_monstro2 && j == posY_monstro2) {
                printf("%c ", MONSTRO2);
            } else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para verificar se o jogador tocou no espinho
void verificarEspinho() {
    if (mapa[posX][posY] == ESPINHO) {
        reiniciarFase();
    }
}

// Função para mover o monstro nível 2 em direção ao jogador
void moverMonstro2() {
    // Implemente a lógica para mover o monstro nível 2 em direção ao jogador
}

int main() {
    srand(time(NULL)); // Semente para gerar números aleatórios

    // Inicializando o mapa 2
    // ...
    
    // Menu do jogo
    int escolha;
    do {
        printf("======= MENU =======\n");
        printf("%d. Jogar\n", JOGAR);
        printf("%d. Sair\n", SAIR);
        printf("%d. ENCERRAMENTO\n", ENCERRAMENTO);
        printf("====================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case JOGAR:
                printf("Iniciando o jogo...\n");
                // Iniciar a segunda fase
                // ...
                break;
            case ENCERRAMENTO:
                // Exibir créditos
                // ...
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
