# Atividade Avaliativa 1 (Remoto)

## Questão 1

Implemente uma lista duplamente ligada e adicione uma opção que remova todos os númeor primos dessa lista.
[Resposta](respostas/q1.c)

---

## Questão 2

Dada uma expreção qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. Por exemplo:

- **Está correto**

  - `a+(b*c)-2-a`
  - `(a+b*(2-c)-2+a)*2`

- **Não está correto**
  - `(a*b-(2+c)`
  - `2*(3-a))`
  - `)3+b*(2-c)(`

Ou seja, todo parênteses que fecha deve ter um outr parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parênteses que abre e a quantidade total de parênteses que abre e fecha deve ser igual.

[Resposta](respostas/q2.c)

---

## Questão 3

- a) Escreva um algoritmo para determinar se uma string de caracteres de entrada é da forma `xCy` onde `x` é uma string consistido nas letras `'A'` e `'B'`, e y é o inverso de `x` (isto é, se `x = "ABABBA"`, `y` deve equivaler a `"ABBABA"`). Em cada ponto, você só poderá ler o proximo caratere da string.
  [Resposta](respostas/q3-a.c)

- b)Escreva um algoritmo para determinar se uma string de cracteres de entrada é da forma: `a D b D c D ... D z`, onde cada string, `a, 6, ..., z` é da forma da string definida no exercício anterior. (Por conseguinte, uma string estará no formato correto se consistir em qualuqer número de strings desse tipo, separadas pelo caractere `'D'`). Em cada ponto, você só poderá ler o próximo caractere da string.
  [Resposta](respostas/q3-b.c)

---

## Questão 4

Elabora um método para manter duas pilhas dentro de um único vetor linear `$[spacesize]` de modo que nenhuma das pilhas incorra em estouro até que toda a memória seja usada, e uma pilha inteira nunca seja deslocada para outro local dentro do vetor. Escreva rotinas em C, `push1, push2, pop1, pop2`, para manipular as duas pilhas.
[Resposta](respostas/q4.c)

> **Dica**: as duas pilhas crescem na direção da outra.

---

## Questão 5

Implemente uma lista ligada e adicione uma opção que busque um número dentro da lista e mostre o valor do registro imediatamente anterior e do imediatamente posterior.
[Resposta](respostas/q5.c)

---

## Questão 6

Dada uma pilha de `n` cartas enumeradas de `1` até `n` com a carta `1` no topo e a `n` na base. A seguinte operação é realizada enquanto tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número `n <= 50`. A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

## Entrada:

A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. a última linha contém o valor.

## Saída:

Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número de carta que resou. Nenhuma linha tem espaços extras no início ou no final. Veja o exemplo para conferir o formato esperado.

### Exemplo de entrada:

```
7
19
1
6
0
```

### Exemplo de saída:

```
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 ,4 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
```

[Resposta](respostas/q6.c)

---

## Questão 7

Implemente uma fila circular utilizando uma estrutura de lista ligada.
[Resposta](respostas/q7.c)
