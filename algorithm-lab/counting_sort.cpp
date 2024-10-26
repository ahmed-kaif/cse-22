#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace std::chrono;

vector<int> counting_sort(vector<int> &A) {
  int N = A.size();
  int max_ele = 0;

  for (int i = 0; i < N; i++)
    max_ele = max(max_ele, A[i]);

  vector<int> C(max_ele + 1, 0); // count array
  for (int i = 0; i < N; i++)
    C[A[i]]++;

  for (int i = 1; i <= max_ele; i++)
    C[i] += C[i - 1]; // cumulative sum

  vector<int> B(N); // output array
  for (int i = N - 1; i >= 0; i--) {
    B[C[A[i]] - 1] = A[i];

    C[A[i]]--;
  }

  return B;
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

  auto st = high_resolution_clock::now();
  // counting sort
  nums = counting_sort(nums);

  auto et = high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(et - st).count();
  time_taken *= 1e-6;

  // for (auto x : nums)
  //   cout << x << endl;

  cout << "Time taken for counting sort: " << time_taken << " ms" << endl;
  cout << "No. of Datas: " << nums.size() << endl;
  return 0;
}
