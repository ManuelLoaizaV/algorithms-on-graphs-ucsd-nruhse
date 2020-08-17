#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int u) {
  visited[u] = true;
  for (int v : adj[u]) if (not visited[v]) DFS(v);
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  visited.resize(n);
  for (int i = 0; i < n; i++) visited[i] = false;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int from, to;
  cin >> from >> to;
  from--;
  to--;
  DFS(from);
  if (visited[to]) cout << 1 << endl;
  else cout << 0 << endl;
}