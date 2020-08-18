#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> adj;
vector<int> color;
bool ok = true;

void DFS(int u, int c) {
  color[u] = c;
  for (int v : adj[u]) {
    if (color[v] == 0) DFS(v, 3 - c);
    else if (color[v] == c) ok = false;
  }
}

void is_bipartite(int n) {
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      DFS(i, 1);
    }
  }
}

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  color.resize(n);
  for (int i = 0; i < n; i++) color[i] = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  is_bipartite(n);
  if (ok) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}