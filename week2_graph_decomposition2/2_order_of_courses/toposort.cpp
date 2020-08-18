#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void DFS(int u) {
  visited[u] = true;
  for (int v : adj[u]) if (not visited[v]) DFS(v);
  order.push_back(u);
}

void topological_sort(int n) {
  for (int i = 0; i < n; i++) if (not visited[i]) DFS(i);
  reverse(order.begin(), order.end());
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
  }
  topological_sort(n);
  for (int i = 0; i  < n; i++) {
    if (i > 0) cout << " ";
    cout << order[i] + 1;
  }
  cout << endl;
  return 0;
}