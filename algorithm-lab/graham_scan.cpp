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

int get_y(Point p) { return p.first; }
int get_x(Point p) { return p.second; }
void generate_points(vpii &P, int n);
void print_points(vpii points, int n);

Point get_min(vpii P) { return *min_element(P.begin(), P.end()); }
Point get_max(vpii P) { return *max_element(P.begin(), P.end()); }

vector<Point> filterCollinearPoints(const vector<Point> &points, Point ref) {
  vector<Point> filtered;

  for (const auto &p : points) {
    bool isCollinear = false;

    // Check for collinearity with existing points in the filtered vector
    for (const auto &existing : filtered) {
      int dx1 = p.first - ref.first, dy1 = p.second - ref.second;
      int dx2 = existing.first - ref.first, dy2 = existing.second - ref.second;
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
  vpii P(n + 2); // points are stored as (y,x)
  generate_points(P, n);
  P[n] = make_pair(0, 110);
  P[n + 1] = make_pair(0, 108);
  print_points(P, n + 2);
  // NOTE: p0 is min y, and leftmost in case of tie
  Point p0 = get_min(P);
  // cout << get_x(p0) << " " << get_y(p0) << endl;
  // NOTE: sort by polar angle
  auto order = [&](Point p1, Point p2) -> bool {
    int dx1 = p1.first - p0.first, dy1 = p1.second - p0.second;
    int dx2 = p2.first - p0.first, dy2 = p2.second - p0.second;

    int cross = dx1 * dy2 - dy1 * dx2;

    if (cross == 0)
      return (dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2);

    return cross > 0;
  };
  sort(P.begin(), P.end(), order);
  print_points(P, n + 2);
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
    P[k] = make_pair(Y[k], X[k]);
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
