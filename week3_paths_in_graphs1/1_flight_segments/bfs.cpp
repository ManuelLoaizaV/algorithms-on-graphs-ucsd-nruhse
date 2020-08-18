#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int INF = 1e9;
vector<vector<int>> adj;
vector<bool> used;
vector<int> dist;

void BFS(int root) {
  used[root] = true;
  dist[root] = 0;
  deque<int> q;
  q.push_back(root);
  while (not q.empty()) {
    int u = q.front();
    q.pop_front();
    for (int v : adj[u]) {
      if (not used[v]) {
        used[v] = true;
        dist[v] = dist[u] + 1;
        q.push_back(v);
      }
    }
  }
}

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  used.resize(n);
  dist.resize(n);
  for (int i = 0; i < n; i++) {
    used[i] = false;
    dist[i] = INF;
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int u, v;
  cin >> u >> v;
  u--;
  v--;
  BFS(u);
  if (dist[v] == INF) cout << -1 << endl;
  else cout << dist[v] << endl;
  return 0;
}