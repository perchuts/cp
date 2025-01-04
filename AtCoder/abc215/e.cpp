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
	int n; cin >> n;
	string s; cin >> s;
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(1<<10, vector<int>(11)));
	for (int i = 0; i <= 10; ++i) dp[0][0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		int code = s[i-1] - 'A';
		for (int j = 0; j < (1 << 10); ++j) {
			for (int w = 0; w < 10; ++w) {
				if (w == code) {
					if (j >> code & 1) dp[i][j][w] = (2*dp[i-1][j][w] + dp[i-1][j-(1<<code)][10]) % mod;
				}
				else dp[i][j][w] = dp[i-1][j][w];
				dp[i][j][10] = (dp[i][j][10] + dp[i][j][w]) % mod;
			}
		}
		dp[i][0][10] = 1;
	}
	int ans = 0;
	for (int i = 0; i < (1 << 10); ++i) ans = (ans + dp[n][i][10]) % mod;
	cout << (ans+mod-1) % mod << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
