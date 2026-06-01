#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da sala (nó da árvore)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Cria uma nova sala
Sala* criarSala(char nome[]) {
    Sala *novaSala = (Sala*) malloc(sizeof(Sala));

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

// Exploração da mansão
void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {

        printf("\n=================================\n");
        printf("Voce esta em: %s\n", atual->nome);

        // Verifica se é uma folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim do caminho! Nenhuma sala conectada.\n");
            break;
        }

        printf("\nOpcoes disponiveis:\n");

        if (atual->esquerda != NULL)
            printf("e - Ir para a esquerda (%s)\n",
                   atual->esquerda->nome);

        if (atual->direita != NULL)
            printf("d - Ir para a direita (%s)\n",
                   atual->direita->nome);

        printf("s - Sair da exploracao\n");

        printf("\nEscolha: ");
        scanf(" %c", &opcao);

        switch (opcao) {

            case 'e':
            case 'E':
                if (atual->esquerda != NULL)
                    atual = atual->esquerda;
                else
                    printf("Nao existe sala a esquerda!\n");
                break;

            case 'd':
            case 'D':
                if (atual->direita != NULL)
                    atual = atual->direita;
                else
                    printf("Nao existe sala a direita!\n");
                break;

            case 's':
            case 'S':
                printf("\nExploracao encerrada.\n");
                return;

            default:
                printf("\nOpcao invalida!\n");
        }
    }
}

// Libera memória da árvore
void liberarArvore(Sala *raiz) {
    if (raiz == NULL)
        return;

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);

    free(raiz);
}

int main() {

    // Construção da árvore da mansão

    Sala *hall = criarSala("Hall de Entrada");

    hall->esquerda = criarSala("Biblioteca");
    hall->direita = criarSala("Sala de Jantar");

    hall->esquerda->esquerda = criarSala("Escritorio");
    hall->esquerda->direita = criarSala("Arquivo Secreto");

    hall->direita->esquerda = criarSala("Cozinha");
    hall->direita->direita = criarSala("Sala de Musica");

    printf("=== DETECTIVE QUEST ===\n");
    printf("Explore a mansao em busca de pistas!\n");

    explorarSalas(hall);

    liberarArvore(hall);

    return 0;
}