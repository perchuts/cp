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

int fexp(int b, int e) {
	int ans = 1, p = b;
	while (e) {
		if (e&1) ans = ans * p % mod;
		e /= 2, p = p * p % mod;
	}
	return ans;
}

	
void solve(){
 	int n; cin >> n;
	vector<vector<int>> stirling(n+1, vector<int>(n+1));
	vector<int> fat(n+1), ifat(n+1), ans(n+1), pot(n+1); 
	stirling[0][0] = fat[0] = pot[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pot[i] = pot[i-1] * n % mod, fat[i] = fat[i-1] * i % mod;
		for (int j = 1; j <= i; ++j) {
			stirling[i][j] = (stirling[i-1][j] * (i-1) + stirling[i-1][j-1]) % mod;
		}
	}
	ifat[n] = fexp(fat[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) ifat[i] = (i + 1) * ifat[i+1] % mod;
	auto c = [&] (int a, int b) {
		return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
	};
	for (int i = n; i >= 1; --i) {
		for (int j = i; j <= n; ++j) {
			ans[i] = (ans[i] - ans[j] * c(j, i)) % mod;
			ans[i] = (ans[i] + mod) % mod;
			ans[i] = (ans[i] + stirling[j][i] * c(n, j) % mod * pot[n-j]) % mod;
		}
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
}

int32_t main(){_
  int t = 1;
  while(t--) solve();
}
