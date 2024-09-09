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
const int maxn = 2e6+10;

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
	vector<int> fat(maxn, 1), ifat(maxn);
	for (int i = 1; i < maxn; ++i) fat[i] = fat[i-1] * i % mod;
	ifat[maxn-1] = fexp(fat[maxn-1], mod - 2);
	for (int i = maxn - 2; i >= 0; --i) ifat[i] = (i + 1) * ifat[i+1] % mod;
	int n; cin >> n;
	int ans = 0;
	auto c = [&] (int a, int b) {
		return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
	};
	for (int i = 0; i <= n; ++i) {
		int x = c(n, i) * fat[n-i] % mod;
		if (i&1) ans = (ans + mod - x) % mod;
		else ans = (ans + x) % mod;
	}
	cout << ans << endl;
}


int32_t main(){_
	solve();
}
