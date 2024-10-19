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
	int n, x; cin >> n >> x;
	vector<int> v(n);
	int s = 0;
	for (auto& y : v) cin >> y, s += y;
	sort(v.rbegin(), v.rend());
	vector<vector<int>> dp(n+1, vector<int>(s+1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		auto ndp = vector<vector<int>>(n+1, vector<int>(s+1, 0));
		for (int k = 0; k <= i; ++k) {
			for (int j = 0; j <= s; ++j) {
				// posso: fechar alguem, abrir alguem, continuar alguem
				// continuar alguem + deixar sozinho:
				ndp[k][j] = dp[k][j] * (k+1) % mod;
				// abrir alguem: (laele)
				if (k and j >= v[i-1]) ndp[k][j] = (ndp[k][j] + dp[k-1][j-v[i-1]]) % mod;
				// fechar alguem: (laele)
				if (k < i and j+v[i-1] <= s) ndp[k][j] = (ndp[k][j] + dp[k+1][j+v[i-1]] * (k+1)) % mod;
			}
		}
		swap(dp, ndp);
	}
	int ans = 0;
	for (int i = 0; i <= x; ++i) ans = (ans + dp[0][i]) % mod;
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
