#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura que representa um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função que exibe a missão do jogador (passagem por valor)
void exibirMissao(char* missao) {
    printf("\nSua missão estratégica: %s\n", missao);
}

// Função que sorteia uma missão e atribui ao jogador (passagem por referência)
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Função que simula um ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Ataque inválido! Ambos os territórios pertencem ao mesmo exército.\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nAtaque de %s contra %s\n", atacante->nome, defensor->nome);
    printf("Rolagem do atacante: %d\n", dadoAtacante);
    printf("Rolagem do defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Vitória do atacante!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf("Defesa bem-sucedida! O atacante perde uma tropa.\n");
        if (atacante->tropas > 0) atacante->tropas--;
    }
}

// Função que verifica se a missão foi cumprida (lógica simples inicial)
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    if (strstr(missao, "vermelha") != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "vermelha") == 0 && mapa[i].tropas > 0) {
                return 0; // Missão não cumprida
            }
        }
        return 1; // Missão cumprida
    }

    if (strstr(missao, "3 territórios") != NULL) {
        int contiguos = 0;
        for (int i = 0; i < tamanho - 2; i++) {
            if (strcmp(mapa[i].cor, mapa[i+1].cor) == 0 &&
                strcmp(mapa[i].cor, mapa[i+2].cor) == 0) {
                contiguos++;
            }
        }
        return contiguos > 0;
    }

    return 0; // Missão genérica não cumprida
}

// Função que exibe o estado atual do mapa
void exibirMapa(Territorio* mapa, int tamanho) {
    printf("\n===== ESTADO ATUAL DO MAPA =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Território %d: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função que libera memória alocada dinamicamente
void liberarMemoria(char* missaoJogador, Territorio* mapa) {
    free(missaoJogador);
    free(mapa);
}

int main() {
    srand(time(NULL)); // Inicializa gerador de números aleatórios

    // Vetor de missões estratégicas
    char* missoes[] = {
        "Conquistar 3 territórios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Controlar todos os territórios com mais de 10 tropas",
        "Ter pelo menos 3 territórios com cor azul",
        "Reduzir qualquer território inimigo a 0 tropas"
    };
    int totalMissoes = 5;

    // Alocação dinâmica da missão do jogador
    char* missaoJogador = (char*) malloc(100 * sizeof(char));
    atribuirMissao(missaoJogador, missoes, totalMissoes);
    exibirMissao(missaoJogador);

    // Alocação dinâmica do mapa de territórios
    int tamanhoMapa = 5;
    Territorio* mapa = (Territorio*) malloc(tamanhoMapa * sizeof(Territorio));

    // Cadastro dos territórios
    for (int i = 0; i < tamanhoMapa; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %29[^\n]", mapa[i].nome);
        printf("Cor do exército: ");
        scanf(" %9s", mapa[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    // Simulação de turnos e verificação de missão
    int turno = 1;
    while (1) {
        printf("\n===== TURNO %d =====\n", turno);
        exibirMapa(mapa, tamanhoMapa);

        int atacante, defensor;
        printf("\nEscolha o território atacante (1 a %d): ", tamanhoMapa);
        scanf("%d", &atacante);
        printf("Escolha o território defensor (1 a %d): ", tamanhoMapa);
        scanf("%d", &defensor);

        atacar(&mapa[atacante - 1], &mapa[defensor - 1]);

        if (verificarMissao(missaoJogador, mapa, tamanhoMapa)) {
            printf("\n🎉 Missão cumprida! Você venceu o jogo! 🎉\n");
            break;
        }

        turno++;
    }

    liberarMemoria(missaoJogador, mapa);
    return 0;
}