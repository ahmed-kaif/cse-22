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

vpii points;  // Points are stored as (y, x)
vpii hull_pts; 
Point p0;     // Reference point

ll get_y(const Point &p) { return p.first; }
ll get_x(const Point &p) { return p.second; }

ll cross_product(const Point &p1, const Point &p2, const Point &p3) {
  return (get_x(p2) - get_x(p1)) * (get_y(p3) - get_y(p1)) -
         (get_y(p2) - get_y(p1)) * (get_x(p3) - get_x(p1));
}

bool polar_order(const Point &p1, const Point &p2) {
  ll cross = cross_product(p0, p1, p2);
  if (cross == 0) {
    return (get_x(p1) - get_x(p0)) * (get_x(p1) - get_x(p0)) +
           (get_y(p1) - get_y(p0)) * (get_y(p1) - get_y(p0)) <
           (get_x(p2) - get_x(p0)) * (get_x(p2) - get_x(p0)) +
           (get_y(p2) - get_y(p0)) * (get_y(p2) - get_y(p0));
  }
  return cross > 0;
}

void read_points_from_file(const string &file_name, vpii &points);
void print_points(const vpii &points);

int main() {
  read_points_from_file("points.txt", points);

  p0 = *min_element(points.begin(), points.end(),
                    [](const Point &p1, const Point &p2) {
                      return p1 < p2; 
                    });

  auto start_time = high_resolution_clock::now(); // clock start
  sort(points.begin(), points.end(), polar_order);

  vpii filtered_points = {p0};
  for (size_t i = 1; i < points.size(); i++) {
    while (i < points.size() - 1 &&
           cross_product(p0, points[i], points[i + 1]) == 0) {
      i++;
    }
    filtered_points.push_back(points[i]);
  }

  vector<Point> hull;
  hull.push_back(filtered_points[0]);
  hull.push_back(filtered_points[1]);
  hull.push_back(filtered_points[2]);

  for (ll i = 3; i < filtered_points.size(); i++) {
    while (hull.size() > 1 &&
           cross_product(hull[hull.size() - 2], hull.back(), filtered_points[i]) <= 0) {
      hull.pop_back();
    }
    hull.push_back(filtered_points[i]);
  }

  auto end_time = high_resolution_clock::now();

  hull_pts = hull; 

  double time_taken = duration_cast<nanoseconds>(end_time - start_time).count() * 1e-6;
  cout << "Time taken for Graham Scan: " << time_taken << " ms" << endl;

  // cout << "Convex hull points:" << endl;
  // print_points(hull_pts);
  return 0;
}

void read_points_from_file(const string &file_name, vpii &points) {
  ifstream inputFile(file_name);
  if (!inputFile.is_open()) {
    cerr << "Error opening the file!" << endl;
    exit(1);
  }
  ll x, y;
  while (inputFile >> x >> y) {
    points.emplace_back(y, x);
  }
  inputFile.close();
}

void print_points(const vpii &points, ll n) {
  cout << "X = [ ";
  for (ll i = 0; i < n; i++) {
    cout << get_x(points[i]) << ", ";
  }
    cout << get_x(points[0]) << ", ";
  cout << "Y = [ ";
  for (ll i = 0; i < n; i++) {
    cout << get_y(points[i]) << ", ";
  }
    cout << get_y(points[0]) << ", ";
}
