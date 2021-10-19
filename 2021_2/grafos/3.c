#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int visited;
    struct Node *adjacentList;
} Node;

Node **graph;
int *in;
int *out;
int graphSize;
int time = 1;

void initializeNodeList(int size);
Node *createNode(int value);
void addToAdjacentList(Node *node, Node *adjacent);
void addToGraph(int from, int to);
Node *getNodeFromValue(int value);
void dfs(int value);
void loadGraph();
void resetGraph();
int distance(int from, int to);

int main()
{
    int nodes, from, to;

    scanf("%d", &nodes);
    initializeNodeList(nodes);

    loadGraph();

    dfs(1);

    scanf("%d %d", &from, &to);

    if (in[from - 1] > in[to - 1] && out[from - 1] < out[to - 1])
        printf("Verdadeiro\n");
    else
        printf("Falso\n");
        
    return EXIT_SUCCESS;
}

void initializeNodeList(int size)
{
    graph = (Node **)calloc(sizeof(Node *), size);
    in = (int *)calloc(sizeof(int), size);
    out = (int *)calloc(sizeof(int), size);
    graphSize = size;
}

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
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

void dfs(int value)
{
    Node *node = getNodeFromValue(value);

    if (node->visited)
        return;

    in[value - 1] = time;

    time++;

    node->visited = 1;

    Node *adjacentAux = node->adjacentList;

    while (adjacentAux != NULL)
    {
        dfs(adjacentAux->value);
        adjacentAux = adjacentAux->adjacentList;
    }

    out[value - 1] = time;
    time++;
}

void loadGraph()
{
    int edges, from, to;

    scanf("%d", &edges);

    while (edges--)
    {
        scanf("%d %d", &from, &to);
        addToGraph(from, to);
    }
}
