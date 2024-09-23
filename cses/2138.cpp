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
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

bitset<50000> bs[50000]; 

void solve(){
 	int n, m; cin >> n >> m;
	vector<vector<int>> g(n), gr(n);
	vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].pb(v), deg[u]++;
		gr[v].pb(u);
	}
	queue<int> q;
	for (int i = 0; i < n; ++i) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		bs[u][u] = 1;
		for (auto v : gr[u]) {
			deg[v]--;
			bs[v] |= bs[u];
			if (deg[v] == 0) q.push(v);
		}
	}
	for (int i = 0; i < n; ++i) cout << bs[i].count() << ' ';
	cout << endl;

}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
