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
	int n; cin >> n;
	vector<int> p(n), onde(n), vis(n), P;
	for (auto& x : p) cin >> x, --x;
	P = p;
	vector<vector<ii>> rounds;
	while (true) {
		bool ok = 1;
		for (int i = 0; i < n; ++i) vis[i] = 0, onde[p[i]] = i, ok &= (p[i] == i);
		if (ok) break;
		vector<vector<int>> cycles;
		for (int i = 0; i < n; ++i) {
			if (vis[i]) continue;
			int cur = i;
			vector<int> cycle;
			while (vis[cur] == 0) vis[cur] = 1, cycle.pb(cur), cur = onde[cur];
			cycles.pb(cycle);
		}
		vector<ii> round;
		for (auto x : cycles) {
			for (int i = 1; i < sz(x); i += 2) round.pb({x[i-1]+1, x[i]+1}), swap(p[x[i]], p[x[i-1]]);	
		}
		rounds.pb(round);
	}
	if (sz(rounds) <= 1) {
		cout << sz(rounds) << endl;
		for (auto x : rounds) {
			cout << sz(x) << endl;
			for (auto [a, b] : x) cout << a << ' ' << b << endl;
		}
		return;
	}

	p = P;

	for (int i = 0; i < n; ++i) vis[i] = 0, onde[p[i]] = i;

	vector<vector<int>> cycles;

	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		int cur = i;
		vector<int> cycle;
		while (vis[cur] == 0) vis[cur] = 1, cycle.pb(cur), cur = onde[cur];
		cycles.pb(cycle);
	}
	
	vector<ii> r1, r2;

	for (auto cycle : cycles) {
		int steps = (sz(cycle)-1)/2;
		for (int i = 1; i <= steps; ++i) r1.pb({cycle[i], cycle[sz(cycle)-i]});
	}

	for (auto [x, y] : r1) swap(p[x], p[y]);

	cycles.clear();

	for (int i = 0; i < n; ++i) vis[i] = 0, onde[p[i]] = i;

	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		int cur = i;
		vector<int> cycle;
		while (vis[cur] == 0) vis[cur] = 1, cycle.pb(cur), cur = onde[cur];
		if (sz(cycle) == 2) r2.pb({cycle[0], cycle[1]});
	}
	cout << 2 << endl;
	cout << sz(r1) << endl;
	for (auto [x, y] : r1) cout << x + 1 << ' ' << y + 1 << endl;
	cout << sz(r2) << endl;
	for (auto [x, y] : r2) cout << x + 1 << ' ' << y + 1 << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
