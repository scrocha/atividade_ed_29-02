#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void problema1(int iInicio, int iFim){
    int iDuracao = iFim - iInicio;

    if (iDuracao <= 0){
        iDuracao += 24;
    }
    cout << "O JOGO DUROU " << iDuracao << " HORA(S)" << endl;
}


void problema2(float fA, float fB, float fC){
    float fDelta = fB * fB - 4 * fA * fC;
    // cout << fDelta << "\n";
    if (fDelta < 0 || fA == 0){
        cout << "Impossivel calcular" << endl;
        return;
    }
    else if (fDelta == 0) {
        float fR1 = -fB / (2 * fA);
        cout << "R1 = " << fR1 << endl;
        return;
    }
    float fR1 = (-fB + std::sqrt(fDelta)) / (2 * fA);
    float fR2 = (-fB - std::sqrt(fDelta)) / (2 * fA);

    cout << "R1 = " << (float) fR1 << endl;        
    cout << "R2 = " << (float) fR2 << endl;
}


void problema3(float fA, float fB, float fC){
    float fDelta = fB * fB - 4 * fA * fC;
    if (fA == 0){
        cout << "Impossivel calcular" << endl;
    }

    else if (fDelta < 0){
        float square_root = std::sqrt(std::abs(fDelta)) / (2 * fA);
        
        float fR = (-fB) / (2 * fA);

        cout << "R1 = " << (float) fR << " + " << square_root << "i" << endl;
        cout << "R2 = " << (float) fR << " - " << square_root << "i" << endl;
    }

    else if (fDelta == 0) {
        float fR1 = -fB / (2 * fA);
        cout << "R1 = " << fR1 << endl;
    }

    else {
    float fR1 = (-fB + std::sqrt(fDelta)) / (2 * fA);
    float fR2 = (-fB - std::sqrt(fDelta)) / (2 * fA);

    cout << "R1 = " << (float) fR1 << endl;        
    cout << "R2 = " << (float) fR2 << endl;
    }
}


int main() {
    // problema3(10, 3, 5);

    return 0;
}

