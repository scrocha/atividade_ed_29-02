#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


typedef struct Aluno
{
    int iMatricula;
    Aluno* ptrNext;
} Aluno;

typedef struct Lista
{
    Aluno* ptrLast;
} Lista;


Lista* criarLista()
{
    Lista* temp = (Lista*) malloc(sizeof(Lista));
    temp->ptrLast = nullptr;

    return temp;
}


Aluno* criarAluno(int iMatricula)
{
    Aluno* temp = (Aluno*) malloc(sizeof(Aluno));
    temp->iMatricula = iMatricula;
    temp->ptrNext = nullptr;

    return temp;
}


bool listaVazia(Lista* const lista)
{
    if (lista->ptrLast == nullptr){
        return true;
    }
    else
    {
        return false;
    }
}


void addAluno(Lista* const lista, int iMatricula)
{
    Aluno* aluno = criarAluno(iMatricula);

    if (listaVazia(lista)){
        lista->ptrLast = aluno;
        return;
    }

    Aluno* current = lista->ptrLast;

    while (current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }

    current->ptrNext = aluno;
}


void printLista(Lista* const lista)
{
    if (listaVazia(lista)){
        cout << "Lista vazia." << endl;
        return;
    }
    Aluno* current = lista->ptrLast;

    cout << "[";

    cout << current->iMatricula;

    while (current->ptrNext != nullptr)
    {
        current = current->ptrNext;
        cout << ", " << current->iMatricula;
    }
    
    cout << "]" << endl;
}


void removeAluno(Lista* const lista, int iMatricula)
{
    if (listaVazia(lista)){
        cout << "Lista vazia." << endl;
        return;
    }

    Aluno* current = lista->ptrLast;
    Aluno* next = current->ptrNext;
    
    if (current->iMatricula == iMatricula){
        lista->ptrLast = current->ptrNext;
        free(current);
        cout << "Matrícula " << iMatricula << " removida com sucesso" << endl;
        return;
    }
    
    while (next != nullptr && next->iMatricula != iMatricula)
    {
        current = next;
        next = current->ptrNext;
    }
    
    if (next == nullptr)
    {
        cout << "Matrícula não encontrada." << endl;
        return;
    }

    current->ptrNext = next->ptrNext;
    free(next);
    cout << "Matrícula " << iMatricula << " removida com sucesso" << endl;
}


void trocaCantos(Lista* const lista)
{
    if (listaVazia(lista)){
        cout << "Lista vazia." << endl;
        return;
    }

    Aluno* current = lista->ptrLast;
    Aluno* next = current->ptrNext;

    while (next->ptrNext != nullptr)
    {
        current = next;
        next = next->ptrNext;
    }
    
    current->ptrNext = lista->ptrLast;
    next->ptrNext = lista->ptrLast->ptrNext;
    lista->ptrLast = next;
    current->ptrNext->ptrNext = nullptr;
}


Lista* intersecaoListas(Lista* const lista1, Lista* const lista2)
{
    Lista* temp = criarLista();

    Aluno* current1 = lista1->ptrLast;
    Aluno* current2;
    
    while (current1 != nullptr)
    {
        
    current2 = lista2->ptrLast;
        while (current2 != nullptr)
        {
            if (current1->iMatricula == current2->iMatricula)
            {
                addAluno(temp, current1->iMatricula);
                break;
            }
            current2 = current2->ptrNext;
        }
    current1 = current1->ptrNext;
    }

    return temp;
}

int loopLista(Lista* const lista)
{
    Aluno* current = lista->ptrLast;
    Aluno* next;
    int iContador = -1;

    while (current->ptrNext != nullptr)
    {
        int iContador = 1;
        next = current->ptrNext;
        
        while (next != nullptr)
        {
            if (current->iMatricula == next->iMatricula)
            {
                return iContador;
            }

            next = next->ptrNext;
            iContador ++;
        }

        current = current->ptrNext;
    }
    
    return iContador;
}


int main()
{
    Lista* lista = criarLista();
    addAluno(lista, 0);
    addAluno(lista, 2);
    addAluno(lista, 3);
    addAluno(lista, 4);
    addAluno(lista, 1);
    addAluno(lista, 1);
    printLista(lista);

    // Lista* lista2 = criarLista();
    // addAluno(lista2, 10);
    // addAluno(lista2, 75);
    // addAluno(lista2, 225);
    // addAluno(lista2, 3);
    // addAluno(lista2, 7);
    // printLista(lista2);

    // Lista* lista3 = intersecaoListas(lista, lista2);
    // printLista(lista3);


    cout << loopLista(lista) << endl;


    return 0;
}

