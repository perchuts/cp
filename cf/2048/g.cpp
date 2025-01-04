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
const int mod = (119<<23)+1;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n, m, v; cin >> n >> m >> v;
	vector<int> fat(n+1, 1), ifat(n+1);
	for (int i = 1; i <= n; ++i) fat[i] = i * fat[i-1] % mod;
	auto fexp = [&] (int b, int e) {
		b = (b % mod + mod) % mod;
		e = (e % (mod-1) + mod-1) % (mod-1);
		int ans = 1;
		while (e) {
			if (e&1) ans = ans * b % mod;
			e /= 2, b = b * b % mod;
		}
		return ans;
	};
	ifat[n] = fexp(fat[n], mod-2);
	for (int i = n-1; i >= 0; --i) ifat[i] = (i+1) * ifat[i+1] % mod;
	auto choose = [&] (int a, int b) {
		return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
	};
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= v; ++k) {
			int cur = choose(n, i) * fexp(v, -m*i) % mod;
			int a = fexp(k, i), b = fexp(v-k+1, mod-2) * v % mod;
			b = fexp(b, i-n);
			cur = cur * (fexp(a-b, m) + mod - fexp(k, i*m)) % mod; 
			if (i&1) ans = (ans + mod - cur) % mod;
			else ans = (ans + cur) % mod;
		}
	}
	ans = (ans * fexp(v, n*m)) % mod;
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; cin >> t;
  while(t--) solve();
}
