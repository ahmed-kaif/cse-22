G = (V,E)

1 -> 2 
1 -> 3
adj list 
    1 -> 2 -> 3
    2 -> 3 
    3 -> 1 

```cpp 
std::vector<std::pair<int,int>> adj[v]

```

```
4 5 
0 3 4 
0 1 2 
2 0 5 
1 0 4 
1 3 3 
```
```cpp
adj[u].push_back({v,w})
```

# Dijkstra

```cpp
vector<int> distance(v)
vector<int> pi(v)
priority_queue<pair<int,int>, vector<pair<int,int>, greater<pair<int,int>> // dist, vertex number
u = pq.top()
pq.pop()
// Relax modification
pq.push({v.d after relax,v})
```

