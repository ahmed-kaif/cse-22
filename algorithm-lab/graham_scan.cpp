#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
using namespace std::chrono;

typedef pair<int, int> Point;
typedef vector<Point> vpii;
stack<Point> S;
vpii P; // points are stored as (y,x)
vpii sorted_points;
vpii hull_pts;

int get_y(const Point p) { return p.first; }
int get_x(const Point p) { return p.second; }
Point get_min(const vpii P) { return *min_element(P.begin(), P.end()); }

bool non_left_turn(const Point p1, const Point p2, Point p) {
  int cross_prod = (get_x(p2) - get_x(p1)) * (get_y(p) - get_y(p1)) -
                   (get_y(p2) - get_y(p1)) * (get_x(p) - get_x(p1));
  if (cross_prod > 0)
    return false;
  else if (cross_prod < 0)
    return true;
  return false;
}

Point next_to_top(stack<Point> &s) {
  Point top = s.top();
  s.pop();
  Point next_top = s.top();
  s.push(top);
  return next_top;
}

void read_points_from_file(const string file_name, vpii &points);
void print_points(const vpii points, int n);

int main() {
  read_points_from_file("points.txt", P);
  Point p0 = get_min(P); // reference point
  auto order = [&](Point p1, Point p2) -> bool {
    int dx1 = get_x(p1) - get_x(p0), dy1 = get_y(p1) - get_y(p0);
    int dx2 = get_x(p2) - get_x(p0), dy2 = get_y(p2) - get_y(p0);

    int cross = dx1 * dy2 - dy1 * dx2;
    if (cross == 0)
      return (dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2);

    return cross > 0;
  };

  sorted_points = P;
  int m = sorted_points.size();
  // print_points(sorted_points, m);

  auto st = high_resolution_clock::now(); // clock start

  sort(sorted_points.begin(), sorted_points.end(), order);
  S.push(p0);
  S.push(sorted_points[1]);
  S.push(sorted_points[2]);

  for (int i = 3; i < m; i++) {
    Point p_i = sorted_points[i];
    while (S.size() > 1 && non_left_turn(next_to_top(S), S.top(), p_i)) {
      S.pop();
    }
    S.push(p_i);
  }

  while (!S.empty()) {
    Point p = S.top();
    hull_pts.push_back(p);
    S.pop();
  }
  auto et = high_resolution_clock::now(); // clock end
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(et - st).count();
  time_taken *= 1e-6;
  cout << "Convex hull points using Graham Scan:" << endl;
  // print_points(hull_pts, hull_pts.size());
  cout << "Time taken for Graham Scan: " << time_taken << " ms" << endl;
  cout << "No. of Points: " << P.size() << endl;
}

void read_points_from_file(const string file_name, vpii &points) {
  ifstream inputFile(file_name);
  if (!inputFile.is_open()) {
    cerr << "Error opening the file!" << endl;
    exit(1);
  }
  string line;
  while (getline(inputFile, line)) {
    stringstream ss(line);
    int x, y;
    ss >> x >> y;
    points.push_back(make_pair(y, x));
  }
  inputFile.close();
}

void print_points(const vpii points, int n) {
  cout << "X = [ ";
  for (int i = 0; i < n; i++) {
    cout << get_x(points[i]) << ", ";
  }
  cout << get_x(points[0]) << " ]" << endl;
  cout << "Y = [ ";
  for (int i = 0; i < n; i++) {
    cout << get_y(points[i]) << ", ";
  }
  cout << get_y(points[0]) << " ]" << endl;
}
