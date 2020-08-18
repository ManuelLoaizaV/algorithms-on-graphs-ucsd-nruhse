#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order;

void DFS1(int u) {
  used[u] = true;
  for (int v : g[u]) if (not used[v]) DFS1(v);
  order.push_back(u);
}

void DFS2(int u) {
  used[u] = true;
  for (int v : gt[u]) if (not used[v]) DFS2(v);
}

void toposort(int n) {
  for (int i = 0; i < n; i++) {
    if (not used[i]) DFS1(i);
  }
}

int count_components(int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int current = order[n - 1 - i];
    if (not used[current]) {
      cnt++;
      DFS2(current);
    }
  }
  return cnt;
}

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  g.resize(n);
  gt.resize(n);
  used.resize(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    gt[v].push_back(u);
  }
  for (int i = 0; i < n; i++) used[i] = false;
  toposort(n);
  for (int i = 0; i < n; i++) used[i] = false;
  cout << count_components(n) << endl;
  return 0;
}