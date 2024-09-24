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
	int n, m; cin >> n >> m;
	vector<ii> pos(m);
	for (auto& [x, y] : pos) cin >> x >> y;
	pos.pb({n, n});
	pos.pb({1, 1});
	vector<int> fat(2*n+1, 1), ifat(2*n+1);
	for (int i = 1; i <= 2*n; ++i) fat[i] = fat[i-1] * i % mod;
	auto fexp = [&] (int b, int e) {
		int ans = 1;
		while (e) {
			if (e&1) ans = ans * b % mod;
			b = b * b % mod, e /= 2;
		}
		return ans;
	};
	ifat[2*n] = fexp(fat[2*n], mod-2);
	for (int i = 2*n-1; i >= 0; --i) ifat[i] = (i + 1) * ifat[i+1] % mod;
	auto c = [&] (int a, int b) {
		return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
	};
	m = sz(pos);
	vector<int> deg(m), dp(m);
	vector<vector<int>> g(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == j) continue;
			if (pos[i].first <= pos[j].first and pos[i].second <= pos[j].second) {
				deg[j]++;
				g[i].pb(j);
			}
		}
	}
	queue<int> q;
	q.push(m-1);
	dp[m-1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : g[u]) {
			int x = mod - c(pos[v].first - pos[u].first + pos[v].second - pos[u].second, pos[v].first - pos[u].first);
			dp[v] = (dp[v] + dp[u] * x) % mod;
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	int ans = (mod - dp[m-2]) % mod;
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
