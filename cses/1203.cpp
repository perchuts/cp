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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<ii>> g(n), gr(n);
	for (int i = 0; i < m; ++i) {
		int u, v, c; cin >> u >> v >> c;
		--u, --v;
		g[u].pb({v, c});
		gr[v].pb({u, c});
	}
	vector<int> dist1(n, 1e18), dist2(n, 1e18);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, 0});
	dist1[0] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dist1[u] != d) continue;
		for (auto [v, d2] : g[u]) {
			if (ckmin(dist1[v], d2 + d)) {
				pq.push({dist1[v], v});
			}
		}
	}
	dist2[n-1] = 0;
	pq.push({0, n-1});
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dist2[u] != d) continue;
		for (auto [v, d2] : gr[u]) {
			if (ckmin(dist2[v], d2 + d)) {
				pq.push({dist2[v], v});
			}
		}
	}
	vector<vector<int>> g2(n);

	for (int i = 0; i < n; ++i) {
		for (auto [v, w] : g[i]) {
			if (dist1[i] + w + dist2[v] == dist1[n-1]) g2[i].pb(v), g2[v].pb(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		sort(all(g2[i]));
		g2[i].erase(unique(all(g2[i])), end(g2[i]));
	}

	vector<int> ans = {n-1, 0}, low(n), tin(n, -1);

	int t = 0;

	auto dfs = [&] (auto&& self, int u, int p) -> void {
		tin[u] = low[u] = ++t;
		bool ok = 0;
		for (auto v : g2[u]) {
			if (v == p) continue;
			if (tin[v] == -1) {
				self(self, v, u);
				ckmin(low[u], low[v]);
				if (low[v] >= tin[u]) ok = 1;
			} else ckmin(low[u], tin[v]);
		}	
		if (ok) ans.pb(u);
	};

	dfs(dfs, 0, -1);

	sort(all(ans));

	ans.erase(unique(all(ans)), end(ans));

	cout << sz(ans) << endl;

	for (auto x : ans) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
