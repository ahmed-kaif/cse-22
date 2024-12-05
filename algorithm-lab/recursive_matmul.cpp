#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

void add_matrices(const Matrix &A, const Matrix &B, Matrix &C, int row_start,
                  int col_start, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[row_start + i][col_start + j] =
          A[row_start + i][col_start + j] + B[row_start + i][col_start + j];
    }
  }
}
void subtract_matrices(const Matrix &A, const Matrix &B, Matrix &C,
                       int row_start, int col_start, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      C[row_start + i][col_start + j] =
          A[row_start + i][col_start + j] - B[row_start + i][col_start + j];
    }
  }
}

void multiply_matrices(Matrix &A, Matrix &B, Matrix &C, int rowA, int colA,
                       int rowB, int colB, int size) {
  if (size == 1) {
    C[rowA][colB] += A[rowA][colA] * B[rowB][colB];
    return;
  }

  int new_size = size / 2;

  // Allocate new matrices
  Matrix A11(new_size, vector<int>(new_size));
  Matrix A12(new_size, vector<int>(new_size));
  Matrix A21(new_size, vector<int>(new_size));
  Matrix A22(new_size, vector<int>(new_size));
  Matrix B11(new_size, vector<int>(new_size));
  Matrix B12(new_size, vector<int>(new_size));
  Matrix B21(new_size, vector<int>(new_size));
  Matrix B22(new_size, vector<int>(new_size));

  // Divide Matrices
  for (int i = 0; i < new_size; i++) {
    for (int j = 0; j < new_size; j++) {
      // top left
      A11[i][j] = A[rowA + i][colA + j];
      // top right
      A12[i][j] = A[rowA + i][colA + j + new_size];
      // bottom left
      A21[i][j] = A[rowA + i + new_size][colA + j];
      // bottom right
      A22[i][j] = A[rowA + i + new_size][colA + j + new_size];

      // top left
      B11[i][j] = B[rowB + i][colB + j];
      // top right
      B12[i][j] = B[rowB + i][colB + j + new_size];
      // bottom left
      B21[i][j] = B[rowB + i + new_size][colB + j];
      // bottom right
      B22[i][j] = B[rowB + i + new_size][colB + j + new_size];
    }
  }
  // C11
  multiply_matrices(A11, B11, C, rowA, colB, rowB, colB, new_size);
  // C12
  multiply_matrices(A12, B21, C, rowA, colB, rowB, colB, new_size);
  multiply_matrices(A11, B12, C, rowA, colB, rowB, colB, new_size);
}
