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
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n), gi(n);
	vector<int> deg(n);
	set<ii> edg;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		if (edg.find({u, v}) != end(edg)) continue;
		edg.insert({u, v});
		--u, --v;
		g[u].pb(v);
		gi[v].pb(u);
	}		
	queue<int> q;
	vector<int> foi(n);
	q.push(n-1), foi[n-1] = 1;
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		for (auto v : gi[u]) if (!foi[v]) q.push(v), foi[v] = 1;
	}
	for (int i = 0; i < n; ++i) for (auto v : g[i]) deg[i] += foi[v];
	vector<int> dp(n), go(n);
	q.push(n-1);
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto v : gi[u]) {
			if (!foi[v]) continue;
			--deg[v];
			if (ckmax(dp[v], dp[u] + 1)) go[v] = u;
			if (deg[v] == 0) q.push(v);
		}
	}
	if (!foi[0]) cout << "IMPOSSIBLE" << endl;
	else {
		vector<int> ans = {0};
		while (ans.back() != n-1) ans.pb(go[ans.back()]);
		cout << sz(ans) << endl;
		for (auto x : ans) cout << x + 1 << ' ';
		cout << endl;
	}
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
