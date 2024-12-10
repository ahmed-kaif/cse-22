// Lab Final Code
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<double> x = {7.47, 7.48, 7.49, 7.50, 7.51, 7.52};
  vector<double> y = {1.93, 1.95, 1.98, 2.01, 2.03, 2.06};
  double result = 0;
  double h = x[1] - x[0];
  double sum = 0;
  for (int i = 1; i < x.size() - 1; i++) {
    sum += y[i];
  }
  result = (h / 2.0) * (y[0] + 2 * sum + y[5]);
  cout << "Approximate Result = " << result << endl;
}
