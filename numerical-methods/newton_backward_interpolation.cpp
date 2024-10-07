#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

double factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return factorial(n - 1) * n;
}

int main() {
  int n = 4;
  int x[] = {1, 3, 5, 7};
  double y[] = {24, 120, 336, 720};
  double diffTable[4][4] = {{24}, {120}, {336}, {720}};

  for (int j = 1; j <= n - 1; j++) {
    for (int i = n - 1; i >= j; i--) {
      diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
    }
  }
  int h = x[1] - x[0];
  double desired_x;
  cout << "Enter desired x: ";
  cin >> desired_x;
  double p = (desired_x - x[n - 1]) / h;

  double result = y[n - 1];
  for (int i = 1; i <= n - 1; i++) {
    double product = p;
    for (int k = 1; k <= i - 1; k++) {
      product = product * (p + k);
    }
    result = result + (product * diffTable[n - 1][i]) / factorial(i);
  }
  // print diff table
  cout << "Backward Difference Table:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << diffTable[i][j] << " ";
    }
    cout << endl;
  }

  printf("y(%.2lf) = %.2lf\n", desired_x, result);
}
