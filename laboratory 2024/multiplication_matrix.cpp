#include "multiplication_matrix.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Calc calc;
    //A*B==C
    matrix A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    matrix B = {{1, 2}, {4, 5}, {7, 8}};
    matrix C;
    C = calc.multiplication(A, B);
    for (int i = 0; i<A.size(); i++){
        for (int j = 0; j<B[0].size(); j++){
            cout<<C[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}