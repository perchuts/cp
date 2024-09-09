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
	int ans = 1;
	while (e) {
		if (e&1) ans = ans * b % mod;
		e /= 2, b = b * b % mod;
	}
	return ans;
}

void solve(){
 	int n, m; cin >> n >> m;
	// let x be the minimum number of rotations to some S s.t. S' = S, where S' is S rotated x times.
	// we claim that x | n -> proved!
 	// ans[k] = m^k - sum(ans[k']), where k' | k
	vector<int> ans(n+1, 1);
	for (int i = 1; i <= n; ++i) ans[i] = ans[i-1] * m % mod;
	int resp = 0;
	for (int i = 1; i <= n; ++i) {
		ans[i] = ans[i] * fexp(i, mod-2) % mod;
		for (int j = 2 * i; j <= n; j += i) ans[j] = (ans[j] + i * mod - i * ans[i]) % mod;
		if (n % i == 0) resp = (resp + ans[i]) % mod;
	}
	cout << resp << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
