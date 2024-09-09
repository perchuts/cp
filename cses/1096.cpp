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

matrix id;

matrix mult(matrix a, matrix b) {
	int n = sz(a);
	matrix ans(n, vector<int>(n));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		for (int k = 0; k < n; ++k) {
			ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % mod;	
		}
	}	
	return ans;
}

matrix fexp(matrix m, int e) {
	matrix ans = id;
	while (e) {
		if (e&1) ans = mult(m, ans);
		m = mult(m, m), e /= 2;
	}		
	return ans;
}

void solve(){
 	int n; cin >> n;
	matrix m(6, vector<int>(6));
	for (int i = 1; i < 6; ++i) m[i][i-1] = 1;
	for (int i = 0; i < 6; ++i) m[0][i] = 1;
	id = matrix(6, vector<int>(6));
	for (int i = 0; i < 6; ++i) id[i][i] = 1;
	m = fexp(m, n);
	cout << m[0][0] << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
