#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
  int n, d;
  cin >> n >> d;
  vector<int> expenditure(n);

  for (int i = 0; i < n; i++) {
    cin >> expenditure[i];
  }
  int i, j;
  int notification = 0;
  for (i = d - 1, j = i + 1; i < n; i++) {
    sort(expenditure.begin(), expenditure.begin() + i);
    int median_index;
    int median;
    if (i % 2 != 0) {
      // odd
      median_index = i / 2;
      median = expenditure[median_index];
    } else {
      // even
      median = (expenditure[i / 2] + expenditure[(i / 2) + 1]) / 2;
    }
    if (expenditure[j] >= (2 * median)) {
      notification++;
    }
  }

  cout << notification << endl;

  return 0;
}
