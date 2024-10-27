#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 10;
 
vector<int> g[maxn];
 
bool vis[maxn];
 
int dist[maxn], pai[maxn], n, m;
 
void bfs(int origem) {
      queue<int> q;
      for (int i = 1; i <= n; i++) dist[i] = -1;
      q.push(origem);
      dist[origem] = 1, vis[origem] = 1, pai[origem] = origem;
      while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : g[v]) {
                  if (vis[u] == 0) {
                        dist[u] = dist[v] + 1, vis[u] = 1, pai[u] = v;
                        q.push(u);
                  }
            }
      } 
}
 
int main() {
      cin >> n >> m;
      for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
      }
      bfs(1);
      if (vis[n]) {
            cout << dist[n] << endl;
            vector<int> caminho;
            int atual = n;
            while (atual != 1) caminho.push_back(atual), atual = pai[atual];
            caminho.push_back(1);
            reverse(caminho.begin(), caminho.end());
            for (auto x : caminho) cout << x << ' ';
      } else cout << "IMPOSSIBLE" << endl;
}
