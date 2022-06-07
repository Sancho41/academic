// https://www.hackerearth.com/pt-br/problem/algorithm/connected-components-in-a-graph/

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int value;
    struct Element *next;
} Element;

typedef struct LinkedList
{
    int qtd;
    Element *start;
} LinkedList;

Element *createElement(int value)
{
    Element *element = (Element *)malloc(sizeof(Element));
    element->next = NULL;
    element->value = value;

    return element;
}

LinkedList *createLinkedList()
{
    LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));
    linkedList->start = NULL;
    linkedList->qtd = 0;

    return linkedList;
}

int addElement(LinkedList *linkedList, Element *element)
{
    int qtd;
    Element *lastElement;

    qtd = linkedList->qtd++;
    lastElement = linkedList->start;

    if (qtd == 0)
    {
        linkedList->start = element;
        return EXIT_SUCCESS;
    }

    while (--qtd)
        lastElement = lastElement->next;

    lastElement->next = element;

    return EXIT_SUCCESS;
}

void printLinkedList(LinkedList *linkedList)
{
    int qtd = linkedList->qtd;

    Element *currentElement = linkedList->start;

    while (qtd--)
    {
        printf("Elemento %d: %d\n", linkedList->qtd - qtd, currentElement->value);
        currentElement = currentElement->next;
    }
}

void dfs(int value, LinkedList **nodeList, int *visited)
{
    LinkedList *adjList;
    Element *adj;
    int qtdAdjList;

    adjList = nodeList[value];
    visited[value] = 1;

    if (adjList == NULL || adjList->qtd == 0)
        return;

    adj = adjList->start;

    while (adj != NULL)
    {
        if (visited[adj->value] == 0)
            dfs(adj->value, nodeList, visited);
        adj = adj->next;
    }
}

int main()
{

    int qtdNodes, qtdEdges;
    int currentNodeValue, currentAdjacentValue;

    int i;

    LinkedList **nodeList, *currentNode;
    int *visited;

    scanf("%d %d", &qtdNodes, &qtdEdges);

    nodeList = (LinkedList **)calloc(qtdNodes, sizeof(LinkedList *));
    visited = (int *)calloc(qtdNodes, sizeof(int));

    while (qtdEdges--)
    {
        scanf("%d %d", &currentNodeValue, &currentAdjacentValue);
        currentNodeValue--;
        currentAdjacentValue--;

        if (nodeList[currentNodeValue] == NULL)
            nodeList[currentNodeValue] = createLinkedList();

        currentNode = nodeList[currentNodeValue];

        addElement(currentNode, createElement(currentAdjacentValue));
    }

    int qtdDfsCalls = 0;

    for (i = 0; i < qtdNodes; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, nodeList, visited);
            qtdDfsCalls++;
        }
    }

    printf("%d\n", qtdDfsCalls);

    return EXIT_SUCCESS;
}
