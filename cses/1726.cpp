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

double dp[8][8][8][8][101], nb[8][8];

void solve(){
 	int k; cin >> k;
	for (int i2 = 0; i2 < 8; ++i2) {
		for (int j2 = 0; j2 < 8; ++j2) {
			dp[i2][j2][i2][j2][0] = 1;
			if (i2 != 0) nb[i2][j2]++; 
			if (j2 != 0) nb[i2][j2]++;
			if (i2 != 7) nb[i2][j2]++;
			if (j2 != 7) nb[i2][j2]++;
		}
	}
	for (int turn = 1; turn <= k; ++turn) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				for (int i2 = 0; i2 < 8; ++i2) {
					for (int j2 = 0; j2 < 8; ++j2) {
						if (i2 != 0) dp[i][j][i2][j2][turn] += dp[i][j][i2-1][j2][turn-1] / nb[i2-1][j2]; 
						if (j2 != 0) dp[i][j][i2][j2][turn] += dp[i][j][i2][j2-1][turn-1] / nb[i2][j2-1];
						if (i2 != 7) dp[i][j][i2][j2][turn] += dp[i][j][i2+1][j2][turn-1] / nb[i2+1][j2];
						if (j2 != 7) dp[i][j][i2][j2][turn] += dp[i][j][i2][j2+1][turn-1] / nb[i2][j2+1];
					}
				}
			}
		}
	}
	double ans = 0;
	int n = 8;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) { 
			double t = 1;
			for (int i2 = 0; i2 < n; ++i2) {
				for (int j2 = 0; j2 < n; ++j2) { 
					t *= (1 - dp[i2][j2][i][j][k]);
				}
			}
			ans += t;
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
