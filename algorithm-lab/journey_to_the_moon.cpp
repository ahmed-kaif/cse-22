#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> visited(N, 0);
int bfs(vector<int> adj[],int s){
  int cnt = 0;
  queue<int> Q;
  Q.push(s);
  visited[s] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    cnt++;
    for (int i = 0; i < adj[u].size(); i++) {
      if (visited[adj[u][i]] == 0) {
        int v = adj[u][i];
        visited[v] = 1;
        Q.push(v);
      }
    }
  }
  return cnt;
}

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> adj[n];
  // pair input
  for (int i = 0; i < p; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long ans = 0;
  int total = n;
  for(int i = 0; i< n; i++){
    if(visited[i]) continue;
    int connected = bfs(adj,i);
    total -= connected;
    ans += (total* connected);

  }
  cout << ans << endl;
}
