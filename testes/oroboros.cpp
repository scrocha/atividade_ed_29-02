#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct Node {
    int iData;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

typedef struct Lista {
    Node* ptrHead;
} Lista;


Node* newNode(int iData)
{
    Node* ptrNewNode = (Node*) malloc(sizeof(Node));
    ptrNewNode->iData = iData;
    ptrNewNode->ptrNext = nullptr;
    ptrNewNode->ptrPrev = nullptr;
    return ptrNewNode;
}

Lista* newLista()
{
    Lista* temp = (Lista*) malloc(sizeof(Lista));
    temp->ptrHead = nullptr;
    return temp;
}

void addNode(Lista* lista, int iData)
{
    Node* ptrNewNode = newNode(iData);
    if (lista->ptrHead == nullptr)
    {
        lista->ptrHead = ptrNewNode;
        ptrNewNode->ptrNext = ptrNewNode;
        ptrNewNode->ptrPrev = ptrNewNode;
        return;
    }

    Node* ptrTemp = lista->ptrHead->ptrNext;

    while (ptrTemp->ptrNext != lista->ptrHead)
    {
        ptrTemp = ptrTemp->ptrNext;
    }

    ptrNewNode->ptrNext = ptrTemp->ptrNext ;
    ptrNewNode->ptrNext->ptrPrev = ptrNewNode;

    ptrTemp->ptrNext = ptrNewNode;
    ptrNewNode->ptrPrev = ptrTemp;
}

void printLista(Lista* lista)
{
    if (lista->ptrHead == nullptr)
    {
        cout << "Lista vazia" << endl;
        return;
    }
    cout << '[' << lista->ptrHead->iData;
    Node* ptrTemp = lista->ptrHead->ptrNext;

    while (ptrTemp != lista->ptrHead)
    {
        cout << ", " << ptrTemp->iData;
        ptrTemp = ptrTemp->ptrNext;
    }
    cout << ']' << endl;
}

void removeNode(Lista* lista, Node* node)
{
    if (lista->ptrHead == nullptr)
    {
        return;
    }

    if (lista->ptrHead == node)
    {
        if (node->ptrNext == node)
        {
            lista->ptrHead = nullptr;
            free(node);
            return;
        }
        lista->ptrHead = node->ptrNext;
    }

    node->ptrPrev->ptrNext = node->ptrNext;
    node->ptrNext->ptrPrev = node->ptrPrev;
    free(node);
    return;
}

// Formula: a = 2^(a-1) * (2b + 1)

int comeOroboros(Lista* lista)
{
    if (lista->ptrHead == nullptr)
    {
        return 0;
    }

    int a = lista->ptrHead->iData;
    Node* ptrTail = lista->ptrHead->ptrPrev;

    if (ptrTail == lista->ptrHead)
    {
        return a;
    }
    
    while (ptrTail != lista->ptrHead)
    {
        a = pow(2, a-1) * (2 * ptrTail->iData + 1);
        removeNode(lista, ptrTail);
        ptrTail = lista->ptrHead->ptrPrev;
    }
    removeNode(lista, ptrTail);
    
    return a;
}

Lista* refazOroboros(int a, int n)
{
    Lista* lista = newLista();

    int iTemp = a;

    for (int i=1; i<n; i++)
    {
        int iNum = 1;
        while (iTemp % 2 == 0)
        {
            iTemp /= 2;
            iNum++;
        }
        int b = (iTemp - 1) / 2;

        addNode(lista, b);
        iTemp = iNum;
    }
    
    addNode(lista, iTemp);
    lista->ptrHead = lista->ptrHead->ptrPrev;

    return lista;
}

int main()
{
    Lista* lista = newLista();
    addNode(lista, 1);
    addNode(lista, 7);
    addNode(lista, 4);
    printLista(lista);

    int resultado = comeOroboros(lista);
    cout << "Resultado do Oroboros: " << resultado << endl;

    Lista* novaLista = refazOroboros(resultado, 3);
    printLista(novaLista);

    return 0;
}
