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
	vector<ii> products;
	vector<int> a_(n), b_(n), c_(n);
	for (auto& z : a_) cin >> z;
	for (auto& z : b_) cin >> z;
	for (auto& z : c_) cin >> z;
	for (int i = 1; i <= n; ++i) {
		int a = a_[i-1], b = b_[i-1], c = c_[i-1]; 
		while (c > 2) {
			products.pb({a, b});
			c--;
			if (c&1) products.pb({a, b});
			c /= 2;
			a *= 2, b *= 2;
		}
		while (c) products.pb({a, b}), c--;
	}
	vector<int>	dp(x+1), ndp(x+1);
	for (auto [cost, val] : products) {
		for (int i = 0; i <= x; ++i) {
			ndp[i] = dp[i];
			if (i >= cost) ckmax(ndp[i], dp[i-cost] + val);
		}
		swap(dp, ndp);
	}
	int ans = 0;
	for (int i = 0; i <= x; ++i) ckmax(ans, dp[i]);
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
