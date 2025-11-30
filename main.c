#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// -----------------------------
// STRUCT DO ITEM
// -----------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// -----------------------------
// FUNÇÃO PARA LISTAR ITENS
// -----------------------------
void listarItens(Item mochila[], int total) {
    printf("\n--- Itens da Mochila ---\n");
    if (total == 0) {
        printf("Nenhum item registrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// -----------------------------
// BUSCA SEQUENCIAL PELO NOME
// -----------------------------
int buscarItem(Item mochila[], int total, char nomeBuscado[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            return i; // encontrou
        }
    }
    return -1; // não encontrou
}

// -----------------------------
// REMOVER ITEM
// -----------------------------
void removerItem(Item mochila[], int *total) {
    char nome[30];
    printf("\nDigite o nome do item a remover: ");
    scanf(" %29[^\n]", nome);

    int index = buscarItem(mochila, *total, nome);

    if (index == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    // "Puxa" os itens para trás
    for (int i = index; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;

    printf("Item removido com sucesso!\n");
}

// -----------------------------
// CADASTRAR UM ITEM
// -----------------------------
void cadastrarItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("Mochila cheia! (max 10 itens)\n");
        return;
    }

    Item novo;

    printf("\nNome do item: ");
    scanf(" %29[^\n]", novo.nome);

    printf("Tipo do item (arma, municao, cura): ");
    scanf(" %19[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*total] = novo;
    (*total)++;

    printf("Item cadastrado com sucesso!\n");
}

// -----------------------------
// BUSCAR ITEM E EXIBIR
// -----------------------------
void buscarEExibir(Item mochila[], int total) {
    char nome[30];
    printf("\nDigite o nome do item para busca: ");
    scanf(" %29[^\n]", nome);

    int index = buscarItem(mochila, total, nome);

    if (index == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    printf("\nItem encontrado:\n");
    printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
           mochila[index].nome, mochila[index].tipo, mochila[index].quantidade);
}

// -----------------------------
// MAIN
// -----------------------------
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 4:
                buscarEExibir(mochila, total);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
