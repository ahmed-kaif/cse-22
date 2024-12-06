#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> vpii;
stack<Point> S;
vpii P; // points are stored as (y,x)
vpii sorted_points;
vpii hull_pts;

int get_y(const Point p) { return p.first; }
int get_x(const Point p) { return p.second; }

bool non_left_turn(const Point p1, const Point p2, const Point p) {
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

void generate_points(vpii &P, int n);
void print_points(const vpii points, int n);

Point get_min(vpii P) { return *min_element(P.begin(), P.end()); }

int main() {
  int n;
  cout << "How many points? ";
  cin >> n;
  generate_points(P, n);

  Point p0 = get_min(P);
  cout << "Reference Point: " << get_x(p0) << " " << get_y(p0) << endl;

  auto order = [&](Point p1, Point p2) -> bool {
    int dx1 = get_x(p1) - get_x(p0), dy1 = get_y(p1) - get_y(p0);
    int dx2 = get_x(p2) - get_x(p0), dy2 = get_y(p2) - get_y(p0);

    int cross = dx1 * dy2 - dy1 * dx2;
    if (cross == 0)
      return (dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2);

    return cross > 0;
  };

  sorted_points = P;
  sort(sorted_points.begin(), sorted_points.end(), order);

  int m = sorted_points.size();
  print_points(sorted_points, m);

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
  print_points(hull_pts, hull_pts.size());
}

void generate_points(vpii &P, int n) {
  srand(time(0));
  for (int k = 0; k < n; k++) {
    int x = rand() % 100 + 1;
    int y = rand() % 100 + 1;
    P.push_back(make_pair(y, x));
  }
}

void print_points(vpii points, int n) {
  cout << "X = [ ";
  for (int i = 0; i < n; i++) {
    cout << get_x(points[i]) << ", ";
  }
  cout << "\b\b ]" << endl;
  cout << "Y = [ ";
  for (int i = 0; i < n; i++) {
    cout << get_y(points[i]) << ", ";
  }
  cout << "\b\b ]" << endl;
}
