#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

void iterative_matrix_multiplication(Matrix &m1, Matrix &m2, Matrix &product) {
  int r1 = m1.size();
  int r2 = m2.size();
  int c1 = m1[0].size();
  int c2 = m2[0].size();
  if (c1 != r2) {
    cout << "Invalid matrix dimension for multiplication" << endl;
    exit(1);
  }
  product.resize(r1, vector<int>(c2, 0));
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      for (int k = 0; k < c1; k++) {
        product[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

void recursive_matrix_multiplication(Matrix &m1, Matrix &m2, Matrix &product) {}

void strassen_algorithm(Matrix &m1, Matrix &m2, Matrix &product) {}

int main() {
  vector<vector<int>> m1 = {{1, 1}, {2, 2}};
  vector<vector<int>> m2 = {{1, 1}, {2, 2}};
  vector<vector<int>> res;

  iterative_matrix_multiplication(m1, m2, res);

  cout << "Multiplication of given two matrices is:\n";
  for (const auto &row : res) {
    for (int val : row) {
      cout << val << "\t";
    }
    cout << endl;
  }

  return 0;
}
