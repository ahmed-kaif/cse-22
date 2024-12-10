// Code Credit: Shad Ibna Hosain
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using namespace std::chrono;

typedef vector<vector<int>> Mat;

typedef vector<vector<int>> Mat;

Mat randomarr() {

  Mat v; // Declare a 2D vector

  int n = 1000; // Define the matrix size

  for (int i = 0; i < n; i++) {

    vector<int> row; // Create a row for the matrix

    for (int j = 0; j < n; j++) {

      int p1 = rand() % n; // Generate a random value

      row.push_back(p1); // Add the value to the current row
    }

    v.push_back(row); // Add the row to the matrix
  }

  return v;
}

Mat add(const Mat &A, const Mat &B) {

  int n = A.size();

  Mat result(n, vector<int>(n));

  for (int i = 0; i < n; ++i)

    for (int j = 0; j < n; ++j)

      result[i][j] = A[i][j] + B[i][j];

  return result;
}

Mat subtract(const Mat &A, const Mat &B) {

  int n = A.size();

  Mat result(n, vector<int>(n));

  for (int i = 0; i < n; ++i)

    for (int j = 0; j < n; ++j)

      result[i][j] = A[i][j] - B[i][j];

  return result;
}

Mat padded(Mat A, int opeN, int AR, int AC) {

  Mat newMatrix(opeN, vector<int>(opeN, 0));

  for (int i = 0; i < AR; i++) {

    for (int j = 0; j < AC; j++) {

      newMatrix[i][j] = A[i][j];
    }
  }

  return newMatrix;
}

Mat Multiply(const Mat &A, const Mat &B) {

  int n = A.size();

  Mat result(n, vector<int>(n, 0));

  if (n == 1) {

    result[0][0] = A[0][0] * B[0][0];

    return result;
  }

  int mid = n / 2;

  Mat A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid));

  Mat A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));

  Mat B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid));

  Mat B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

  for (int i = 0; i < mid; ++i) {

    for (int j = 0; j < mid; ++j) {

      A11[i][j] = A[i][j];

      A12[i][j] = A[i][j + mid];

      A21[i][j] = A[i + mid][j];

      A22[i][j] = A[i + mid][j + mid];

      B11[i][j] = B[i][j];

      B12[i][j] = B[i][j + mid];

      B21[i][j] = B[i + mid][j];

      B22[i][j] = B[i + mid][j + mid];
    }
  }

  Mat M1 = Multiply(add(A11, A22), add(B11, B22));

  Mat M2 = Multiply(add(A21, A22), B11);

  Mat M3 = Multiply(A11, subtract(B12, B22));

  Mat M4 = Multiply(A22, subtract(B21, B11));

  Mat M5 = Multiply(add(A11, A12), B22);

  Mat M6 = Multiply(subtract(A21, A11), add(B11, B12));

  Mat M7 = Multiply(subtract(A12, A22), add(B21, B22));

  Mat C11 = add(subtract(add(M1, M4), M5), M7);

  Mat C12 = add(M3, M5);

  Mat C21 = add(M2, M4);

  Mat C22 = add(subtract(add(M1, M3), M2), M6);

  for (int i = 0; i < mid; ++i) {

    for (int j = 0; j < mid; ++j) {

      result[i][j] = C11[i][j];

      result[i][j + mid] = C12[i][j];

      result[i + mid][j] = C21[i][j];

      result[i + mid][j + mid] = C22[i][j];
    }
  }

  return result;
}

Mat multiply(const Mat &A, const Mat &B) {

  int n = A.size();

  Mat result(n, vector<int>(n, 0));

  if (n == 1) {

    result[0][0] = A[0][0] * B[0][0];

    return result;
  }

  int mid = n / 2;

  Mat A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid));

  Mat A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));

  Mat B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid));

  Mat B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

  for (int i = 0; i < mid; ++i) {

    for (int j = 0; j < mid; ++j) {

      A11[i][j] = A[i][j];

      A12[i][j] = A[i][j + mid];

      A21[i][j] = A[i + mid][j];

      A22[i][j] = A[i + mid][j + mid];

      B11[i][j] = B[i][j];

      B12[i][j] = B[i][j + mid];

      B21[i][j] = B[i + mid][j];

      B22[i][j] = B[i + mid][j + mid];
    }
  }

  Mat C11 = add(multiply(A11, B11), multiply(A12, B21));

  Mat C12 = add(multiply(A11, B12), multiply(A12, B22));

  Mat C21 = add(multiply(A21, B11), multiply(A22, B21));

  Mat C22 = add(multiply(A21, B12), multiply(A22, B22));

  for (int i = 0; i < mid; ++i) {

    for (int j = 0; j < mid; ++j) {

      result[i][j] = C11[i][j];

      result[i][j + mid] = C12[i][j];

      result[i + mid][j] = C21[i][j];

      result[i + mid][j + mid] = C22[i][j];
    }
  }

  return result;
}

void printMatrix(const Mat &mat) {

  for (const auto &row : mat) {

    for (int val : row) {

      cout << val << " ";
    }

    cout << endl;
  }
}

int main() {

  srand(time(0));

  // Random matrices

  Mat A = randomarr();

  Mat B = randomarr();

  int AR = A.size();

  int AC = A[0].size();

  int BR = B.size();

  int BC = B[0].size();

  if (AC != BR) {

    cout << "INVALID input // Make sure First input COLUMN size equals Second "
            "input ROW size"
         << endl;

    return 0;
  }

  int maxSize = max({AR, AC, BR, BC});

  int N = 1;

  while (N < maxSize) {

    N *= 2;
  }

  // Pad matrices to size N x N

  Mat newA = padded(A, N, AR, AC);

  Mat newB = padded(B, N, BR, BC);

  auto start = high_resolution_clock::now();

  Mat C = multiply(newA, newB);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Divide-and-Conquer Time: " << duration.count() << " microseconds"
       << endl;

  start = high_resolution_clock::now();

  Mat D = Multiply(newA, newB);

  stop = high_resolution_clock::now();

  duration = duration_cast<microseconds>(stop - start);

  cout << "Strassen's Algorithm Time: " << duration.count() << " microseconds"
       << endl;

  return 0;
}
