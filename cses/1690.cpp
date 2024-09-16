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
	vector adj(n, vector(n, 0ll));
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u][v]++;
	}
	vector dp(n, vector(1<<n, 0ll));
	dp[0][1] = 1;
	vector<int> bits(n);	
	for (int i = 2; i < (1 << n); ++i) {
		int q = 0;
		for (int j = 0; j < n; ++j) if ((i>>j)&1) bits[q++] = j;
		for (int j = 0; j < q; ++j) {
			for (int k = j+1; k < q; ++k) {
				dp[bits[k]][i] = (dp[bits[k]][i] + adj[bits[j]][bits[k]] * dp[bits[j]][i-(1<<bits[k])]) % mod;
				dp[bits[j]][i] = (dp[bits[j]][i] + adj[bits[k]][bits[j]] * dp[bits[k]][i-(1<<bits[j])]) % mod;
			}
		}
		
	}
	cout << dp[n-1][(1<<n)-1] << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
