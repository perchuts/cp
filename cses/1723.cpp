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

using matrix = vector<vector<int>>;

matrix mult(matrix a, matrix b) {
	int n = sz(a);
	matrix ans(n, vector<int>(n, 2e18));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		for (int k = 0; k < n; ++k) ans[i][j] = min(ans[i][j], a[i][k] + b[k][j]);
	}
	return ans;
}

matrix id;

matrix fexp(matrix m, int e) {
	matrix ans = id;
	while (e) {
		if (e&1) ans = mult(m, ans);
		e /= 2, m = mult(m, m);
	}
	return ans;
}

void solve(){
	int n, M, k; cin >> n >> M >> k;
	matrix m;
	m = matrix(n, vector<int>(n, 2e18));
	id = matrix(n, vector<int>(n, 2e18));
	for (int i = 0; i < n; ++i) id[i][i] = 0;
	for (int i = 0; i < M; ++i) {
		int u, v, c; cin >> u >> v >> c;
		--u, --v;
		ckmin(m[u][v], c);
	}
	m = fexp(m, k);
	cout << (m[0][n-1] == 2e18 ? -1 : m[0][n-1]) << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
