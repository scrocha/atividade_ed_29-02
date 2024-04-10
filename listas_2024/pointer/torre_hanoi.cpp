#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


typedef struct Node
{
    int iTamanho;
    Node* ptrNext;
} Node;

typedef struct Pilha
{
    Node* ptrTop;
} Pilha;


Pilha* criarPilha()
{
    Pilha* temp = (Pilha*) malloc(sizeof(Pilha));
    temp->ptrTop = nullptr;

    return temp;
}


Node* criarNode(int iTamanho)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iTamanho = iTamanho;
    temp->ptrNext = nullptr;

    return temp;
}


bool pilhaVazia(Pilha* const pilha)
{
    if (pilha->ptrTop == nullptr){
        return true;
    }
    else
    {
        return false;
    }
}

void addNode(Pilha* const pilha, int iTamanho)
{
    Node* temp = criarNode(iTamanho);

    if (pilhaVazia(pilha)){
        pilha->ptrTop = temp;
        return;
    }

    temp->ptrNext = pilha->ptrTop;
    pilha->ptrTop = temp;

}


void printPilha(Pilha* const pilha)
{
    if (pilhaVazia(pilha))
    {
        cout << "Pilha vazia." << endl;
        return;
    }
    
    Node* temp = pilha->ptrTop;
    int iPosicao = 1;
    cout << "Elemento " << iPosicao << ": " << temp->iTamanho << endl;
    temp = temp->ptrNext;
    while (temp != nullptr)
    {
        iPosicao++;

        cout << "Elemento " << iPosicao << ": " << temp->iTamanho << endl;
        temp = temp->ptrNext;
    }
}


void trocaNodes(Pilha* const pilha1, Pilha* const pilha2)
{
    if (pilha1->ptrTop->iTamanho > pilha2->ptrTop->iTamanho)
    {
        cout << "Operação inválida." << endl;
        return;
    }

    Node* top = pilha1->ptrTop;
    pilha1->ptrTop = top->ptrNext;

    top->ptrNext = pilha2->ptrTop;
    pilha2->ptrTop = top;
}


int main()
{
    // Pilha* pilha = criarPilha();
    // addNode(pilha, 5);
    // addNode(pilha, 4);
    // addNode(pilha, 3);
    // printPilha(pilha);

    // Pilha* pilha2 = criarPilha();
    // addNode(pilha2, 2);
    // addNode(pilha2, 1);
    // printPilha(pilha2);

    // cout << "===========\n";

    // trocaNodes(pilha2, pilha);

    // printPilha(pilha);
    // printPilha(pilha2);


    
    // cout << "===========\n";

    // trocaNodes(pilha2, pilha);
    // trocaNodes(pilha2, pilha);

    // printPilha(pilha);
    // printPilha(pilha2);

    return 0;
}
