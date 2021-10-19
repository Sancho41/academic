#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int distance;
    int visited;
    struct Node *adjacentList;
} Node;

Node **graph;
int graphSize;

void initializeNodeList(int size);
Node *createNode(int value);
void addToAdjacentList(Node *node, Node *adjacent);
void addToGraph(int from, int to);
Node *getNodeFromValue(int value);
void dfs(int value, int distance);
void loadGraph();
void resetGraph();
int distance(int from, int to);

int main()
{
    int qtdTests, to, from;

    loadGraph();

    scanf("%d", &qtdTests);

    while (qtdTests--)
    {
        scanf("%d %d", &from, &to);
        printf("%d\n", distance(from, to));
        resetGraph();
    }

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
    addToAdjacentList(graph[indexTo], createNode(from));
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

void loadGraph()
{
    int qtdNodes, qtdEdges, nodeTo, nodeFrom;

    scanf("%d", &qtdNodes);
    initializeNodeList(qtdNodes);

    scanf("%d", &qtdEdges);

    while (qtdEdges--)
    {
        scanf("%d %d", &nodeFrom, &nodeTo);
        addToGraph(nodeFrom, nodeTo);
    }
}

void resetGraph()
{
    Node *current;
    int i;
    for (i = 0; i < graphSize; i++) {
        graph[i]->distance = 0;
        graph[i]->visited = 0;
    }
}

int distance(int from, int to)
{
    Node *toNode = getNodeFromValue(to);

    dfs(from, 0);
    return toNode->distance;
}
