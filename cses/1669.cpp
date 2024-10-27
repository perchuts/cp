#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1e5 + 10;
 
vector<int> g[maxn];
 
int vis[maxn];
 
 
pair<int,int> dfs(int u) {
      for (auto v : g[u]) {
            if (vis[v] == 0) {
                  vis[v] = u;
                  pair<int, int> x = dfs(v);
                  if (x.first != 0) return x;
            } else {
                  if (vis[u] == v) continue;
                  else {
                        return {u, v};
                  }
            }
      }
      return {0, 0};
}
 
int main() {
      int n, m; 
      cin >> n >> m;
      for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
      }
      for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                  vis[i] = i;
                  pair<int, int> x = dfs(i);
                  if (x.first != 0) {
                        vector<int> resp;
                        int atual = x.first;
                        while (atual != x.second) {
                              resp.push_back(atual);
                              atual = vis[atual];
                        }
                        resp.push_back(x.second), resp.push_back(x.first);
                        cout << resp.size() << endl;
                        for (auto x : resp) cout << x << ' ';
                        return 0;
                  }
            }
      }
      cout << "IMPOSSIBLE" << endl;
}
