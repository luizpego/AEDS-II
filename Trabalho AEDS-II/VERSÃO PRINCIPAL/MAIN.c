#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} No;

typedef struct
{
    No *inicio;
} Lista;

void inicializar(Lista *lista)
{
    lista->inicio = NULL;
}

void inserir_inicio(Lista *lista, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void remover_valor(Lista *lista, int valor)
{
    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Valor não encontrado.\n");
        return;
    }

    if (anterior == NULL)
    {
        lista->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Valor removido com sucesso.\n");
}

void exibir(Lista *lista)
{
    No *atual = lista->inicio;

    printf("Lista: ");

    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }

    printf("\n");
}

void liberar(Lista *lista)
{
    No *atual = lista->inicio;
    No *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
}

int main()
{
    Lista lista;

    inicializar(&lista);

    inserir_inicio(&lista, 30);
    inserir_inicio(&lista, 20);
    inserir_inicio(&lista, 10);

    exibir(&lista);

    remover_valor(&lista, 20);

    exibir(&lista);

    liberar(&lista);

    return 0;
}