#include <iostream>

using namespace std;


bool bVerificarBissexto(int nAno)
{
    // Função que verifica se um ano é bissexto, primeiro olhando se é
    // Divisível por 400, depois por 100 e por fim por 4.
    if (nAno % 400 == 0)
    {
        return true;
    }
    else if (nAno % 100 == 0)
    {
        return false;
    }
    else if (nAno % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int nAno;

    // Recebe o input de um ano do usuário.
    cout << "Insira um ano: ";
    cin >> nAno;

    // Verifica se ele é ou não bissexto pela função.
    bool bBissexto = bVerificarBissexto(nAno);

    // Imprime no console se o ano é ou não bissexto.
    if (bBissexto == true)
    {
        cout << "Ano bissexto!";
    }
    else
    {
        cout << "Não é bissexto!";
    }

    return 0;
}

