#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void printArray(int* array, int size){

    cout << "{" << *array;

    if (size > 1){
        for (int i=1; i<size; i++){
            cout << ", " << *(array + i);
        }
    }
    cout << "}" << endl;
}


void operarArrays(int* arrayA, int* arrayB, char oper, int size){
    if (oper == '+'){
        for (int i=0; i<size; i++){
            *(arrayA + i) += *(arrayB + i);
        }
    }

    else if (oper == '-'){
        for (int i=0; i<size; i++){
            *(arrayA + i) -= *(arrayB + i);
        }
    }

    else {
        cout << "Operação inexistente!" << endl;
    }
}


int main() {
    // int a[5] = {1, 2, 3, 4, 5};
    // int b[5] = {2, 4, 1, 2, 3};

    // operarArrays(a, b, '-', 5);
    // printArray(a, 5);

    return 0;
}
