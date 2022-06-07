#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int lower;
    int in;
    int visited;
    struct Node *adjacentList;
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
        if (!graph[i]->visited)
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
    node->adjacentList = NULL;
    node->visited = 0;
    node->in = 0;
    node->lower = 0;

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
    int indexFrom = from;
    int indexTo = to;

    if (graph[indexFrom] == NULL)
        graph[indexFrom] = createNode(from);

    if (graph[indexTo] == NULL)
        graph[indexTo] = createNode(to);

    addToAdjacentList(graph[indexFrom], createNode(to));
    addToAdjacentList(graph[indexTo], createNode(from));
}

Node *getNodeFromValue(int value)
{
    int i;
    for (i = 0; i < graphSize; i++)
        if (graph[i]->value == value)
            return graph[i];
    return NULL;
}

void dfs(int value, int parent)
{
    Node *parentNode, *adjacent, *adjacentNode, *node = getNodeFromValue(value);

    node->visited = 1;
    node->in = count;
    node->lower = count;
    count++;

    adjacent = node->adjacentList;
    
    for (adjacent = node->adjacentList; adjacent != NULL; adjacent = adjacent->adjacentList)
    {
        adjacentNode = getNodeFromValue(adjacent->value);

        if (!adjacentNode->visited)
        {
            dfs(adjacentNode->value, value);
            node->lower = min(node->lower, adjacentNode->lower);

            if (parent != -1 && adjacentNode->lower > node->in)
                printf("Bridge: %d %d\n", parent, value);
        }
        else if (adjacentNode->value != parent)
            node->lower = min(node->lower, adjacentNode->in);
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
