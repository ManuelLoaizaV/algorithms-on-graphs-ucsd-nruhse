#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int INF = 1e8;

struct Edge {
  int from;
  int to;
  int weight;
};

vector<vector<int>> adj;
vector<vector<int>> cost;
vector<int> dist;
vector<Edge> edges;

bool bellman_ford() {
  bool ok = true;
  for (int iteration = 0; iteration < adj.size(); iteration++) {
    ok = true;
    for (Edge edge : edges) {
      int from = edge.from;
      int to = edge.to;
      int weight = edge.weight;
      if (dist[from] + weight < dist[to]) {
        dist[to] = dist[from] + weight;
        ok = false;
      }
    }
  }
  return ok;
}

int main() {
  fastio;
  int number_vertices, number_edges;
  cin >> number_vertices >> number_edges;
  adj.resize(number_vertices);
  cost.resize(number_vertices);
  dist.resize(number_vertices);
  for (int i = 0; i < number_vertices; i++) dist[i] = INF;
  while (number_edges--) {
    Edge current;
    cin >> current.from >> current.to >> current.weight;
    current.from--;
    current.to--;
    edges.push_back(current);
  }
  if (bellman_ford()) cout << 0 << endl;
  else cout << 1 << endl;
  return 0;
}