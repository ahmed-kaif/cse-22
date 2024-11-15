#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef enum { WHITE, GRAY, BLACK } color_t;

typedef struct vertex Vertex;
struct vertex {
  int data;
  color_t color;
  int distance = -1;
  Vertex *pi = nullptr;
  vector<Vertex *> neighbors;
};

vector<Vertex *> adj;

Vertex *create_vertex(int item, color_t color) {
  auto *new_vertex = new Vertex;
  if (new_vertex == nullptr) {
    cout << "Error!!" << endl;
    exit(1);
  }
  new_vertex->data = item;
  new_vertex->color = color;
  return new_vertex;
}

void add_neighbor(Vertex *u, Vertex *v) { u->neighbors.push_back(v); }

void set_color(Vertex *v, const color_t color) { v->color = color; }
void set_distance(Vertex *v, const int distance) { v->distance = distance; }

void bfs(Vertex *s) {
  for (const auto &vertex : adj) {
    set_color(vertex, WHITE);
    set_distance(vertex, INT_MAX);
    vertex->pi = nullptr;
  }

  set_color(s, GRAY);
  set_distance(s, 0);
  queue<Vertex *> q;
  q.push(s);

  while (!q.empty()) {
    Vertex *u = q.front();
    q.pop();
    for (auto &v : u->neighbors) {
      if (v->color == WHITE) {
        set_color(v, GRAY);
        set_distance(v, u->distance + 1);
        v->pi = u;
        q.push(v);
      }
    }
    set_color(u, BLACK);
  }
}

int main() {
  int n;
  cout << "How many vertices? ";
  cin >> n;

  // Create vertices
  for (int i = 0; i < n; i++) {
    cout << "Vertex_" << i + 1 << " data: ";
    int data;
    cin >> data;
    Vertex *v = create_vertex(data, WHITE);
    adj.push_back(v);
  }

  cout << "Enter neighbors in the format 'u v' (1-based indexing). Type '0 0' to finish:\n";
  cin.ignore(); // Ignore newline from previous input

  while (true) {
    string input;
    getline(cin, input);

    int u, v;
    sscanf(input.c_str(), "%d %d", &u, &v);

    if (u == 0 && v == 0) break;

    
    if (u >= 1 && u <= n && v >= 1 && v <= n) {
      add_neighbor(adj[u - 1], adj[v - 1]);
    } else {
      cout << "Invalid vertices. Please enter values between 1 and " << n << endl;
    }
  }

  bfs(adj[0]);  

  for (const auto &vertex : adj) {
    cout << "Vertex: " << vertex->data << ", Distance: " << vertex->distance
         << ", Parent: " << (vertex->pi ? to_string(vertex->pi->data) : "None") << endl;
  }

  return 0;
}
