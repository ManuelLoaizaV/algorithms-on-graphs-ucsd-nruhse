#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair; // <minimum distance, node>
typedef priority_queue<Pair, vector<Pair>, greater<Pair>> PriorityQueue;

const Long INF = 1e15;

vector<vector<Long>> adj;
vector<vector<Long>> cost;
vector<bool> used;
vector<Long> dist;

void dijkstra(Long source) {
  dist[source] = 0;
  PriorityQueue done;
  done.push({0, source});
  while (not done.empty()) {
    Pair minimum = done.top();
    Long path_weight = minimum.first;
    Long from = minimum.second;
    done.pop();
    if (not used[from]) {
      for (int pos = 0; pos < adj[from].size(); pos++) {
        Long to = adj[from][pos];
        Long weight = cost[from][pos];
        if (path_weight + weight < dist[to]) {
          dist[to] = path_weight + weight;
          done.push({dist[to], to});
        }
      }
      used[from] = true;
    }
  }
}

int main() {
  Long vertices, edges;
  cin >> vertices >> edges;
  adj.resize(vertices);
  cost.resize(vertices);
  used.resize(vertices);
  dist.resize(vertices);
  for (int i = 0; i < vertices; i++) {
    used[i] = false;
    dist[i] = INF;
  }
  while (edges--) {
    Long from, to, weight;
    cin >> from >> to >> weight;
    from--;
    to--;
    adj[from].push_back(to);
    cost[from].push_back(weight);
  }
  Long from, to;
  cin >> from >> to;
  from--;
  to--;
  dijkstra(from);
  Long minimum_distance = ((dist[to] == INF) ? -1 : dist[to]);
  cout << minimum_distance << endl;
  return 0;
}