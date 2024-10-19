#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int ll

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
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
	int m; cin >> n >> m; 
	vector<ii> edg(m);
	for (auto& [x, y] : edg) {
		cin >> x >> y;
		--x, --y;
		g[x].pb(y);
		gi[y].pb(x);
	}
	kosaraju();
	int ans = 0;
	vector<int> qnt(n);
	for (int i = 0; i < n; ++i) qnt[comp[i]]++;
	vector<vector<int>> g2(n);
	for (auto [x, y] : edg) {
		if (comp[x] != comp[y]) g2[comp[x]].pb(comp[y]), g2[comp[y]].pb(comp[x]);
	}
	for (int i = 0; i < n; ++i) vis[i] = 0;
	bool ok = 1;
	auto dfs = [&] (auto&& self, int u) -> int {
		vis[u] = 1, ok &= (qnt[u]==1);
		int tot = qnt[u];
		for (auto v : g2[u]) {
			if (vis[v]) continue;
			else tot += self(self, v);
		}	
		return tot;
	};
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ok = 1;
			int k = dfs(dfs, i);
			if (ok) ans += k-1;
			else ans += k;
		}
	}
	// |comp| + (tot-#def1) - 1
	// 
	cout << ans << endl;


}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
