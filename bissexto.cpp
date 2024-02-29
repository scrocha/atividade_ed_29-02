#include <iostream>

using namespace std;


bool bVerificarBissexto(int nAno)
{

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

    cout << "Insira um ano: ";
    cin >> nAno;

    bool bBissexto = bVerificarBissexto(nAno);

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

