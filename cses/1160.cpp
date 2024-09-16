#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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
 	int n, qry; cin >> n >> qry;
	vector<vector<int>> g(n), p(30, vector<int>(n));
	vector<int> t(n), deg(n), vis(n), dep(n), tam(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i]; --t[i];
		deg[t[i]]++;
		g[t[i]].pb(i);
	}
	for (int i = 0; i < 30; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0) p[i][j] = t[j];
			else p[i][j] = p[i-1][p[i-1][j]];
		}
	}
	queue<int> q;
	for (int i = 0; i < n; ++i) if (deg[i] == 0) vis[i] = 1, q.push(i);
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		deg[t[u]]--;
		if (deg[t[u]] == 0) q.push(t[u]), vis[t[u]] = 1;
	}
	vector<ii> comp(n, make_pair(-1, -1));
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		int cur = i, j = 0;
		do {
			comp[cur] = {i, j++}, vis[cur] = 1;
			cur = t[cur];
		} while (cur != i);
		tam[i] = j;
	}
	auto dfs = [&] (auto&& self, int u) -> void {
		for (auto v : g[u]) {
			if (comp[v].first != -1) continue;
			dep[v] = dep[u] + 1;
			self(self, v);
		}
	};
	for (int i = 0; i < n; ++i) {
		if (comp[i].first == -1) continue;
		dfs(dfs, i);
	}
	auto inside = [&] (int x, int y) {
		if (comp[x].second <= comp[y].second) return comp[y].second - comp[x].second;
		return tam[comp[x].first] - (comp[x].second - comp[y].second);
	};
	while (qry--) {
		int x, y; cin >> x >> y;
		--x, --y;
		if (x == y) {
			cout << 0 << endl;
			continue;
		}
		if (dep[x] < dep[y]) cout << -1 << endl;
		else {
			int k = dep[x] - dep[y], cur = x;
			for (int i = 29; i >= 0; --i) {
				if ((k>>i)&1) cur = p[i][cur];
			}
			if (cur == y) cout << k << endl;
			else if (comp[cur].first == comp[y].first && comp[cur].first != -1) {
				cout << k + inside(cur, y) << endl;
			} else cout << -1 << endl;
		}
	}
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
