#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MaxTam 100

/*
    Este programa implementa uma lista sequencial estática.

    Uma lista sequencial é uma estrutura de dados linear, ou seja, seus elementos
    são organizados um após o outro. Neste programa, essa lista é implementada
    utilizando um vetor de inteiros.

    Ela é chamada de sequencial porque os elementos ficam armazenados em posições
    consecutivas de memória. Também é chamada de estática porque sua capacidade
    máxima já é definida antes da execução do programa, por meio da constante
    MaxTam.

    Neste caso, MaxTam vale 100. Portanto, a lista pode armazenar no máximo
    100 valores inteiros.

    A principal vantagem da lista sequencial é o acesso direto aos elementos
    pelo índice do vetor. Porém, algumas operações, como a remoção, podem exigir
    deslocamento de elementos para manter a organização da lista.
*/

/*
    Estrutura que representa a lista sequencial usada no programa.

    O vetor item armazena os valores inteiros da lista.

    A variável inicio indica a posição inicial da lista. Neste programa, ela
    permanece igual a zero, pois a lista sempre começa na primeira posição
    do vetor.

    A variável fim indica a próxima posição livre do vetor. Além disso, ela
    também representa o tamanho lógico da lista.

    Por exemplo:
    - se inicio = 0 e fim = 0, a lista está vazia;
    - se inicio = 0 e fim = 3, existem elementos nas posições 0, 1 e 2;
    - a próxima inserção acontecerá na posição 3.
*/
typedef struct
{
    int item[MaxTam];
    int inicio;
    int fim;
} TipoLista;

/*
    Função responsável pela interação inicial com o usuário.

    Ela apresenta as operações disponíveis e retorna a opção escolhida.

    Teoricamente, o menu funciona como uma interface simples entre o usuário
    e as operações da estrutura de dados. O valor digitado será utilizado na
    função main para decidir qual operação será executada.
*/
int menu()
{
    int A = 0;

    printf("\n========== MENU ==========\n");
    printf("1 - Inserir dado\n");
    printf("2 - Remover dado\n");
    printf("3 - Exibir maior e menor valor\n");
    printf("4 - Exibir dados na ordem de entrada\n");
    printf("5 - Exibir endereço de memória dos valores da lista\n");
    printf("0 - Sair\n");
    printf("==========================\n");
    printf("Qual opção você deseja? ");
    scanf("%d", &A);

    return A;
}

/*
    Insere um novo elemento no final da lista.

    Como a inserção acontece diretamente na posição indicada por fim, essa
    operação é simples. Em uma lista sequencial com inserção no final, não é
    necessário deslocar outros elementos.

    Antes da inserção, é feita uma verificação para saber se a lista está cheia.
    A lista está cheia quando fim é igual a MaxTam, pois isso significa que
    todas as posições do vetor já foram ocupadas.

    Depois que o valor é inserido, a variável fim é incrementada. Assim, ela
    passa a apontar para a próxima posição livre.

    Complexidade: O(1), considerando que ainda existe espaço disponível.
*/
void adicionar(TipoLista *Lista)
{
    if (Lista->fim == MaxTam)
    {
        printf("A lista está cheia.\n");
    }
    else
    {
        printf("Qual valor você deseja adicionar à lista? ");
        scanf("%d", &Lista->item[Lista->fim]);

        Lista->fim++;

        printf("Valor adicionado com sucesso.\n");
    }
}

/*
    Remove da lista o valor informado pelo usuário.

    Primeiro, o algoritmo verifica se a lista está vazia. Uma lista está vazia
    quando inicio e fim possuem o mesmo valor.

    Depois, é realizada uma busca sequencial. Nessa busca, o programa percorre
    os elementos válidos da lista, um por um, procurando o valor informado.

    Caso o valor seja encontrado, sua posição é armazenada na variável B.

    Depois disso, os elementos posteriores são deslocados uma posição para a
    esquerda. Esse deslocamento é necessário porque, em uma lista sequencial,
    os elementos válidos devem permanecer em posições consecutivas.

    Por fim, a variável fim é decrementada, reduzindo o tamanho lógico da lista.

    Complexidade: O(n), pois pode ser necessário percorrer e deslocar elementos.
*/
void remover(TipoLista *Lista)
{
    int A = 0, B = -1;

    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Qual valor você deseja remover? ");
        scanf("%d", &A);

        for (int j = Lista->inicio; j < Lista->fim; j++)
        {
            if (Lista->item[j] == A)
            {
                B = j;
                break;
            }
        }

        if (B == -1)
        {
            printf("Valor não encontrado.\n");
        }
        else
        {
            for (int i = B; i < Lista->fim - 1; i++)
            {
                Lista->item[i] = Lista->item[i + 1];
            }

            Lista->fim--;

            printf("Valor removido com sucesso.\n");
        }
    }
}

