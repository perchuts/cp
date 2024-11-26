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
	int n, m; cin >> m >> n;
	vector<int> a(m), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	vector<vector<int>> ways(m, vector<int>(m)), ans = ways;
	for (int i = 0; i < m; ++i) ans[i][i] = 1;
	for (int j2 = 0; j2 < m; ++j2) for (int j = 0; j < m; ++j) {
		ways[j][j2] = ((a[j] + b[j]) * (a[j2] + b[j2]) % mod) - (b[j] * b[j2] % mod);
		ways[j][j2] = (ways[j][j2] + mod) % mod;
	}
	auto mult = [] (vector<vector<int>> x, vector<vector<int>> y) {
		int n = sz(x);
		vector<vector<int>> z(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					z[i][j] = (z[i][j] + x[i][k] * y[k][j]) % mod;
				}
			}
		}
		return z;
	};
	if (n&1) ans = ways;
	for (int p = 1; p < 30; ++p) {
		ways = mult(ways, ways);
		if (n >> p & 1) ans = mult(ans, ways);
	}
	int resp = 0;
	for (int i = 0; i < m; ++i) resp = (resp + ans[i][0]) % mod;
	cout << resp << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}

