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
const int maxn = 3e6+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }


int f(int n, int d) {
	string s = to_string(n);
	int x = *max_element(all(s)) - '0';
	return max(0ll, n - max(x, d));
}


void solve(){
	vector dp(10, vector(20, vector(10, vector(10, make_pair(0ll, 0)))));
	vector pot(20, 1ll);
	for (int y = 1; y <= 2; ++y) {
		pot[y] = 10 * pot[y-1];
		for (int x = 1; x < 10; ++x) {
			for (int r = 0; r < 10; ++r) {
				for (int d = 0; d < 10; ++d) {
					int N = x * pot[y] + r, L = N;
					auto& DP = dp[d][y][x][r];
					while (N) {
						DP.first += (N % 10 == 0);
						L = N, N = f(N, d);	
					}
					DP.second = L;
				}
			}
		}
	}
	for (int y = 3; y < 18; ++y) {
		pot[y] = 10 * pot[y-1];
		for (int x = 1; x < 10; ++x) {
			for (int r = 0; r < 10; ++r) {
				for (int d = 0; d < 10; ++d) {
					auto& DP = dp[d][y][x][r];
					int N = x * pot[y] + r;
					if (x == 1) {
						if (d <= r) {
							DP.first = 1 + pot[y-1]/90;
							while (N >= pot[y]) N = f(N, d);
							DP.first += dp[d][y-1][9][N%9].first;
							DP.second = dp[d][y-1][9][N%9].second;
							continue;
						}
						if (r) N = f(N, d);
						if (N % 10 == 0) DP.first = 1, N = f(N, d);
						while (N % 10) N = f(N, d);
						DP.first += 1 + ((N%pot[y-1]) - 1)/90 + dp[d][y-1][9][N%9].first;
						DP.second = dp[d][y-1][9][N%9].second;
						continue;
					} 
					if (r) N = f(N, d);
					if (N % 10 == 0) DP.first = 1, N = f(N, d);
					while (N % 10) N = f(N, d);
					int digit = (N/10)%10, target = (x-1) * pot[y] + 9 * pot[y-1] + digit;
					DP.first += 1 + (N-target-1)/90 + dp[max(d, x-1)][y-1][9][digit].first;
					int R = dp[max(d, x-1)][y-1][9][digit].second;
					DP.first += dp[d][y][x-1][R].first;
					DP.second = dp[d][y][x-1][R].second;
				}
			}
		}
	}
 	int n, ans = 0, flag = 0; cin >> n;
	int N = n;
	if (n == 10 * pot[17]) flag = 1, n = f(n, 0);
	vector<ii> dp2(10);
	for (int y = 0; y < 18; ++y) {
		int x = n % 10;
		n /= 10;
		if (x == 0) continue;
		ans = dp2[x].first + dp[0][y][x][dp2[x].second].first;
		vector<ii> ndp2(10);
		for (int d = 0; d < 10; ++d) {
			if (y) {
				ndp2[d].first = dp2[max(d, x)].first + dp[d][y][x][dp2[max(d, x)].second].first;	
				ndp2[d].second = dp[d][y][x][dp2[max(d, x)].second].second;
			} else ndp2[d].second = x;
		}
		swap(dp2, ndp2);
	}
	cout << (N + 9) / 10 + ans + flag << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
