#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int problema1(long int iNum){
    if (iNum % 2 == 0 || iNum % 5 == 0){
        return 1;
    }

    int iOnes = 1;
    unsigned int iMult = 1;

    while (iMult % iNum != 0){
        iMult = iMult * 10 + 1;
        iOnes++;
        iMult = iMult % iNum;
    }

    return iOnes;
}


int problema2(int iNum){



    
}


int main() {
    cout << problema1(9901) << "\n";

    return 0;
}
