#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <utility>
#include <vector>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef pair<ll, ll> Point;
typedef vector<Point> vpii;

vpii hull_points;

bool order(Point p1, Point p2) {
  Point ref = hull_points[0];
  ll dx1 = p1.first - ref.first, dy1 = p1.second - ref.second;
  ll dx2 = p2.first - ref.first, dy2 = p2.second - ref.second;

  ll cross = dx1 * dy2 - dy1 * dx2;

  if (cross == 0)
    return (dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2);

  return cross > 0;
}

ll get_side(Point p1, Point p2, Point p) {
  ll cross_prod = (p2.first - p1.first) * (p.second - p1.second) -
                  (p2.second - p1.second) * (p.first - p1.first);
  if (cross_prod > 0)
    return 1;
  else if (cross_prod < 0)
    return -1;
  return 0;
}

Point get_min(const vpii pts) { return *min_element(pts.begin(), pts.end()); }
Point get_max(const vpii pts) { return *max_element(pts.begin(), pts.end()); }

ll dist(Point p1, Point p2, Point p) {
  return abs(((p2.first - p1.first) * (p1.second - p.second)) -
             ((p1.first - p.first) * (p2.second - p1.second)));
}

void quick_hull(const vpii pts, ll n, Point p1, Point p2, ll side) {
  // find point with max dist
  ll max_dist = 0;
  ll max_index = -1;
  for (ll i = 0; i < n; i++) {
    ll temp_dist = dist(p1, p2, pts[i]);
    if (get_side(p1, p2, pts[i]) == side && temp_dist > max_dist) {
      max_index = i;
      max_dist = temp_dist;
    }
  }
  // push 2 extreme points
  if (max_index == -1) {
    hull_points.push_back(p1);
    hull_points.push_back(p2);
    return;
  }

  quick_hull(pts, n, pts[max_index], p1, -get_side(pts[max_index], p1, p2));
  quick_hull(pts, n, pts[max_index], p2, -get_side(pts[max_index], p2, p1));
}

void read_points_from_file(const string file_name, vpii &points);
void print_points(vpii points, ll n);

int main() {
  vpii P;
  read_points_from_file("points.txt", P);
  ll n = P.size();
  // print_points(P, n);

  auto st = high_resolution_clock::now(); // clock start

  Point min = get_min(P);
  Point max = get_max(P);

  quick_hull(P, n, min, max, 1);
  quick_hull(P, n, min, max, -1);

  auto et = high_resolution_clock::now(); // clock end
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(et - st).count();
  time_taken *= 1e-6;

  sort(hull_points.begin(), hull_points.end(), order);
  hull_points.erase(unique(hull_points.begin(), hull_points.end()),
                    hull_points.end());

  // cout << "Convex hull points using Quick Hull:" << endl;
  // print_points(hull_points, hull_points.size());
  cout << "Time taken for Quick hull: " << time_taken << " ms" << endl;
  cout << "No. of Points: " << n << endl;
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
    ll x, y;
    ss >> x >> y;
    points.push_back(make_pair(x, y));
  }
  inputFile.close();
}

void print_points(const vpii points, ll n) {
  cout << "X = [ ";
  for (ll i = 0; i < n; i++) {
    cout << points[i].first << ", ";
  }
  cout << points[0].first << " ]" << endl;
  cout << "Y = [ ";
  for (ll i = 0; i < n; i++) {
    cout << points[i].second << ", ";
  }
  cout << points[0].second << " ]" << endl;
}
