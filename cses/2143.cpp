#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int ll
#pragma GCC target("popcnt")

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const int MAX = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

bitset<50000> bs[50000]; 
// Kosaraju
//
// O(n + m)

int n;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) scc(u, u);
	}
}
void solve(){
 	int m, qr; cin >> n >> m >> qr;
	vector<int> deg(n);
	vector<ii> edg;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		edg.pb({u, v});
		g[u].pb(v);
		gi[v].pb(u);
	}
	kosaraju();
	vector<vector<int>> g2r(n);
	for (auto [u, v] : edg) {
		if (comp[u] == comp[v]) continue;
		deg[comp[u]]++;
		g2r[comp[v]].pb(comp[u]);
	}
	queue<int> q;
	for (int i = 0; i < n; ++i) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		bs[u][u] = 1;
		for (auto v : g2r[u]) {
			deg[v]--;
			bs[v] |= bs[u];
			if (deg[v] == 0) q.push(v);
		}
	}
	while (qr--) {
		int u, v; cin >> u >> v;
		--u, --v;
		cout << (bs[comp[u]][comp[v]] ? "YES" : "NO") << endl;
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
