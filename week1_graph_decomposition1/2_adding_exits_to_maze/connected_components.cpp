#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int u) {
  visited[u] = true;
  for (int v : adj[u]) if (not visited[v]) DFS(v);
}

int count_connected_components(int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (not visited[i]) {
      DFS(i);
      cnt++;
    }
  }
  return cnt;
}

int main() {
  fastio;
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
  cout << count_connected_components(n) << endl;
  return 0;
}