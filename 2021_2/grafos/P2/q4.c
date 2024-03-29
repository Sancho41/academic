#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int lower;
    int in;
    int visited;
    struct Node *next;
} Node;

Node **graph;
int graphSize;
int count;

void initializeNodeList(int size);
Node *createNode(int value);
void addToAdjacentList(Node *node, Node *adjacent);
void addToGraph(int from, int to);
Node *getNodeFromValue(int value);
void dfs(int value, int parent);
void loadGraph();
int min(int a, int b);
void resetGraph();

int main()
{
    loadGraph();

    for (int i = 0; i < graphSize; i++)
        if (graph[i]->visited == 0)
            dfs(graph[i]->value, -1);

    return EXIT_SUCCESS;
}

void initializeNodeList(int size)
{
    graph = calloc(sizeof(Node *), size);
    graphSize = size;
}

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->visited = 0;
    node->in = 0;
    node->lower = 0;

    return node;
}

void addToAdjacentList(Node *node, Node *adjacent)
{
    Node *aux = node->next;
    node->next = adjacent;
    adjacent->next = aux;
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

void dfs(int value, int parent)
{
    Node *adjacent, *next, *current;

    current = getNodeFromValue(value);
    current->visited = 1;
    current->in = count;
    current->lower = count;

    count++;

    for (adjacent = current->next; adjacent != NULL; adjacent = adjacent->next)
    {
        next = getNodeFromValue(adjacent->value);

        if (next->value == parent) continue;

        if (next->visited == 0)
        {

            dfs(next->value, value);

            if (next->lower > current->in)
                printf("A cidade que conecta %d e %d não pode entrar em reforma\n", current->value, next->value);

            current->lower = min(current->lower, next->lower);
        }
        else
            current->lower = min(current->lower, next->in);
    }
}

void loadGraph()
{
    int qtdNodes, qtdEdges, nodeTo, nodeFrom;

    count = 0;

    scanf("%d", &qtdNodes);
    initializeNodeList(qtdNodes);

    scanf("%d", &qtdEdges);

    while (qtdEdges--)
    {
        scanf("%d %d", &nodeFrom, &nodeTo);
        addToGraph(nodeFrom, nodeTo);
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}
