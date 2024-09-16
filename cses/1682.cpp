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
	vector<vector<int>> g(n), gr(n);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		gr[v].pb(u);
	}
	vector<int> vis(n);
	for (int i = 0; i < 2; ++i) {
		queue<int> q;
		q.push(0), vis[0] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v : g[u]) {
				if (!vis[v]) vis[v] = 1, q.push(v);
			}
		}
		for (int j = 0; j < n; ++j) {
			if (!vis[j]) {
				cout << "NO" << endl;
				if (!i) cout << 1 << ' ' << j+1 << endl;
				else cout << j+1 << ' ' << 1 << endl;
				exit(0);
			}
		}
		swap(g, gr);
		vis = vector<int>(n, 0);
	}
	cout << "YES" << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
