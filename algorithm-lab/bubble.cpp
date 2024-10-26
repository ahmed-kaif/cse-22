#include "include/VariadicTable.h"
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using namespace std::chrono;

void bubble_sort(vector<int> &nums_for_bubble, int p, int r) {
  for (int i = p; i < r; i++) {
    for (int j = p; j < r - (i - p); j++) {
      if (nums_for_bubble[j] > nums_for_bubble[j + 1]) {
        swap(nums_for_bubble[j], nums_for_bubble[j + 1]);
      }
    }
  }
}
void merge(vector<int> &A, int p, int q, int r) {
  int nl = q - p + 1;
  int nr = r - q;
  vector<int> L(nl);
  vector<int> R(nr);

  for (int i = 0; i < nl; i++) {
    L[i] = A[p + i];
  }
  for (int i = 0; i < nr; i++) {
    R[i] = A[q + i + 1];
  }
  int i = 0;
  int j = 0;
  int k = p;

  while (i < nl && j < nr) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < nl) {
    A[k] = L[i];
    i++;
    k++;
  }
  while (j < nr) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void hybrid_sort(vector<int> &A, int p, int r, int threshold) {
  if (p >= r)
    return;

  if (abs(r - p + 1) <= threshold) {
    bubble_sort(A, p, r);
    return;
  }

  int q = floor((p + r) / 2);

  hybrid_sort(A, p, q, threshold);
  hybrid_sort(A, q + 1, r, threshold);
  merge(A, p, q, r);
}

int main() {
  ifstream inputFile("nums.txt");
  vector<int> nums;
  if (!inputFile.is_open()) {
    cerr << "Error opening the file!" << endl;
    return 1;
  }
  string line;
  while (getline(inputFile, line)) {
    nums.push_back(stoi(line));
  }

  inputFile.close();

  vector<int> clone = nums;

  vector<double> times;

  int len = nums.size();
  int threshold;
  cout << "Enter start threshold: ";
  cin >> threshold;

  VariadicTable<int, double> vtable({"Threshold", "Time (ms)"}, 10);
  for (int i = 0; i < 20; i++) {
    auto st = high_resolution_clock::now();

    // hybrid sort
    hybrid_sort(nums, 0, len - 1, threshold);

    auto et = high_resolution_clock::now();
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(et - st).count();
    time_taken *= 1e-6;
    times.push_back(time_taken);

    // for (auto x : nums)
    //   cout << x << endl;
    vtable.addRow(threshold, time_taken);
    threshold++;
  }
  cout << "[ ";
  for (auto x : times) {
    cout << x << ", ";
  }
  cout << "\b\b]" << endl;
  vtable.print(std::cout);

  return 0;
}
