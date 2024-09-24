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
	if (2*n <= k) {
		cout << 0 << endl;
		return;
	}
	vector dp1(n+1, vector(2*n+1, 0LL)), dp2 = dp1;
	// dp1 vai do 1 ateh o n, dp2 vai do 2 ateh o n-1
	dp1[0][0] = 1;
	int mode = n&1;
	for (int i = 1; 2*i-1 <= n; ++i) {
		int x = (mode == 1 and i == (n+1)/2);
		for (int j = 0; j <= n; ++j) {
			// colocar ngm
			dp1[i][j] = dp1[i-1][j];
			// colocar 1 cara (pode ser desse lado ou do outro)
			if (j) dp1[i][j] += (x ? 1 : 2) * dp1[i-1][j-1] * (2*i-1-j+1);
			// colocar 2 caras	
			if (j >= 2 and x == 0) dp1[i][j] += dp1[i-1][j-2] * (2*i-1-j+2) * (2*i-1-j+1);
			dp1[i][j] %= mod;
		}
	}
	dp2[0][0] = 1;
	for (int i = 1; 2*i <= n; ++i) {
		int x = (mode == 0 and i == n/2);
		for (int j = 0; j <= n; ++j) {
			// colocar ngm
			dp2[i][j] = dp2[i-1][j];
			// colocar 1 cara (pode ser desse lado ou do outro)
			if (j) dp2[i][j] += (x ? 1 : 2) * dp2[i-1][j-1] * (2*i-j+1);
			// colocar 2 caras	
			if (j >= 2 and x == 0) dp2[i][j] += dp2[i-1][j-2] * (2*i-j+2) * (2*i-j+1);
			dp2[i][j] %= mod;
		}
	}
	int ans = 0;
	if (n&1) {
		for (int i = 0; i <= k; ++i) ans = (ans + dp1[n/2+1][i] * dp2[n/2][k-i]) % mod;
	} else {
		for (int i = 0; i <= k; ++i) ans = (ans + dp1[n/2][i] * dp2[n/2][k-i]) % mod;
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
