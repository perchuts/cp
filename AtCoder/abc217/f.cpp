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
const int mod = (119<<23)+1;
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
	n *= 2;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, -- v, adj[u][v] = adj[v][u] = 1;
	}
	vector<vector<int>> dp(n+1, vector<int>(n+1)), ncr = dp;
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= i; ++j) {
		if (i == j or j == 0) ncr[i][j] = 1;
		else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
	}
	for (int i = 1; i <= n; ++i) dp[i][i-1] = 1;
	for (int l = n-1; ~l; --l) {
		for (int r = l+1; r < n; r += 2) {
			for (int k = l+1; k <= r; k += 2) {
				if (adj[l][k]) dp[l][r] = (dp[l][r] + dp[l+1][k-1] * dp[k+1][r] % mod * ncr[(r-l+1)/2][(k-l+1)/2]) % mod;
			}
		}
	}
	cout << dp[0][n-1] << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
