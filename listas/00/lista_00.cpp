#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void problema1(int iInicio, int iFim){
    int iDuracao = iFim - iInicio;

    if (iDuracao < 0){
        iDuracao += 24;
    }
    cout << "O JOGO DUROU " << iDuracao << " HORA(S)" << endl;
}

void problema2(float fA, float fB, float fC){
    float fDelta = fB * fB - 4 * fA * fC;
    // cout << fDelta << "\n";
    if (fDelta < 0){
        cout << "Impossivel calcular" << endl;
    }
    else if (fDelta == 0) {
        float fR1 = -fB / (2 * fA);
        cout << "R1 = " << (float) fR1 << endl;
    }

}


int main() {
    problema2(1, 4, 4);

    return 0;
}

