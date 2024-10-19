#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
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
	int n, m, k; cin >> n >> m >> k;
	map<ii, vector<int>> ops;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v; --u, --v;
		if (u < v) swap(u, v);
		ops[{u, v}].pb(1);
	}
	vector<vector<ii>> seg(4*k+10);
	auto add = [&] (auto&& self, int i, int l, int r, int x, int y, ii edg) {
		if (r < x or y < l) return;
		if (x <= l && r <= y) {
			seg[i].pb(edg);
			return;
		}
		int md = (l + r) / 2;
		self(self, 2*i, l, md, x, y, edg);
		self(self, 2*i+1, md+1, r, x, y, edg);
	};
	for (int i = 2; i <= k+1; ++i) {
		int t, u, v; cin >> t >> u >> v;
		--u, --v;
		if (u < v) swap(u, v);
		ops[{u, v}].pb(i);
	}
	for (auto [edg, pos] : ops) {
		if (sz(pos)&1) pos.pb(k+2);
		for (int i = 1; i < sz(pos); i += 2) {
			add(add, 1, 1, k+2, pos[i-1], pos[i]-1, edg); 
		}
	}
	vector<int> p(n), lvl(n, 1);
	iota(all(p), 0);
	auto findp = [&] (auto&& self, int u) -> int {
		assert(u < n and u >= 0);
		return (p[u] == u ? u : self(self, p[u]));
	};
	stack<ii> merges;
	auto unite = [&] (int u, int v) {
		u = findp(findp, u), v = findp(findp, v);
		if (u == v) return false;
		if (lvl[u] < lvl[v]) swap(u, v);
		merges.push({u, v});	
		lvl[u] += lvl[v];
		p[v] = u;
		return true;
	};
	auto undo = [&] () {
		auto [u, v] = merges.top();
		merges.pop();
		p[v] = v, lvl[u] -= lvl[v];
	};
	vector<int> ans(k+3);
	int cur = n;
	auto dfs = [&] (auto&& self, int i, int l, int r) -> void{
		int bef = sz(merges);
		for (auto [x, y] : seg[i]) {
			if (unite(x, y)) cur--;	
		}
		int tam = sz(merges);
		if (l == r) {
			ans[l] = cur;
			return;
		}
		int md = (l+r)/2;
		self(self, 2*i, l, md);
		while (sz(merges) != tam) undo(), cur++;
		self(self, 2*i+1, md+1, r);
		while (sz(merges) != bef) undo(), cur++;
	};
	dfs(dfs, 1, 1, k+2);
	for (int i = 1; i <= k + 1; ++i) cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
