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
	if (m == 1) {
		cout << (n % 2 ? 0 : 1) << endl;
		return;
	}
	vector<int> dp(1<<n), tr;
	for (int i = 0; i < (1 << n); ++i) {
		int c = 0, sobra = 1;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				if (c&1) sobra = 0;
				c = 0;
			} else c++;
		}
		if (c&1) sobra = 0;
		if (sobra) tr.pb(i);
	}	
	dp[0] = 1;
	for (int __ = 0; __ < m-1; ++__) {
		vector<int> ndp(1<<n);
		for (auto j : tr) {
			for (int s = j; ; s = (s-1) & j) {
				int s2 = j - s;
				ndp[s] = (ndp[s] + dp[s2]) % mod;
				if (s == 0) break;
			}
		}
		swap(dp, ndp);
	}
	int ans = 0;
	for (auto i : tr) ans = (ans + dp[i]) % mod;
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
