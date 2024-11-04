#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[100];
int visited[100];

/// s = source index
/// n = number of vertices
void bfs(int s, int n) {
  // make all vertex non-visited
  for (int i = 0; i < n; i++)
    visited[i] = 0;
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
        Q.push(v);
      }
    }
  }
}

int main() {}
