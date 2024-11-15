#include <bits/stdc++.h>
#include <cmath>
#include <csignal>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> vpii;
int main() {
  vpii points;
  string file_name = "points.txt";
  ifstream inputFile(file_name);
  if (!inputFile.is_open()) {
    cerr << "Error opening the file!" << endl;
    return 1;
  }
  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    int x, y;
    ss >> x >> y;
    points.push_back(make_pair(x, y));
  }

  inputFile.close();

  for (auto x : points) {
    cout << x.first << " " << x.second << endl;
  }
}
