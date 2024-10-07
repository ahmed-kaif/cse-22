#include <bits/stdc++.h>
using namespace std;

int main() {
  int x[] = {1, 3, 5, 7};
  double y[] = {24, 120, 336, 720};
  int n = sizeof(x) / sizeof(x[0]); // no. of data points

  double value;
  cout << "Enter value: ";
  cin >> value;
  double result = 0.0;

  for (int i = 0; i <= n - 1; i++) {
    double term = y[i];
    for (int j = 0; j <= n - 1; j++) {
      if (j != i) {
        term = term * (value - x[j]) / (x[i] - x[j]);
      }
    }
    result = result + term;
  }
  cout << "y(" << value << ") = ";
  cout << result << endl;
}
