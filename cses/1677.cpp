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
	int n, m, k; cin >> n >> m >> k;
	vector<ii> edg(m);
	for (auto& [x, y] : edg) cin >> x >> y, --x, --y;
	map<ii, int> foi;
	vector<ii> queries(k);
	for (auto& [x, y] : queries) cin >> x >> y, --x, --y, foi[{min(x, y), max(x, y)}] = 1;
	vector<int> p(n), lvl(n);
	auto findp = [&] (auto&& self, int u) -> int{
		return p[u] = (p[u] == u ? u : self(self, p[u]));
	};
	auto unite = [&] (int u, int v) {
		u = findp(findp, u), v = findp(findp, v);
		if (u == v) return false;
		if (lvl[u] < lvl[v]) swap(u, v);
		p[v] = u;
		if (lvl[u] == lvl[v]) lvl[u]++;
		return true;
	};
	reverse(all(queries));
	for (int i = 0; i < n; ++i) p[i] = i;
	int ans = n;
	for (auto [x, y] : edg) if (!foi[{min(x, y), max(x, y)}]) {
		if (unite(x, y)) ans--;
	}
	vector<int> resp;
	for (auto [x, y] : queries) {
		resp.pb(ans);
		if (unite(x, y)) ans--;
	}
	reverse(all(resp));
	for (auto x : resp) cout << x << ' ';
	cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
