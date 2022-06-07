#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int hasGirl;
    int distance;
    int visited;
    struct Node *adjacentList;
} Node;

Node **graph;

void initializeNodeList(int size)
{
    graph = calloc(sizeof(Node *), size);
}

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->hasGirl = 0;
    node->distance = 0;
    node->adjacentList = NULL;
    node->visited = 0;

    return node;
}

void addToAdjacentList(Node *node, Node *adjacent)
{
    Node *aux = node;

    while (aux->adjacentList != NULL)
        aux = aux->adjacentList;

    aux->adjacentList = adjacent;
}

void addToGraph(int from, int to)
{
    int indexFrom = from - 1;
    int indexTo = to - 1;

    if (graph[indexFrom] == NULL)
        graph[indexFrom] = createNode(from);

    if (graph[indexTo] == NULL)
        graph[indexTo] = createNode(to);

    addToAdjacentList(graph[indexFrom], createNode(to));
}

Node *getNodeFromValue(int value)
{
    return graph[value - 1];
}

void dfs(int value, int distance)
{
    Node *node = getNodeFromValue(value);

    if (node->visited)
        return;

    node->visited = 1;
    node->distance = distance;

    Node *adjacentAux = node->adjacentList;

    while (adjacentAux != NULL)
    {
        dfs(adjacentAux->value, distance + 1);
        adjacentAux = adjacentAux->adjacentList;
    }
}

int main()
{
    int qtd, qtdCountry, from, to, value, i;
    Node *min = NULL, *aux;

    scanf("%d", &qtd);
    qtdCountry = qtd;

    initializeNodeList(qtd);

    qtd--;

    while (qtd--)
    {
        scanf("%d %d", &from, &to);
        addToGraph(from, to);
    }

    scanf("%d", &qtd);
    while (qtd--)
    {
        scanf("%d", &value);
        getNodeFromValue(value)->hasGirl = 1;
    }

    dfs(1, 0);

    for (i = 0; i < qtdCountry; i++)
    {
        aux = graph[i];
        if (aux->hasGirl == 0)
            continue;

        if (min == NULL)
        {
            min = aux;
            continue;
        }

        if (aux->distance <= min->distance && aux->value < min->value)
            min = aux;
    }

    printf("%d\n", min->value);

    return EXIT_SUCCESS;
}
