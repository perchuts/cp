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
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }



void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n), gi(n);
	vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		gi[v].pb(u);
		++deg[u];
	}		
	queue<int> q;
	vector<int> foi(n);
	for (int i = 0; i < n; ++i) if (deg[i] == 0) q.push(i); 
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		foi[u] = 1;
		for (auto v : gi[u]) {
			--deg[v];
			if (deg[v] == 0) q.push(v);
		}
	}
	vector<int> vis(n), cur;
	auto dfs = [&] (auto&& self, int u) -> bool {
		cur.pb(u), vis[u] = 1;
		for (auto v : g[u]) {
			if (foi[v]) continue;
			if (vis[v]) {
				cur.pb(v);
				return true;
			} else if (self(self, v)) return true;
		}
		cur.pop_back();
		assert(false);
	};		
	for (int i = 0; i < n; ++i) {
		if (foi[i]) continue;
		dfs(dfs, i);
		vector<int> ans;
		bool mode = 0;
		for (auto x : cur) {
			if (x == cur.back()) mode = 1;
			if (mode) ans.pb(x);
		}
		cout << sz(ans) << endl;
		for (auto x : ans) cout << x + 1 << ' ';
		cout << endl;
		return;
	}
	cout << "IMPOSSIBLE" << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
