/*
Entrada

6
0 6 9 11 5 9
6 0 3 6 5 2
9 3 0 0 4 4
11 6 0 0 5 6
5 5 4 5 0 8
9 2 4 6 8 0
F

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int visited;
    int weight;
    int distance;
    struct Node *next;
} Node;

Node **graph;
int adjSize;

void loadGraph();
void addToGraph(int from, int to, int weight);
Node *createNode(int value, int weight);
Node *getNoteFromValue(int value);
void addToAdjacentList(Node *node, Node *newNode);
void printAdjList();
void dijkstra(int start);
Node *getMinNode();
void printDistances();
int getWeightFromNodeAdj(Node *node, int value);

int main()
{
    int letter;
    loadGraph();

    scanf("%*c%c", &letter);
    letter = letter - 'A';

    dijkstra(letter);

    printDistances();

    return EXIT_SUCCESS;
}

void dijkstra(int start)
{
    Node *minNode, *node, *src = getNoteFromValue(start);
    int i, weight;

    src->distance = 0;

    for (i = 0; i < adjSize - 1; i++)
    {
        minNode = getMinNode();
        minNode->visited = 1;

        for (int j = 0; j < adjSize; j++)
        {
            node = graph[j];

            weight = getWeightFromNodeAdj(minNode, node->value);

            if (node->visited == 0 && weight && minNode->distance != INT_MAX && minNode->distance + weight < node->distance)
                node->distance = minNode->distance + weight;
        }
    }
}

int getWeightFromNodeAdj(Node *node, int value)
{
    Node *adjNode = node->next;

    while (adjNode != NULL)
    {
        if (adjNode->value == value)
            return adjNode->weight;

        adjNode = adjNode->next;
    }

    return 0;
}

Node *getMinNode()
{
    Node *minNode;
    int min = INT_MAX;

    for (int j = 0; j < adjSize; j++)
    {
        if (graph[j]->visited == 0 && graph[j]->distance < min)
        {
            min = graph[j]->distance;
            minNode = graph[j];
        }
    }

    return minNode;
}

void loadGraph()
{
    int i, j, weight;

    scanf("%d", &adjSize);

    graph = (Node **)calloc(sizeof(Node *), adjSize);

    for (i = 0; i < adjSize; i++)
        for (j = 0; j < adjSize; j++)
        {
            scanf("%d", &weight);
            addToGraph(i, j, weight);
        }
}

void printAdjList()
{
    for (int i = 0; i < adjSize; i++)
    {
        printf("%d: ", i + 1);

        for (Node *next = graph[i]->next; next != NULL; next = next->next)
            printf("%d ", next->distance);

        printf("\n");
    }
}

void printDistances()
{
    for (int i = 0; i < adjSize; i++)
        printf("%c: %d\n", i + 'A', graph[i]->distance);
}

void addToGraph(int from, int to, int weight)
{

    if (graph[from] == NULL)
        graph[from] = createNode(from, weight);
    if (graph[to] == NULL)
        graph[to] = createNode(to, weight);

    addToAdjacentList(graph[from], createNode(to, weight));
    addToAdjacentList(graph[to], createNode(from, weight));
}

Node *createNode(int value, int weight)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->weight = weight;
    node->next = NULL;
    node->visited = 0;
    node->distance = INT_MAX;

    return node;
}

void addToAdjacentList(Node *node, Node *adjacent)
{
    if (node->next == NULL)
        node->next = adjacent;
    else
    {
        Node *next = node->next;

        while (next->next != NULL)
        {
            if (next->next->value == adjacent->value)
                return;
            next = next->next;
        }

        next->next = adjacent;
    }
}

Node *getNoteFromValue(int value)
{
    return graph[value];
}
