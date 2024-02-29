#include <iostream>

using namespace std;


float fCalcularImc(float fMassa, float fAltura)
{

    float fImc = fMassa / (fAltura*fAltura);

    return fImc;
}


string sVerificarImc(float fImc)
{

    if (fImc < 17)
    {
        return "Muito abaixo do peso";
    }
    else if (fImc < 18.5)
    {
        return "Abaixo do peso";
    }
    else if (fImc < 25)
    {
        return "Peso normal";
    }
    else if (fImc < 30)
    {
        return "Acima do peso";
    }
    else if (fImc < 35)
    {
        return "Obesidade";
    }
    else if (fImc < 40)
    {
        return "Obesidade severa";
    }
    else
    {
        return "Obesidade mórbida";
    }
}


int main()
{
    float fMassa;
    float fAltura;

    cout << "Insira sua massa: ";
    cin >> fMassa;

    cout << "Insira sua altura: ";
    cin >> fAltura;

    float fImc = fCalcularImc(fMassa, fAltura);

    string sResultado = sVerificarImc(fImc);

    cout << "Seu IMC é: " << fImc << "\n" << "Classificação: " << sResultado;

    return 0;
}

