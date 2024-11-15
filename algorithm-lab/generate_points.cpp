#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
  ofstream myfile;
  int n;
  cout << "How many points? ";
  cin >> n;
  myfile.open("./points.txt");
  if (myfile.is_open()) {
    srand(time(0));
    for (int k = 0; k < n; k++) {
      int x = rand() % 100 + 1;
      int y = rand() % 100 + 1;
      myfile << x << " " << y << "\n";
    }
    myfile.close();
  } else {
    cout << "Error opening file." << endl;
  }
  return 0;
}
