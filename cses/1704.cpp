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
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].pb(v), g[v].pb(u);
	}
	int root = 0;
	for (int i = 0; i < n; ++i) if (sz(g[i]) > 1) root = i;
	vector<int> height(n), direction(n, -1);
	auto dfs = [&] (auto&& self, int u, int p) -> void {
		for (auto v : g[u]) {
			if (v == p) continue;
			self(self, v, u);
			if (ckmax(height[u], height[v] + 1)) direction[u] = v;
		}
	};
	dfs(dfs, root, root);
	set<ii> s;
	for (auto v : g[root]) s.insert({height[v], v});	
	vector<ii> ans;
	auto upd = [&] (auto&& self, int u) -> int {
		for (auto v : g[u]) {
			if (height[v] > height[u] or direction[u] == v) continue;
			s.insert({height[v], v});
		}
		if (height[u]) return self(self, direction[u]);
		return u;
	};
	while (sz(s)) {
		if (sz(s) > 1) {
			auto u = *prev(end(s));
			s.erase(prev(end(s)));
			auto v = *prev(end(s));
			s.erase(prev(end(s)));
			int x = upd(upd, v.second), y = upd(upd, u.second);
			ans.pb({x, y});
		} else {
			auto u = *begin(s);
			s.erase(begin(s));
			ans.pb({upd(upd, u.second), root});
		}
	}
	cout << sz(ans) << endl;
	for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
