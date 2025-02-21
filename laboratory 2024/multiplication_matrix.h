#ifndef C_MULTIPLICATION_MATRIX_H
#define C_MULTIPLICATION_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<float>> matrix;

class Calc{
public:
    float multiplication_for_index(matrix A, matrix B, int index_row, int index_col) {
        vector<float> number(B.size());
        float num = 0;
        for (int i = 0; i < A[0].size(); i++) {
            number[i] = A[index_row][i];
        }
        for (int i = 0; i < B.size(); i++) {
            number[i] *= B[i][index_col];
        }
        for (int i = 0; i < number.size(); i++)
            num += number[i];
        return num;
    }

    matrix multiplication(matrix A, matrix B) {
        vector<float> in_matrix(B[0].size());
        matrix C(A.size(), in_matrix);
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] = multiplication_for_index(A, B, i, j);
            }
        }
        return C;
    }
};

#endif //C_MULTIPLICATION_MATRIX_H
