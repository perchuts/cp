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
	int n; cin >> n;
	vector<int> fat(2*n+1, 1), ifat(2*n+1), pw(2*n+1, 1);
	for (int i = 1; i <= 2*n; ++i) fat[i] = fat[i-1] * i % mod, pw[i] = 2 * pw[i-1] % mod;
	auto fexp = [&] (int b, int e) {
		int ans = 1;
		while (e) {
			if (e&1) ans = ans * b % mod;
			b = b * b % mod, e /= 2;
		}
		return ans;
	};
	ifat[2*n] = fexp(fat[2*n], mod-2);
	for (int i = 2*n-1; i >= 0; --i) ifat[i] = (i + 1) * ifat[i+1] % mod;
	auto c = [&] (int a, int b) {
		return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
	};
	int ans = fat[n];
	for (int i = 2; i <= n; ++i) {
		// vou decidir quantos grupos tem
		for (int j = 1; j <= i/2; ++j) {
			// quero escolher i itens de forma q existam j componentes conexas no final
			// distribuindo a quantidade de itens nas componentes
			int inside = c(i-2*j+j-1, j-1);
			// distribuindo o espacamento entre as componentes
			int outside = c(n-i+j, j);
			int ways = inside * outside % mod * fat[n-i+j] % mod * pw[j] % mod;
			if ((i-j)&1) ans = (ans - ways + mod) % mod;
			else ans = (ans + ways) % mod;
		}
	}
	cout << ans << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
