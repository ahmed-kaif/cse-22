#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m; // node , edge
    vector<int> adj[n + 1];
    int visited[n + 1];
    int distance[n + 1];
    for (int i = 1; i < n + 1; i++) {
      distance[i] = -1;
      visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      // edge input
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int s; // source node
    cin >> s;
    // bfs
    queue<int> Q;
    Q.push(s);      // start from source vertex
    visited[s] = 1; // make the source vertex visited
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (int i = 0; i < adj[u].size(); i++) {
        if (visited[adj[u][i]] == 0) {
          int v = adj[u][i];
          visited[v] = 1;
          distance[v] = (distance[u] + 1) * 6;
          Q.push(v);
        }
      }
    }
    for (int i = 1; i < n + 1; i++) {
      if (i == s)
        continue;
      cout << distance[i] << " ";
    }
    cout << endl;
  }
}
