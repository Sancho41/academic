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
