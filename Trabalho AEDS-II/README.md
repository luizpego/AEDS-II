# Lista Sequencial Estática em C

## 📋 Descrição

Este programa implementa uma **Lista Sequencial Estática**, uma estrutura de dados linear que armazena elementos em um vetor de inteiros. Os elementos ficam armazenados em posições consecutivas de memória, com capacidade máxima de 100 valores.

## 🎯 Características Principais

- **Estrutura de Dados**: Vetor de inteiros com capacidade fixa (MaxTam = 100)
- **Operações Básicas**: Inserção, remoção, busca e exibição de elementos
- **Acesso Direto**: Os elementos podem ser acessados diretamente pelo índice
- **Implementação Simples**: Ideal para fins educacionais e aprendizado

## 📊 Estrutura da Lista

```c
typedef struct {
    int item[MaxTam];  // Vetor que armazena os valores
    int inicio;        // Posição inicial (sempre 0)
    int fim;           // Próxima posição livre / tamanho lógico
} TipoLista;
```

## ⚙️ Operações Disponíveis

| Opção | Operação | Complexidade | Descrição |
|-------|----------|--------------|-----------|
| 1 | Inserir dado | O(1) | Adiciona um novo valor no final da lista |
| 2 | Remover dado | O(n) | Remove um valor específico da lista |
| 3 | Maior e Menor | O(n) | Encontra o maior e menor valor |
| 4 | Exibir dados | O(n) | Mostra todos os elementos em ordem |
| 5 | Exibir endereços | O(n) | Mostra os endereços de memória dos valores |
| 0 | Sair | - | Encerra o programa |

## 🔧 Como Usar

1. **Compilar**:
   ```bash
   gcc MAIN.c -o lista
   ```

2. **Executar**:
   ```bash
   ./lista
   ```

3. **Interagir**: Escolha uma opção no menu e siga as instruções na tela.

## 📝 Exemplos de Uso

**Inserir valores**: 10, 20, 30
```
Qual opção você deseja? 1
Qual valor você deseja adicionar à lista? 10
Valor adicionado com sucesso.
```

**Exibir dados**:
```
Qual opção você deseja? 4
Valores da lista: 10 20 30
```

**Remover valor**:
```
Qual opção você deseja? 2
Qual valor você deseja remover? 20
Valor removido com sucesso.
```

## ✅ Vantagens

- ✔️ Acesso direto aos elementos pelo índice
- ✔️ Implementação simples e intuitiva
- ✔️ Estrutura compacta em memória

## ❌ Limitações

- ❌ Capacidade fixa (não pode exceder 100 elementos)
- ❌ Remoção de elementos no meio exige deslocamento de dados
- ❌ Desperdício de espaço se a lista não está completamente cheia

## 💻 Ambiente

- **Linguagem**: C
- **Suporte ao Windows**: Configuração de codificação UTF-8 para caracteres acentuados
- **Suporte ao Linux/macOS**: Compatível com locales

## 📚 Conceitos Aprendidos

Este programa demonstra:
- Estruturas de dados básicas
- Operações fundamentais em listas (CRUD)
- Manipulação de vetores
- Busca e ordenação de dados
- Análise de complexidade de tempo
- Contiguidade de memória

---

**Desenvolvido como trabalho acadêmico para AEDS II**
