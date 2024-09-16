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

int n = 4, m = 4;
vector<int> g[64];

void init() {
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		vector<int> mov = {2, 1};
		for (int xx = 0; xx < 2; ++xx) {
			for (auto yy = 0; yy < 2; ++yy) {
				for (auto zz = 0; zz < 2; ++zz) {
					int i2 = i + mov[0], j2 = j + mov[1];
					if (min(i2, j2) >= 0 && i2 < n && j2 < m) g[m*i+j].pb(m*i2+j2);
					mov[0] *= -1;	
				}
				mov[1] *= -1;
			}
			swap(mov[0], mov[1]);
		}
	}
}
void solve(){
	init();
	cout << "Terminei" << endl;
	cout.flush();
	vector dp(1<<(n*m), vector(n*m, 0));
	dp[1][0] = 1;
	int mx = 0;
	vector<int> good;
	for (int i = 2; i < (1 << (n*m)); ++i) {
		cout << i << endl;
		cout.flush();
		for (int j = 0; j < n * m; ++j) {
			if ((i>>j)&1) {
				for (auto w : g[j]) {
					if ((i>>w)&1) dp[i][j] |= dp[i-(1<<j)][w];
				}
			}
			if (dp[i][j] == 1) {
				if (ckmax(mx, __builtin_popcount(i))) good = {j};
				else if (__builtin_popcount(i) == mx) good.pb(j);
			}
		}
	}
	cout << mx << endl;
	for (auto x : good) cout << x / m << ' ' << x % m << endl;
}

int32_t main(){_
	solve();
}
