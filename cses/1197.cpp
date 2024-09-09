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

const int inf = 2e18;
const int mod = 1e9+7;
const int MAX = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

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
	vector<iii> edg(m);
	for (auto& [x, y, z] : edg) {
		cin >> x >> y >> z, --x, --y;
		g[x].pb(y);
		gi[y].pb(x);
	}
	kosaraju();
	vector<int> dist(n, 1e18), go(n, -1);
	int id = -1;
	bool ruim = 1;
	iii lst;
	vector<iii> nedg;
	for (auto [x, y, z] : edg) if (comp[x] == comp[y]) nedg.pb({x, y, z});
	swap(edg, nedg);
	vector<int> foi(n);
	for (int i = 0; i < n; ++i) if (foi[comp[i]] == 0) foi[comp[i]] = 1, dist[i] = 0;
	for (int i = 0; i <= n; ++i) {
		bool ok = 0;
		for (auto [u, v, w] : edg) {
			if (ckmin(dist[v], dist[u] + w)) ok = 1, go[v] = u, id = v;
		}
		ruim &= ok;
	}
	if (!ruim) {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i < n; ++i) vis[i] = 0;
	while (vis[id] == 0) vis[id] = 1, id = go[id];
	vector<int> ans;
	while (vis[id] == 1) ans.pb(id), vis[id] = 2, id = go[id];
	reverse(all(ans));
	ans.pb(ans[0]);
	cout << "YES" << endl;
	for (auto x : ans) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
