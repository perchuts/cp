#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
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
	vector<int> c(n), pr(n+1);
	for (auto& x : c) cin >> x;
	vector<vector<int>> f(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; ++i) pr[i] = pr[i-1] + c[i-1];
	for (int i = 2; i <= n; ++i) f[0][i] = f[0][i-1] + pr[i-1];
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			f[i][j] = f[i][j-1];	
			f[i][j] += pr[j-1] - pr[(i+j-1)/2];
		}
	}
	vector<int> dp(n+1, 1e18), ndp(n+1, 1e18);
	dp[0] = 0;
	cout << endl;
	for (int __ = 1; __ <= k; ++__) {
		ndp[0] = 1e18;
		auto dnc = [&] (auto&& self, int l, int r, int optl, int optr) -> void {
			if (l > r) return;	
			int md = (l+r)/2, pos = -1;
			ndp[md] = 1e18;
			if (min(optl, optr) != -1) {
				for (int i = optl; i <= min(optr, md); ++i) {
					if(ckmin(ndp[md], dp[i] + f[i][md])) pos = i;	
				}
			}
			self(self, l, md-1, optl, pos), self(self, md+1, r, pos, optr);
		};
		dnc(dnc, 1, n, 0, n);
		swap(dp, ndp);
	}
	int ans = dp[n];
	vector<int> cost(n+1);
	for (int i = n-1; i >= 1; --i) cost[i] = cost[i + 1] + pr[n] - pr[i];
	for (int i = 1; i <= n; ++i) ckmin(ans, dp[i] + cost[i]);
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
