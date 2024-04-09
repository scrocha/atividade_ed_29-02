#include <iostream>

using namespace std;


float fCalcularImc(float fMassa, float fAltura)
{
    // Função que realiza o cálculo básico do IMC, sendo ele massa sob altura ao quadrado.

    float fImc = fMassa / (fAltura*fAltura);

    return fImc;
}


string sVerificarImc(float fImc)
{
    // Função que retorna a classificação com base no IMC inserido utilizando
    // if, else if e else.

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
    // Recebe o input de massa do usuário.
    cout << "Insira sua massa: ";
    cin >> fMassa;

    // Recebe o input de altura do usuário.
    cout << "Insira sua altura: ";
    cin >> fAltura;

    // Calcula o IMC com os inputs.
    float fImc = fCalcularImc(fMassa, fAltura);

    // Verifica a classificação do IMC.
    string sResultado = sVerificarImc(fImc);

    // Imprime no terminal o IMC e a classificação.
    cout << "Seu IMC é: " << fImc << "\n" << "Classificação: " << sResultado;

    return 0;
}

