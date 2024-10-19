#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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

ll dp[5001][5001];
int opt[5001][5001];

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	vector<ll> pr(n+1);
	for (auto& x : v) cin >> x;
	for (int i = 1; i <= n; ++i) pr[i] = pr[i-1] + v[i-1];
	for (int s = 1; s <= n; ++s) {
		for (int i = 1; i <= n-s+1; ++i) {
			dp[i][s] = 1e18;
			if (s == 1) dp[i][s] = 0, opt[i][s] = i;
			else {
				for (int k = opt[i][s-1]; k <= min(i+s-1, opt[i+1][s-1]); ++k) {
					if (ckmin(dp[i][s], dp[i][k-i+1] + dp[k+1][i+s-1-k] + pr[i+s-1] - pr[i-1])) opt[i][s] = k;
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
