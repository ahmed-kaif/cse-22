#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef pair<int, int> pii;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pii> adj[n + 1];
    vector<int> distance(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> state;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    int s;
    cin >> s;
    distance[s] = 0;
    state.push({0, s});
    while (!state.empty()) {
      int u = state.top().second;             // vertex num
      int state_distance = state.top().first; // vertex distance
      state.pop();
      if (distance[u] < state_distance)
        continue;
      for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;  // vertex num
        int w = adj[u][i].second; // weight
        if (distance[u] + w < distance[v]) {
          distance[v] = distance[u] + w;
          state.push({distance[v], v});
        }
      }
    }
    for (int i = 1; i < n + 1; i++) {
      if (i == s)
        continue;
      if (distance[i] == INT_MAX)
        cout << "-1 ";
      else
        cout << distance[i] << " ";
    }
    cout << endl;
  }
}
