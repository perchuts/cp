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
	string s; cin >> s;
	int n = sz(s);
	// basicamente quero contar o numero de RBS coloridas com a restricao de que so posso parear parentesis q formem letras iguais
	vector<vector<int>> dp(n+2, vector<int>(n+1, 0)), ncr(n+1, vector<int>(n+1));
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= i; ++j) {
		if (j == 0 or i == j) ncr[i][j] = 1;
		else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
	}
	// dp[i][j] = rbs no i, j
	for (int i = 1; i <= n; ++i) dp[i+1][i] = 1;
	for (int i = n; i >= 1; --i) {
		for (int j = i+1; j <= n; ++j) {
			for (int k = i+1; k <= j; k += 2) {
				if (s[i-1] == s[k-1]) {
					int ways = ncr[(j-i+1)/2][(k-i+1)/2];
					dp[i][j] = (dp[i][j] + dp[i+1][k-1] * dp[k+1][j] % mod * ways) % mod;
				}
			}
		}
	}
	cout << dp[1][n] << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
