#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> state;
bool ok = true;

void DFS(int u) {
  state[u] = 1;
  for (int v : adj[u]) {
    if (state[v] == 0) DFS(v);
    else if (state[v] == 1) ok = false;
  }
  state[u] = 2;
}

void acyclic(int n) {
  for (int i = 0; i < n; i++) {
    if (state[i] == 0) DFS(i);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  state.resize(n);
  for (int i = 0; i < n; i++) state[i] = 0;
  while (m--) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    adj[from].push_back(to);
  }
  acyclic(n);
  if (ok) cout << 0 << endl;
  else cout << 1 << endl;
}
