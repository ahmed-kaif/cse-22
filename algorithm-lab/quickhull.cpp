#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Point;
typedef vector<Point> vpii;

set<Point> hull_points;

int get_side(Point p1, Point p2, Point p) {
  int cross_prod = (p2.first - p1.first) * (p.second - p1.second) -
                   (p2.second - p1.second) * (p.first - p1.first);
  if (cross_prod > 0)
    return 1;
  else if (cross_prod < 0)
    return -1;
  return 0;
}

Point get_min(vpii pts) {
  Point min_x_pt = *min_element(pts.begin(), pts.end());
  return min_x_pt;
}

Point get_max(vpii pts) {
  Point max_x_pt = *max_element(pts.begin(), pts.end());
  return max_x_pt;
}

int dist(Point p1, Point p2, Point p) {
  return abs(((p2.first - p1.first) * (p1.second - p.second)) -
             ((p1.first - p.first) * (p2.second - p1.second)));
}

int raw_dist(Point p1, Point p2, Point p) {
  return (((p2.first - p1.first) * (p1.second - p.second)) -
          ((p1.first - p.first) * (p2.second - p1.second)));
}

void quick_hull(vpii pts, int n, Point p1, Point p2, int side) {

  // find point w max dist
  int max_dist = 0;
  int max_index = -1;
  for (int i = 0; i < n; i++) {
    int temp_dist = dist(p1, p2, pts[i]);
    if (get_side(p1, p2, pts[i]) == side && temp_dist > max_dist) {
      max_index = i;
      max_dist = temp_dist;
    }
  }

  if (max_index == -1) {
    hull_points.insert(p1);
    hull_points.insert(p2);
    return;
  }

  quick_hull(pts, n, pts[max_index], p1, -get_side(pts[max_index], p1, p2));
  quick_hull(pts, n, pts[max_index], p2, -get_side(pts[max_index], p2, p1));
}

int main() {
  int n;
  vpii P; // set of all points
  vector<int> X;
  vector<int> Y;
  cin >> n;
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
    P.push_back(make_pair(X[k], Y[k]));
  }

  // P.push_back(make_pair(110, 45));
  // P.push_back(make_pair(110, 95));

  cout << "[ ";
  for (int i = 0; i < n; i++) {
    cout << P[i].first << ", ";
  }
  cout << "]" << endl;
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    cout << P[i].second << ", ";
  }
  cout << "]" << endl;

  // Point generate logic END

  Point min = get_min(P);
  Point max = get_max(P);

  cout << min.first << ", " << min.second << endl;
  cout << max.first << ", " << max.second << endl;

  quick_hull(P, n, min, max, 1);
  quick_hull(P, n, min, max, -1);

  cout << "[ ";
  for (auto x : hull_points) {
    cout << x.first << ", ";
  }
  cout << "] " << endl;
  cout << "[ ";
  for (auto x : hull_points) {
    cout << x.second << ", ";
  }
  cout << "] " << endl;
}
