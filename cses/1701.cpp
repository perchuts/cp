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
	vector<vector<int>> g1(n), g2(n);
	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g1[u].pb(v), g1[v].pb(u);
	}
	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g2[u].pb(v), g2[v].pb(u);
	}
	vector<int> f1(n), f2(n);
	for (int i = 0; i < n; ++i) {
		f1[sz(g1[i])]++;
		f2[sz(g2[i])]++;
	}
	if (f1 != f2) {
		cout << "NO" << endl;
		return;
	}
	int mn = n * 69, id = 0;
	for (int i = 1; i < n; ++i) {
		if (f1[i] != 0 and ckmin(mn, f1[i])) id = i;
	}
	int root = 0;
	for (int i = 0; i < n; ++i) if (sz(g1[i]) == id) root = i;
	// check if there is a pairing between two trees
	map<multiset<int>, int> subtree;
	int tool = 0;
	auto dfs = [&] (auto&& self, int u, int p, vector<vector<int>>& g) -> int {
		multiset<int> my;
		for (auto v : g[u]) {
			if (v == p) continue;
			int k = self(self, v, u, g);
			my.insert(k);	
		}
		if (subtree.count(my)) return subtree[my];
		return subtree[my] = tool++;
	};
	int a = dfs(dfs, root, root, g1);
	for (int i = 0; i < n; ++i) {
		if (sz(g2[i]) == id) {
			int b = dfs(dfs, i, i, g2);
			if (a == b) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int32_t main(){_
  int t = 1; cin >> t;
  while(t--) solve();
}
