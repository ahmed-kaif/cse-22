#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
  cout << "sample" << setw(18) << "quick sort" << setw(15) << "bubble sort"
       << endl;
  int sample[7] = {10000, 20000, 30000, 40000, 50000, 60000, 70000};
  for (int l = 0; l < 7; l++) {
    vector<int> nums;
    vector<int> nums_for_bubble;
    srand(time(0));
    for (int k = 0; k < sample[l]; k++) {
      int x = rand() % 100007 + 1;
      nums.push_back(x);
      nums_for_bubble.push_back(x);
    }
    auto st = high_resolution_clock::now();
    sort(nums.begin(), nums.end());
    auto et = high_resolution_clock::now();
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(et - st).count();
    time_taken *= 1e-9;
    // cout << "Quick sort: " << ((double)(endt - startt)/CLOCKS_PER_SEC) <<
    // endl;
    // bubble sort
    auto st2 = high_resolution_clock::now();
    for (int i = 0; i < nums_for_bubble.size(); i++) {
      for (int j = 0; j < nums_for_bubble.size() - i; j++) {
        if (nums_for_bubble[j] > nums_for_bubble[j + 1]) {
          int temp = nums_for_bubble[j + 1];
          nums_for_bubble[j + 1] = nums_for_bubble[j];
          nums_for_bubble[j] = temp;
        }
      }
    }
    auto et2 = high_resolution_clock::now();
    double time_taken_2 =
        chrono::duration_cast<chrono::nanoseconds>(et2 - st2).count();
    time_taken_2 *= 1e-9;
    cout << nums.size() << setw(18) << time_taken << setw(15) << time_taken_2
         << endl;
  }
}