/*
    Encontra e exibe o maior e o menor valor da lista.

    O algoritmo percorre todos os elementos válidos comparando cada valor com
    os valores armazenados nas variáveis maior e menor.

    O primeiro elemento da lista é usado como referência inicial. Isso evita
    erros quando a lista possui valores negativos, pois não começamos comparando
    com zero, mas sim com um valor que realmente pertence à lista.

    Durante o percurso:
    - se o valor atual for maior que maior, ele passa a ser o novo maior;
    - se o valor atual for menor que menor, ele passa a ser o novo menor.

    Complexidade: O(n), pois todos os elementos da lista são analisados.
*/
void maior_menor(TipoLista *Lista)
{
    int menor = 0, maior = 0;

    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        maior = Lista->item[Lista->inicio];
        menor = Lista->item[Lista->inicio];

        for (int i = Lista->inicio + 1; i < Lista->fim; i++)
        {
            if (Lista->item[i] > maior)
            {
                maior = Lista->item[i];
            }

            if (Lista->item[i] < menor)
            {
                menor = Lista->item[i];
            }
        }

        printf("O maior valor é: %d\n", maior);
        printf("O menor valor é: %d\n", menor);
    }
}

/*
    Exibe todos os elementos da lista na ordem de inserção.

    Como a lista é sequencial, os elementos válidos estão armazenados entre
    inicio e fim - 1.

    Portanto, basta percorrer o vetor da posição inicial até a última posição
    válida para exibir os dados na mesma ordem em que foram inseridos.

    Complexidade: O(n), pois a função visita todos os elementos armazenados.
*/
void exibir(TipoLista *Lista)
{
    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Valores da lista: ");

        for (int i = Lista->inicio; i < Lista->fim; i++)
        {
            printf("%d ", Lista->item[i]);
        }

        printf("\n");
    }
}

/*
    Exibe o endereço de memória de cada elemento da lista.

    Essa função ajuda a demonstrar uma característica importante dos vetores:
    seus elementos ficam armazenados de forma contígua na memória.

    O operador & é usado para acessar o endereço de memória de uma posição
    do vetor.

    O especificador %p é utilizado para exibir endereços de memória.

    Como o vetor armazena valores do tipo int, os endereços geralmente aparecem
    separados por alguns bytes, dependendo do tamanho do inteiro na arquitetura
    do computador.
*/
void exibir_endereco_memoria(TipoLista *Lista)
{
    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Endereços de memória dos valores da lista:\n");

        for (int i = Lista->inicio; i < Lista->fim; i++)
        {
            printf("Valor %d está no endereço %p\n", Lista->item[i], (void *)&Lista->item[i]);
        }
    }
}

/*
    Função principal do programa.

    A função main é o ponto inicial da execução.

    Primeiro, são feitas as configurações de idioma e codificação. A função
    setlocale permite que o programa trabalhe melhor com padrões regionais,
    como acentos e caracteres da língua portuguesa.

    No Windows, as funções SetConsoleOutputCP e SetConsoleCP configuram o
    console para UTF-8. Isso ajuda a exibir corretamente caracteres acentuados,
    como ç, ã, é, í e õ, sem precisar usar o comando system("chcp 65001 > nul").

    Depois, a lista é declarada e inicializada. Quando inicio e fim recebem zero,
    significa que a lista começa vazia.

    Em seguida, o programa entra em um laço do-while. Esse laço mantém o menu
    em execução até que o usuário escolha a opção 0.

    A estrutura switch verifica a opção escolhida e chama a função correspondente.
*/
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    TipoLista Lista;

    Lista.inicio = 0;
    Lista.fim = 0;

    int Menu = 0;

    do
    {
        Menu = menu();

        switch (Menu)
        {
        case 1:
            adicionar(&Lista);
            break;

        case 2:
            remover(&Lista);
            break;

        case 3:
            maior_menor(&Lista);
            break;

        case 4:
            exibir(&Lista);
            break;

        case 5:
            exibir_endereco_memoria(&Lista);
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
        }

        system("pause");
        system("cls");

    } while (Menu != 0);

    return 0;
}