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
	int n, k; cin >> n >> k;
	// dp[i][j] = resposta pra (i, j)
	// dp[i][j] : vamos decidir quem vai ficar na ponta!
	// dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-i]
	vector<int> dp(1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		vector<int> ndp(i * (i-1) / 2 + 1);
		int L = (i-1) * (i-2) / 2;
		for (int j = 0; j <= i * (i-1) / 2; ++j) {
			ndp[j] = (dp[min(L, j)] - (j-i < 0 ? 0 : dp[j-i]) + mod) % mod;
			if (j) ndp[j] = (ndp[j-1] + ndp[j]) % mod;
		}
		swap(dp, ndp);
	}
	cout << (dp[k] - (k ? dp[k-1] : 0) + mod) % mod << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
