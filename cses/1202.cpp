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
	vector<vector<ii>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v, c; cin >> u >> v >> c;
		--u, --v;
		g[u].pb({v, c});
	}
	vector<int> dist(n, 1e18);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, 0}), dist[0] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d != dist[u]) continue;
		for (auto [v, w] : g[u]) {
			if (ckmin(dist[v], d + w)) pq.push({dist[v], v});
		}
	}
	vector<vector<int>> g2(n), g2r(n);
	for (int i = 0; i < n; ++i) {
		for (auto [v, w] : g[i]) {
			if (dist[v] == dist[i] + w) {
				g2[i].pb(v);
				g2r[v].pb(i);
			}
		}
	}
	vector<int> vis(n), deg(n);
	queue<int> q;
	q.push(n-1), vis.back() = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : g2r[u]) {
			deg[v]++;
			if (!vis[v]) vis[v] = 1, q.push(v);
		}
	}
	q.push(n-1);
	vector<int> dp1(n), dp2(n), dp3(n);
	dp3[n-1] = 1;
	// min, max, number
	while (!q.empty()) {
		int u = q.front(); q.pop();
		dp1[u] = inf;
		if (u == n - 1) dp1[u] = 0;
		for (auto v : g2[u]) {
			if (!vis[v]) continue;
			ckmin(dp1[u], dp1[v] + 1);
			ckmax(dp2[u], dp2[v] + 1);
			dp3[u] = (dp3[u] + dp3[v]) % mod;
		}
		for (auto v : g2r[u]) {
			if (!vis[v]) continue;
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	cout << dist[n-1] << ' ' << dp3[0] << ' ' << dp1[0] << ' ' << dp2[0] << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
