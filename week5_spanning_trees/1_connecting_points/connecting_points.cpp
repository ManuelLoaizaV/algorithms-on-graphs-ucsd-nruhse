#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define x first
#define y second
using namespace std;

typedef long double Double;
typedef pair<int, int> Pair;

struct Edge {
  int u;
  int v;
  int square;
  bool operator < (const Edge& other) const {
    return square < other.square;
  }
};

struct DisjointSet {
  vector<int> parent;
  vector<int> rank;
  int size;

  DisjointSet(int n) {
    size = n;
    parent.resize(n);
    rank.resize(n);
  }

  void make_set(int u) {
    parent[u] = u;
    rank[u] = 0;
  }

  int find_set(int u) {
    if (u != parent[u]) parent[u] = find_set(parent[u]);
    return parent[u];
  }

  bool same_set(int u, int v) {
    return find_set(u) == find_set(v);
  }

  void union_set(int u, int v) {
    int u_id = find_set(u);
    int v_id = find_set(v);
    if (u_id == v_id) return;
    if (rank[u_id] > rank[v_id]) {
      parent[v_id] = u_id;
    } else {
      parent[u_id] = v_id;
      if (rank[u_id] == rank[v_id]) rank[v_id]++;
    }
  }
};

vector<Pair> points;
vector<Edge> edges;
vector<Edge> mst;

int get_square(Pair a, Pair b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy; 
}

void kruskal() {
  sort(edges.begin(), edges.end());
  int number_points = points.size();
  int number_edges = edges.size();
  DisjointSet tree(number_points);
  for (int pos = 0; pos < number_points; pos++) tree.make_set(pos);
  for (int pos = 0; pos < number_edges; pos++) {
    int u = edges[pos].u;
    int v = edges[pos].v;
    if (not tree.same_set(u, v)) {
      tree.union_set(u, v);
      mst.push_back(edges[pos]);
    }
  }
}

int main() {
  fastio;
  int number_points;
  cin >> number_points;
  for (int pos = 0; pos < number_points; pos++) {
    Pair current;
    cin >> current.x >> current.y;
    points.push_back(current);
  }
  for (int i = 0; i < number_points - 1; i++) {
    for (int j = i + 1; j < number_points; j++) {
      Edge current;
      current.u = i;
      current.v = j;
      current.square = get_square(points[i], points[j]);
      edges.push_back(current);
    }
  }
  kruskal();
  Double minimum_length = 0.0;
  for (int pos = 0; pos < number_points - 1; pos++) {
    Double current_length = sqrt((Double) mst[pos].square);
    minimum_length += current_length;
  }
  cout << fixed << setprecision(7) << minimum_length << endl;
  return 0;
}