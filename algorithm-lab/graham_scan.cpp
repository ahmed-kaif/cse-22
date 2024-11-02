#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include <vector>
using std::vector;

using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> vpii;
stack<Point> S;
vpii P; // points are stored as (y,x)
vpii sorted_points;
vpii hull_pts;

int get_y(Point p) { return p.first; }
int get_x(Point p) { return p.second; }

bool non_left_turn(Point p1, Point p2, Point p) {
  int cross_prod = (get_x(p2) - get_x(p1)) * (get_y(p) - get_y(p1)) -
                   (get_y(p2) - get_y(p1)) * (get_x(p) - get_x(p1));
  if (cross_prod > 0)
    // clockwise
    return true;
  else if (cross_prod < 0)
    // ccw
    return false;
  return 0;
}

Point next_to_top(stack<Point> &s) {
  Point top = s.top();
  s.pop();
  Point next_top = s.top();
  s.push(top);
  return next_top;
}

void generate_points(vpii &P, int n);
void print_points(vpii points, int n);

Point get_min(vpii P) { return *min_element(P.begin(), P.end()); }
Point get_max(vpii P) { return *max_element(P.begin(), P.end()); }

vector<Point> filterCollinearPoints(const vector<Point> &points, Point ref) {
  vector<Point> filtered;
  filtered.push_back(ref);
  for (const auto &p : points) {
    bool isCollinear = false;

    // Check for collinearity with existing points in the filtered vector
    for (auto &existing : filtered) {
      int dx1 = get_x(p) - get_x(ref), dy1 = get_y(p) - get_y(ref);
      int dx2 = get_x(existing) - get_x(ref),
          dy2 = get_y(existing) - get_y(ref);
      int cross = dx1 * dy2 - dy1 * dx2;

      if (cross == 0) { // Points are collinear
        isCollinear = true;

        // Compare distances to keep the farthest point
        int dist1 = dx1 * dx1 + dy1 * dy1;
        int dist2 = dx2 * dx2 + dy2 * dy2;

        if (dist1 > dist2) {
          // Replace existing point with the new farthest point
          existing = p;
        }
        break; // No need to check other points
      }
    }

    // If not collinear, add the point to the filtered list
    if (!isCollinear) {
      filtered.push_back(p);
    }
  }

  return filtered;
}

int main() {
  int n;
  cout << "How many points? ";
  cin >> n;
  generate_points(P, n);
  // P.push_back(make_pair(0, 110));
  // P.push_back(make_pair(0, 108));
  // print_points(P, P.size());
  // NOTE: p0 is min y, and leftmost in case of tie
  Point p0 = get_min(P);
  cout << get_x(p0) << " " << get_y(p0) << endl;
  // NOTE: sort by polar angle
  auto order = [&](Point p1, Point p2) -> bool {
    int dx1 = get_x(p1) - get_x(p0), dy1 = get_y(p1) - get_y(p0);
    int dx2 = get_x(p2) - get_x(p0), dy2 = get_y(p2) - get_y(p0);

    int cross = dx1 * dy2 - dy1 * dx2;
    // take the farthest point last
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
  for (int i = i; i < m; i++) {
    Point p_i = sorted_points[i];
    // angle formed by next_to_top, top and pi makes a nonleft turn
    while (S.size() > 1 && non_left_turn(next_to_top(S), S.top(), p_i)) {
      S.pop();
    }
    S.push(p_i);
  }
  // print points in stack
  while (!S.empty()) {
    Point p = S.top();
    hull_pts.push_back(p);
    S.pop();
  }
  print_points(hull_pts, hull_pts.size());
}

void generate_points(vpii &P, int n) {
  vector<int> X;
  vector<int> Y;
  srand(time(0));
  for (int k = 0; k < n; k++) {
    int x = rand() % 100 + 1;
    X.push_back(x);
    // int x = rand();
  }

  for (int k = 0; k < n; k++) {
    int y = rand() % 100 + 1;
    Y.push_back(y);
  }

  for (int k = 0; k < n; k++) {
    P.push_back(make_pair(Y[k], X[k]));
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
