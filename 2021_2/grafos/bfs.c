#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int visited;
    struct Node *next;
} Node;

Node **graph;
int graphSize;
int qtdQueue;
Node *first, *last;

void intializeGraph(int size)
{
    graph = (Node **)calloc(sizeof(Node *), size);
    graphSize = size;
    qtdQueue = 0;
    first = NULL;
    last = NULL;
}

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->visited = 0;

    return node;
}

void addToAdjacentList(Node *node, Node *adjacent)
{
    Node *aux = node;

    while (aux->next != NULL)
        aux = aux->next;

    aux->next = adjacent;
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
    addToAdjacentList(graph[indexTo], createNode(from));
}

Node *getNodeFromValue(int value)
{
    return graph[value - 1];
}

void push(Node *node)
{
    if (first == NULL)
        first = node;

    if (last != NULL)
        last->next = node;
    last = node;
    qtdQueue++;
}

Node *pop()
{
    if (qtdQueue == 0)
        return NULL;

    Node *aux = first;
    first = aux->next;

    qtdQueue--;

    if (qtdQueue == 0)
        last == NULL;

    return aux;
}

void bfs(int value)
{
    Node *auxAdj, *auxGraph,*current = getNodeFromValue(value);

    push(createNode(current->value));

    current->visited = 1;

    while (qtdQueue)
    {
        current = getNodeFromValue(pop()->value);

        printf("%d\n", current->value);

        auxAdj = current->next;

        while (auxAdj != NULL)
        {
            auxGraph = getNodeFromValue(auxAdj->value);
            if (auxGraph->visited == 0) {
                auxGraph->visited = 1;
                push(createNode(auxAdj->value));
            }
            auxAdj = auxAdj->next;
        }
    }
}

int main()
{
    int edges, from, to;

    scanf("%d %d", &edges, &qtdQueue);

    intializeGraph(qtdQueue);

    while (edges--)
    {
        scanf("%d %d", &from, &to);
        addToGraph(from, to);
    }

    bfs(1);
    return 0;
}
